#include <bx/bx.h>
#include <bgfx.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>

#include <tinystl/allocator.h>
#include <tinystl/vector.h>
#include <tinystl/string.h>
namespace stl = tinystl;

#include <bgfx/bgfx.h>
#include <bx/endian.h>
#include <bx/math.h>
#include <bx/readerwriter.h>
#include <bx/string.h>
#include <bimg/bimg.h>
#include <bimg/decode.h>
#include <bounds.h>
#include <bx/bx.h>
#include <bx/file.h>
#include <bx/sort.h>
#include <meshoptimizer/src/meshoptimizer.h>

bx::DefaultAllocator default_allocator;
bx::AllocatorI * allocator = & default_allocator;

struct MeshState
{
	struct Texture
	{
		uint32_t            m_flags;
		bgfx::UniformHandle m_sampler;
		bgfx::TextureHandle m_texture;
		uint8_t             m_stage;
	};

	Texture             m_textures[4];
	uint64_t            m_state;
	bgfx::ProgramHandle m_program;
	uint8_t             m_numTextures;
	bgfx::ViewId        m_viewId;
};

struct Primitive
{
	uint32_t m_startIndex;
	uint32_t m_numIndices;
	uint32_t m_startVertex;
	uint32_t m_numVertices;

	Sphere m_sphere;
	Aabb m_aabb;
	Obb m_obb;
};

typedef stl::vector<Primitive> PrimitiveArray;

struct Group
{
	Group();
	void reset();

	bgfx::VertexBufferHandle m_vbh;
	bgfx::IndexBufferHandle m_ibh;
	uint16_t m_numVertices;
	uint8_t* m_vertices;
	uint32_t m_numIndices;
	uint16_t* m_indices;
	Sphere m_sphere;
	Aabb m_aabb;
	Obb m_obb;
	PrimitiveArray m_prims;
};
typedef stl::vector<Group> GroupArray;

struct Mesh
{
	void load(bx::ReaderSeekerI* _reader, bool _ramcopy);
	void unload();
	void submit(bgfx::ViewId _id, bgfx::ProgramHandle _program, const void* _mtx, uint64_t _state) const;
	void submit(const MeshState*const* _state, uint8_t _numPasses, const void* _mtx, uint16_t _numMatrices) const;

	bgfx::VertexLayout m_layout;
	GroupArray m_groups;
};


Group::Group()
{
	reset();
}

void Group::reset()
{
	m_vbh.idx = bgfx::kInvalidHandle;
	m_ibh.idx = bgfx::kInvalidHandle;
	m_numVertices = 0;
	m_vertices = NULL;
	m_numIndices = 0;
	m_indices = NULL;
	m_prims.clear();
}

namespace bgfx
{
	int32_t read(bx::ReaderI* _reader, bgfx::VertexLayout& _layout, bx::Error* _err = NULL);
}

void Mesh::load(bx::ReaderSeekerI* _reader, bool _ramcopy)
{
	constexpr uint32_t kChunkVertexBuffer           = BX_MAKEFOURCC('V', 'B', ' ', 0x1);
	constexpr uint32_t kChunkVertexBufferCompressed = BX_MAKEFOURCC('V', 'B', 'C', 0x0);
	constexpr uint32_t kChunkIndexBuffer            = BX_MAKEFOURCC('I', 'B', ' ', 0x0);
	constexpr uint32_t kChunkIndexBufferCompressed  = BX_MAKEFOURCC('I', 'B', 'C', 0x1);
	constexpr uint32_t kChunkPrimitive              = BX_MAKEFOURCC('P', 'R', 'I', 0x0);

	using namespace bx;
	using namespace bgfx;

	Group group;

	uint32_t chunk;
	bx::Error err;
	while (4 == bx::read(_reader, chunk, &err)
	   &&  err.isOk() )
	{
		switch (chunk)
		{
			case kChunkVertexBuffer:
			{
				read(_reader, group.m_sphere);
				read(_reader, group.m_aabb);
				read(_reader, group.m_obb);

				read(_reader, m_layout);

				uint16_t stride = m_layout.getStride();

				read(_reader, group.m_numVertices);
				const bgfx::Memory* mem = bgfx::alloc(group.m_numVertices*stride);
				read(_reader, mem->data, mem->size);

				if (_ramcopy)
				{
					group.m_vertices = (uint8_t*)BX_ALLOC(allocator, group.m_numVertices*stride);
					bx::memCopy(group.m_vertices, mem->data, mem->size);
				}

				group.m_vbh = bgfx::createVertexBuffer(mem, m_layout);
			}
				break;

			case kChunkVertexBufferCompressed:
			{
				read(_reader, group.m_sphere);
				read(_reader, group.m_aabb);
				read(_reader, group.m_obb);

				read(_reader, m_layout);

				uint16_t stride = m_layout.getStride();

				read(_reader, group.m_numVertices);

				const bgfx::Memory* mem = bgfx::alloc(group.m_numVertices*stride);

				uint32_t compressedSize;
				bx::read(_reader, compressedSize);

				void* compressedVertices = BX_ALLOC(allocator, compressedSize);
				bx::read(_reader, compressedVertices, compressedSize);

				meshopt_decodeVertexBuffer(mem->data, group.m_numVertices, stride, (uint8_t*)compressedVertices, compressedSize);

				BX_FREE(allocator, compressedVertices);

				if (_ramcopy)
				{
					group.m_vertices = (uint8_t*)BX_ALLOC(allocator, group.m_numVertices*stride);
					bx::memCopy(group.m_vertices, mem->data, mem->size);
				}

				group.m_vbh = bgfx::createVertexBuffer(mem, m_layout);
			}
				break;

			case kChunkIndexBuffer:
			{
				read(_reader, group.m_numIndices);
				const bgfx::Memory* mem = bgfx::alloc(group.m_numIndices*2);
				read(_reader, mem->data, mem->size);

				if (_ramcopy)
				{
					group.m_indices = (uint16_t*)BX_ALLOC(allocator, group.m_numIndices*2);
					bx::memCopy(group.m_indices, mem->data, mem->size);
				}

				group.m_ibh = bgfx::createIndexBuffer(mem);
			}
				break;

			case kChunkIndexBufferCompressed:
			{
				bx::read(_reader, group.m_numIndices);

				const bgfx::Memory* mem = bgfx::alloc(group.m_numIndices*2);

				uint32_t compressedSize;
				bx::read(_reader, compressedSize);

				void* compressedIndices = BX_ALLOC(allocator, compressedSize);

				bx::read(_reader, compressedIndices, compressedSize);

				meshopt_decodeIndexBuffer(mem->data, group.m_numIndices, 2, (uint8_t*)compressedIndices, compressedSize);

				BX_FREE(allocator, compressedIndices);

				if (_ramcopy)
				{
					group.m_indices = (uint16_t*)BX_ALLOC(allocator, group.m_numIndices*2);
					bx::memCopy(group.m_indices, mem->data, mem->size);
				}

				group.m_ibh = bgfx::createIndexBuffer(mem);
			}
				break;

			case kChunkPrimitive:
			{
				uint16_t len;
				read(_reader, len);

				stl::string material;
				material.resize(len);
				read(_reader, const_cast<char*>(material.c_str() ), len);

				uint16_t num;
				read(_reader, num);

				for (uint32_t ii = 0; ii < num; ++ii)
				{
					read(_reader, len);

					stl::string name;
					name.resize(len);
					read(_reader, const_cast<char*>(name.c_str() ), len);

					Primitive prim;
					read(_reader, prim.m_startIndex);
					read(_reader, prim.m_numIndices);
					read(_reader, prim.m_startVertex);
					read(_reader, prim.m_numVertices);
					read(_reader, prim.m_sphere);
					read(_reader, prim.m_aabb);
					read(_reader, prim.m_obb);

					group.m_prims.push_back(prim);
				}

				m_groups.push_back(group);
				group.reset();
			}
				break;

			default:
//				DBG("%08x at %d", chunk, bx::skip(_reader, 0) );
				break;
		}
	}
}

void Mesh::unload()
{
	for (GroupArray::const_iterator it = m_groups.begin(), itEnd = m_groups.end(); it != itEnd; ++it)
	{
		const Group& group = *it;
		bgfx::destroy(group.m_vbh);

		if (bgfx::isValid(group.m_ibh) )
		{
			bgfx::destroy(group.m_ibh);
		}

		if (NULL != group.m_vertices)
		{
			BX_FREE(allocator, group.m_vertices);
		}

		if (NULL != group.m_indices)
		{
			BX_FREE(allocator, group.m_indices);
		}
	}
	m_groups.clear();
}

void Mesh::submit(bgfx::ViewId _id, bgfx::ProgramHandle _program, const void* _mtx, uint64_t _state) const
{
	if (BGFX_STATE_MASK == _state)
	{
		_state = 0
			| BGFX_STATE_WRITE_RGB
			| BGFX_STATE_WRITE_A
			| BGFX_STATE_WRITE_Z
			| BGFX_STATE_DEPTH_TEST_LESS
			| BGFX_STATE_CULL_CCW
			| BGFX_STATE_MSAA
			;
	}

	bgfx::setTransform(_mtx);
	bgfx::setState(_state);

	for (GroupArray::const_iterator it = m_groups.begin(), itEnd = m_groups.end(); it != itEnd; ++it)
	{
		const Group& group = *it;

		bgfx::setIndexBuffer(group.m_ibh);
		bgfx::setVertexBuffer(0, group.m_vbh);
		bgfx::submit(_id, _program, 0, (it == itEnd-1) ? (BGFX_DISCARD_INDEX_BUFFER | BGFX_DISCARD_VERTEX_STREAMS | BGFX_DISCARD_STATE) : BGFX_DISCARD_NONE);
	}
}

void Mesh::submit(const MeshState*const* _state, uint8_t _numPasses, const void* _mtx, uint16_t _numMatrices) const
{
	uint32_t cached = bgfx::setTransform(_mtx, _numMatrices);

	for (uint32_t pass = 0; pass < _numPasses; ++pass)
	{
		bgfx::setTransform(cached, _numMatrices);

		const MeshState& state = *_state[pass];
		bgfx::setState(state.m_state);

		for (uint8_t tex = 0; tex < state.m_numTextures; ++tex)
		{
			const MeshState::Texture& texture = state.m_textures[tex];
			bgfx::setTexture(
				  texture.m_stage
				, texture.m_sampler
				, texture.m_texture
				, texture.m_flags
				);
		}

		for (GroupArray::const_iterator it = m_groups.begin(), itEnd = m_groups.end(); it != itEnd; ++it)
		{
			const Group& group = *it;

			bgfx::setIndexBuffer(group.m_ibh);
			bgfx::setVertexBuffer(0, group.m_vbh);
			bgfx::submit(
				  state.m_viewId
				, state.m_program
				, 0
				, (it == itEnd - 1) ? (BGFX_DISCARD_INDEX_BUFFER | BGFX_DISCARD_VERTEX_STREAMS | BGFX_DISCARD_STATE) : BGFX_DISCARD_NONE
				);
		}
	}
}


//Mesh* meshLoad(const char* _filePath, bool _ramcopy)
Mesh* meshLoad(const char* _filePath, bool _ramcopy)
{
	bx::FileReaderI* reader = BX_NEW(allocator, bx::FileReader);
	if (bx::open(reader, _filePath) )
	{
        Mesh* mesh = new Mesh;
	    mesh->load(reader, _ramcopy);
		bx::close(reader);
		return mesh;
	}
    BX_DELETE(allocator, reader);
	return NULL;
}

void meshUnload(Mesh* _mesh)
{
	_mesh->unload();
	delete _mesh;
}

MeshState* meshStateCreate()
{
	MeshState* state = (MeshState*)BX_ALLOC(allocator, sizeof(MeshState) );
	return state;
}

void meshStateDestroy(MeshState* _meshState)
{
	BX_FREE(allocator, _meshState);
}


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_bgfx_utils(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{
		pybind11::class_<Mesh, std::shared_ptr<Mesh>> cl(M("bgfx"), "InternalMesh", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new Mesh(); } ) );
		cl.def_readwrite("m_layout", &Mesh::m_layout);
		cl.def_readwrite("m_groups", &Mesh::m_groups);
		cl.def("load", (void (Mesh::*)(int *, bool)) &Mesh::load, "C++: Mesh::load(int *, bool) --> void", pybind11::arg("_reader"), pybind11::arg("_ramcopy"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("unload", (void (Mesh::*)()) &Mesh::unload, "C++: Mesh::unload() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("submit", (void (Mesh::*)(unsigned short, struct bgfx::ProgramHandle, const void *, uint64_t) const) &Mesh::submit, "C++: Mesh::submit(unsigned short, struct bgfx::ProgramHandle, const void *, unsigned long long) const --> void", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::arg("_mtx"), pybind11::arg("_state"), pybind11::call_guard<pybind11::gil_scoped_release>());
	}

    M("bgfx").def("mesh_load", (struct Mesh * (*)(const char *, const bool)) &meshLoad, "C++: meshLoad(const char *, bool) --> struct bgfx::TextureHandle", pybind11::arg("_filePath"), pybind11::arg("_ramcopy"), pybind11::call_guard<pybind11::gil_scoped_release>());

}