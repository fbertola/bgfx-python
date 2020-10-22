// File: bgfx.cpp
#include <bgfx.h>
#include <sstream> // __str__

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <cstdint>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

//void bind_types(std::function< pybind11::module &(std::string const &namespace_) > &M)
//{
//	pybind11::class_<Bool>(M("bgfx"), "Bool")
//		.def(pybind11::init())
//		.def(pybind11::init<bool>())
//		.def_readwrite("value", &Bool::value);
//
//	pybind11::class_<Float>(M("bgfx"), "Float")
//		.def(pybind11::init())
//		.def(pybind11::init<float>())
//		.def_readwrite("value", &Float::value);
//
//	pybind11::class_<Int>(M("bgfx"), "Int")
//		.def(pybind11::init())
//		.def(pybind11::init<int>())
//		.def_readwrite("value", &Int::value);
//
//	pybind11::class_<String>(M("bgfx"), "String")
//		.def(pybind11::init())
//		.def(pybind11::init<std::string>())
//		.def_readwrite("value", &String::value);
//}

void bind_bgfx(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // bgfx::Fatal file:bgfx.h line:31
		pybind11::class_<bgfx::Fatal, std::shared_ptr<bgfx::Fatal>> cl(M("bgfx"), "Fatal", "Fatal error enum.\n\n \n C99 equivalent is `bgfx_fatal_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::Fatal(); } ) );

		pybind11::enum_<bgfx::Fatal::Enum>(cl, "Enum", pybind11::arithmetic(), "")
			.value("DEBUG_CHECK", bgfx::Fatal::Enum::DebugCheck)
			.value("INVALID_SHADER", bgfx::Fatal::Enum::InvalidShader)
			.value("UNABLE_TO_INITIALIZE", bgfx::Fatal::Enum::UnableToInitialize)
			.value("UNABLE_TO_CREATE_TEXTURE", bgfx::Fatal::Enum::UnableToCreateTexture)
			.value("DEVICE_LOST", bgfx::Fatal::Enum::DeviceLost)
			.value("COUNT", bgfx::Fatal::Enum::Count)
			.export_values();

	}
	{ // bgfx::RendererType file:bgfx.h line:49
		pybind11::class_<bgfx::RendererType, std::shared_ptr<bgfx::RendererType>> cl(M("bgfx"), "RendererType", "Renderer backend type enum.\n\n \n C99 equivalent is `bgfx_renderer_type_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::RendererType(); } ) );

		pybind11::enum_<bgfx::RendererType::Enum>(cl, "Enum", pybind11::arithmetic(), "Renderer types:")
			.value("NOOP", bgfx::RendererType::Enum::Noop)
			.value("DIRECT3D9", bgfx::RendererType::Enum::Direct3D9)
			.value("DIRECT3D11", bgfx::RendererType::Enum::Direct3D11)
			.value("DIRECT3D12", bgfx::RendererType::Enum::Direct3D12)
			.value("GNM", bgfx::RendererType::Enum::Gnm)
			.value("METAL", bgfx::RendererType::Enum::Metal)
			.value("NVN", bgfx::RendererType::Enum::Nvn)
			.value("OPENGLES", bgfx::RendererType::Enum::OpenGLES)
			.value("OPENGL", bgfx::RendererType::Enum::OpenGL)
			.value("VULKAN", bgfx::RendererType::Enum::Vulkan)
			.value("COUNT", bgfx::RendererType::Enum::Count)
			.export_values();

	}
	{ // bgfx::Access file:bgfx.h line:73
		pybind11::class_<bgfx::Access, std::shared_ptr<bgfx::Access>> cl(M("bgfx"), "Access", "Access mode enum.\n\n \n C99 equivalent is `bgfx_access_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::Access(); } ) );

		pybind11::enum_<bgfx::Access::Enum>(cl, "Enum", pybind11::arithmetic(), "Access:")
			.value("READ", bgfx::Access::Enum::Read)
			.value("WRITE", bgfx::Access::Enum::Write)
			.value("READ_WRITE", bgfx::Access::Enum::ReadWrite)
			.value("COUNT", bgfx::Access::Enum::Count)
			.export_values();

	}
	{ // bgfx::Attrib file:bgfx.h line:90
		pybind11::class_<bgfx::Attrib, std::shared_ptr<bgfx::Attrib>> cl(M("bgfx"), "Attrib", "Vertex attribute enum.\n\n \n C99 equivalent is `bgfx_attrib_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::Attrib(); } ) );

		pybind11::enum_<bgfx::Attrib::Enum>(cl, "Enum", pybind11::arithmetic(), "Corresponds to vertex shader attribute.")
			.value("POSITION", bgfx::Attrib::Enum::Position)
			.value("NORMAL", bgfx::Attrib::Enum::Normal)
			.value("TANGENT", bgfx::Attrib::Enum::Tangent)
			.value("BITANGENT", bgfx::Attrib::Enum::Bitangent)
			.value("COLOR0", bgfx::Attrib::Enum::Color0)
			.value("COLOR1", bgfx::Attrib::Enum::Color1)
			.value("COLOR2", bgfx::Attrib::Enum::Color2)
			.value("COLOR3", bgfx::Attrib::Enum::Color3)
			.value("INDICES", bgfx::Attrib::Enum::Indices)
			.value("WEIGHT", bgfx::Attrib::Enum::Weight)
			.value("TEXCOORD0", bgfx::Attrib::Enum::TexCoord0)
			.value("TEXCOORD1", bgfx::Attrib::Enum::TexCoord1)
			.value("TEXCOORD2", bgfx::Attrib::Enum::TexCoord2)
			.value("TEXCOORD3", bgfx::Attrib::Enum::TexCoord3)
			.value("TEXCOORD4", bgfx::Attrib::Enum::TexCoord4)
			.value("TEXCOORD5", bgfx::Attrib::Enum::TexCoord5)
			.value("TEXCOORD6", bgfx::Attrib::Enum::TexCoord6)
			.value("TEXCOORD7", bgfx::Attrib::Enum::TexCoord7)
			.value("COUNT", bgfx::Attrib::Enum::Count)
			.export_values();

	}
	{ // bgfx::AttribType file:bgfx.h line:122
		pybind11::class_<bgfx::AttribType, std::shared_ptr<bgfx::AttribType>> cl(M("bgfx"), "AttribType", "Vertex attribute type enum.\n\n \n C99 equivalent is `bgfx_attrib_type_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::AttribType(); } ) );

		pybind11::enum_<bgfx::AttribType::Enum>(cl, "Enum", pybind11::arithmetic(), "Attribute types:")
			.value("UINT8", bgfx::AttribType::Enum::Uint8)
			.value("UINT10", bgfx::AttribType::Enum::Uint10)
			.value("INT16", bgfx::AttribType::Enum::Int16)
			.value("HALF", bgfx::AttribType::Enum::Half)
			.value("FLOAT", bgfx::AttribType::Enum::Float)
			.value("COUNT", bgfx::AttribType::Enum::Count)
			.export_values();

	}
	{ // bgfx::TextureFormat file:bgfx.h line:155
		pybind11::class_<bgfx::TextureFormat, std::shared_ptr<bgfx::TextureFormat>> cl(M("bgfx"), "TextureFormat", "Texture format enum.\n\n Notation:\n\n       RGBA16S\n       ^   ^ ^\n       |   | +-- [ ]Unorm\n       |   |     [F]loat\n       |   |     [S]norm\n       |   |     [I]nt\n       |   |     [U]int\n       |   +---- Number of bits per component\n       +-------- Components\n\n \n Availability depends on Caps (see: formats).\n\n \n C99 equivalent is `bgfx_texture_format_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::TextureFormat(); } ) );

		pybind11::enum_<bgfx::TextureFormat::Enum>(cl, "Enum", pybind11::arithmetic(), "Texture formats:")
			.value("BC1", bgfx::TextureFormat::Enum::BC1)
			.value("BC2", bgfx::TextureFormat::Enum::BC2)
			.value("BC3", bgfx::TextureFormat::Enum::BC3)
			.value("BC4", bgfx::TextureFormat::Enum::BC4)
			.value("BC5", bgfx::TextureFormat::Enum::BC5)
			.value("BC6H", bgfx::TextureFormat::Enum::BC6H)
			.value("BC7", bgfx::TextureFormat::Enum::BC7)
			.value("ETC1", bgfx::TextureFormat::Enum::ETC1)
			.value("ETC2", bgfx::TextureFormat::Enum::ETC2)
			.value("ETC2A", bgfx::TextureFormat::Enum::ETC2A)
			.value("ETC2A1", bgfx::TextureFormat::Enum::ETC2A1)
			.value("PTC12", bgfx::TextureFormat::Enum::PTC12)
			.value("PTC14", bgfx::TextureFormat::Enum::PTC14)
			.value("PTC12A", bgfx::TextureFormat::Enum::PTC12A)
			.value("PTC14A", bgfx::TextureFormat::Enum::PTC14A)
			.value("PTC22", bgfx::TextureFormat::Enum::PTC22)
			.value("PTC24", bgfx::TextureFormat::Enum::PTC24)
			.value("ATC", bgfx::TextureFormat::Enum::ATC)
			.value("ATCE", bgfx::TextureFormat::Enum::ATCE)
			.value("ATCI", bgfx::TextureFormat::Enum::ATCI)
			.value("ASTC4X4", bgfx::TextureFormat::Enum::ASTC4x4)
			.value("ASTC5X5", bgfx::TextureFormat::Enum::ASTC5x5)
			.value("ASTC6X6", bgfx::TextureFormat::Enum::ASTC6x6)
			.value("ASTC8X5", bgfx::TextureFormat::Enum::ASTC8x5)
			.value("ASTC8X6", bgfx::TextureFormat::Enum::ASTC8x6)
			.value("ASTC10X5", bgfx::TextureFormat::Enum::ASTC10x5)
			.value("UNKNOWN", bgfx::TextureFormat::Enum::Unknown)
			.value("R1", bgfx::TextureFormat::Enum::R1)
			.value("A8", bgfx::TextureFormat::Enum::A8)
			.value("R8", bgfx::TextureFormat::Enum::R8)
			.value("R8I", bgfx::TextureFormat::Enum::R8I)
			.value("R8U", bgfx::TextureFormat::Enum::R8U)
			.value("R8S", bgfx::TextureFormat::Enum::R8S)
			.value("R16", bgfx::TextureFormat::Enum::R16)
			.value("R16I", bgfx::TextureFormat::Enum::R16I)
			.value("R16U", bgfx::TextureFormat::Enum::R16U)
			.value("R16F", bgfx::TextureFormat::Enum::R16F)
			.value("R16S", bgfx::TextureFormat::Enum::R16S)
			.value("R32I", bgfx::TextureFormat::Enum::R32I)
			.value("R32U", bgfx::TextureFormat::Enum::R32U)
			.value("R32F", bgfx::TextureFormat::Enum::R32F)
			.value("RG8", bgfx::TextureFormat::Enum::RG8)
			.value("RG8I", bgfx::TextureFormat::Enum::RG8I)
			.value("RG8U", bgfx::TextureFormat::Enum::RG8U)
			.value("RG8S", bgfx::TextureFormat::Enum::RG8S)
			.value("RG16", bgfx::TextureFormat::Enum::RG16)
			.value("RG16I", bgfx::TextureFormat::Enum::RG16I)
			.value("RG16U", bgfx::TextureFormat::Enum::RG16U)
			.value("RG16F", bgfx::TextureFormat::Enum::RG16F)
			.value("RG16S", bgfx::TextureFormat::Enum::RG16S)
			.value("RG32I", bgfx::TextureFormat::Enum::RG32I)
			.value("RG32U", bgfx::TextureFormat::Enum::RG32U)
			.value("RG32F", bgfx::TextureFormat::Enum::RG32F)
			.value("RGB8", bgfx::TextureFormat::Enum::RGB8)
			.value("RGB8I", bgfx::TextureFormat::Enum::RGB8I)
			.value("RGB8U", bgfx::TextureFormat::Enum::RGB8U)
			.value("RGB8S", bgfx::TextureFormat::Enum::RGB8S)
			.value("RGB9E5F", bgfx::TextureFormat::Enum::RGB9E5F)
			.value("BGRA8", bgfx::TextureFormat::Enum::BGRA8)
			.value("RGBA8", bgfx::TextureFormat::Enum::RGBA8)
			.value("RGBA8I", bgfx::TextureFormat::Enum::RGBA8I)
			.value("RGBA8U", bgfx::TextureFormat::Enum::RGBA8U)
			.value("RGBA8S", bgfx::TextureFormat::Enum::RGBA8S)
			.value("RGBA16", bgfx::TextureFormat::Enum::RGBA16)
			.value("RGBA16I", bgfx::TextureFormat::Enum::RGBA16I)
			.value("RGBA16U", bgfx::TextureFormat::Enum::RGBA16U)
			.value("RGBA16F", bgfx::TextureFormat::Enum::RGBA16F)
			.value("RGBA16S", bgfx::TextureFormat::Enum::RGBA16S)
			.value("RGBA32I", bgfx::TextureFormat::Enum::RGBA32I)
			.value("RGBA32U", bgfx::TextureFormat::Enum::RGBA32U)
			.value("RGBA32F", bgfx::TextureFormat::Enum::RGBA32F)
			.value("R5G6B5", bgfx::TextureFormat::Enum::R5G6B5)
			.value("RGBA4", bgfx::TextureFormat::Enum::RGBA4)
			.value("RGB5A1", bgfx::TextureFormat::Enum::RGB5A1)
			.value("RGB10A2", bgfx::TextureFormat::Enum::RGB10A2)
			.value("RG11B10F", bgfx::TextureFormat::Enum::RG11B10F)
			.value("UNKNOWN_DEPTH", bgfx::TextureFormat::Enum::UnknownDepth)
			.value("D16", bgfx::TextureFormat::Enum::D16)
			.value("D24", bgfx::TextureFormat::Enum::D24)
			.value("D24S8", bgfx::TextureFormat::Enum::D24S8)
			.value("D32", bgfx::TextureFormat::Enum::D32)
			.value("D16F", bgfx::TextureFormat::Enum::D16F)
			.value("D24F", bgfx::TextureFormat::Enum::D24F)
			.value("D32F", bgfx::TextureFormat::Enum::D32F)
			.value("D0S8", bgfx::TextureFormat::Enum::D0S8)
			.value("COUNT", bgfx::TextureFormat::Enum::Count)
			.export_values();

	}
	{ // bgfx::UniformType file:bgfx.h line:258
		pybind11::class_<bgfx::UniformType, std::shared_ptr<bgfx::UniformType>> cl(M("bgfx"), "UniformType", "Uniform type enum.\n\n \n C99 equivalent is `bgfx_uniform_type_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::UniformType(); } ) );

		pybind11::enum_<bgfx::UniformType::Enum>(cl, "Enum", pybind11::arithmetic(), "Uniform types:")
			.value("SAMPLER", bgfx::UniformType::Enum::Sampler)
			.value("END", bgfx::UniformType::Enum::End)
			.value("VEC4", bgfx::UniformType::Enum::Vec4)
			.value("MAT3", bgfx::UniformType::Enum::Mat3)
			.value("MAT4", bgfx::UniformType::Enum::Mat4)
			.value("COUNT", bgfx::UniformType::Enum::Count)
			.export_values();

	}
	{ // bgfx::BackbufferRatio file:bgfx.h line:278
		pybind11::class_<bgfx::BackbufferRatio, std::shared_ptr<bgfx::BackbufferRatio>> cl(M("bgfx"), "BackbufferRatio", "Backbuffer ratio enum.\n\n \n C99 equivalent is `bgfx_backbuffer_ratio_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::BackbufferRatio(); } ) );

		pybind11::enum_<bgfx::BackbufferRatio::Enum>(cl, "Enum", pybind11::arithmetic(), "Backbuffer ratios:")
			.value("EQUAL", bgfx::BackbufferRatio::Enum::Equal)
			.value("HALF", bgfx::BackbufferRatio::Enum::Half)
			.value("QUARTER", bgfx::BackbufferRatio::Enum::Quarter)
			.value("EIGHTH", bgfx::BackbufferRatio::Enum::Eighth)
			.value("SIXTEENTH", bgfx::BackbufferRatio::Enum::Sixteenth)
			.value("DOUBLE", bgfx::BackbufferRatio::Enum::Double)
			.value("COUNT", bgfx::BackbufferRatio::Enum::Count)
			.export_values();

	}
	{ // bgfx::OcclusionQueryResult file:bgfx.h line:298
		pybind11::class_<bgfx::OcclusionQueryResult, std::shared_ptr<bgfx::OcclusionQueryResult>> cl(M("bgfx"), "OcclusionQueryResult", "Occlusion query result.\n\n \n C99 equivalent is `bgfx_occlusion_query_result_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::OcclusionQueryResult(); } ) );

		pybind11::enum_<bgfx::OcclusionQueryResult::Enum>(cl, "Enum", pybind11::arithmetic(), "Occlusion query results:")
			.value("INVISIBLE", bgfx::OcclusionQueryResult::Enum::Invisible)
			.value("VISIBLE", bgfx::OcclusionQueryResult::Enum::Visible)
			.value("NORESULT", bgfx::OcclusionQueryResult::Enum::NoResult)
			.value("COUNT", bgfx::OcclusionQueryResult::Enum::Count)
			.export_values();

	}
	{ // bgfx::Topology file:bgfx.h line:315
		pybind11::class_<bgfx::Topology, std::shared_ptr<bgfx::Topology>> cl(M("bgfx"), "Topology", "Primitive topology.\n\n \n C99 equivalent is `bgfx_topology_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::Topology(); } ) );

		pybind11::enum_<bgfx::Topology::Enum>(cl, "Enum", pybind11::arithmetic(), "Primitive topology:")
			.value("TRILIST", bgfx::Topology::Enum::TriList)
			.value("TRISTRIP", bgfx::Topology::Enum::TriStrip)
			.value("LINELIST", bgfx::Topology::Enum::LineList)
			.value("LINESTRIP", bgfx::Topology::Enum::LineStrip)
			.value("POINTLIST", bgfx::Topology::Enum::PointList)
			.value("COUNT", bgfx::Topology::Enum::Count)
			.export_values();

	}
	{ // bgfx::TopologyConvert file:bgfx.h line:334
		pybind11::class_<bgfx::TopologyConvert, std::shared_ptr<bgfx::TopologyConvert>> cl(M("bgfx"), "TopologyConvert", "Topology conversion function.\n\n \n C99 equivalent is `bgfx_topology_convert_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::TopologyConvert(); } ) );

		pybind11::enum_<bgfx::TopologyConvert::Enum>(cl, "Enum", pybind11::arithmetic(), "Topology conversion functions:")
			.value("TRI_LIST_FLIP_WINDING", bgfx::TopologyConvert::Enum::TriListFlipWinding)
			.value("TRI_STRIP_FLIP_WINDING", bgfx::TopologyConvert::Enum::TriStripFlipWinding)
			.value("TRI_LIST_TO_LINE_LIST", bgfx::TopologyConvert::Enum::TriListToLineList)
			.value("TRI_STRIP_TO_TRI_LIST", bgfx::TopologyConvert::Enum::TriStripToTriList)
			.value("LINE_STRIP_TO_LINE_LIST", bgfx::TopologyConvert::Enum::LineStripToLineList)
			.value("COUNT", bgfx::TopologyConvert::Enum::Count)
			.export_values();

	}
	{ // bgfx::TopologySort file:bgfx.h line:353
		pybind11::class_<bgfx::TopologySort, std::shared_ptr<bgfx::TopologySort>> cl(M("bgfx"), "TopologySort", "Topology sort order.\n\n \n C99 equivalent is `bgfx_topology_sort_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::TopologySort(); } ) );

		pybind11::enum_<bgfx::TopologySort::Enum>(cl, "Enum", pybind11::arithmetic(), "Topology sort order:")
			.value("DIRECTION_FRONT_TO_BACK_MIN", bgfx::TopologySort::Enum::DirectionFrontToBackMin)
			.value("DIRECTION_FRONT_TO_BACK_AVG", bgfx::TopologySort::Enum::DirectionFrontToBackAvg)
			.value("DIRECTION_FRONT_TO_BACK_MAX", bgfx::TopologySort::Enum::DirectionFrontToBackMax)
			.value("DIRECTION_BACK_TO_FRONT_MIN", bgfx::TopologySort::Enum::DirectionBackToFrontMin)
			.value("DIRECTION_BACK_TO_FRONT_AVG", bgfx::TopologySort::Enum::DirectionBackToFrontAvg)
			.value("DIRECTION_BACK_TO_FRONT_MAX", bgfx::TopologySort::Enum::DirectionBackToFrontMax)
			.value("DISTANCE_FRONT_TO_BACK_MIN", bgfx::TopologySort::Enum::DistanceFrontToBackMin)
			.value("DISTANCE_FRONT_TO_BACK_AVG", bgfx::TopologySort::Enum::DistanceFrontToBackAvg)
			.value("DISTANCE_FRONT_TO_BACK_MAX", bgfx::TopologySort::Enum::DistanceFrontToBackMax)
			.value("DISTANCE_BACK_TO_FRONT_MIN", bgfx::TopologySort::Enum::DistanceBackToFrontMin)
			.value("DISTANCE_BACK_TO_FRONT_AVG", bgfx::TopologySort::Enum::DistanceBackToFrontAvg)
			.value("DISTANCE_BACK_TO_FRONT_MAX", bgfx::TopologySort::Enum::DistanceBackToFrontMax)
			.value("COUNT", bgfx::TopologySort::Enum::Count)
			.export_values();

	}
	{ // bgfx::ViewMode file:bgfx.h line:379
		pybind11::class_<bgfx::ViewMode, std::shared_ptr<bgfx::ViewMode>> cl(M("bgfx"), "ViewMode", "View mode sets draw call sort order.\n\n \n C99 equivalent is `bgfx_view_mode_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::ViewMode(); } ) );

		pybind11::enum_<bgfx::ViewMode::Enum>(cl, "Enum", pybind11::arithmetic(), "View modes:")
			.value("DEFAULT", bgfx::ViewMode::Enum::Default)
			.value("SEQUENTIAL", bgfx::ViewMode::Enum::Sequential)
			.value("DEPTH_ASCENDING", bgfx::ViewMode::Enum::DepthAscending)
			.value("DEPTH_DESCENDING", bgfx::ViewMode::Enum::DepthDescending)
			.value("COUNT", bgfx::ViewMode::Enum::Count)
			.export_values();

	}
	{ // bgfx::DynamicIndexBufferHandle file: line:395
		pybind11::class_<bgfx::DynamicIndexBufferHandle, std::shared_ptr<bgfx::DynamicIndexBufferHandle>> cl(M("bgfx"), "DynamicIndexBufferHandle", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::DynamicIndexBufferHandle(); } ) );
		cl.def_readwrite("idx", &bgfx::DynamicIndexBufferHandle::idx);
	}
}


// File: unknown/unknown.cpp
#include <bgfx.h>
#include <sstream> // __str__

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_unknown_unknown(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// bgfx::isValid(struct bgfx::DynamicIndexBufferHandle) file: line:18
	M("bgfx").def("is_valid", (bool (*)(struct bgfx::DynamicIndexBufferHandle)) &bgfx::isValid, "C++: bgfx::isValid(struct bgfx::DynamicIndexBufferHandle) --> bool", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	{ // bgfx::DynamicVertexBufferHandle file: line:396
		pybind11::class_<bgfx::DynamicVertexBufferHandle, std::shared_ptr<bgfx::DynamicVertexBufferHandle>> cl(M("bgfx"), "DynamicVertexBufferHandle", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::DynamicVertexBufferHandle(); } ) );
		cl.def_readwrite("idx", &bgfx::DynamicVertexBufferHandle::idx);
	}
	// bgfx::isValid(struct bgfx::DynamicVertexBufferHandle) file: line:18
	M("bgfx").def("is_valid", (bool (*)(struct bgfx::DynamicVertexBufferHandle)) &bgfx::isValid, "C++: bgfx::isValid(struct bgfx::DynamicVertexBufferHandle) --> bool", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	{ // bgfx::FrameBufferHandle file: line:397
		pybind11::class_<bgfx::FrameBufferHandle, std::shared_ptr<bgfx::FrameBufferHandle>> cl(M("bgfx"), "FrameBufferHandle", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::FrameBufferHandle(); } ) );
		cl.def_readwrite("idx", &bgfx::FrameBufferHandle::idx);
	}
	// bgfx::isValid(struct bgfx::FrameBufferHandle) file: line:18
	M("bgfx").def("is_valid", (bool (*)(struct bgfx::FrameBufferHandle)) &bgfx::isValid, "C++: bgfx::isValid(struct bgfx::FrameBufferHandle) --> bool", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	{ // bgfx::IndexBufferHandle file: line:398
		pybind11::class_<bgfx::IndexBufferHandle, std::shared_ptr<bgfx::IndexBufferHandle>> cl(M("bgfx"), "IndexBufferHandle", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::IndexBufferHandle(); } ) );
		cl.def_readwrite("idx", &bgfx::IndexBufferHandle::idx);
	}
	// bgfx::isValid(struct bgfx::IndexBufferHandle) file: line:18
	M("bgfx").def("is_valid", (bool (*)(struct bgfx::IndexBufferHandle)) &bgfx::isValid, "C++: bgfx::isValid(struct bgfx::IndexBufferHandle) --> bool", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	{ // bgfx::IndirectBufferHandle file: line:399
		pybind11::class_<bgfx::IndirectBufferHandle, std::shared_ptr<bgfx::IndirectBufferHandle>> cl(M("bgfx"), "IndirectBufferHandle", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::IndirectBufferHandle(); } ) );
		cl.def_readwrite("idx", &bgfx::IndirectBufferHandle::idx);
	}
	// bgfx::isValid(struct bgfx::IndirectBufferHandle) file: line:18
	M("bgfx").def("is_valid", (bool (*)(struct bgfx::IndirectBufferHandle)) &bgfx::isValid, "C++: bgfx::isValid(struct bgfx::IndirectBufferHandle) --> bool", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	{ // bgfx::OcclusionQueryHandle file: line:400
		pybind11::class_<bgfx::OcclusionQueryHandle, std::shared_ptr<bgfx::OcclusionQueryHandle>> cl(M("bgfx"), "OcclusionQueryHandle", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::OcclusionQueryHandle(); } ) );
		cl.def_readwrite("idx", &bgfx::OcclusionQueryHandle::idx);
	}
	// bgfx::isValid(struct bgfx::OcclusionQueryHandle) file: line:18
	M("bgfx").def("is_valid", (bool (*)(struct bgfx::OcclusionQueryHandle)) &bgfx::isValid, "C++: bgfx::isValid(struct bgfx::OcclusionQueryHandle) --> bool", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	{ // bgfx::ProgramHandle file: line:401
		pybind11::class_<bgfx::ProgramHandle, std::shared_ptr<bgfx::ProgramHandle>> cl(M("bgfx"), "ProgramHandle", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::ProgramHandle(); } ) );
		cl.def_readwrite("idx", &bgfx::ProgramHandle::idx);
	}
	// bgfx::isValid(struct bgfx::ProgramHandle) file: line:18
	M("bgfx").def("is_valid", (bool (*)(struct bgfx::ProgramHandle)) &bgfx::isValid, "C++: bgfx::isValid(struct bgfx::ProgramHandle) --> bool", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	{ // bgfx::ShaderHandle file: line:402
		pybind11::class_<bgfx::ShaderHandle, std::shared_ptr<bgfx::ShaderHandle>> cl(M("bgfx"), "ShaderHandle", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::ShaderHandle(); } ) );
		cl.def_readwrite("idx", &bgfx::ShaderHandle::idx);
	}
	// bgfx::isValid(struct bgfx::ShaderHandle) file: line:18
	M("bgfx").def("is_valid", (bool (*)(struct bgfx::ShaderHandle)) &bgfx::isValid, "C++: bgfx::isValid(struct bgfx::ShaderHandle) --> bool", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	{ // bgfx::TextureHandle file: line:403
		pybind11::class_<bgfx::TextureHandle, std::shared_ptr<bgfx::TextureHandle>> cl(M("bgfx"), "TextureHandle", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::TextureHandle(); } ) );
		cl.def_readwrite("idx", &bgfx::TextureHandle::idx);
	}
	// bgfx::isValid(struct bgfx::TextureHandle) file: line:18
	M("bgfx").def("is_valid", (bool (*)(struct bgfx::TextureHandle)) &bgfx::isValid, "C++: bgfx::isValid(struct bgfx::TextureHandle) --> bool", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	{ // bgfx::UniformHandle file: line:404
		pybind11::class_<bgfx::UniformHandle, std::shared_ptr<bgfx::UniformHandle>> cl(M("bgfx"), "UniformHandle", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::UniformHandle(); } ) );
		cl.def_readwrite("idx", &bgfx::UniformHandle::idx);
	}
	// bgfx::isValid(struct bgfx::UniformHandle) file: line:18
	M("bgfx").def("is_valid", (bool (*)(struct bgfx::UniformHandle)) &bgfx::isValid, "C++: bgfx::isValid(struct bgfx::UniformHandle) --> bool", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	{ // bgfx::VertexBufferHandle file: line:405
		pybind11::class_<bgfx::VertexBufferHandle, std::shared_ptr<bgfx::VertexBufferHandle>> cl(M("bgfx"), "VertexBufferHandle", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::VertexBufferHandle(); } ) );
		cl.def_readwrite("idx", &bgfx::VertexBufferHandle::idx);
	}
	// bgfx::isValid(struct bgfx::VertexBufferHandle) file: line:18
	M("bgfx").def("is_valid", (bool (*)(struct bgfx::VertexBufferHandle)) &bgfx::isValid, "C++: bgfx::isValid(struct bgfx::VertexBufferHandle) --> bool", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	{ // bgfx::VertexLayoutHandle file: line:406
		pybind11::class_<bgfx::VertexLayoutHandle, std::shared_ptr<bgfx::VertexLayoutHandle>> cl(M("bgfx"), "VertexLayoutHandle", "");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::VertexLayoutHandle(); } ) );
		cl.def_readwrite("idx", &bgfx::VertexLayoutHandle::idx);
	}
	// bgfx::isValid(struct bgfx::VertexLayoutHandle) file: line:18
	M("bgfx").def("is_valid", (bool (*)(struct bgfx::VertexLayoutHandle)) &bgfx::isValid, "C++: bgfx::isValid(struct bgfx::VertexLayoutHandle) --> bool", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	{ // bgfx::CallbackI file:bgfx.h line:418
		pybind11::class_<bgfx::CallbackI, std::shared_ptr<bgfx::CallbackI>> cl(M("bgfx"), "CallbackI", "Callback interface to implement application specific behavior.\n Cached items are currently used for OpenGL and Direct3D 12 binary\n shaders.\n\n \n\n   'fatal' and 'trace' callbacks can be called from any thread. Other\n   callbacks are called from the render thread.\n\n \n C99 equivalent is `bgfx_callback_interface_t`.");
		pybind11::handle cl_type = cl;

		cl.def("fatal", (void (bgfx::CallbackI::*)(const char *, unsigned short, enum bgfx::Fatal::Enum, const char *)) &bgfx::CallbackI::fatal, "This callback is called on unrecoverable errors.\n It's not safe to continue (Exluding _code `Fatal::DebugCheck`),\n inform the user and terminate the application.\n\n \n File path where fatal message was generated.\n \n\n Line where fatal message was generated.\n \n\n Fatal error code.\n \n\n More information about error.\n\n \n\n   Not thread safe and it can be called from any thread.\n\n \n C99 equivalent is `bgfx_callback_vtbl.fatal`.\n\nC++: bgfx::CallbackI::fatal(const char *, unsigned short, enum bgfx::Fatal::Enum, const char *) --> void", pybind11::arg("_filePath"), pybind11::arg("_line"), pybind11::arg("_code"), pybind11::arg("_str"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("profiler begin", (void (bgfx::CallbackI::*)(const char *, unsigned int, const char *, unsigned short)) &bgfx::CallbackI::profilerBegin, "Profiler region begin.\n\n \n Region name, contains dynamic string.\n \n\n Color of profiler region.\n \n\n File path where `profilerBegin` was called.\n \n\n Line where `profilerBegin` was called.\n\n \n\n   Not thread safe and it can be called from any thread.\n\n \n C99 equivalent is `bgfx_callback_vtbl.profiler_begin`.\n\nC++: bgfx::CallbackI::profilerBegin(const char *, unsigned int, const char *, unsigned short) --> void", pybind11::arg("_name"), pybind11::arg("_abgr"), pybind11::arg("_filePath"), pybind11::arg("_line"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("profiler begin literal", (void (bgfx::CallbackI::*)(const char *, unsigned int, const char *, unsigned short)) &bgfx::CallbackI::profilerBeginLiteral, "Profiler region begin with string literal name.\n\n \n Region name, contains string literal.\n \n\n Color of profiler region.\n \n\n File path where `profilerBeginLiteral` was called.\n \n\n Line where `profilerBeginLiteral` was called.\n\n \n\n   Not thread safe and it can be called from any thread.\n\n \n C99 equivalent is `bgfx_callback_vtbl.profiler_begin_literal`.\n\nC++: bgfx::CallbackI::profilerBeginLiteral(const char *, unsigned int, const char *, unsigned short) --> void", pybind11::arg("_name"), pybind11::arg("_abgr"), pybind11::arg("_filePath"), pybind11::arg("_line"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("profiler end", (void (bgfx::CallbackI::*)()) &bgfx::CallbackI::profilerEnd, "Profiler region end.\n\n \n\n   Not thread safe and it can be called from any thread.\n\n \n C99 equivalent is `bgfx_callback_vtbl.profiler_end`.\n\nC++: bgfx::CallbackI::profilerEnd() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("cache read size", (unsigned int (bgfx::CallbackI::*)(uint64_t)) &bgfx::CallbackI::cacheReadSize, "Returns the size of a cached item. Returns 0 if no cached item was\n found.\n\n \n Cache id.\n \n\n Number of bytes to read.\n\n \n C99 equivalent is `bgfx_callback_vtbl.cache_read_size`.\n\nC++: bgfx::CallbackI::cacheReadSize(uint64_t) --> unsigned int", pybind11::arg("_id"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("cache read", (bool (bgfx::CallbackI::*)(uint64_t, void *, unsigned int)) &bgfx::CallbackI::cacheRead, "Read cached item.\n\n \n Cache id.\n \n\n Buffer where to read data.\n \n\n Size of data to read.\n\n \n True if data is read.\n\n \n C99 equivalent is `bgfx_callback_vtbl.cache_read`.\n\nC++: bgfx::CallbackI::cacheRead(uint64_t, void *, unsigned int) --> bool", pybind11::arg("_id"), pybind11::arg("_data"), pybind11::arg("_size"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("cache write", (void (bgfx::CallbackI::*)(uint64_t, const void *, unsigned int)) &bgfx::CallbackI::cacheWrite, "Write cached item.\n\n \n Cache id.\n \n\n Data to write.\n \n\n Size of data to write.\n\n \n C99 equivalent is `bgfx_callback_vtbl.cache_write`.\n\nC++: bgfx::CallbackI::cacheWrite(uint64_t, const void *, unsigned int) --> void", pybind11::arg("_id"), pybind11::arg("_data"), pybind11::arg("_size"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("screen shot", (void (bgfx::CallbackI::*)(const char *, unsigned int, unsigned int, unsigned int, const void *, unsigned int, bool)) &bgfx::CallbackI::screenShot, "Screenshot captured. Screenshot format is always 4-byte BGRA.\n\n \n File path.\n \n\n Image width.\n \n\n Image height.\n \n\n Number of bytes to skip between the start of\n   each horizontal line of the image.\n \n\n Image data.\n \n\n Image size.\n \n\n If true, image origin is bottom left.\n\n \n C99 equivalent is `bgfx_callback_vtbl.screen_shot`.\n\nC++: bgfx::CallbackI::screenShot(const char *, unsigned int, unsigned int, unsigned int, const void *, unsigned int, bool) --> void", pybind11::arg("_filePath"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_pitch"), pybind11::arg("_data"), pybind11::arg("_size"), pybind11::arg("_yflip"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("capture begin", (void (bgfx::CallbackI::*)(unsigned int, unsigned int, unsigned int, enum bgfx::TextureFormat::Enum, bool)) &bgfx::CallbackI::captureBegin, "Called when a video capture begins.\n\n \n Image width.\n \n\n Image height.\n \n\n Number of bytes to skip between the start of\n   each horizontal line of the image.\n \n\n Texture format. See: `TextureFormat::Enum`.\n \n\n If true, image origin is bottom left.\n\n \n C99 equivalent is `bgfx_callback_vtbl.capture_begin`.\n\nC++: bgfx::CallbackI::captureBegin(unsigned int, unsigned int, unsigned int, enum bgfx::TextureFormat::Enum, bool) --> void", pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_pitch"), pybind11::arg("_format"), pybind11::arg("_yflip"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("capture end", (void (bgfx::CallbackI::*)()) &bgfx::CallbackI::captureEnd, "Called when a video capture ends.\n\n \n C99 equivalent is `bgfx_callback_vtbl.capture_end`.\n\nC++: bgfx::CallbackI::captureEnd() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("capture frame", (void (bgfx::CallbackI::*)(const void *, unsigned int)) &bgfx::CallbackI::captureFrame, "Captured frame.\n\n \n Image data.\n \n\n Image size.\n\n \n C99 equivalent is `bgfx_callback_vtbl.capture_frame`.\n\nC++: bgfx::CallbackI::captureFrame(const void *, unsigned int) --> void", pybind11::arg("_data"), pybind11::arg("_size"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("assign", (struct bgfx::CallbackI & (bgfx::CallbackI::*)(const struct bgfx::CallbackI &)) &bgfx::CallbackI::operator=, "C++: bgfx::CallbackI::operator=(const struct bgfx::CallbackI &) --> struct bgfx::CallbackI &", pybind11::return_value_policy::reference_internal, pybind11::arg(""), pybind11::call_guard<pybind11::gil_scoped_release>());
	}
	{ // bgfx::PlatformData file:bgfx.h line:608
		pybind11::class_<bgfx::PlatformData, std::shared_ptr<bgfx::PlatformData>> cl(M("bgfx"), "PlatformData", "Platform data.\n\n \n C99 equivalent is `bgfx_platform_data_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::PlatformData(); } ) );
		cl.def( pybind11::init( [](bgfx::PlatformData const &o){ return new bgfx::PlatformData(o); } ) );
        cl.def_readwrite("ndt", &bgfx::PlatformData::ndt);
		cl.def_readwrite("nwh", &bgfx::PlatformData::nwh);
		cl.def_readwrite("context", &bgfx::PlatformData::context);
		cl.def_readwrite("back_buffer", &bgfx::PlatformData::backBuffer);
		cl.def_readwrite("back_buffer_ds", &bgfx::PlatformData::backBufferDS);
	}
	{ // bgfx::Resolution file:bgfx.h line:623
		pybind11::class_<bgfx::Resolution, std::shared_ptr<bgfx::Resolution>> cl(M("bgfx"), "Resolution", "Backbuffer resolution and reset parameters.\n\n \n C99 equivalent is `bgfx_resolution_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::Resolution(); } ) );
		cl.def( pybind11::init( [](bgfx::Resolution const &o){ return new bgfx::Resolution(o); } ) );
		cl.def_readwrite("format", &bgfx::Resolution::format);
		cl.def_readwrite("width", &bgfx::Resolution::width);
		cl.def_readwrite("height", &bgfx::Resolution::height);
		cl.def_readwrite("reset", &bgfx::Resolution::reset);
		cl.def_readwrite("num_back_buffers", &bgfx::Resolution::numBackBuffers);
		cl.def_readwrite("max_frame_latency", &bgfx::Resolution::maxFrameLatency);
	}
	{ // bgfx::Init file:bgfx.h line:639
		pybind11::class_<bgfx::Init, std::shared_ptr<bgfx::Init>> cl(M("bgfx"), "Init", "Initialization parameters used by `bgfx::init`.\n\n \n C99 equivalent is `bgfx_init_t`.");
		pybind11::handle cl_type = cl;

		{ // bgfx::Init::Limits file:bgfx.h line:670
			auto & enclosing_class = cl;
			pybind11::class_<bgfx::Init::Limits, std::shared_ptr<bgfx::Init::Limits>> cl(enclosing_class, "Limits", "");
			pybind11::handle cl_type = cl;

			cl.def( pybind11::init( [](){ return new bgfx::Init::Limits(); } ) );
			cl.def( pybind11::init( [](bgfx::Init::Limits const &o){ return new bgfx::Init::Limits(o); } ) );
			cl.def_readwrite("max_encoders", &bgfx::Init::Limits::maxEncoders);
			cl.def_readwrite("transient_vb_size", &bgfx::Init::Limits::transientVbSize);
			cl.def_readwrite("transient_ib_size", &bgfx::Init::Limits::transientIbSize);
		}

		cl.def( pybind11::init( [](){ return new bgfx::Init(); } ) );
		cl.def( pybind11::init( [](bgfx::Init const &o){ return new bgfx::Init(o); } ) );
		cl.def_readwrite("type", &bgfx::Init::type);
		cl.def_readwrite("vendor_id", &bgfx::Init::vendorId);
		cl.def_readwrite("device_id", &bgfx::Init::deviceId);
		cl.def_readwrite("debug", &bgfx::Init::debug);
		cl.def_readwrite("profile", &bgfx::Init::profile);
		cl.def_readwrite("platform_data", &bgfx::Init::platformData);
		cl.def_readwrite("resolution", &bgfx::Init::resolution);
		cl.def_readwrite("limits", &bgfx::Init::limits);
	}
}


// File: bgfx_1.cpp
#include <bgfx.h>
#include <sstream> // __str__

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_bgfx_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // bgfx::Memory file:bgfx.h line:704
		pybind11::class_<bgfx::Memory, std::shared_ptr<bgfx::Memory>> cl(M("bgfx"), "Memory", "Memory must be obtained by calling `bgfx::alloc`, `bgfx::copy`, or `bgfx::makeRef`.\n\n \n It is illegal to create this structure on stack and pass it to any bgfx API.\n\n \n C99 equivalent is `bgfx_memory_t`.");
		pybind11::handle cl_type = cl;

//		cl.def( pybind11::init( [](){ return new bgfx::Memory(); } ) );
		cl.def_readwrite("size", &bgfx::Memory::size);
	}
	{ // bgfx::Caps file:bgfx.h line:714
		pybind11::class_<bgfx::Caps, std::shared_ptr<bgfx::Caps>> cl(M("bgfx"), "Caps", "Renderer capabilities.\n\n \n C99 equivalent is `bgfx_caps_t`.");
		pybind11::handle cl_type = cl;

		{ // bgfx::Caps::GPU file:bgfx.h line:735
			auto & enclosing_class = cl;
			pybind11::class_<bgfx::Caps::GPU, std::shared_ptr<bgfx::Caps::GPU>> cl(enclosing_class, "GPU", "GPU info.\n\n \n C99 equivalent is `bgfx_caps_gpu_t`.");
			pybind11::handle cl_type = cl;

			cl.def( pybind11::init( [](){ return new bgfx::Caps::GPU(); } ) );
			cl.def_readwrite("vendor_id", &bgfx::Caps::GPU::vendorId);
			cl.def_readwrite("device_id", &bgfx::Caps::GPU::deviceId);
		}

		{ // bgfx::Caps::Limits file:bgfx.h line:743
			auto & enclosing_class = cl;
			pybind11::class_<bgfx::Caps::Limits, std::shared_ptr<bgfx::Caps::Limits>> cl(enclosing_class, "Limits", "");
			pybind11::handle cl_type = cl;

			cl.def( pybind11::init( [](){ return new bgfx::Caps::Limits(); } ) );
			cl.def_readwrite("max_draw_calls", &bgfx::Caps::Limits::maxDrawCalls);
			cl.def_readwrite("max_blits", &bgfx::Caps::Limits::maxBlits);
			cl.def_readwrite("max_texture_size", &bgfx::Caps::Limits::maxTextureSize);
			cl.def_readwrite("max_texture_layers", &bgfx::Caps::Limits::maxTextureLayers);
			cl.def_readwrite("max_views", &bgfx::Caps::Limits::maxViews);
			cl.def_readwrite("max_frame_buffers", &bgfx::Caps::Limits::maxFrameBuffers);
			cl.def_readwrite("max_f_b_attachments", &bgfx::Caps::Limits::maxFBAttachments);
			cl.def_readwrite("max_programs", &bgfx::Caps::Limits::maxPrograms);
			cl.def_readwrite("max_shaders", &bgfx::Caps::Limits::maxShaders);
			cl.def_readwrite("max_textures", &bgfx::Caps::Limits::maxTextures);
			cl.def_readwrite("max_texture_samplers", &bgfx::Caps::Limits::maxTextureSamplers);
			cl.def_readwrite("max_compute_bindings", &bgfx::Caps::Limits::maxComputeBindings);
			cl.def_readwrite("max_vertex_layouts", &bgfx::Caps::Limits::maxVertexLayouts);
			cl.def_readwrite("max_vertex_streams", &bgfx::Caps::Limits::maxVertexStreams);
			cl.def_readwrite("max_index_buffers", &bgfx::Caps::Limits::maxIndexBuffers);
			cl.def_readwrite("max_vertex_buffers", &bgfx::Caps::Limits::maxVertexBuffers);
			cl.def_readwrite("max_dynamic_index_buffers", &bgfx::Caps::Limits::maxDynamicIndexBuffers);
			cl.def_readwrite("max_dynamic_vertex_buffers", &bgfx::Caps::Limits::maxDynamicVertexBuffers);
			cl.def_readwrite("max_uniforms", &bgfx::Caps::Limits::maxUniforms);
			cl.def_readwrite("max_occlusion_queries", &bgfx::Caps::Limits::maxOcclusionQueries);
			cl.def_readwrite("max_encoders", &bgfx::Caps::Limits::maxEncoders);
			cl.def_readwrite("transient_vb_size", &bgfx::Caps::Limits::transientVbSize);
			cl.def_readwrite("transient_ib_size", &bgfx::Caps::Limits::transientIbSize);
		}

		cl.def( pybind11::init( [](){ return new bgfx::Caps(); } ) );
		cl.def_readwrite("renderer_type", &bgfx::Caps::rendererType);
		cl.def_readwrite("supported", &bgfx::Caps::supported);
		cl.def_readwrite("vendor_id", &bgfx::Caps::vendorId);
		cl.def_readwrite("device_id", &bgfx::Caps::deviceId);
		cl.def_readwrite("homogeneous_depth", &bgfx::Caps::homogeneousDepth);
		cl.def_readwrite("origin_bottom_left", &bgfx::Caps::originBottomLeft);
		cl.def_readwrite("num_gpus", &bgfx::Caps::numGPUs);
		cl.def_readwrite("limits", &bgfx::Caps::limits);
	}
	{ // bgfx::TransientIndexBuffer file:bgfx.h line:800
		pybind11::class_<bgfx::TransientIndexBuffer, std::shared_ptr<bgfx::TransientIndexBuffer>> cl(M("bgfx"), "TransientIndexBuffer", "Transient index buffer.\n\n \n C99 equivalent is `bgfx_transient_index_buffer_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::TransientIndexBuffer(); } ) );
		cl.def_readwrite("size", &bgfx::TransientIndexBuffer::size);
		cl.def_readwrite("start_index", &bgfx::TransientIndexBuffer::startIndex);
		cl.def_readwrite("handle", &bgfx::TransientIndexBuffer::handle);
	}
	{ // bgfx::TransientVertexBuffer file:bgfx.h line:812
		pybind11::class_<bgfx::TransientVertexBuffer, std::shared_ptr<bgfx::TransientVertexBuffer>> cl(M("bgfx"), "TransientVertexBuffer", "Transient vertex buffer.\n\n \n C99 equivalent is `bgfx_transient_vertex_buffer_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::TransientVertexBuffer(); } ) );
		cl.def_readwrite("size", &bgfx::TransientVertexBuffer::size);
		cl.def_readwrite("start_vertex", &bgfx::TransientVertexBuffer::startVertex);
		cl.def_readwrite("stride", &bgfx::TransientVertexBuffer::stride);
		cl.def_readwrite("handle", &bgfx::TransientVertexBuffer::handle);
		cl.def_readwrite("layout_handle", &bgfx::TransientVertexBuffer::layoutHandle);
	}
	{ // bgfx::InstanceDataBuffer file:bgfx.h line:826
		pybind11::class_<bgfx::InstanceDataBuffer, std::shared_ptr<bgfx::InstanceDataBuffer>> cl(M("bgfx"), "InstanceDataBuffer", "Instance data buffer info.\n\n \n C99 equivalent is `bgfx_texture_info_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::InstanceDataBuffer(); } ) );
		cl.def_readwrite("size", &bgfx::InstanceDataBuffer::size);
		cl.def_readwrite("offset", &bgfx::InstanceDataBuffer::offset);
		cl.def_readwrite("num", &bgfx::InstanceDataBuffer::num);
		cl.def_readwrite("stride", &bgfx::InstanceDataBuffer::stride);
		cl.def_readwrite("handle", &bgfx::InstanceDataBuffer::handle);
	}
	{ // bgfx::TextureInfo file:bgfx.h line:840
		pybind11::class_<bgfx::TextureInfo, std::shared_ptr<bgfx::TextureInfo>> cl(M("bgfx"), "TextureInfo", "Texture info.\n\n \n C99 equivalent is `bgfx_texture_info_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::TextureInfo(); } ) );
		cl.def_readwrite("format", &bgfx::TextureInfo::format);
		cl.def_readwrite("storage_size", &bgfx::TextureInfo::storageSize);
		cl.def_readwrite("width", &bgfx::TextureInfo::width);
		cl.def_readwrite("height", &bgfx::TextureInfo::height);
		cl.def_readwrite("depth", &bgfx::TextureInfo::depth);
		cl.def_readwrite("num_layers", &bgfx::TextureInfo::numLayers);
		cl.def_readwrite("num_mips", &bgfx::TextureInfo::numMips);
		cl.def_readwrite("bits_per_pixel", &bgfx::TextureInfo::bitsPerPixel);
		cl.def_readwrite("cube_map", &bgfx::TextureInfo::cubeMap);
	}
	{ // bgfx::UniformInfo file:bgfx.h line:857
		pybind11::class_<bgfx::UniformInfo, std::shared_ptr<bgfx::UniformInfo>> cl(M("bgfx"), "UniformInfo", "Uniform info.\n\n \n C99 equivalent is `bgfx_uniform_info_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::UniformInfo(); } ) );
		cl.def_readwrite("type", &bgfx::UniformInfo::type);
		cl.def_readwrite("num", &bgfx::UniformInfo::num);
	}
	{ // bgfx::Attachment file:bgfx.h line:868
		pybind11::class_<bgfx::Attachment, std::shared_ptr<bgfx::Attachment>> cl(M("bgfx"), "Attachment", "Frame buffer texture attachment info.\n\n \n C99 equivalent is `bgfx_attachment_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::Attachment(); } ) );
		cl.def_readwrite("access", &bgfx::Attachment::access);
		cl.def_readwrite("handle", &bgfx::Attachment::handle);
		cl.def_readwrite("mip", &bgfx::Attachment::mip);
		cl.def_readwrite("layer", &bgfx::Attachment::layer);
		cl.def_readwrite("resolve", &bgfx::Attachment::resolve);
		cl.def("init", [](bgfx::Attachment &o, struct bgfx::TextureHandle const & a0) -> void { return o.init(a0); }, "", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("init", [](bgfx::Attachment &o, struct bgfx::TextureHandle const & a0, enum bgfx::Access::Enum const & a1) -> void { return o.init(a0, a1); }, "", pybind11::arg("_handle"), pybind11::arg("_access"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("init", [](bgfx::Attachment &o, struct bgfx::TextureHandle const & a0, enum bgfx::Access::Enum const & a1, unsigned short const & a2) -> void { return o.init(a0, a1, a2); }, "", pybind11::arg("_handle"), pybind11::arg("_access"), pybind11::arg("_layer"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("init", [](bgfx::Attachment &o, struct bgfx::TextureHandle const & a0, enum bgfx::Access::Enum const & a1, unsigned short const & a2, unsigned short const & a3) -> void { return o.init(a0, a1, a2, a3); }, "", pybind11::arg("_handle"), pybind11::arg("_access"), pybind11::arg("_layer"), pybind11::arg("_mip"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("init", (void (bgfx::Attachment::*)(struct bgfx::TextureHandle, enum bgfx::Access::Enum, unsigned short, unsigned short, unsigned char)) &bgfx::Attachment::init, "Init attachment.\n\n \n Render target texture handle.\n \n\n Access. See `Access::Enum`.\n \n\n Cubemap side or depth layer/slice.\n \n\n Mip level.\n \n\n Resolve flags. See: `BGFX_RESOLVE_*`\n\nC++: bgfx::Attachment::init(struct bgfx::TextureHandle, enum bgfx::Access::Enum, unsigned short, unsigned short, unsigned char) --> void", pybind11::arg("_handle"), pybind11::arg("_access"), pybind11::arg("_layer"), pybind11::arg("_mip"), pybind11::arg("_resolve"), pybind11::call_guard<pybind11::gil_scoped_release>());
	}
	{ // bgfx::Transform file:bgfx.h line:897
		pybind11::class_<bgfx::Transform, std::shared_ptr<bgfx::Transform>> cl(M("bgfx"), "Transform", "Transform data.\n\n \n C99 equivalent is `bgfx_transform_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::Transform(); } ) );
		cl.def_readwrite("num", &bgfx::Transform::num);
	}
		{ // bgfx::ViewStats file:bgfx.h line:910
		pybind11::class_<bgfx::ViewStats, std::shared_ptr<bgfx::ViewStats>> cl(M("bgfx"), "ViewStats", "View stats.\n\n \n C99 equivalent is `bgfx_view_stats_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::ViewStats(); } ) );
		cl.def_readwrite("view", &bgfx::ViewStats::view);
		cl.def_readwrite("cpu_time_begin", &bgfx::ViewStats::cpuTimeBegin);
		cl.def_readwrite("gpu_time_begin", &bgfx::ViewStats::gpuTimeBegin);
		cl.def_readwrite("cpu_time_end", &bgfx::ViewStats::cpuTimeEnd);
		cl.def_readwrite("gpu_time_end", &bgfx::ViewStats::gpuTimeEnd);
	}
	{ // bgfx::EncoderStats file:bgfx.h line:922
		pybind11::class_<bgfx::EncoderStats, std::shared_ptr<bgfx::EncoderStats>> cl(M("bgfx"), "EncoderStats", "Encoder stats.\n\n \n C99 equivalent is `bgfx_encoder_stats_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::EncoderStats(); } ) );
		cl.def_readwrite("cpu_time_begin", &bgfx::EncoderStats::cpuTimeBegin);
		cl.def_readwrite("cpu_time_end", &bgfx::EncoderStats::cpuTimeEnd);
	}
	{ // bgfx::Stats file:bgfx.h line:934
		pybind11::class_<bgfx::Stats, std::shared_ptr<bgfx::Stats>> cl(M("bgfx"), "Stats", "Renderer statistics data.\n\n \n C99 equivalent is `bgfx_stats_t`.\n\n \n All time values are high-resolution timestamps, while\n   time frequencies define timestamps-per-second for that hardware.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::Stats(); } ) );
		cl.def_readwrite("cpu_time_frame", &bgfx::Stats::cpuTimeFrame);
		cl.def_readwrite("cpu_time_begin", &bgfx::Stats::cpuTimeBegin);
		cl.def_readwrite("cpu_time_end", &bgfx::Stats::cpuTimeEnd);
		cl.def_readwrite("cpu_timer_freq", &bgfx::Stats::cpuTimerFreq);
		cl.def_readwrite("gpu_time_begin", &bgfx::Stats::gpuTimeBegin);
		cl.def_readwrite("gpu_time_end", &bgfx::Stats::gpuTimeEnd);
		cl.def_readwrite("gpu_timer_freq", &bgfx::Stats::gpuTimerFreq);
		cl.def_readwrite("wait_render", &bgfx::Stats::waitRender);
		cl.def_readwrite("wait_submit", &bgfx::Stats::waitSubmit);
		cl.def_readwrite("num_draw", &bgfx::Stats::numDraw);
		cl.def_readwrite("num_compute", &bgfx::Stats::numCompute);
		cl.def_readwrite("num_blit", &bgfx::Stats::numBlit);
		cl.def_readwrite("max_gpu_latency", &bgfx::Stats::maxGpuLatency);
		cl.def_readwrite("num_dynamic_index_buffers", &bgfx::Stats::numDynamicIndexBuffers);
		cl.def_readwrite("num_dynamic_vertex_buffers", &bgfx::Stats::numDynamicVertexBuffers);
		cl.def_readwrite("num_frame_buffers", &bgfx::Stats::numFrameBuffers);
		cl.def_readwrite("num_index_buffers", &bgfx::Stats::numIndexBuffers);
		cl.def_readwrite("num_occlusion_queries", &bgfx::Stats::numOcclusionQueries);
		cl.def_readwrite("num_programs", &bgfx::Stats::numPrograms);
		cl.def_readwrite("num_shaders", &bgfx::Stats::numShaders);
		cl.def_readwrite("num_textures", &bgfx::Stats::numTextures);
		cl.def_readwrite("num_uniforms", &bgfx::Stats::numUniforms);
		cl.def_readwrite("num_vertex_buffers", &bgfx::Stats::numVertexBuffers);
		cl.def_readwrite("num_vertex_layouts", &bgfx::Stats::numVertexLayouts);
		cl.def_readwrite("texture_memory_used", &bgfx::Stats::textureMemoryUsed);
		cl.def_readwrite("rt_memory_used", &bgfx::Stats::rtMemoryUsed);
		cl.def_readwrite("transient_vb_used", &bgfx::Stats::transientVbUsed);
		cl.def_readwrite("transient_ib_used", &bgfx::Stats::transientIbUsed);
		cl.def_readwrite("gpu_memory_max", &bgfx::Stats::gpuMemoryMax);
		cl.def_readwrite("gpu_memory_used", &bgfx::Stats::gpuMemoryUsed);
		cl.def_readwrite("width", &bgfx::Stats::width);
		cl.def_readwrite("height", &bgfx::Stats::height);
		cl.def_readwrite("text_width", &bgfx::Stats::textWidth);
		cl.def_readwrite("text_height", &bgfx::Stats::textHeight);
		cl.def_readwrite("num_views", &bgfx::Stats::numViews);
		cl.def_readwrite("view_stats", &bgfx::Stats::viewStats);
		cl.def_readwrite("num_encoders", &bgfx::Stats::numEncoders);
		cl.def_readwrite("encoder_stats", &bgfx::Stats::encoderStats);
	}
	{ // bgfx::Encoder file:bgfx.h line:993
		pybind11::class_<bgfx::Encoder, std::shared_ptr<bgfx::Encoder>> cl(M("bgfx"), "Encoder", "Encoders are used for submitting draw calls from multiple threads. Only one encoder\n per thread should be used. Use `bgfx::begin()` to obtain an encoder for a thread.\n\n \n C99 equivalent is `bgfx_encoder`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::Encoder(); } ) );
		cl.def("set_marker", (void (bgfx::Encoder::*)(const char *)) &bgfx::Encoder::setMarker, "Sets a debug marker. This allows you to group\n graphics calls together for easy browsing in\n graphics debugging tools.\n\n \n C99 equivalent is `bgfx_encoder_set_marker`.\n\nC++: bgfx::Encoder::setMarker(const char *) --> void", pybind11::arg("_marker"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_state", [](bgfx::Encoder &o, uint64_t const & a0) -> void { return o.setState(a0); }, "", pybind11::arg("_state"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_state", (void (bgfx::Encoder::*)(uint64_t, unsigned int)) &bgfx::Encoder::setState, "Set render states for draw primitive.\n\n \n State flags. Default state for primitive type is\n   triangles. See: `BGFX_STATE_DEFAULT`.\n   - `BGFX_STATE_DEPTH_TEST_*` - Depth test function.\n   - `BGFX_STATE_BLEND_*` - See remark 1 about BGFX_STATE_BLEND_FUNC.\n   - `BGFX_STATE_BLEND_EQUATION_*` - See remark 2.\n   - `BGFX_STATE_CULL_*` - Backface culling mode.\n   - `BGFX_STATE_WRITE_*` - Enable R, G, B, A or Z write.\n   - `BGFX_STATE_MSAA` - Enable hardware multisample antialiasing.\n   - `BGFX_STATE_PT_[TRISTRIP/LINES/POINTS]` - Primitive type.\n\n \n Sets blend factor used by `BGFX_STATE_BLEND_FACTOR` and\n   `BGFX_STATE_BLEND_INV_FACTOR` blend modes.\n\n \n\n   1. To setup more complex states use:\n      `BGFX_STATE_ALPHA_REF(_ref)`,\n      `BGFX_STATE_POINT_SIZE(_size)`,\n      `BGFX_STATE_BLEND_FUNC(_src, _dst)`,\n      `BGFX_STATE_BLEND_FUNC_SEPARATE(_srcRGB, _dstRGB, _srcA, _dstA)`,\n      `BGFX_STATE_BLEND_EQUATION(_equation)`,\n      `BGFX_STATE_BLEND_EQUATION_SEPARATE(_equationRGB, _equationA)`\n   2. `BGFX_STATE_BLEND_EQUATION_ADD` is set when no other blend\n      equation is specified.\n\n \n C99 equivalent is `bgfx_encoder_set_state`.\n\nC++: bgfx::Encoder::setState(unsigned long long, unsigned int) --> void", pybind11::arg("_state"), pybind11::arg("_rgba"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_condition", (void (bgfx::Encoder::*)(struct bgfx::OcclusionQueryHandle, bool)) &bgfx::Encoder::setCondition, "Set condition for rendering.\n\n \n Occlusion query handle.\n \n\n Render if occlusion query is visible.\n\n \n C99 equivalent is `bgfx_encoder_set_condition`.\n\nC++: bgfx::Encoder::setCondition(struct bgfx::OcclusionQueryHandle, bool) --> void", pybind11::arg("_handle"), pybind11::arg("_visible"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_stencil", [](bgfx::Encoder &o, unsigned int const & a0) -> void { return o.setStencil(a0); }, "", pybind11::arg("_fstencil"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_stencil", (void (bgfx::Encoder::*)(unsigned int, unsigned int)) &bgfx::Encoder::setStencil, "Set stencil test state.\n\n \n Front stencil state.\n \n\n Back stencil state. If back is set to `BGFX_STENCIL_NONE`\n   _fstencil is applied to both front and back facing primitives.\n\n \n C99 equivalent is `bgfx_encoder_set_stencil`.\n\nC++: bgfx::Encoder::setStencil(unsigned int, unsigned int) --> void", pybind11::arg("_fstencil"), pybind11::arg("_bstencil"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_scissor", (unsigned short (bgfx::Encoder::*)(unsigned short, unsigned short, unsigned short, unsigned short)) &bgfx::Encoder::setScissor, "Set scissor for draw primitive. To scissor for all primitives in\n view see `bgfx::setViewScissor`.\n\n \n Position x from the left side of the window.\n \n\n Position y from the top of the window.\n \n\n Width of scissor region.\n \n\n Height of scissor region.\n \n\n Scissor cache index.\n\n \n C99 equivalent is `bgfx_encoder_set_scissor`.\n\nC++: bgfx::Encoder::setScissor(unsigned short, unsigned short, unsigned short, unsigned short) --> unsigned short", pybind11::arg("_x"), pybind11::arg("_y"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_scissor", [](bgfx::Encoder &o) -> void { return o.setScissor(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_scissor", (void (bgfx::Encoder::*)(unsigned short)) &bgfx::Encoder::setScissor, "Set scissor from cache for draw primitive.\n\n \n Index in scissor cache.\n   Pass UINT16_MAX to have primitive use view scissor instead.\n\n \n C99 equivalent is `bgfx_encoder_set_scissor_cached`.\n\nC++: bgfx::Encoder::setScissor(unsigned short) --> void", pybind11::arg("_cache"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_transform", [](bgfx::Encoder &o, const void * a0) -> unsigned int { return o.setTransform(a0); }, "", pybind11::arg("_mtx"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_transform", (unsigned int (bgfx::Encoder::*)(const void *, unsigned short)) &bgfx::Encoder::setTransform, "Set model matrix for draw primitive. If it is not called, model will\n be rendered with identity model matrix.\n\n \n Pointer to first matrix in array.\n \n\n Number of matrices in array.\n \n\n Index into matrix cache in case the same model matrix has\n   to be used for other draw primitive call.\n\n \n C99 equivalent is `bgfx_encoder_set_transform`.\n\nC++: bgfx::Encoder::setTransform(const void *, unsigned short) --> unsigned int", pybind11::arg("_mtx"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("alloc_transform", (unsigned int (bgfx::Encoder::*)(struct bgfx::Transform *, unsigned short)) &bgfx::Encoder::allocTransform, "Reserve `_num` matrices in internal matrix cache.\n\n \n Pointer to `Transform` structure.\n \n\n Number of matrices.\n \n\n Index into matrix cache.\n\n \n Pointer returned can be modifed until `bgfx::frame` is called.\n \n\n C99 equivalent is `bgfx_encoder_alloc_transform`.\n\nC++: bgfx::Encoder::allocTransform(struct bgfx::Transform *, unsigned short) --> unsigned int", pybind11::arg("_transform"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_transform", [](bgfx::Encoder &o, unsigned int const & a0) -> void { return o.setTransform(a0); }, "", pybind11::arg("_cache"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_transform", (void (bgfx::Encoder::*)(unsigned int, unsigned short)) &bgfx::Encoder::setTransform, "Set model matrix from matrix cache for draw primitive.\n\n \n Index in matrix cache.\n \n\n Number of matrices from cache.\n\n \n C99 equivalent is `bgfx_encoder_set_transform_cached`.\n\nC++: bgfx::Encoder::setTransform(unsigned int, unsigned short) --> void", pybind11::arg("_cache"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_uniform", [](bgfx::Encoder &o, struct bgfx::UniformHandle const & a0, const void * a1) -> void { return o.setUniform(a0, a1); }, "", pybind11::arg("_handle"), pybind11::arg("_value"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_uniform", (void (bgfx::Encoder::*)(struct bgfx::UniformHandle, const void *, unsigned short)) &bgfx::Encoder::setUniform, "Set shader uniform parameter for draw primitive.\n\n \n Uniform.\n \n\n Pointer to uniform data.\n \n\n Number of elements. Passing `UINT16_MAX` will\n   use the _num passed on uniform creation.\n\n \n C99 equivalent is `bgfx_encoder_set_uniform`.\n\nC++: bgfx::Encoder::setUniform(struct bgfx::UniformHandle, const void *, unsigned short) --> void", pybind11::arg("_handle"), pybind11::arg("_value"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_index_buffer", (void (bgfx::Encoder::*)(struct bgfx::IndexBufferHandle)) &bgfx::Encoder::setIndexBuffer, "Set index buffer for draw primitive.\n\n \n Index buffer.\n\n \n C99 equivalent is `bgfx_encoder_set_index_buffer`.\n\nC++: bgfx::Encoder::setIndexBuffer(struct bgfx::IndexBufferHandle) --> void", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_index_buffer", (void (bgfx::Encoder::*)(struct bgfx::IndexBufferHandle, unsigned int, unsigned int)) &bgfx::Encoder::setIndexBuffer, "Set index buffer for draw primitive.\n\n \n Index buffer.\n \n\n First index to render.\n \n\n Number of indices to render.\n\n \n C99 equivalent is `bgfx_encoder_set_index_buffer`.\n\nC++: bgfx::Encoder::setIndexBuffer(struct bgfx::IndexBufferHandle, unsigned int, unsigned int) --> void", pybind11::arg("_handle"), pybind11::arg("_firstIndex"), pybind11::arg("_numIndices"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_index_buffer", (void (bgfx::Encoder::*)(struct bgfx::DynamicIndexBufferHandle)) &bgfx::Encoder::setIndexBuffer, "Set index buffer for draw primitive.\n\n \n Dynamic index buffer.\n\n \n C99 equivalent is `bgfx_encoder_set_dynamic_index_buffer`.\n\nC++: bgfx::Encoder::setIndexBuffer(struct bgfx::DynamicIndexBufferHandle) --> void", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_index_buffer", (void (bgfx::Encoder::*)(struct bgfx::DynamicIndexBufferHandle, unsigned int, unsigned int)) &bgfx::Encoder::setIndexBuffer, "Set index buffer for draw primitive.\n\n \n Dynamic index buffer.\n \n\n First index to render.\n \n\n Number of indices to render.\n\n \n C99 equivalent is `bgfx_encoder_set_dynamic_index_buffer`.\n\nC++: bgfx::Encoder::setIndexBuffer(struct bgfx::DynamicIndexBufferHandle, unsigned int, unsigned int) --> void", pybind11::arg("_handle"), pybind11::arg("_firstIndex"), pybind11::arg("_numIndices"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_index_buffer", (void (bgfx::Encoder::*)(const struct bgfx::TransientIndexBuffer *)) &bgfx::Encoder::setIndexBuffer, "Set index buffer for draw primitive.\n\n \n Transient index buffer.\n\n \n C99 equivalent is `bgfx_encoder_set_transient_index_buffer`.\n\nC++: bgfx::Encoder::setIndexBuffer(const struct bgfx::TransientIndexBuffer *) --> void", pybind11::arg("_tib"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_index_buffer", (void (bgfx::Encoder::*)(const struct bgfx::TransientIndexBuffer *, unsigned int, unsigned int)) &bgfx::Encoder::setIndexBuffer, "Set index buffer for draw primitive.\n\n \n Transient index buffer.\n \n\n First index to render.\n \n\n Number of indices to render.\n\n \n C99 equivalent is `bgfx_encoder_set_transient_index_buffer`.\n\nC++: bgfx::Encoder::setIndexBuffer(const struct bgfx::TransientIndexBuffer *, unsigned int, unsigned int) --> void", pybind11::arg("_tib"), pybind11::arg("_firstIndex"), pybind11::arg("_numIndices"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_vertex_buffer", (void (bgfx::Encoder::*)(unsigned char, struct bgfx::VertexBufferHandle)) &bgfx::Encoder::setVertexBuffer, "Set vertex buffer for draw primitive.\n\n \n Vertex stream.\n \n\n Vertex buffer.\n\n \n C99 equivalent is `bgfx_encoder_set_vertex_buffer`.\n\nC++: bgfx::Encoder::setVertexBuffer(unsigned char, struct bgfx::VertexBufferHandle) --> void", pybind11::arg("_stream"), pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_vertex_buffer", [](bgfx::Encoder &o, unsigned char const & a0, struct bgfx::VertexBufferHandle const & a1, unsigned int const & a2, unsigned int const & a3) -> void { return o.setVertexBuffer(a0, a1, a2, a3); }, "", pybind11::arg("_stream"), pybind11::arg("_handle"), pybind11::arg("_startVertex"), pybind11::arg("_numVertices"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_vertex_buffer", (void (bgfx::Encoder::*)(unsigned char, struct bgfx::VertexBufferHandle, unsigned int, unsigned int, struct bgfx::VertexLayoutHandle)) &bgfx::Encoder::setVertexBuffer, "Set vertex buffer for draw primitive.\n\n \n Vertex stream.\n \n\n Vertex buffer.\n \n\n First vertex to render.\n \n\n Number of vertices to render.\n \n\n Vertex layout for aliasing vertex buffer.\n\n \n C99 equivalent is `bgfx_encoder_set_vertex_buffer`.\n\nC++: bgfx::Encoder::setVertexBuffer(unsigned char, struct bgfx::VertexBufferHandle, unsigned int, unsigned int, struct bgfx::VertexLayoutHandle) --> void", pybind11::arg("_stream"), pybind11::arg("_handle"), pybind11::arg("_startVertex"), pybind11::arg("_numVertices"), pybind11::arg("_layoutHandle"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_vertex_buffer", (void (bgfx::Encoder::*)(unsigned char, struct bgfx::DynamicVertexBufferHandle)) &bgfx::Encoder::setVertexBuffer, "Set vertex buffer for draw primitive.\n\n \n Vertex stream.\n \n\n Dynamic vertex buffer.\n\n \n C99 equivalent is `bgfx_encoder_set_dynamic_vertex_buffer`.\n\nC++: bgfx::Encoder::setVertexBuffer(unsigned char, struct bgfx::DynamicVertexBufferHandle) --> void", pybind11::arg("_stream"), pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_vertex_buffer", [](bgfx::Encoder &o, unsigned char const & a0, struct bgfx::DynamicVertexBufferHandle const & a1, unsigned int const & a2, unsigned int const & a3) -> void { return o.setVertexBuffer(a0, a1, a2, a3); }, "", pybind11::arg("_stream"), pybind11::arg("_handle"), pybind11::arg("_startVertex"), pybind11::arg("_numVertices"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_vertex_buffer", (void (bgfx::Encoder::*)(unsigned char, struct bgfx::DynamicVertexBufferHandle, unsigned int, unsigned int, struct bgfx::VertexLayoutHandle)) &bgfx::Encoder::setVertexBuffer, "Set vertex buffer for draw primitive.\n\n \n Vertex stream.\n \n\n Dynamic vertex buffer.\n \n\n First vertex to render.\n \n\n Number of vertices to render.\n \n\n Vertex layout for aliasing vertex buffer.\n\n \n C99 equivalent is `bgfx_encoder_set_dynamic_vertex_buffer`.\n\nC++: bgfx::Encoder::setVertexBuffer(unsigned char, struct bgfx::DynamicVertexBufferHandle, unsigned int, unsigned int, struct bgfx::VertexLayoutHandle) --> void", pybind11::arg("_stream"), pybind11::arg("_handle"), pybind11::arg("_startVertex"), pybind11::arg("_numVertices"), pybind11::arg("_layoutHandle"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_vertex_buffer", (void (bgfx::Encoder::*)(unsigned char, const struct bgfx::TransientVertexBuffer *)) &bgfx::Encoder::setVertexBuffer, "Set vertex buffer for draw primitive.\n\n \n Vertex stream.\n \n\n Transient vertex buffer.\n\n \n C99 equivalent is `bgfx_encoder_set_transient_vertex_buffer`.\n\nC++: bgfx::Encoder::setVertexBuffer(unsigned char, const struct bgfx::TransientVertexBuffer *) --> void", pybind11::arg("_stream"), pybind11::arg("_tvb"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_vertex_buffer", [](bgfx::Encoder &o, unsigned char const & a0, const struct bgfx::TransientVertexBuffer * a1, unsigned int const & a2, unsigned int const & a3) -> void { return o.setVertexBuffer(a0, a1, a2, a3); }, "", pybind11::arg("_stream"), pybind11::arg("_tvb"), pybind11::arg("_startVertex"), pybind11::arg("_numVertices"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_vertex_buffer", (void (bgfx::Encoder::*)(unsigned char, const struct bgfx::TransientVertexBuffer *, unsigned int, unsigned int, struct bgfx::VertexLayoutHandle)) &bgfx::Encoder::setVertexBuffer, "Set vertex buffer for draw primitive.\n\n \n Vertex stream.\n \n\n Transient vertex buffer.\n \n\n First vertex to render.\n \n\n Number of vertices to render.\n \n\n Vertex layout for aliasing vertex buffer.\n\n \n C99 equivalent is `bgfx_encoder_set_transient_vertex_buffer`.\n\nC++: bgfx::Encoder::setVertexBuffer(unsigned char, const struct bgfx::TransientVertexBuffer *, unsigned int, unsigned int, struct bgfx::VertexLayoutHandle) --> void", pybind11::arg("_stream"), pybind11::arg("_tvb"), pybind11::arg("_startVertex"), pybind11::arg("_numVertices"), pybind11::arg("_layoutHandle"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_vertex_count", (void (bgfx::Encoder::*)(unsigned int)) &bgfx::Encoder::setVertexCount, "Set number of vertices for auto generated vertices use in conjuction\n with gl_VertexID.\n\n \n Number of vertices.\n\n \n Availability depends on: `BGFX_CAPS_VERTEX_ID`.\n \n\n C99 equivalent is `bgfx_encoder_set_vertex_count`.\n\nC++: bgfx::Encoder::setVertexCount(unsigned int) --> void", pybind11::arg("_numVertices"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_instance_data_buffer", (void (bgfx::Encoder::*)(const struct bgfx::InstanceDataBuffer *)) &bgfx::Encoder::setInstanceDataBuffer, "Set instance data buffer for draw primitive.\n\n \n Transient instance data buffer.\n\n \n C99 equivalent is `bgfx_encoder_set_instance_data_buffer`.\n\nC++: bgfx::Encoder::setInstanceDataBuffer(const struct bgfx::InstanceDataBuffer *) --> void", pybind11::arg("_idb"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_instance_data_buffer", (void (bgfx::Encoder::*)(const struct bgfx::InstanceDataBuffer *, unsigned int, unsigned int)) &bgfx::Encoder::setInstanceDataBuffer, "Set instance data buffer for draw primitive.\n\n \n Transient instance data buffer.\n \n\n First instance data.\n \n\n Number of data instances.\n\n \n C99 equivalent is `bgfx_encoder_set_instance_data_buffer`.\n\nC++: bgfx::Encoder::setInstanceDataBuffer(const struct bgfx::InstanceDataBuffer *, unsigned int, unsigned int) --> void", pybind11::arg("_idb"), pybind11::arg("_start"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_instance_data_buffer", (void (bgfx::Encoder::*)(struct bgfx::VertexBufferHandle, unsigned int, unsigned int)) &bgfx::Encoder::setInstanceDataBuffer, "Set instance data buffer for draw primitive.\n\n \n Vertex buffer.\n \n\n First instance data.\n \n\n Number of data instances.\n\n \n C99 equivalent is `bgfx_encoder_set_instance_data_from_vertex_buffer`.\n\nC++: bgfx::Encoder::setInstanceDataBuffer(struct bgfx::VertexBufferHandle, unsigned int, unsigned int) --> void", pybind11::arg("_handle"), pybind11::arg("_start"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_instance_data_buffer", (void (bgfx::Encoder::*)(struct bgfx::DynamicVertexBufferHandle, unsigned int, unsigned int)) &bgfx::Encoder::setInstanceDataBuffer, "Set instance data buffer for draw primitive.\n\n \n Vertex buffer.\n \n\n First instance data.\n \n\n Number of data instances.\n\n \n C99 equivalent is `bgfx_encoder_set_instance_data_from_dynamic_vertex_buffer`.\n\nC++: bgfx::Encoder::setInstanceDataBuffer(struct bgfx::DynamicVertexBufferHandle, unsigned int, unsigned int) --> void", pybind11::arg("_handle"), pybind11::arg("_start"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_instance_count", (void (bgfx::Encoder::*)(unsigned int)) &bgfx::Encoder::setInstanceCount, "Set number of instances for auto generated instances use in conjuction\n with gl_InstanceID.\n\n \n Number of instances.\n\n \n Availability depends on: `BGFX_CAPS_VERTEX_ID`.\n \n\n C99 equivalent is `bgfx_encoder_set_instance_count`.\n\nC++: bgfx::Encoder::setInstanceCount(unsigned int) --> void", pybind11::arg("_numInstances"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_texture", [](bgfx::Encoder &o, unsigned char const & a0, struct bgfx::UniformHandle const & a1, struct bgfx::TextureHandle const & a2) -> void { return o.setTexture(a0, a1, a2); }, "", pybind11::arg("_stage"), pybind11::arg("_sampler"), pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_texture", (void (bgfx::Encoder::*)(unsigned char, struct bgfx::UniformHandle, struct bgfx::TextureHandle, unsigned int)) &bgfx::Encoder::setTexture, "Set texture stage for draw primitive.\n\n \n Texture unit.\n \n\n Program sampler.\n \n\n Texture handle.\n \n\n Texture sampling mode. Default value UINT32_MAX uses\n   texture sampling settings from the texture.\n   - `BGFX_SAMPLER_[U/V/W]_[MIRROR/CLAMP]` - Mirror or clamp to edge wrap\n     mode.\n   - `BGFX_SAMPLER_[MIN/MAG/MIP]_[POINT/ANISOTROPIC]` - Point or anisotropic\n     sampling.\n\n \n C99 equivalent is `bgfx_encoder_set_texture`.\n\nC++: bgfx::Encoder::setTexture(unsigned char, struct bgfx::UniformHandle, struct bgfx::TextureHandle, unsigned int) --> void", pybind11::arg("_stage"), pybind11::arg("_sampler"), pybind11::arg("_handle"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("touch", (void (bgfx::Encoder::*)(unsigned short)) &bgfx::Encoder::touch, "Submit an empty primitive for rendering. Uniforms and draw state\n will be applied but no geometry will be submitted.\n\n These empty draw calls will sort before ordinary draw calls.\n\n \n View id.\n\n \n C99 equivalent is `bgfx_encoder_touch`.\n\nC++: bgfx::Encoder::touch(unsigned short) --> void", pybind11::arg("_id"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("submit", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::ProgramHandle const & a1) -> void { return o.submit(a0, a1); }, "", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("submit", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::ProgramHandle const & a1, unsigned int const & a2) -> void { return o.submit(a0, a1, a2); }, "", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::arg("_depth"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("submit", (void (bgfx::Encoder::*)(unsigned short, struct bgfx::ProgramHandle, unsigned int, unsigned char)) &bgfx::Encoder::submit, "Submit primitive for rendering.\n\n \n View id.\n \n\n Program.\n \n\n Depth for sorting.\n \n\n Discard or preserve states. See `BGFX_DISCARD_*`.\n\n \n C99 equivalent is `bgfx_encoder_submit`.\n\nC++: bgfx::Encoder::submit(unsigned short, struct bgfx::ProgramHandle, unsigned int, unsigned char) --> void", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::arg("_depth"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("submit", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::ProgramHandle const & a1, struct bgfx::OcclusionQueryHandle const & a2) -> void { return o.submit(a0, a1, a2); }, "", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::arg("_occlusionQuery"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("submit", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::ProgramHandle const & a1, struct bgfx::OcclusionQueryHandle const & a2, unsigned int const & a3) -> void { return o.submit(a0, a1, a2, a3); }, "", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::arg("_occlusionQuery"), pybind11::arg("_depth"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("submit", (void (bgfx::Encoder::*)(unsigned short, struct bgfx::ProgramHandle, struct bgfx::OcclusionQueryHandle, unsigned int, unsigned char)) &bgfx::Encoder::submit, "Submit primitive with occlusion query for rendering.\n\n \n View id.\n \n\n Program.\n \n\n Occlusion query.\n \n\n Depth for sorting.\n \n\n Discard or preserve states. See `BGFX_DISCARD_*`.\n\n \n C99 equivalent is `bgfx_encoder_submit_occlusion_query`.\n\nC++: bgfx::Encoder::submit(unsigned short, struct bgfx::ProgramHandle, struct bgfx::OcclusionQueryHandle, unsigned int, unsigned char) --> void", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::arg("_occlusionQuery"), pybind11::arg("_depth"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("submit", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::ProgramHandle const & a1, struct bgfx::IndirectBufferHandle const & a2) -> void { return o.submit(a0, a1, a2); }, "", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::arg("_indirectHandle"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("submit", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::ProgramHandle const & a1, struct bgfx::IndirectBufferHandle const & a2, unsigned short const & a3) -> void { return o.submit(a0, a1, a2, a3); }, "", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::arg("_indirectHandle"), pybind11::arg("_start"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("submit", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::ProgramHandle const & a1, struct bgfx::IndirectBufferHandle const & a2, unsigned short const & a3, unsigned short const & a4) -> void { return o.submit(a0, a1, a2, a3, a4); }, "", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::arg("_indirectHandle"), pybind11::arg("_start"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("submit", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::ProgramHandle const & a1, struct bgfx::IndirectBufferHandle const & a2, unsigned short const & a3, unsigned short const & a4, unsigned int const & a5) -> void { return o.submit(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::arg("_indirectHandle"), pybind11::arg("_start"), pybind11::arg("_num"), pybind11::arg("_depth"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("submit", (void (bgfx::Encoder::*)(unsigned short, struct bgfx::ProgramHandle, struct bgfx::IndirectBufferHandle, unsigned short, unsigned short, unsigned int, unsigned char)) &bgfx::Encoder::submit, "Submit primitive for rendering with index and instance data info from\n indirect buffer.\n\n \n View id.\n \n\n Program.\n \n\n Indirect buffer.\n \n\n First element in indirect buffer.\n \n\n Number of dispatches.\n \n\n Depth for sorting.\n \n\n Discard or preserve states. See `BGFX_DISCARD_*`.\n\n \n C99 equivalent is `bgfx_encoder_submit_indirect`.\n\nC++: bgfx::Encoder::submit(unsigned short, struct bgfx::ProgramHandle, struct bgfx::IndirectBufferHandle, unsigned short, unsigned short, unsigned int, unsigned char) --> void", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::arg("_indirectHandle"), pybind11::arg("_start"), pybind11::arg("_num"), pybind11::arg("_depth"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_buffer", (void (bgfx::Encoder::*)(unsigned char, struct bgfx::IndexBufferHandle, enum bgfx::Access::Enum)) &bgfx::Encoder::setBuffer, "Set compute index buffer.\n\n \n Compute stage.\n \n\n Index buffer handle.\n \n\n Buffer access. See `Access::Enum`.\n\n \n C99 equivalent is `bgfx_encoder_set_compute_index_buffer`.\n\nC++: bgfx::Encoder::setBuffer(unsigned char, struct bgfx::IndexBufferHandle, enum bgfx::Access::Enum) --> void", pybind11::arg("_stage"), pybind11::arg("_handle"), pybind11::arg("_access"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_buffer", (void (bgfx::Encoder::*)(unsigned char, struct bgfx::VertexBufferHandle, enum bgfx::Access::Enum)) &bgfx::Encoder::setBuffer, "Set compute vertex buffer.\n\n \n Compute stage.\n \n\n Vertex buffer handle.\n \n\n Buffer access. See `Access::Enum`.\n\n \n C99 equivalent is `bgfx_encoder_set_compute_vertex_buffer`.\n\nC++: bgfx::Encoder::setBuffer(unsigned char, struct bgfx::VertexBufferHandle, enum bgfx::Access::Enum) --> void", pybind11::arg("_stage"), pybind11::arg("_handle"), pybind11::arg("_access"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_buffer", (void (bgfx::Encoder::*)(unsigned char, struct bgfx::DynamicIndexBufferHandle, enum bgfx::Access::Enum)) &bgfx::Encoder::setBuffer, "Set compute dynamic index buffer.\n\n \n Compute stage.\n \n\n Dynamic index buffer handle.\n \n\n Buffer access. See `Access::Enum`.\n\n \n C99 equivalent is `bgfx_encoder_set_compute_dynamic_index_buffer`.\n\nC++: bgfx::Encoder::setBuffer(unsigned char, struct bgfx::DynamicIndexBufferHandle, enum bgfx::Access::Enum) --> void", pybind11::arg("_stage"), pybind11::arg("_handle"), pybind11::arg("_access"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_buffer", (void (bgfx::Encoder::*)(unsigned char, struct bgfx::DynamicVertexBufferHandle, enum bgfx::Access::Enum)) &bgfx::Encoder::setBuffer, "Set compute dynamic vertex buffer.\n\n \n Compute stage.\n \n\n Dynamic vertex buffer handle.\n \n\n Buffer access. See `Access::Enum`.\n\n \n C99 equivalent is `bgfx_encoder_set_compute_dynamic_vertex_buffer`.\n\nC++: bgfx::Encoder::setBuffer(unsigned char, struct bgfx::DynamicVertexBufferHandle, enum bgfx::Access::Enum) --> void", pybind11::arg("_stage"), pybind11::arg("_handle"), pybind11::arg("_access"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_buffer", (void (bgfx::Encoder::*)(unsigned char, struct bgfx::IndirectBufferHandle, enum bgfx::Access::Enum)) &bgfx::Encoder::setBuffer, "Set compute indirect buffer.\n\n \n Compute stage.\n \n\n Indirect buffer handle.\n \n\n Buffer access. See `Access::Enum`.\n\n \n C99 equivalent is `bgfx_encoder_set_compute_indirect_buffer`.\n\nC++: bgfx::Encoder::setBuffer(unsigned char, struct bgfx::IndirectBufferHandle, enum bgfx::Access::Enum) --> void", pybind11::arg("_stage"), pybind11::arg("_handle"), pybind11::arg("_access"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_image", [](bgfx::Encoder &o, unsigned char const & a0, struct bgfx::TextureHandle const & a1, unsigned char const & a2, enum bgfx::Access::Enum const & a3) -> void { return o.setImage(a0, a1, a2, a3); }, "", pybind11::arg("_stage"), pybind11::arg("_handle"), pybind11::arg("_mip"), pybind11::arg("_access"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("set_image", (void (bgfx::Encoder::*)(unsigned char, struct bgfx::TextureHandle, unsigned char, enum bgfx::Access::Enum, enum bgfx::TextureFormat::Enum)) &bgfx::Encoder::setImage, "Set compute image from texture.\n\n \n Texture unit.\n \n\n Texture handle.\n \n\n Mip level.\n \n\n Texture access. See `Access::Enum`.\n \n\n Texture format. See: `TextureFormat::Enum`.\n\n \n C99 equivalent is `bgfx_encoder_set_image`.\n\nC++: bgfx::Encoder::setImage(unsigned char, struct bgfx::TextureHandle, unsigned char, enum bgfx::Access::Enum, enum bgfx::TextureFormat::Enum) --> void", pybind11::arg("_stage"), pybind11::arg("_handle"), pybind11::arg("_mip"), pybind11::arg("_access"), pybind11::arg("_format"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("dispatch", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::ProgramHandle const & a1) -> void { return o.dispatch(a0, a1); }, "", pybind11::arg("_id"), pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("dispatch", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::ProgramHandle const & a1, unsigned int const & a2) -> void { return o.dispatch(a0, a1, a2); }, "", pybind11::arg("_id"), pybind11::arg("_handle"), pybind11::arg("_numX"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("dispatch", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::ProgramHandle const & a1, unsigned int const & a2, unsigned int const & a3) -> void { return o.dispatch(a0, a1, a2, a3); }, "", pybind11::arg("_id"), pybind11::arg("_handle"), pybind11::arg("_numX"), pybind11::arg("_numY"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("dispatch", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::ProgramHandle const & a1, unsigned int const & a2, unsigned int const & a3, unsigned int const & a4) -> void { return o.dispatch(a0, a1, a2, a3, a4); }, "", pybind11::arg("_id"), pybind11::arg("_handle"), pybind11::arg("_numX"), pybind11::arg("_numY"), pybind11::arg("_numZ"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("dispatch", (void (bgfx::Encoder::*)(unsigned short, struct bgfx::ProgramHandle, unsigned int, unsigned int, unsigned int, unsigned char)) &bgfx::Encoder::dispatch, "Dispatch compute.\n\n \n View id.\n \n\n Compute program.\n \n\n Number of groups X.\n \n\n Number of groups Y.\n \n\n Number of groups Z.\n \n\n Discard or preserve states. See `BGFX_DISCARD_*`.\n\n \n C99 equivalent is `bgfx_encoder_dispatch`.\n\nC++: bgfx::Encoder::dispatch(unsigned short, struct bgfx::ProgramHandle, unsigned int, unsigned int, unsigned int, unsigned char) --> void", pybind11::arg("_id"), pybind11::arg("_handle"), pybind11::arg("_numX"), pybind11::arg("_numY"), pybind11::arg("_numZ"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("dispatch", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::ProgramHandle const & a1, struct bgfx::IndirectBufferHandle const & a2) -> void { return o.dispatch(a0, a1, a2); }, "", pybind11::arg("_id"), pybind11::arg("_handle"), pybind11::arg("_indirectHandle"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("dispatch", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::ProgramHandle const & a1, struct bgfx::IndirectBufferHandle const & a2, unsigned short const & a3) -> void { return o.dispatch(a0, a1, a2, a3); }, "", pybind11::arg("_id"), pybind11::arg("_handle"), pybind11::arg("_indirectHandle"), pybind11::arg("_start"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("dispatch", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::ProgramHandle const & a1, struct bgfx::IndirectBufferHandle const & a2, unsigned short const & a3, unsigned short const & a4) -> void { return o.dispatch(a0, a1, a2, a3, a4); }, "", pybind11::arg("_id"), pybind11::arg("_handle"), pybind11::arg("_indirectHandle"), pybind11::arg("_start"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("dispatch", (void (bgfx::Encoder::*)(unsigned short, struct bgfx::ProgramHandle, struct bgfx::IndirectBufferHandle, unsigned short, unsigned short, unsigned char)) &bgfx::Encoder::dispatch, "Dispatch compute indirect.\n\n \n View id.\n \n\n Compute program.\n \n\n Indirect buffer.\n \n\n First element in indirect buffer.\n \n\n Number of dispatches.\n \n\n Discard or preserve states. See `BGFX_DISCARD_*`.\n\n \n C99 equivalent is `bgfx_encoder_dispatch_indirect`.\n\nC++: bgfx::Encoder::dispatch(unsigned short, struct bgfx::ProgramHandle, struct bgfx::IndirectBufferHandle, unsigned short, unsigned short, unsigned char) --> void", pybind11::arg("_id"), pybind11::arg("_handle"), pybind11::arg("_indirectHandle"), pybind11::arg("_start"), pybind11::arg("_num"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("blit", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned short const & a2, unsigned short const & a3, struct bgfx::TextureHandle const & a4) -> void { return o.blit(a0, a1, a2, a3, a4); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_src"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("blit", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned short const & a2, unsigned short const & a3, struct bgfx::TextureHandle const & a4, unsigned short const & a5) -> void { return o.blit(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_src"), pybind11::arg("_srcX"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("blit", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned short const & a2, unsigned short const & a3, struct bgfx::TextureHandle const & a4, unsigned short const & a5, unsigned short const & a6) -> void { return o.blit(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_src"), pybind11::arg("_srcX"), pybind11::arg("_srcY"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("blit", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned short const & a2, unsigned short const & a3, struct bgfx::TextureHandle const & a4, unsigned short const & a5, unsigned short const & a6, unsigned short const & a7) -> void { return o.blit(a0, a1, a2, a3, a4, a5, a6, a7); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_src"), pybind11::arg("_srcX"), pybind11::arg("_srcY"), pybind11::arg("_width"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("blit", (void (bgfx::Encoder::*)(unsigned short, struct bgfx::TextureHandle, unsigned short, unsigned short, struct bgfx::TextureHandle, unsigned short, unsigned short, unsigned short, unsigned short)) &bgfx::Encoder::blit, "Blit texture 2D region between two 2D textures.\n\n \n View id.\n \n\n Destination texture handle.\n \n\n Destination texture X position.\n \n\n Destination texture Y position.\n \n\n Source texture handle.\n \n\n Source texture X position.\n \n\n Source texture Y position.\n \n\n Width of region.\n \n\n Height of region.\n\n \n Destination texture must be created with `BGFX_TEXTURE_BLIT_DST` flag.\n \n\n Availability depends on: `BGFX_CAPS_TEXTURE_BLIT`.\n \n\n C99 equivalent is `bgfx_encoder_blit`.\n\nC++: bgfx::Encoder::blit(unsigned short, struct bgfx::TextureHandle, unsigned short, unsigned short, struct bgfx::TextureHandle, unsigned short, unsigned short, unsigned short, unsigned short) --> void", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_src"), pybind11::arg("_srcX"), pybind11::arg("_srcY"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("blit", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned char const & a2, unsigned short const & a3, unsigned short const & a4, unsigned short const & a5, struct bgfx::TextureHandle const & a6) -> void { return o.blit(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstMip"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_dstZ"), pybind11::arg("_src"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("blit", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned char const & a2, unsigned short const & a3, unsigned short const & a4, unsigned short const & a5, struct bgfx::TextureHandle const & a6, unsigned char const & a7) -> void { return o.blit(a0, a1, a2, a3, a4, a5, a6, a7); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstMip"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_dstZ"), pybind11::arg("_src"), pybind11::arg("_srcMip"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("blit", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned char const & a2, unsigned short const & a3, unsigned short const & a4, unsigned short const & a5, struct bgfx::TextureHandle const & a6, unsigned char const & a7, unsigned short const & a8) -> void { return o.blit(a0, a1, a2, a3, a4, a5, a6, a7, a8); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstMip"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_dstZ"), pybind11::arg("_src"), pybind11::arg("_srcMip"), pybind11::arg("_srcX"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("blit", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned char const & a2, unsigned short const & a3, unsigned short const & a4, unsigned short const & a5, struct bgfx::TextureHandle const & a6, unsigned char const & a7, unsigned short const & a8, unsigned short const & a9) -> void { return o.blit(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstMip"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_dstZ"), pybind11::arg("_src"), pybind11::arg("_srcMip"), pybind11::arg("_srcX"), pybind11::arg("_srcY"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("blit", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned char const & a2, unsigned short const & a3, unsigned short const & a4, unsigned short const & a5, struct bgfx::TextureHandle const & a6, unsigned char const & a7, unsigned short const & a8, unsigned short const & a9, unsigned short const & a10) -> void { return o.blit(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstMip"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_dstZ"), pybind11::arg("_src"), pybind11::arg("_srcMip"), pybind11::arg("_srcX"), pybind11::arg("_srcY"), pybind11::arg("_srcZ"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("blit", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned char const & a2, unsigned short const & a3, unsigned short const & a4, unsigned short const & a5, struct bgfx::TextureHandle const & a6, unsigned char const & a7, unsigned short const & a8, unsigned short const & a9, unsigned short const & a10, unsigned short const & a11) -> void { return o.blit(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstMip"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_dstZ"), pybind11::arg("_src"), pybind11::arg("_srcMip"), pybind11::arg("_srcX"), pybind11::arg("_srcY"), pybind11::arg("_srcZ"), pybind11::arg("_width"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("blit", [](bgfx::Encoder &o, unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned char const & a2, unsigned short const & a3, unsigned short const & a4, unsigned short const & a5, struct bgfx::TextureHandle const & a6, unsigned char const & a7, unsigned short const & a8, unsigned short const & a9, unsigned short const & a10, unsigned short const & a11, unsigned short const & a12) -> void { return o.blit(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstMip"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_dstZ"), pybind11::arg("_src"), pybind11::arg("_srcMip"), pybind11::arg("_srcX"), pybind11::arg("_srcY"), pybind11::arg("_srcZ"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("blit", (void (bgfx::Encoder::*)(unsigned short, struct bgfx::TextureHandle, unsigned char, unsigned short, unsigned short, unsigned short, struct bgfx::TextureHandle, unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short)) &bgfx::Encoder::blit, "Blit texture region between two textures.\n\n \n View id.\n \n\n Destination texture handle.\n \n\n Destination texture mip level.\n \n\n Destination texture X position.\n \n\n Destination texture Y position.\n \n\n If texture is 2D this argument should be 0. If destination texture is cube\n   this argument represents destination texture cube face. For 3D texture this argument\n   represents destination texture Z position.\n \n\n Source texture handle.\n \n\n Source texture mip level.\n \n\n Source texture X position.\n \n\n Source texture Y position.\n \n\n If texture is 2D this argument should be 0. If source texture is cube\n   this argument represents source texture cube face. For 3D texture this argument\n   represents source texture Z position.\n \n\n Width of region.\n \n\n Height of region.\n \n\n If texture is 3D this argument represents depth of region, otherwise it's\n   unused.\n\n \n Destination texture must be created with `BGFX_TEXTURE_BLIT_DST` flag.\n \n\n Availability depends on: `BGFX_CAPS_TEXTURE_BLIT`.\n \n\n C99 equivalent is `bgfx_encoder_blit`.\n\nC++: bgfx::Encoder::blit(unsigned short, struct bgfx::TextureHandle, unsigned char, unsigned short, unsigned short, unsigned short, struct bgfx::TextureHandle, unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short) --> void", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstMip"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_dstZ"), pybind11::arg("_src"), pybind11::arg("_srcMip"), pybind11::arg("_srcX"), pybind11::arg("_srcY"), pybind11::arg("_srcZ"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_depth"), pybind11::call_guard<pybind11::gil_scoped_release>());
	}
}


// File: bgfx_2.cpp
#include <bgfx.h>
#include <sstream> // __str__

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_bgfx_2(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // bgfx::VertexLayout file:bgfx.h line:1669
		pybind11::class_<bgfx::VertexLayout, std::shared_ptr<bgfx::VertexLayout>> cl(M("bgfx"), "VertexLayout", "Vertex layout.\n\n \n C99 equivalent is `bgfx_vertex_layout_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::VertexLayout(); } ) );
		cl.def_readwrite("m_hash", &bgfx::VertexLayout::m_hash);
		cl.def_readwrite("m_stride", &bgfx::VertexLayout::m_stride);
		cl.def("begin", [](bgfx::VertexLayout &o) -> bgfx::VertexLayout & { return o.begin(); }, "", pybind11::return_value_policy::reference_internal, pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("begin", (struct bgfx::VertexLayout & (bgfx::VertexLayout::*)(enum bgfx::RendererType::Enum)) &bgfx::VertexLayout::begin, "Start VertexLayout.\n\n \n C99 equivalent is `bgfx_vertex_layout_begin`.\n\nC++: bgfx::VertexLayout::begin(enum bgfx::RendererType::Enum) --> struct bgfx::VertexLayout &", pybind11::return_value_policy::reference_internal, pybind11::arg("_renderer"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("end", (void (bgfx::VertexLayout::*)()) &bgfx::VertexLayout::end, "End VertexLayout.\n\n \n C99 equivalent is `bgfx_vertex_layout_end`.\n\nC++: bgfx::VertexLayout::end() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("add", [](bgfx::VertexLayout &o, enum bgfx::Attrib::Enum const & a0, unsigned char const & a1, enum bgfx::AttribType::Enum const & a2) -> bgfx::VertexLayout & { return o.add(a0, a1, a2); }, "", pybind11::return_value_policy::reference_internal, pybind11::arg("_attrib"), pybind11::arg("_num"), pybind11::arg("_type"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("add", [](bgfx::VertexLayout &o, enum bgfx::Attrib::Enum const & a0, unsigned char const & a1, enum bgfx::AttribType::Enum const & a2, bool const & a3) -> bgfx::VertexLayout & { return o.add(a0, a1, a2, a3); }, "", pybind11::return_value_policy::reference_internal, pybind11::arg("_attrib"), pybind11::arg("_num"), pybind11::arg("_type"), pybind11::arg("_normalized"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("add", (struct bgfx::VertexLayout & (bgfx::VertexLayout::*)(enum bgfx::Attrib::Enum, unsigned char, enum bgfx::AttribType::Enum, bool, bool)) &bgfx::VertexLayout::add, "Add attribute to VertexLayout.\n\n \n Attribute semantics. See: `bgfx::Attrib`\n \n\n Number of elements 1, 2, 3 or 4.\n \n\n Element type.\n \n\n When using fixed point AttribType (f.e. Uint8)\n   value will be normalized for vertex shader usage. When normalized\n   is set to true, AttribType::Uint8 value in range 0-255 will be\n   in range 0.0-1.0 in vertex shader.\n \n\n Packaging rule for vertexPack, vertexUnpack, and\n   vertexConvert for AttribType::Uint8 and AttribType::Int16.\n   Unpacking code must be implemented inside vertex shader.\n\n \n\n   Must be called between begin/end.\n\n \n C99 equivalent is `bgfx_vertex_layout_add`.\n\nC++: bgfx::VertexLayout::add(enum bgfx::Attrib::Enum, unsigned char, enum bgfx::AttribType::Enum, bool, bool) --> struct bgfx::VertexLayout &", pybind11::return_value_policy::reference_internal, pybind11::arg("_attrib"), pybind11::arg("_num"), pybind11::arg("_type"), pybind11::arg("_normalized"), pybind11::arg("_asInt"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("skip", (struct bgfx::VertexLayout & (bgfx::VertexLayout::*)(unsigned char)) &bgfx::VertexLayout::skip, "Skip _num bytes in vertex stream.\n\n \n C99 equivalent is `bgfx_vertex_layout_skip`.\n\nC++: bgfx::VertexLayout::skip(unsigned char) --> struct bgfx::VertexLayout &", pybind11::return_value_policy::reference_internal, pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("decode", (void (bgfx::VertexLayout::*)(enum bgfx::Attrib::Enum, unsigned char &, enum bgfx::AttribType::Enum &, bool &, bool &) const) &bgfx::VertexLayout::decode, "Decode attribute.\n\n \n C99 equivalent is `bgfx_vertex_layout_decode`.\n\nC++: bgfx::VertexLayout::decode(enum bgfx::Attrib::Enum, unsigned char &, enum bgfx::AttribType::Enum &, bool &, bool &) const --> void", pybind11::arg("_attrib"), pybind11::arg("_num"), pybind11::arg("_type"), pybind11::arg("_normalized"), pybind11::arg("_asInt"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("has", (bool (bgfx::VertexLayout::*)(enum bgfx::Attrib::Enum) const) &bgfx::VertexLayout::has, "Returns true if VertexLayout contains attribute.\n\n \n C99 equivalent is `bgfx_vertex_layout_has`.\n\nC++: bgfx::VertexLayout::has(enum bgfx::Attrib::Enum) const --> bool", pybind11::arg("_attrib"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("get_offset", (unsigned short (bgfx::VertexLayout::*)(enum bgfx::Attrib::Enum) const) &bgfx::VertexLayout::getOffset, "Returns relative attribute offset from the vertex.\n\nC++: bgfx::VertexLayout::getOffset(enum bgfx::Attrib::Enum) const --> unsigned short", pybind11::arg("_attrib"), pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("get_stride", (unsigned short (bgfx::VertexLayout::*)() const) &bgfx::VertexLayout::getStride, "Returns vertex stride.\n\nC++: bgfx::VertexLayout::getStride() const --> unsigned short", pybind11::call_guard<pybind11::gil_scoped_release>());
		cl.def("get_size", (unsigned int (bgfx::VertexLayout::*)(unsigned int) const) &bgfx::VertexLayout::getSize, "Returns size of vertex buffer for number of vertices.\n\nC++: bgfx::VertexLayout::getSize(unsigned int) const --> unsigned int", pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());
	}
	// bgfx::vertexConvert(const struct bgfx::VertexLayout &, void *, const struct bgfx::VertexLayout &, const void *, unsigned int) file:bgfx.h line:1798
	M("bgfx").def("vertex_convert", [](const struct bgfx::VertexLayout & a0, void * a1, const struct bgfx::VertexLayout & a2, const void * a3) -> void { return bgfx::vertexConvert(a0, a1, a2, a3); }, "", pybind11::arg("_destLayout"), pybind11::arg("_destData"), pybind11::arg("_srcLayout"), pybind11::arg("_srcData"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("vertex_convert", (void (*)(const struct bgfx::VertexLayout &, void *, const struct bgfx::VertexLayout &, const void *, unsigned int)) &bgfx::vertexConvert, "Converts vertex stream data from one vertex stream format to another.\n\n \n Destination vertex stream layout.\n \n\n Destination vertex stream.\n \n\n Source vertex stream layout.\n \n\n Source vertex stream data.\n \n\n Number of vertices to convert from source to destination.\n\n \n C99 equivalent is `bgfx_vertex_convert`.\n\nC++: bgfx::vertexConvert(const struct bgfx::VertexLayout &, void *, const struct bgfx::VertexLayout &, const void *, unsigned int) --> void", pybind11::arg("_destLayout"), pybind11::arg("_destData"), pybind11::arg("_srcLayout"), pybind11::arg("_srcData"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::weldVertices(unsigned short *, const struct bgfx::VertexLayout &, const void *, unsigned short, float) file:bgfx.h line:1818
	M("bgfx").def("weld_vertices", [](void * a0, const struct bgfx::VertexLayout & a1, const void * a2, unsigned short const & a3, bool a4) -> unsigned short { return bgfx::weldVertices(a0, a1, a2, a3, a4); }, "", pybind11::arg("_output"), pybind11::arg("_layout"), pybind11::arg("_data"), pybind11::arg("_num"), pybind11::arg("_index32"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("weld_vertices", (unsigned short (*)(void *, const struct bgfx::VertexLayout &, const void *, unsigned short, bool, float)) &bgfx::weldVertices, "Weld vertices.\n\n \n Welded vertices remapping table. The size of buffer\n   must be the same as number of vertices.\n \n\n Vertex stream layout.\n \n\n Vertex stream.\n \n\n Number of vertices in vertex stream.\n \n\nSet to `true` if input indices are 32-bit.\n \n\n Error tolerance for vertex position comparison.\n \n\n Number of unique vertices after vertex welding.\n\n \n C99 equivalent is `bgfx_weld_vertices`.\n\nC++: bgfx::weldVertices(unsigned short *, const struct bgfx::VertexLayout &, const void *, unsigned short, float) --> unsigned short", pybind11::arg("_output"), pybind11::arg("_layout"), pybind11::arg("_data"), pybind11::arg("_num"), pybind11::arg("_index32"), pybind11::arg("_epsilon"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::topologyConvert(enum bgfx::TopologyConvert::Enum, void *, unsigned int, const void *, unsigned int, bool) file:bgfx.h line:1842
	M("bgfx").def("topology_convert", (unsigned int (*)(enum bgfx::TopologyConvert::Enum, void *, unsigned int, const void *, unsigned int, bool)) &bgfx::topologyConvert, "Convert index buffer for use with different primitive topologies.\n\n \n Conversion type, see `TopologyConvert::Enum`.\n \n\n Destination index buffer. If this argument is NULL\n    function will return number of indices after conversion.\n \n\n Destination index buffer in bytes. It must be\n    large enough to contain output indices. If destination size is\n    insufficient index buffer will be truncated.\n \n\n Source indices.\n \n\n Number of input indices.\n \n\n Set to `true` if input indices are 32-bit.\n\n \n Number of output indices after conversion.\n\n \n C99 equivalent is `bgfx_topology_convert`.\n\nC++: bgfx::topologyConvert(enum bgfx::TopologyConvert::Enum, void *, unsigned int, const void *, unsigned int, bool) --> unsigned int", pybind11::arg("_conversion"), pybind11::arg("_dst"), pybind11::arg("_dstSize"), pybind11::arg("_indices"), pybind11::arg("_numIndices"), pybind11::arg("_index32"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::getSupportedRenderers(unsigned char, enum bgfx::RendererType::Enum *) file:bgfx.h line:1892
	M("bgfx").def("get_supported_renderers", []() -> unsigned char { return bgfx::getSupportedRenderers(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("get_supported_renderers", [](unsigned char const & a0) -> unsigned char { return bgfx::getSupportedRenderers(a0); }, "", pybind11::arg("_max"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("get_supported_renderers", (unsigned char (*)(unsigned char, enum bgfx::RendererType::Enum *)) &bgfx::getSupportedRenderers, "Returns supported backend API renderers.\n\n \n Maximum number of elements in _enum array.\n \n\n Array where supported renderers will be written.\n\n \n Number of supported renderers.\n\n \n C99 equivalent is `bgfx_get_supported_renderers`.\n\nC++: bgfx::getSupportedRenderers(unsigned char, enum bgfx::RendererType::Enum *) --> unsigned char", pybind11::arg("_max"), pybind11::arg("_enum"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::getRendererName(enum bgfx::RendererType::Enum) file:bgfx.h line:1901
	M("bgfx").def("get_renderer_name", (const char * (*)(enum bgfx::RendererType::Enum)) &bgfx::getRendererName, "Returns name of renderer.\n\n \n C99 equivalent is `bgfx_get_renderer_name`.\n\nC++: bgfx::getRendererName(enum bgfx::RendererType::Enum) --> const char *", pybind11::return_value_policy::reference, pybind11::arg("_type"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::init(const struct bgfx::Init &) file:bgfx.h line:1911
	M("bgfx").def("init", []() -> bool { return bgfx::init(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("init", (bool (*)(const struct bgfx::Init &)) &bgfx::init, "Initialize bgfx library.\n\n \n Initialization parameters. See: `bgfx::Init` for more info.\n\n \n `true` if initialization was successful.\n\n \n C99 equivalent is `bgfx_init`.\n\nC++: bgfx::init(const struct bgfx::Init &) --> bool", pybind11::arg("_init"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::shutdown() file:bgfx.h line:1917
	M("bgfx").def("shutdown", (void (*)()) &bgfx::shutdown, "Shutdown bgfx library.\n\n \n C99 equivalent is `bgfx_shutdown`.\n\nC++: bgfx::shutdown() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::reset(unsigned int, unsigned int, unsigned int, enum bgfx::TextureFormat::Enum) file:bgfx.h line:1942
	M("bgfx").def("reset", [](unsigned int const & a0, unsigned int const & a1) -> void { return bgfx::reset(a0, a1); }, "", pybind11::arg("_width"), pybind11::arg("_height"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("reset", [](unsigned int const & a0, unsigned int const & a1, unsigned int const & a2) -> void { return bgfx::reset(a0, a1, a2); }, "", pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("reset", (void (*)(unsigned int, unsigned int, unsigned int, enum bgfx::TextureFormat::Enum)) &bgfx::reset, "Reset graphic settings and back-buffer size.\n\n \n Back-buffer width.\n \n\n Back-buffer height.\n \n\n See: `BGFX_RESET_*` for more info.\n   - `BGFX_RESET_NONE` - No reset flags.\n   - `BGFX_RESET_FULLSCREEN` - Not supported yet.\n   - `BGFX_RESET_MSAA_X[2/4/8/16]` - Enable 2, 4, 8 or 16 x MSAA.\n   - `BGFX_RESET_VSYNC` - Enable V-Sync.\n   - `BGFX_RESET_MAXANISOTROPY` - Turn on/off max anisotropy.\n   - `BGFX_RESET_CAPTURE` - Begin screen capture.\n   - `BGFX_RESET_FLUSH_AFTER_RENDER` - Flush rendering after submitting to GPU.\n   - `BGFX_RESET_FLIP_AFTER_RENDER` - This flag  specifies where flip\n     occurs. Default behavior is that flip occurs before rendering new\n     frame. This flag only has effect when `BGFX_CONFIG_MULTITHREADED=0`.\n   - `BGFX_RESET_SRGB_BACKBUFFER` - Enable sRGB backbuffer.\n \n\n Texture format. See: `TextureFormat::Enum`.\n\n \n This call doesn't actually change window size, it just\n   resizes back-buffer. Windowing code has to change window size.\n\n \n C99 equivalent is `bgfx_reset`.\n\nC++: bgfx::reset(unsigned int, unsigned int, unsigned int, enum bgfx::TextureFormat::Enum) --> void", pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_flags"), pybind11::arg("_format"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::begin(bool) file:bgfx.h line:1953
	M("bgfx").def("begin", []() -> bgfx::Encoder * { return bgfx::begin(); }, "", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("begin", (struct bgfx::Encoder * (*)(bool)) &bgfx::begin, "Begin submitting draw calls from thread.\n\n \n Explicitly request an encoder for a worker thread.\n\nC++: bgfx::begin(bool) --> struct bgfx::Encoder *", pybind11::return_value_policy::reference, pybind11::arg("_forThread"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::end(struct bgfx::Encoder *) file:bgfx.h line:1957
	M("bgfx").def("end", (void (*)(struct bgfx::Encoder *)) &bgfx::end, "End submitting draw calls from thread.\n\nC++: bgfx::end(struct bgfx::Encoder *) --> void", pybind11::arg("_encoder"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::frame(bool) file:bgfx.h line:1971
	M("bgfx").def("frame", []() -> unsigned int { return bgfx::frame(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("frame", (unsigned int (*)(bool)) &bgfx::frame, "Advance to next frame. When using multithreaded renderer, this call\n just swaps internal buffers, kicks render thread, and returns. In\n singlethreaded renderer this call does frame rendering.\n\n \n Capture frame with graphics debugger.\n\n \n Current frame number. This might be used in conjunction with\n   double/multi buffering data outside the library and passing it to\n   library via `bgfx::makeRef` calls.\n\n \n C99 equivalent is `bgfx_frame`.\n\nC++: bgfx::frame(bool) --> unsigned int", pybind11::arg("_capture"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::getRendererType() file:bgfx.h line:1980
	M("bgfx").def("get_renderer_type", (enum bgfx::RendererType::Enum (*)()) &bgfx::getRendererType, "Returns current renderer backend API type.\n\n \n\n   Library must be initialized.\n\n \n C99 equivalent is `bgfx_get_renderer_type`.\n\nC++: bgfx::getRendererType() --> enum bgfx::RendererType::Enum", pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::getCaps() file:bgfx.h line:1991
	M("bgfx").def("get_caps", (const struct bgfx::Caps * (*)()) &bgfx::getCaps, "Returns renderer capabilities.\n\n \n Pointer to static `bgfx::Caps` structure.\n\n \n\n   Library must be initialized.\n\n \n C99 equivalent is `bgfx_get_caps`.\n\nC++: bgfx::getCaps() --> const struct bgfx::Caps *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: bgfx_3.cpp
#include <bgfx.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_bgfx_3(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// bgfx::getStats() file:bgfx.h line:1998
	M("bgfx").def("get_stats", (const struct bgfx::Stats * (*)()) &bgfx::getStats, "Returns performance counters.\n\n \n Pointer returned is valid until `bgfx::frame` is called.\n \n\n C99 equivalent is `bgfx_get_stats`.\n\nC++: bgfx::getStats() --> const struct bgfx::Stats *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::alloc(unsigned int) file:bgfx.h line:2006
	M("bgfx").def("alloc", (const struct bgfx::Memory * (*)(unsigned int)) &bgfx::alloc, "Allocate buffer to pass to bgfx calls. Data will be freed inside bgfx.\n\n \n Size to allocate.\n\n \n C99 equivalent is `bgfx_alloc`.\n\nC++: bgfx::alloc(unsigned int) --> const struct bgfx::Memory *", pybind11::return_value_policy::reference, pybind11::arg("_size"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::copy(const void *, unsigned int) file:bgfx.h line:2015
	M("bgfx").def("copy", (const struct bgfx::Memory * (*)(const void *, unsigned int)) &bgfx::copy, "Allocate buffer and copy data into it. Data will be freed inside bgfx.\n\n \n Pointer to data to be copied.\n \n\n Size of data to be copied.\n\n \n C99 equivalent is `bgfx_copy`.\n\nC++: bgfx::copy(const void *, unsigned int) --> const struct bgfx::Memory *", pybind11::return_value_policy::reference, pybind11::arg("_data"), pybind11::arg("_size"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setDebug(unsigned int) file:bgfx.h line:2056
	M("bgfx").def("set_debug", (void (*)(unsigned int)) &bgfx::setDebug, "Set debug flags.\n\n \n Available flags:\n   - `BGFX_DEBUG_IFH` - Infinitely fast hardware. When this flag is set\n     all rendering calls will be skipped. This is useful when profiling\n     to quickly assess potential bottlenecks between CPU and GPU.\n   - `BGFX_DEBUG_PROFILER` - Enable profiler.\n   - `BGFX_DEBUG_STATS` - Display internal statistics.\n   - `BGFX_DEBUG_TEXT` - Display debug text.\n   - `BGFX_DEBUG_WIREFRAME` - Wireframe rendering. All rendering\n     primitives will be rendered as lines.\n\n \n C99 equivalent is `bgfx_set_debug`.\n\nC++: bgfx::setDebug(unsigned int) --> void", pybind11::arg("_debug"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::dbgTextClear(unsigned char, bool) file:bgfx.h line:2065
	M("bgfx").def("dbg_text_clear", []() -> void { return bgfx::dbgTextClear(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("dbg_text_clear", [](unsigned char const & a0) -> void { return bgfx::dbgTextClear(a0); }, "", pybind11::arg("_attr"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("dbg_text_clear", (void (*)(unsigned char, bool)) &bgfx::dbgTextClear, "Clear internal debug text buffer.\n\n \n Background color.\n \n\n Default 8x16 or 8x8 font.\n\n \n C99 equivalent is `bgfx_dbg_text_clear`.\n\nC++: bgfx::dbgTextClear(unsigned char, bool) --> void", pybind11::arg("_attr"), pybind11::arg("_small"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::dbgTextPrintf(unsigned short, unsigned short, unsigned char, const char *) file:bgfx.h line:2079
	M("bgfx").def("dbg_text_printf", [](unsigned short const & a0, unsigned short const & a1, unsigned char const & a2, const char * a3) -> void { return bgfx::dbgTextPrintf(a0, a1, a2, a3); }, "", pybind11::arg("_x"), pybind11::arg("_y"), pybind11::arg("_attr"), pybind11::arg("_format"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::dbgTextImage(unsigned short, unsigned short, unsigned short, unsigned short, const void *, unsigned short) file:bgfx.h line:2114
	M("bgfx").def("dbg_text_image", (void (*)(unsigned short, unsigned short, unsigned short, unsigned short, const void *, unsigned short)) &bgfx::dbgTextImage, "Draw image into internal debug text buffer.\n\n \n _y 2D position from top-left.\n \n\n _height  Image width and height.\n \n\n  Raw image data (character/attribute raw encoding).\n \n\n Image pitch in bytes.\n\n \n C99 equivalent is `bgfx_dbg_text_image`.\n\nC++: bgfx::dbgTextImage(unsigned short, unsigned short, unsigned short, unsigned short, const void *, unsigned short) --> void", pybind11::arg("_x"), pybind11::arg("_y"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_data"), pybind11::arg("_pitch"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::createIndexBuffer(const struct bgfx::Memory *, unsigned short) file:bgfx.h line:2141
	M("bgfx").def("create_index_buffer", [](const struct bgfx::Memory * a0) -> bgfx::IndexBufferHandle { return bgfx::createIndexBuffer(a0); }, "", pybind11::arg("_mem"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_index_buffer", (struct bgfx::IndexBufferHandle (*)(const struct bgfx::Memory *, unsigned short)) &bgfx::createIndexBuffer, "Create static index buffer.\n\n \n Index buffer data.\n \n\n Buffer creation flags.\n   - `BGFX_BUFFER_NONE` - No flags.\n   - `BGFX_BUFFER_COMPUTE_READ` - Buffer will be read from by compute shader.\n   - `BGFX_BUFFER_COMPUTE_WRITE` - Buffer will be written into by compute shader. When buffer\n       is created with `BGFX_BUFFER_COMPUTE_WRITE` flag it cannot be updated from CPU.\n   - `BGFX_BUFFER_COMPUTE_READ_WRITE` - Buffer will be used for read/write by compute shader.\n   - `BGFX_BUFFER_ALLOW_RESIZE` - Buffer will resize on buffer update if a different amount of\n       data is passed. If this flag is not specified, and more data is passed on update, the buffer\n       will be trimmed to fit the existing buffer size. This flag has effect only on dynamic\n       buffers.\n   - `BGFX_BUFFER_INDEX32` - Buffer is using 32-bit indices. This flag has effect only on\n       index buffers.\n\n \n C99 equivalent is `bgfx_create_index_buffer`.\n\nC++: bgfx::createIndexBuffer(const struct bgfx::Memory *, unsigned short) --> struct bgfx::IndexBufferHandle", pybind11::arg("_mem"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setName(struct bgfx::IndexBufferHandle, const char *, int) file:bgfx.h line:2155
	M("bgfx").def("set_name", [](struct bgfx::IndexBufferHandle const & a0, const char * a1) -> void { return bgfx::setName(a0, a1); }, "", pybind11::arg("_handle"), pybind11::arg("_name"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_name", (void (*)(struct bgfx::IndexBufferHandle, const char *, int)) &bgfx::setName, "Set static index buffer debug name.\n\n \n Static index buffer handle.\n \n\n Static index buffer name.\n \n\n Static index buffer name length (if length is INT32_MAX, it's expected\n   that _name is zero terminated string.\n\n \n C99 equivalent is `bgfx_set_index_buffer_name`.\n\nC++: bgfx::setName(struct bgfx::IndexBufferHandle, const char *, int) --> void", pybind11::arg("_handle"), pybind11::arg("_name"), pybind11::arg("_len"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::destroy(struct bgfx::IndexBufferHandle) file:bgfx.h line:2167
	M("bgfx").def("destroy", (void (*)(struct bgfx::IndexBufferHandle)) &bgfx::destroy, "Destroy static index buffer.\n\n \n Static index buffer handle.\n\n \n C99 equivalent is `bgfx_destroy_index_buffer`.\n\nC++: bgfx::destroy(struct bgfx::IndexBufferHandle) --> void", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::createVertexLayout(const struct bgfx::VertexLayout &) file:bgfx.h line:2173
	M("bgfx").def("create_vertex_layout", (struct bgfx::VertexLayoutHandle (*)(const struct bgfx::VertexLayout &)) &bgfx::createVertexLayout, "Create vertex layout.\n\n \n C99 equivalent is `bgfx_create_vertex_layout`.\n\nC++: bgfx::createVertexLayout(const struct bgfx::VertexLayout &) --> struct bgfx::VertexLayoutHandle", pybind11::arg("_layout"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::destroy(struct bgfx::VertexLayoutHandle) file:bgfx.h line:2179
	M("bgfx").def("destroy", (void (*)(struct bgfx::VertexLayoutHandle)) &bgfx::destroy, "Destroy vertex layout.\n\n \n C99 equivalent is `bgfx_destroy_vertex_layout`.\n\nC++: bgfx::destroy(struct bgfx::VertexLayoutHandle) --> void", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::createVertexBuffer(const struct bgfx::Memory *, const struct bgfx::VertexLayout &, unsigned short) file:bgfx.h line:2201
	M("bgfx").def("create_vertex_buffer", [](const struct bgfx::Memory * a0, const struct bgfx::VertexLayout & a1) -> bgfx::VertexBufferHandle { return bgfx::createVertexBuffer(a0, a1); }, "", pybind11::arg("_mem"), pybind11::arg("_layout"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_vertex_buffer", (struct bgfx::VertexBufferHandle (*)(const struct bgfx::Memory *, const struct bgfx::VertexLayout &, unsigned short)) &bgfx::createVertexBuffer, "Create static vertex buffer.\n\n \n Vertex buffer data.\n \n\n Vertex layout.\n \n\n Buffer creation flags.\n   - `BGFX_BUFFER_NONE` - No flags.\n   - `BGFX_BUFFER_COMPUTE_READ` - Buffer will be read from by compute shader.\n   - `BGFX_BUFFER_COMPUTE_WRITE` - Buffer will be written into by compute shader. When buffer\n       is created with `BGFX_BUFFER_COMPUTE_WRITE` flag it cannot be updated from CPU.\n   - `BGFX_BUFFER_COMPUTE_READ_WRITE` - Buffer will be used for read/write by compute shader.\n   - `BGFX_BUFFER_ALLOW_RESIZE` - Buffer will resize on buffer update if a different amount of\n       data is passed. If this flag is not specified, and more data is passed on update, the buffer\n       will be trimmed to fit the existing buffer size. This flag has effect only on dynamic\n       buffers.\n   - `BGFX_BUFFER_INDEX32` - Buffer is using 32-bit indices. This flag has effect only on\n       index buffers.\n \n\n Static vertex buffer handle.\n\n \n C99 equivalent is `bgfx_create_vertex_buffer`.\n\nC++: bgfx::createVertexBuffer(const struct bgfx::Memory *, const struct bgfx::VertexLayout &, unsigned short) --> struct bgfx::VertexBufferHandle", pybind11::arg("_mem"), pybind11::arg("_layout"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setName(struct bgfx::VertexBufferHandle, const char *, int) file:bgfx.h line:2216
	M("bgfx").def("set_name", [](struct bgfx::VertexBufferHandle const & a0, const char * a1) -> void { return bgfx::setName(a0, a1); }, "", pybind11::arg("_handle"), pybind11::arg("_name"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_name", (void (*)(struct bgfx::VertexBufferHandle, const char *, int)) &bgfx::setName, "Set static vertex buffer debug name.\n\n \n Static vertex buffer handle.\n \n\n Static vertex buffer name.\n \n\n Static vertex buffer name length (if length is INT32_MAX, it's expected\n   that _name is zero terminated string.\n\n \n C99 equivalent is `bgfx_set_vertex_buffer_name`.\n\nC++: bgfx::setName(struct bgfx::VertexBufferHandle, const char *, int) --> void", pybind11::arg("_handle"), pybind11::arg("_name"), pybind11::arg("_len"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::destroy(struct bgfx::VertexBufferHandle) file:bgfx.h line:2228
	M("bgfx").def("destroy", (void (*)(struct bgfx::VertexBufferHandle)) &bgfx::destroy, "Destroy static vertex buffer.\n\n \n Static vertex buffer handle.\n\n \n C99 equivalent is `bgfx_destroy_vertex_buffer`.\n\nC++: bgfx::destroy(struct bgfx::VertexBufferHandle) --> void", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::createDynamicIndexBuffer(unsigned int, unsigned short) file:bgfx.h line:2249
	M("bgfx").def("create_dynamic_index_buffer", [](unsigned int const & a0) -> bgfx::DynamicIndexBufferHandle { return bgfx::createDynamicIndexBuffer(a0); }, "", pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_dynamic_index_buffer", (struct bgfx::DynamicIndexBufferHandle (*)(unsigned int, unsigned short)) &bgfx::createDynamicIndexBuffer, "Create empty dynamic index buffer.\n\n \n Number of indices.\n \n\n Buffer creation flags.\n   - `BGFX_BUFFER_NONE` - No flags.\n   - `BGFX_BUFFER_COMPUTE_READ` - Buffer will be read from by compute shader.\n   - `BGFX_BUFFER_COMPUTE_WRITE` - Buffer will be written into by compute shader. When buffer\n       is created with `BGFX_BUFFER_COMPUTE_WRITE` flag it cannot be updated from CPU.\n   - `BGFX_BUFFER_COMPUTE_READ_WRITE` - Buffer will be used for read/write by compute shader.\n   - `BGFX_BUFFER_ALLOW_RESIZE` - Buffer will resize on buffer update if a different amount of\n       data is passed. If this flag is not specified, and more data is passed on update, the buffer\n       will be trimmed to fit the existing buffer size. This flag has effect only on dynamic\n       buffers.\n   - `BGFX_BUFFER_INDEX32` - Buffer is using 32-bit indices. This flag has effect only on\n       index buffers.\n \n\n Dynamic index buffer handle.\n\n \n C99 equivalent is `bgfx_create_dynamic_index_buffer`.\n\nC++: bgfx::createDynamicIndexBuffer(unsigned int, unsigned short) --> struct bgfx::DynamicIndexBufferHandle", pybind11::arg("_num"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::createDynamicIndexBuffer(const struct bgfx::Memory *, unsigned short) file:bgfx.h line:2273
	M("bgfx").def("create_dynamic_index_buffer", [](const struct bgfx::Memory * a0) -> bgfx::DynamicIndexBufferHandle { return bgfx::createDynamicIndexBuffer(a0); }, "", pybind11::arg("_mem"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_dynamic_index_buffer", (struct bgfx::DynamicIndexBufferHandle (*)(const struct bgfx::Memory *, unsigned short)) &bgfx::createDynamicIndexBuffer, "Create dynamic index buffer and initialized it.\n\n \n Index buffer data.\n \n\n Buffer creation flags.\n   - `BGFX_BUFFER_NONE` - No flags.\n   - `BGFX_BUFFER_COMPUTE_READ` - Buffer will be read from by compute shader.\n   - `BGFX_BUFFER_COMPUTE_WRITE` - Buffer will be written into by compute shader. When buffer\n       is created with `BGFX_BUFFER_COMPUTE_WRITE` flag it cannot be updated from CPU.\n   - `BGFX_BUFFER_COMPUTE_READ_WRITE` - Buffer will be used for read/write by compute shader.\n   - `BGFX_BUFFER_ALLOW_RESIZE` - Buffer will resize on buffer update if a different amount of\n       data is passed. If this flag is not specified, and more data is passed on update, the buffer\n       will be trimmed to fit the existing buffer size. This flag has effect only on dynamic\n       buffers.\n   - `BGFX_BUFFER_INDEX32` - Buffer is using 32-bit indices. This flag has effect only on\n       index buffers.\n \n\n Dynamic index buffer handle.\n\n \n C99 equivalent is `bgfx_create_dynamic_index_buffer_mem`.\n\nC++: bgfx::createDynamicIndexBuffer(const struct bgfx::Memory *, unsigned short) --> struct bgfx::DynamicIndexBufferHandle", pybind11::arg("_mem"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::update(struct bgfx::DynamicIndexBufferHandle, unsigned int, const struct bgfx::Memory *) file:bgfx.h line:2286
	M("bgfx").def("update", (void (*)(struct bgfx::DynamicIndexBufferHandle, unsigned int, const struct bgfx::Memory *)) &bgfx::update, "Update dynamic index buffer.\n\n \n Dynamic index buffer handle.\n \n\n Start index.\n \n\n Index buffer data.\n\n \n C99 equivalent is `bgfx_update_dynamic_index_buffer`.\n\nC++: bgfx::update(struct bgfx::DynamicIndexBufferHandle, unsigned int, const struct bgfx::Memory *) --> void", pybind11::arg("_handle"), pybind11::arg("_startIndex"), pybind11::arg("_mem"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::destroy(struct bgfx::DynamicIndexBufferHandle) file:bgfx.h line:2298
	M("bgfx").def("destroy", (void (*)(struct bgfx::DynamicIndexBufferHandle)) &bgfx::destroy, "Destroy dynamic index buffer.\n\n \n Dynamic index buffer handle.\n\n \n C99 equivalent is `bgfx_destroy_dynamic_index_buffer`.\n\nC++: bgfx::destroy(struct bgfx::DynamicIndexBufferHandle) --> void", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::createDynamicVertexBuffer(unsigned int, const struct bgfx::VertexLayout &, unsigned short) file:bgfx.h line:2320
	M("bgfx").def("create_dynamic_vertex_buffer", [](unsigned int const & a0, const struct bgfx::VertexLayout & a1) -> bgfx::DynamicVertexBufferHandle { return bgfx::createDynamicVertexBuffer(a0, a1); }, "", pybind11::arg("_num"), pybind11::arg("_layout"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_dynamic_vertex_buffer", (struct bgfx::DynamicVertexBufferHandle (*)(unsigned int, const struct bgfx::VertexLayout &, unsigned short)) &bgfx::createDynamicVertexBuffer, "Create empty dynamic vertex buffer.\n\n \n Number of vertices.\n \n\n Vertex layout.\n \n\n Buffer creation flags.\n   - `BGFX_BUFFER_NONE` - No flags.\n   - `BGFX_BUFFER_COMPUTE_READ` - Buffer will be read from by compute shader.\n   - `BGFX_BUFFER_COMPUTE_WRITE` - Buffer will be written into by compute shader. When buffer\n       is created with `BGFX_BUFFER_COMPUTE_WRITE` flag it cannot be updated from CPU.\n   - `BGFX_BUFFER_COMPUTE_READ_WRITE` - Buffer will be used for read/write by compute shader.\n   - `BGFX_BUFFER_ALLOW_RESIZE` - Buffer will resize on buffer update if a different amount of\n       data is passed. If this flag is not specified, and more data is passed on update, the buffer\n       will be trimmed to fit the existing buffer size. This flag has effect only on dynamic\n       buffers.\n   - `BGFX_BUFFER_INDEX32` - Buffer is using 32-bit indices. This flag has effect only on\n       index buffers.\n \n\n Dynamic vertex buffer handle.\n\n \n C99 equivalent is `bgfx_create_dynamic_vertex_buffer`.\n\nC++: bgfx::createDynamicVertexBuffer(unsigned int, const struct bgfx::VertexLayout &, unsigned short) --> struct bgfx::DynamicVertexBufferHandle", pybind11::arg("_num"), pybind11::arg("_layout"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: bgfx_4.cpp
#include <bgfx.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_bgfx_4(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// bgfx::createDynamicVertexBuffer(const struct bgfx::Memory *, const struct bgfx::VertexLayout &, unsigned short) file:bgfx.h line:2346
	M("bgfx").def("create_dynamic_vertex_buffer", [](const struct bgfx::Memory * a0, const struct bgfx::VertexLayout & a1) -> bgfx::DynamicVertexBufferHandle { return bgfx::createDynamicVertexBuffer(a0, a1); }, "", pybind11::arg("_mem"), pybind11::arg("_layout"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_dynamic_vertex_buffer", (struct bgfx::DynamicVertexBufferHandle (*)(const struct bgfx::Memory *, const struct bgfx::VertexLayout &, unsigned short)) &bgfx::createDynamicVertexBuffer, "Create dynamic vertex buffer and initialize it.\n\n \n Vertex buffer data.\n \n\n Vertex layout.\n \n\n Buffer creation flags.\n   - `BGFX_BUFFER_NONE` - No flags.\n   - `BGFX_BUFFER_COMPUTE_READ` - Buffer will be read from by compute shader.\n   - `BGFX_BUFFER_COMPUTE_WRITE` - Buffer will be written into by compute shader. When buffer\n       is created with `BGFX_BUFFER_COMPUTE_WRITE` flag it cannot be updated from CPU.\n   - `BGFX_BUFFER_COMPUTE_READ_WRITE` - Buffer will be used for read/write by compute shader.\n   - `BGFX_BUFFER_ALLOW_RESIZE` - Buffer will resize on buffer update if a different amount of\n       data is passed. If this flag is not specified, and more data is passed on update, the buffer\n       will be trimmed to fit the existing buffer size. This flag has effect only on dynamic\n       buffers.\n   - `BGFX_BUFFER_INDEX32` - Buffer is using 32-bit indices. This flag has effect only on\n       index buffers.\n \n\n Dynamic vertex buffer handle.\n\n \n C99 equivalent is `bgfx_create_dynamic_vertex_buffer_mem`.\n\nC++: bgfx::createDynamicVertexBuffer(const struct bgfx::Memory *, const struct bgfx::VertexLayout &, unsigned short) --> struct bgfx::DynamicVertexBufferHandle", pybind11::arg("_mem"), pybind11::arg("_layout"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::update(struct bgfx::DynamicVertexBufferHandle, unsigned int, const struct bgfx::Memory *) file:bgfx.h line:2360
	M("bgfx").def("update", (void (*)(struct bgfx::DynamicVertexBufferHandle, unsigned int, const struct bgfx::Memory *)) &bgfx::update, "Update dynamic vertex buffer.\n\n \n Dynamic vertex buffer handle.\n \n\n Start vertex.\n \n\n Vertex buffer data.\n\n \n C99 equivalent is `bgfx_update_dynamic_vertex_buffer`.\n\nC++: bgfx::update(struct bgfx::DynamicVertexBufferHandle, unsigned int, const struct bgfx::Memory *) --> void", pybind11::arg("_handle"), pybind11::arg("_startVertex"), pybind11::arg("_mem"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::destroy(struct bgfx::DynamicVertexBufferHandle) file:bgfx.h line:2372
	M("bgfx").def("destroy", (void (*)(struct bgfx::DynamicVertexBufferHandle)) &bgfx::destroy, "Destroy dynamic vertex buffer.\n\n \n Dynamic vertex buffer handle.\n\n \n C99 equivalent is `bgfx_destroy_dynamic_vertex_buffer`.\n\nC++: bgfx::destroy(struct bgfx::DynamicVertexBufferHandle) --> void", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::getAvailTransientIndexBuffer(unsigned int) file:bgfx.h line:2380
	M("bgfx").def("get_avail_transient_index_buffer", (unsigned int (*)(unsigned int)) &bgfx::getAvailTransientIndexBuffer, "Returns number of requested or maximum available indices.\n\n \n Number of required indices.\n\n \n C99 equivalent is `bgfx_get_avail_transient_index_buffer`.\n\nC++: bgfx::getAvailTransientIndexBuffer(unsigned int) --> unsigned int", pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::getAvailTransientVertexBuffer(unsigned int, const struct bgfx::VertexLayout &) file:bgfx.h line:2389
	M("bgfx").def("get_avail_transient_vertex_buffer", (unsigned int (*)(unsigned int, const struct bgfx::VertexLayout &)) &bgfx::getAvailTransientVertexBuffer, "Returns number of requested or maximum available vertices.\n\n \n Number of required vertices.\n \n\n Vertex layout.\n\n \n C99 equivalent is `bgfx_get_avail_transient_vertex_buffer`.\n\nC++: bgfx::getAvailTransientVertexBuffer(unsigned int, const struct bgfx::VertexLayout &) --> unsigned int", pybind11::arg("_num"), pybind11::arg("_layout"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::getAvailInstanceDataBuffer(unsigned int, unsigned short) file:bgfx.h line:2401
	M("bgfx").def("get_avail_instance_data_buffer", (unsigned int (*)(unsigned int, unsigned short)) &bgfx::getAvailInstanceDataBuffer, "Returns number of requested or maximum available instance buffer slots.\n\n \n Number of required instances.\n \n\n Stride per instance.\n\n \n C99 equivalent is `bgfx_get_avail_instance_data_buffer`.\n\nC++: bgfx::getAvailInstanceDataBuffer(unsigned int, unsigned short) --> unsigned int", pybind11::arg("_num"), pybind11::arg("_stride"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::allocTransientIndexBuffer(struct bgfx::TransientIndexBuffer *, unsigned int) file:bgfx.h line:2418
	M("bgfx").def("alloc_transient_index_buffer", (void (*)(struct bgfx::TransientIndexBuffer *, unsigned int)) &bgfx::allocTransientIndexBuffer, "Allocate transient index buffer.\n\n \n TransientIndexBuffer structure is filled and is valid\n   for the duration of frame, and it can be reused for multiple draw\n   calls.\n \n\n Number of indices to allocate.\n\n \n\n   Only 16-bit index buffer is supported.\n\n \n C99 equivalent is `bgfx_alloc_transient_index_buffer`.\n\nC++: bgfx::allocTransientIndexBuffer(struct bgfx::TransientIndexBuffer *, unsigned int) --> void", pybind11::arg("_tib"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::allocTransientVertexBuffer(struct bgfx::TransientVertexBuffer *, unsigned int, const struct bgfx::VertexLayout &) file:bgfx.h line:2433
	M("bgfx").def("alloc_transient_vertex_buffer", (void (*)(struct bgfx::TransientVertexBuffer *, unsigned int, const struct bgfx::VertexLayout &)) &bgfx::allocTransientVertexBuffer, "Allocate transient vertex buffer.\n\n \n TransientVertexBuffer structure is filled and is valid\n   for the duration of frame, and it can be reused for multiple draw\n   calls.\n \n\n Number of vertices to allocate.\n \n\n Vertex layout.\n\n \n C99 equivalent is `bgfx_alloc_transient_vertex_buffer`.\n\nC++: bgfx::allocTransientVertexBuffer(struct bgfx::TransientVertexBuffer *, unsigned int, const struct bgfx::VertexLayout &) --> void", pybind11::arg("_tvb"), pybind11::arg("_num"), pybind11::arg("_layout"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::allocTransientBuffers(struct bgfx::TransientVertexBuffer *, const struct bgfx::VertexLayout &, unsigned int, struct bgfx::TransientIndexBuffer *, unsigned int) file:bgfx.h line:2448
	M("bgfx").def("alloc_transient_buffers", (bool (*)(struct bgfx::TransientVertexBuffer *, const struct bgfx::VertexLayout &, unsigned int, struct bgfx::TransientIndexBuffer *, unsigned int)) &bgfx::allocTransientBuffers, "Check for required space and allocate transient vertex and index\n buffers. If both space requirements are satisfied function returns\n true.\n\n \n\n   Only 16-bit index buffer is supported.\n\n \n C99 equivalent is `bgfx_alloc_transient_buffers`.\n\nC++: bgfx::allocTransientBuffers(struct bgfx::TransientVertexBuffer *, const struct bgfx::VertexLayout &, unsigned int, struct bgfx::TransientIndexBuffer *, unsigned int) --> bool", pybind11::arg("_tvb"), pybind11::arg("_layout"), pybind11::arg("_numVertices"), pybind11::arg("_tib"), pybind11::arg("_numIndices"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::allocInstanceDataBuffer(struct bgfx::InstanceDataBuffer *, unsigned int, unsigned short) file:bgfx.h line:2466
	M("bgfx").def("alloc_instance_data_buffer", (void (*)(struct bgfx::InstanceDataBuffer *, unsigned int, unsigned short)) &bgfx::allocInstanceDataBuffer, "Allocate instance data buffer.\n\n \n InstanceDataBuffer structure is filled and is valid\n   for duration of frame, and it can be reused for multiple draw\n   calls.\n \n\n Number of instances.\n \n\n Instance stride. Must be multiple of 16.\n\n \n C99 equivalent is `bgfx_alloc_instance_data_buffer`.\n\nC++: bgfx::allocInstanceDataBuffer(struct bgfx::InstanceDataBuffer *, unsigned int, unsigned short) --> void", pybind11::arg("_idb"), pybind11::arg("_num"), pybind11::arg("_stride"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::createIndirectBuffer(unsigned int) file:bgfx.h line:2479
	M("bgfx").def("create_indirect_buffer", (struct bgfx::IndirectBufferHandle (*)(unsigned int)) &bgfx::createIndirectBuffer, "Create draw indirect buffer.\n\n \n Number of indirect calls.\n \n\n Indirect buffer handle.\n\n \n C99 equivalent is `bgfx_create_indirect_buffer`.\n\nC++: bgfx::createIndirectBuffer(unsigned int) --> struct bgfx::IndirectBufferHandle", pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::destroy(struct bgfx::IndirectBufferHandle) file:bgfx.h line:2487
	M("bgfx").def("destroy", (void (*)(struct bgfx::IndirectBufferHandle)) &bgfx::destroy, "Destroy draw indirect buffer.\n\n \n Indirect buffer handle.\n\n \n C99 equivalent is `bgfx_destroy_indirect_buffer`.\n\nC++: bgfx::destroy(struct bgfx::IndirectBufferHandle) --> void", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::createShader(const struct bgfx::Memory *) file:bgfx.h line:2493
	M("bgfx").def("create_shader", (struct bgfx::ShaderHandle (*)(const struct bgfx::Memory *)) &bgfx::createShader, "Create shader from memory buffer.\n\n \n C99 equivalent is `bgfx_create_shader`.\n\nC++: bgfx::createShader(const struct bgfx::Memory *) --> struct bgfx::ShaderHandle", pybind11::arg("_mem"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::getShaderUniforms(struct bgfx::ShaderHandle, struct bgfx::UniformHandle *, unsigned short) file:bgfx.h line:2507
	M("bgfx").def("get_shader_uniforms", [](struct bgfx::ShaderHandle const & a0) -> unsigned short { return bgfx::getShaderUniforms(a0); }, "", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("get_shader_uniforms", [](struct bgfx::ShaderHandle const & a0, struct bgfx::UniformHandle * a1) -> unsigned short { return bgfx::getShaderUniforms(a0, a1); }, "", pybind11::arg("_handle"), pybind11::arg("_uniforms"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("get_shader_uniforms", (unsigned short (*)(struct bgfx::ShaderHandle, struct bgfx::UniformHandle *, unsigned short)) &bgfx::getShaderUniforms, "Returns the number of uniforms and uniform handles used inside a shader.\n\n \n Shader handle.\n \n\n UniformHandle array where data will be stored.\n \n\n Maximum capacity of array.\n \n\n Number of uniforms used by shader.\n\n \n\n   Only non-predefined uniforms are returned.\n\n \n C99 equivalent is `bgfx_get_shader_uniforms`.\n\nC++: bgfx::getShaderUniforms(struct bgfx::ShaderHandle, struct bgfx::UniformHandle *, unsigned short) --> unsigned short", pybind11::arg("_handle"), pybind11::arg("_uniforms"), pybind11::arg("_max"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setName(struct bgfx::ShaderHandle, const char *, int) file:bgfx.h line:2522
	M("bgfx").def("set_name", [](struct bgfx::ShaderHandle const & a0, const char * a1) -> void { return bgfx::setName(a0, a1); }, "", pybind11::arg("_handle"), pybind11::arg("_name"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_name", (void (*)(struct bgfx::ShaderHandle, const char *, int)) &bgfx::setName, "Set shader debug name.\n\n \n Shader handle.\n \n\n Shader name.\n \n\n Shader name length (if length is INT32_MAX, it's expected\n   that _name is zero terminated string.\n\n \n C99 equivalent is `bgfx_set_shader_name`.\n\nC++: bgfx::setName(struct bgfx::ShaderHandle, const char *, int) --> void", pybind11::arg("_handle"), pybind11::arg("_name"), pybind11::arg("_len"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::destroy(struct bgfx::ShaderHandle) file:bgfx.h line:2535
	M("bgfx").def("destroy", (void (*)(struct bgfx::ShaderHandle)) &bgfx::destroy, "Destroy shader. Once a shader program is created with _handle,\n it is safe to destroy that shader.\n\n \n Shader handle.\n\n \n C99 equivalent is `bgfx_destroy_shader`.\n\nC++: bgfx::destroy(struct bgfx::ShaderHandle) --> void", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::createProgram(struct bgfx::ShaderHandle, struct bgfx::ShaderHandle, bool) file:bgfx.h line:2548
	M("bgfx").def("create_program", [](struct bgfx::ShaderHandle const & a0, struct bgfx::ShaderHandle const & a1) -> bgfx::ProgramHandle { return bgfx::createProgram(a0, a1); }, "", pybind11::arg("_vsh"), pybind11::arg("_fsh"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_program", (struct bgfx::ProgramHandle (*)(struct bgfx::ShaderHandle, struct bgfx::ShaderHandle, bool)) &bgfx::createProgram, "Create program with vertex and fragment shaders.\n\n \n Vertex shader.\n \n\n Fragment shader.\n \n\n If true, shaders will be destroyed when\n   program is destroyed.\n \n\n Program handle if vertex shader output and fragment shader\n   input are matching, otherwise returns invalid program handle.\n\n \n C99 equivalent is `bgfx_create_program`.\n\nC++: bgfx::createProgram(struct bgfx::ShaderHandle, struct bgfx::ShaderHandle, bool) --> struct bgfx::ProgramHandle", pybind11::arg("_vsh"), pybind11::arg("_fsh"), pybind11::arg("_destroyShaders"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::createProgram(struct bgfx::ShaderHandle, bool) file:bgfx.h line:2563
	M("bgfx").def("create_program", [](struct bgfx::ShaderHandle const & a0) -> bgfx::ProgramHandle { return bgfx::createProgram(a0); }, "", pybind11::arg("_csh"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_program", (struct bgfx::ProgramHandle (*)(struct bgfx::ShaderHandle, bool)) &bgfx::createProgram, "Create program with compute shader.\n\n \n Compute shader.\n \n\n If true, shader will be destroyed when\n   program is destroyed.\n \n\n Program handle.\n\n \n C99 equivalent is `bgfx_create_compute_program`.\n\nC++: bgfx::createProgram(struct bgfx::ShaderHandle, bool) --> struct bgfx::ProgramHandle", pybind11::arg("_csh"), pybind11::arg("_destroyShader"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::destroy(struct bgfx::ProgramHandle) file:bgfx.h line:2574
	M("bgfx").def("destroy", (void (*)(struct bgfx::ProgramHandle)) &bgfx::destroy, "Destroy program.\n\n \n Program handle.\n\n \n C99 equivalent is `bgfx_destroy_program`.\n\nC++: bgfx::destroy(struct bgfx::ProgramHandle) --> void", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::isTextureValid(unsigned short, bool, unsigned short, enum bgfx::TextureFormat::Enum, uint64_t) file:bgfx.h line:2587
	M("bgfx").def("is_texture_valid", (bool (*)(unsigned short, bool, unsigned short, enum bgfx::TextureFormat::Enum, uint64_t)) &bgfx::isTextureValid, "Validate texture parameters.\n\n \n Depth dimension of volume texture.\n \n\n Indicates that texture contains cubemap.\n \n\n Number of layers in texture array.\n \n\n Texture format. See: `TextureFormat::Enum`.\n \n\n Texture flags. See `BGFX_TEXTURE_*`.\n \n\n True if texture can be successfully created.\n\n \n C99 equivalent is `bgfx_is_texture_valid`.\n\nC++: bgfx::isTextureValid(unsigned short, bool, unsigned short, enum bgfx::TextureFormat::Enum, uint64_t) --> bool", pybind11::arg("_depth"), pybind11::arg("_cubeMap"), pybind11::arg("_numLayers"), pybind11::arg("_format"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::calcTextureSize(struct bgfx::TextureInfo &, unsigned short, unsigned short, unsigned short, bool, bool, unsigned short, enum bgfx::TextureFormat::Enum) file:bgfx.h line:2608
	M("bgfx").def("calc_texture_size", (void (*)(struct bgfx::TextureInfo &, unsigned short, unsigned short, unsigned short, bool, bool, unsigned short, enum bgfx::TextureFormat::Enum)) &bgfx::calcTextureSize, "Calculate amount of memory required for texture.\n\n \n Resulting texture info structure. See: `TextureInfo`.\n \n\n Width.\n \n\n Height.\n \n\n Depth dimension of volume texture.\n \n\n Indicates that texture contains cubemap.\n \n\n Indicates that texture contains full mip-map chain.\n \n\n Number of layers in texture array.\n \n\n Texture format. See: `TextureFormat::Enum`.\n\n \n C99 equivalent is `bgfx_calc_texture_size`.\n\nC++: bgfx::calcTextureSize(struct bgfx::TextureInfo &, unsigned short, unsigned short, unsigned short, bool, bool, unsigned short, enum bgfx::TextureFormat::Enum) --> void", pybind11::arg("_info"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_depth"), pybind11::arg("_cubeMap"), pybind11::arg("_hasMips"), pybind11::arg("_numLayers"), pybind11::arg("_format"), pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: bgfx_5.cpp
#include <bgfx.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_bgfx_5(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// bgfx::createTexture(const struct bgfx::Memory *, uint64_t, unsigned char, struct bgfx::TextureInfo *) file:bgfx.h line:2635
	M("bgfx").def("create_texture", [](const struct bgfx::Memory * a0) -> bgfx::TextureHandle { return bgfx::createTexture(a0); }, "", pybind11::arg("_mem"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_texture", [](const struct bgfx::Memory * a0, uint64_t const & a1) -> bgfx::TextureHandle { return bgfx::createTexture(a0, a1); }, "", pybind11::arg("_mem"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_texture", [](const struct bgfx::Memory * a0, uint64_t const & a1, unsigned char const & a2) -> bgfx::TextureHandle { return bgfx::createTexture(a0, a1, a2); }, "", pybind11::arg("_mem"), pybind11::arg("_flags"), pybind11::arg("_skip"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_texture", (struct bgfx::TextureHandle (*)(const struct bgfx::Memory *, uint64_t, unsigned char, struct bgfx::TextureInfo *)) &bgfx::createTexture, "Create texture from memory buffer.\n\n \n DDS, KTX or PVR texture data.\n \n\n Texture creation (see `BGFX_TEXTURE_*`.), and sampler (see `BGFX_SAMPLER_*`)\n   flags. Default texture sampling mode is linear, and wrap mode is repeat.\n   - `BGFX_SAMPLER_[U/V/W]_[MIRROR/CLAMP]` - Mirror or clamp to edge wrap\n     mode.\n   - `BGFX_SAMPLER_[MIN/MAG/MIP]_[POINT/ANISOTROPIC]` - Point or anisotropic\n     sampling.\n\n \n Skip top level mips when parsing texture.\n \n\n When non-`NULL` is specified it returns parsed texture information.\n \n\n Texture handle.\n\n \n C99 equivalent is `bgfx_create_texture`.\n\nC++: bgfx::createTexture(const struct bgfx::Memory *, uint64_t, unsigned char, struct bgfx::TextureInfo *) --> struct bgfx::TextureHandle", pybind11::arg("_mem"), pybind11::arg("_flags"), pybind11::arg("_skip"), pybind11::arg("_info"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::createTexture2D(unsigned short, unsigned short, bool, unsigned short, enum bgfx::TextureFormat::Enum, uint64_t, const struct bgfx::Memory *) file:bgfx.h line:2663
	M("bgfx").def("create_texture2d", [](unsigned short const & a0, unsigned short const & a1, bool const & a2, unsigned short const & a3, enum bgfx::TextureFormat::Enum const & a4) -> bgfx::TextureHandle { return bgfx::createTexture2D(a0, a1, a2, a3, a4); }, "", pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_hasMips"), pybind11::arg("_numLayers"), pybind11::arg("_format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_texture2d", [](unsigned short const & a0, unsigned short const & a1, bool const & a2, unsigned short const & a3, enum bgfx::TextureFormat::Enum const & a4, uint64_t const & a5) -> bgfx::TextureHandle { return bgfx::createTexture2D(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_hasMips"), pybind11::arg("_numLayers"), pybind11::arg("_format"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_texture2d", (struct bgfx::TextureHandle (*)(unsigned short, unsigned short, bool, unsigned short, enum bgfx::TextureFormat::Enum, uint64_t, const struct bgfx::Memory *)) &bgfx::createTexture2D, "Create 2D texture.\n\n \n Width.\n \n\n Height.\n \n\n Indicates that texture contains full mip-map chain.\n \n\n Number of layers in texture array. Must be 1 if caps\n   `BGFX_CAPS_TEXTURE_2D_ARRAY` flag is not set.\n \n\n Texture format. See: `TextureFormat::Enum`.\n \n\n Texture creation (see `BGFX_TEXTURE_*`.), and sampler (see `BGFX_SAMPLER_*`)\n   flags. Default texture sampling mode is linear, and wrap mode is repeat.\n   - `BGFX_SAMPLER_[U/V/W]_[MIRROR/CLAMP]` - Mirror or clamp to edge wrap\n     mode.\n   - `BGFX_SAMPLER_[MIN/MAG/MIP]_[POINT/ANISOTROPIC]` - Point or anisotropic\n     sampling.\n\n \n Texture data. If `_mem` is non-NULL, created texture will be immutable. If\n   `_mem` is NULL content of the texture is uninitialized. When `_numLayers` is more than\n   1, expected memory layout is texture and all mips together for each array element.\n\n \n C99 equivalent is `bgfx_create_texture_2d`.\n\nC++: bgfx::createTexture2D(unsigned short, unsigned short, bool, unsigned short, enum bgfx::TextureFormat::Enum, uint64_t, const struct bgfx::Memory *) --> struct bgfx::TextureHandle", pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_hasMips"), pybind11::arg("_numLayers"), pybind11::arg("_format"), pybind11::arg("_flags"), pybind11::arg("_mem"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::createTexture2D(enum bgfx::BackbufferRatio::Enum, bool, unsigned short, enum bgfx::TextureFormat::Enum, uint64_t) file:bgfx.h line:2691
	M("bgfx").def("create_texture2d", [](enum bgfx::BackbufferRatio::Enum const & a0, bool const & a1, unsigned short const & a2, enum bgfx::TextureFormat::Enum const & a3) -> bgfx::TextureHandle { return bgfx::createTexture2D(a0, a1, a2, a3); }, "", pybind11::arg("_ratio"), pybind11::arg("_hasMips"), pybind11::arg("_numLayers"), pybind11::arg("_format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_texture2d", (struct bgfx::TextureHandle (*)(enum bgfx::BackbufferRatio::Enum, bool, unsigned short, enum bgfx::TextureFormat::Enum, uint64_t)) &bgfx::createTexture2D, "Create texture with size based on backbuffer ratio. Texture will maintain ratio\n if back buffer resolution changes.\n\n \n Frame buffer size in respect to back-buffer size. See:\n   `BackbufferRatio::Enum`.\n \n\n Indicates that texture contains full mip-map chain.\n \n\n Number of layers in texture array. Must be 1 if caps\n   `BGFX_CAPS_TEXTURE_2D_ARRAY` flag is not set.\n \n\n Texture format. See: `TextureFormat::Enum`.\n \n\n Texture creation (see `BGFX_TEXTURE_*`.), and sampler (see `BGFX_SAMPLER_*`)\n   flags. Default texture sampling mode is linear, and wrap mode is repeat.\n   - `BGFX_SAMPLER_[U/V/W]_[MIRROR/CLAMP]` - Mirror or clamp to edge wrap\n     mode.\n   - `BGFX_SAMPLER_[MIN/MAG/MIP]_[POINT/ANISOTROPIC]` - Point or anisotropic\n     sampling.\n\n \n C99 equivalent is `bgfx_create_texture_2d_scaled`.\n\nC++: bgfx::createTexture2D(enum bgfx::BackbufferRatio::Enum, bool, unsigned short, enum bgfx::TextureFormat::Enum, uint64_t) --> struct bgfx::TextureHandle", pybind11::arg("_ratio"), pybind11::arg("_hasMips"), pybind11::arg("_numLayers"), pybind11::arg("_format"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::createTexture3D(unsigned short, unsigned short, unsigned short, bool, enum bgfx::TextureFormat::Enum, uint64_t, const struct bgfx::Memory *) file:bgfx.h line:2718
	M("bgfx").def("create_texture3d", [](unsigned short const & a0, unsigned short const & a1, unsigned short const & a2, bool const & a3, enum bgfx::TextureFormat::Enum const & a4) -> bgfx::TextureHandle { return bgfx::createTexture3D(a0, a1, a2, a3, a4); }, "", pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_depth"), pybind11::arg("_hasMips"), pybind11::arg("_format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_texture3d", [](unsigned short const & a0, unsigned short const & a1, unsigned short const & a2, bool const & a3, enum bgfx::TextureFormat::Enum const & a4, uint64_t const & a5) -> bgfx::TextureHandle { return bgfx::createTexture3D(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_depth"), pybind11::arg("_hasMips"), pybind11::arg("_format"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_texture3d", (struct bgfx::TextureHandle (*)(unsigned short, unsigned short, unsigned short, bool, enum bgfx::TextureFormat::Enum, uint64_t, const struct bgfx::Memory *)) &bgfx::createTexture3D, "Create 3D texture.\n\n \n Width.\n \n\n Height.\n \n\n Depth.\n \n\n Indicates that texture contains full mip-map chain.\n \n\n Texture format. See: `TextureFormat::Enum`.\n \n\n Texture creation (see `BGFX_TEXTURE_*`.), and sampler (see `BGFX_SAMPLER_*`)\n   flags. Default texture sampling mode is linear, and wrap mode is repeat.\n   - `BGFX_SAMPLER_[U/V/W]_[MIRROR/CLAMP]` - Mirror or clamp to edge wrap\n     mode.\n   - `BGFX_SAMPLER_[MIN/MAG/MIP]_[POINT/ANISOTROPIC]` - Point or anisotropic\n     sampling.\n\n \n Texture data. If `_mem` is non-NULL, created texture will be immutable. If\n   `_mem` is NULL content of the texture is uninitialized.\n\n \n C99 equivalent is `bgfx_create_texture_3d`.\n\nC++: bgfx::createTexture3D(unsigned short, unsigned short, unsigned short, bool, enum bgfx::TextureFormat::Enum, uint64_t, const struct bgfx::Memory *) --> struct bgfx::TextureHandle", pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_depth"), pybind11::arg("_hasMips"), pybind11::arg("_format"), pybind11::arg("_flags"), pybind11::arg("_mem"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::createTextureCube(unsigned short, bool, unsigned short, enum bgfx::TextureFormat::Enum, uint64_t, const struct bgfx::Memory *) file:bgfx.h line:2748
	M("bgfx").def("create_texture_cube", [](unsigned short const & a0, bool const & a1, unsigned short const & a2, enum bgfx::TextureFormat::Enum const & a3) -> bgfx::TextureHandle { return bgfx::createTextureCube(a0, a1, a2, a3); }, "", pybind11::arg("_size"), pybind11::arg("_hasMips"), pybind11::arg("_numLayers"), pybind11::arg("_format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_texture_cube", [](unsigned short const & a0, bool const & a1, unsigned short const & a2, enum bgfx::TextureFormat::Enum const & a3, uint64_t const & a4) -> bgfx::TextureHandle { return bgfx::createTextureCube(a0, a1, a2, a3, a4); }, "", pybind11::arg("_size"), pybind11::arg("_hasMips"), pybind11::arg("_numLayers"), pybind11::arg("_format"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_texture_cube", (struct bgfx::TextureHandle (*)(unsigned short, bool, unsigned short, enum bgfx::TextureFormat::Enum, uint64_t, const struct bgfx::Memory *)) &bgfx::createTextureCube, "Create Cube texture.\n\n \n Cube side size.\n \n\n Indicates that texture contains full mip-map chain.\n \n\n Number of layers in texture array. Must be 1 if caps\n   `BGFX_CAPS_TEXTURE_CUBE_ARRAY` flag is not set.\n \n\n Texture format. See: `TextureFormat::Enum`.\n \n\n Texture creation (see `BGFX_TEXTURE_*`.), and sampler (see `BGFX_SAMPLER_*`)\n   flags. Default texture sampling mode is linear, and wrap mode is repeat.\n   - `BGFX_SAMPLER_[U/V/W]_[MIRROR/CLAMP]` - Mirror or clamp to edge wrap\n     mode.\n   - `BGFX_SAMPLER_[MIN/MAG/MIP]_[POINT/ANISOTROPIC]` - Point or anisotropic\n     sampling.\n\n \n Texture data. If `_mem` is non-NULL, created texture will be immutable. If\n   `_mem` is NULL content of the texture is uninitialized. When `_numLayers` is more than\n   1, expected memory layout is texture and all mips together for each array element.\n\n \n C99 equivalent is `bgfx_create_texture_cube`.\n\nC++: bgfx::createTextureCube(unsigned short, bool, unsigned short, enum bgfx::TextureFormat::Enum, uint64_t, const struct bgfx::Memory *) --> struct bgfx::TextureHandle", pybind11::arg("_size"), pybind11::arg("_hasMips"), pybind11::arg("_numLayers"), pybind11::arg("_format"), pybind11::arg("_flags"), pybind11::arg("_mem"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::updateTexture2D(struct bgfx::TextureHandle, unsigned short, unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, const struct bgfx::Memory *, unsigned short) file:bgfx.h line:2774
	M("bgfx").def("update_texture2d", [](struct bgfx::TextureHandle const & a0, unsigned short const & a1, unsigned char const & a2, unsigned short const & a3, unsigned short const & a4, unsigned short const & a5, unsigned short const & a6, const struct bgfx::Memory * a7) -> void { return bgfx::updateTexture2D(a0, a1, a2, a3, a4, a5, a6, a7); }, "", pybind11::arg("_handle"), pybind11::arg("_layer"), pybind11::arg("_mip"), pybind11::arg("_x"), pybind11::arg("_y"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_mem"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("update_texture2d", (void (*)(struct bgfx::TextureHandle, unsigned short, unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, const struct bgfx::Memory *, unsigned short)) &bgfx::updateTexture2D, "Update 2D texture.\n\n \n Texture handle.\n \n\n Layers in texture array.\n \n\n Mip level.\n \n\n X offset in texture.\n \n\n Y offset in texture.\n \n\n Width of texture block.\n \n\n Height of texture block.\n \n\n Texture update data.\n \n\n Pitch of input image (bytes). When _pitch is set to\n   UINT16_MAX, it will be calculated internally based on _width.\n\n \n It's valid to update only mutable texture. See `bgfx::createTexture2D` for more info.\n\n \n C99 equivalent is `bgfx_update_texture_2d`.\n\nC++: bgfx::updateTexture2D(struct bgfx::TextureHandle, unsigned short, unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, const struct bgfx::Memory *, unsigned short) --> void", pybind11::arg("_handle"), pybind11::arg("_layer"), pybind11::arg("_mip"), pybind11::arg("_x"), pybind11::arg("_y"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_mem"), pybind11::arg("_pitch"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::updateTexture3D(struct bgfx::TextureHandle, unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, const struct bgfx::Memory *) file:bgfx.h line:2802
	M("bgfx").def("update_texture3d", (void (*)(struct bgfx::TextureHandle, unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, const struct bgfx::Memory *)) &bgfx::updateTexture3D, "Update 3D texture.\n\n \n Texture handle.\n \n\n Mip level.\n \n\n X offset in texture.\n \n\n Y offset in texture.\n \n\n Z offset in texture.\n \n\n Width of texture block.\n \n\n Height of texture block.\n \n\n Depth of texture block.\n \n\n Texture update data.\n\n \n It's valid to update only mutable texture. See `bgfx::createTexture3D` for more info.\n\n \n C99 equivalent is `bgfx_update_texture_3d`.\n\nC++: bgfx::updateTexture3D(struct bgfx::TextureHandle, unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, const struct bgfx::Memory *) --> void", pybind11::arg("_handle"), pybind11::arg("_mip"), pybind11::arg("_x"), pybind11::arg("_y"), pybind11::arg("_z"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_depth"), pybind11::arg("_mem"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::updateTextureCube(struct bgfx::TextureHandle, unsigned short, unsigned char, unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, const struct bgfx::Memory *, unsigned short) file:bgfx.h line:2851
	M("bgfx").def("update_texture_cube", [](struct bgfx::TextureHandle const & a0, unsigned short const & a1, unsigned char const & a2, unsigned char const & a3, unsigned short const & a4, unsigned short const & a5, unsigned short const & a6, unsigned short const & a7, const struct bgfx::Memory * a8) -> void { return bgfx::updateTextureCube(a0, a1, a2, a3, a4, a5, a6, a7, a8); }, "", pybind11::arg("_handle"), pybind11::arg("_layer"), pybind11::arg("_side"), pybind11::arg("_mip"), pybind11::arg("_x"), pybind11::arg("_y"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_mem"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("update_texture_cube", (void (*)(struct bgfx::TextureHandle, unsigned short, unsigned char, unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, const struct bgfx::Memory *, unsigned short)) &bgfx::updateTextureCube, "Update Cube texture.\n\n \n Texture handle.\n \n\n Layers in texture array.\n \n\n Cubemap side `BGFX_CUBE_MAP_<POSITIVE or NEGATIVE>_<X, Y or Z>`,\n   where 0 is +X, 1 is -X, 2 is +Y, 3 is -Y, 4 is +Z, and 5 is -Z.\n\n                  +----------+\n                  |-z       2|\n                  | ^  +y    |\n                  | |        |    Unfolded cube:\n                  | +---->+x |\n       +----------+----------+----------+----------+\n       |+y       1|+y       4|+y       0|+y       5|\n       | ^  -x    | ^  +z    | ^  +x    | ^  -z    |\n       | |        | |        | |        | |        |\n       | +---->+z | +---->+x | +---->-z | +---->-x |\n       +----------+----------+----------+----------+\n                  |+z       3|\n                  | ^  -y    |\n                  | |        |\n                  | +---->+x |\n                  +----------+\n\n \n Mip level.\n \n\n X offset in texture.\n \n\n Y offset in texture.\n \n\n Width of texture block.\n \n\n Height of texture block.\n \n\n Texture update data.\n \n\n Pitch of input image (bytes). When _pitch is set to\n   UINT16_MAX, it will be calculated internally based on _width.\n\n \n It's valid to update only mutable texture. See `bgfx::createTextureCube` for more info.\n\n \n C99 equivalent is `bgfx_update_texture_cube`.\n\nC++: bgfx::updateTextureCube(struct bgfx::TextureHandle, unsigned short, unsigned char, unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, const struct bgfx::Memory *, unsigned short) --> void", pybind11::arg("_handle"), pybind11::arg("_layer"), pybind11::arg("_side"), pybind11::arg("_mip"), pybind11::arg("_x"), pybind11::arg("_y"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_mem"), pybind11::arg("_pitch"), pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: bgfx_6.cpp
#include <bgfx.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_bgfx_6(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// bgfx::readTexture(struct bgfx::TextureHandle, void *, unsigned char) file:bgfx.h line:2876
	M("bgfx").def("read_texture", [](struct bgfx::TextureHandle const & a0, void * a1) -> unsigned int { return bgfx::readTexture(a0, a1); }, "", pybind11::arg("_handle"), pybind11::arg("_data"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("read_texture", (unsigned int (*)(struct bgfx::TextureHandle, void *, unsigned char)) &bgfx::readTexture, "Read back texture content.\n\n \n Texture handle.\n \n\n Destination buffer.\n \n\n Mip level.\n\n \n Frame number when the result will be available. See: `bgfx::frame`.\n\n \n Texture must be created with `BGFX_TEXTURE_READ_BACK` flag.\n \n\n Availability depends on: `BGFX_CAPS_TEXTURE_READ_BACK`.\n \n\n C99 equivalent is `bgfx_read_texture`.\n\nC++: bgfx::readTexture(struct bgfx::TextureHandle, void *, unsigned char) --> unsigned int", pybind11::arg("_handle"), pybind11::arg("_data"), pybind11::arg("_mip"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setName(struct bgfx::TextureHandle, const char *, int) file:bgfx.h line:2891
	M("bgfx").def("set_name", [](struct bgfx::TextureHandle const & a0, const char * a1) -> void { return bgfx::setName(a0, a1); }, "", pybind11::arg("_handle"), pybind11::arg("_name"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_name", (void (*)(struct bgfx::TextureHandle, const char *, int)) &bgfx::setName, "Set texture debug name.\n\n \n Texture handle.\n \n\n Texture name.\n \n\n Texture name length (if length is INT32_MAX, it's expected\n   that _name is zero terminated string.\n\n \n C99 equivalent is `bgfx_set_texture_name`.\n\nC++: bgfx::setName(struct bgfx::TextureHandle, const char *, int) --> void", pybind11::arg("_handle"), pybind11::arg("_name"), pybind11::arg("_len"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::getDirectAccessPtr(struct bgfx::TextureHandle) file:bgfx.h line:2911
	M("bgfx").def("get_direct_access_ptr", (void * (*)(struct bgfx::TextureHandle)) &bgfx::getDirectAccessPtr, "Returns texture direct access pointer.\n\n \n Texture handle.\n\n \n Pointer to texture memory. If returned pointer is `NULL` direct access\n   is not available for this texture. If pointer is `UINTPTR_MAX` sentinel value\n   it means texture is pending creation. Pointer returned can be cached and it\n   will be valid until texture is destroyed.\n\n \n Availability depends on: `BGFX_CAPS_TEXTURE_DIRECT_ACCESS`. This feature\n   is available on GPUs that have unified memory architecture (UMA) support.\n\n \n C99 equivalent is `bgfx_get_direct_access_ptr`.\n\nC++: bgfx::getDirectAccessPtr(struct bgfx::TextureHandle) --> void *", pybind11::return_value_policy::reference, pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::destroy(struct bgfx::TextureHandle) file:bgfx.h line:2919
	M("bgfx").def("destroy", (void (*)(struct bgfx::TextureHandle)) &bgfx::destroy, "Destroy texture.\n\n \n Texture handle.\n\n \n C99 equivalent is `bgfx_destroy_texture`.\n\nC++: bgfx::destroy(struct bgfx::TextureHandle) --> void", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::createFrameBuffer(unsigned short, unsigned short, enum bgfx::TextureFormat::Enum, uint64_t) file:bgfx.h line:2937
	M("bgfx").def("create_frame_buffer", [](unsigned short const & a0, unsigned short const & a1, enum bgfx::TextureFormat::Enum const & a2) -> bgfx::FrameBufferHandle { return bgfx::createFrameBuffer(a0, a1, a2); }, "", pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_frame_buffer", (struct bgfx::FrameBufferHandle (*)(unsigned short, unsigned short, enum bgfx::TextureFormat::Enum, uint64_t)) &bgfx::createFrameBuffer, "Create frame buffer (simple).\n\n \n Texture width.\n \n\n Texture height.\n \n\n Texture format. See: `TextureFormat::Enum`.\n \n\n Default texture sampling mode is linear, and wrap mode\n   is repeat.\n   - `BGFX_SAMPLER_[U/V/W]_[MIRROR/CLAMP]` - Mirror or clamp to edge wrap\n     mode.\n   - `BGFX_SAMPLER_[MIN/MAG/MIP]_[POINT/ANISOTROPIC]` - Point or anisotropic\n     sampling.\n\n \n Handle to frame buffer object.\n\n \n C99 equivalent is `bgfx_create_frame_buffer`.\n\nC++: bgfx::createFrameBuffer(unsigned short, unsigned short, enum bgfx::TextureFormat::Enum, uint64_t) --> struct bgfx::FrameBufferHandle", pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_format"), pybind11::arg("_textureFlags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::createFrameBuffer(enum bgfx::BackbufferRatio::Enum, enum bgfx::TextureFormat::Enum, uint64_t) file:bgfx.h line:2961
	M("bgfx").def("create_frame_buffer", [](enum bgfx::BackbufferRatio::Enum const & a0, enum bgfx::TextureFormat::Enum const & a1) -> bgfx::FrameBufferHandle { return bgfx::createFrameBuffer(a0, a1); }, "", pybind11::arg("_ratio"), pybind11::arg("_format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_frame_buffer", (struct bgfx::FrameBufferHandle (*)(enum bgfx::BackbufferRatio::Enum, enum bgfx::TextureFormat::Enum, uint64_t)) &bgfx::createFrameBuffer, "Create frame buffer with size based on backbuffer ratio. Frame buffer will maintain ratio\n if back buffer resolution changes.\n\n \n Frame buffer size in respect to back-buffer size. See:\n   `BackbufferRatio::Enum`.\n \n\n Texture format. See: `TextureFormat::Enum`.\n \n\n Default texture sampling mode is linear, and wrap mode\n   is repeat.\n   - `BGFX_SAMPLER_[U/V/W]_[MIRROR/CLAMP]` - Mirror or clamp to edge wrap\n     mode.\n   - `BGFX_SAMPLER_[MIN/MAG/MIP]_[POINT/ANISOTROPIC]` - Point or anisotropic\n     sampling.\n\n \n Handle to frame buffer object.\n\n \n C99 equivalent is `bgfx_create_frame_buffer_scaled`.\n\nC++: bgfx::createFrameBuffer(enum bgfx::BackbufferRatio::Enum, enum bgfx::TextureFormat::Enum, uint64_t) --> struct bgfx::FrameBufferHandle", pybind11::arg("_ratio"), pybind11::arg("_format"), pybind11::arg("_textureFlags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::createFrameBuffer(unsigned char, const struct bgfx::TextureHandle *, bool) file:bgfx.h line:2978
	M("bgfx").def("create_frame_buffer", [](unsigned char const & a0, const struct bgfx::TextureHandle * a1) -> bgfx::FrameBufferHandle { return bgfx::createFrameBuffer(a0, a1); }, "", pybind11::arg("_num"), pybind11::arg("_handles"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_frame_buffer", (struct bgfx::FrameBufferHandle (*)(unsigned char, const struct bgfx::TextureHandle *, bool)) &bgfx::createFrameBuffer, "Create MRT frame buffer from texture handles (simple).\n\n \n Number of texture attachments.\n \n\n Texture attachments.\n \n\n If true, textures will be destroyed when\n   frame buffer is destroyed.\n\n \n Handle to frame buffer object.\n\n \n C99 equivalent is `bgfx_create_frame_buffer_from_handles`.\n\nC++: bgfx::createFrameBuffer(unsigned char, const struct bgfx::TextureHandle *, bool) --> struct bgfx::FrameBufferHandle", pybind11::arg("_num"), pybind11::arg("_handles"), pybind11::arg("_destroyTextures"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::createFrameBuffer(unsigned char, const struct bgfx::Attachment *, bool) file:bgfx.h line:2996
	M("bgfx").def("create_frame_buffer", [](unsigned char const & a0, const struct bgfx::Attachment * a1) -> bgfx::FrameBufferHandle { return bgfx::createFrameBuffer(a0, a1); }, "", pybind11::arg("_num"), pybind11::arg("_attachment"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_frame_buffer", (struct bgfx::FrameBufferHandle (*)(unsigned char, const struct bgfx::Attachment *, bool)) &bgfx::createFrameBuffer, "Create MRT frame buffer from texture handles with specific layer and\n mip level.\n\n \n Number of texture attachments.\n \n\n Attachment texture info. See: `bgfx::Attachment`.\n \n\n If true, textures will be destroyed when\n   frame buffer is destroyed.\n\n \n Handle to frame buffer object.\n\n \n C99 equivalent is `bgfx_create_frame_buffer_from_attachment`.\n\nC++: bgfx::createFrameBuffer(unsigned char, const struct bgfx::Attachment *, bool) --> struct bgfx::FrameBufferHandle", pybind11::arg("_num"), pybind11::arg("_attachment"), pybind11::arg("_destroyTextures"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::createFrameBuffer(void *, unsigned short, unsigned short, enum bgfx::TextureFormat::Enum, enum bgfx::TextureFormat::Enum) file:bgfx.h line:3017
	M("bgfx").def("create_frame_buffer", [](void * a0, unsigned short const & a1, unsigned short const & a2) -> bgfx::FrameBufferHandle { return bgfx::createFrameBuffer(a0, a1, a2); }, "", pybind11::arg("_nwh"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_frame_buffer", [](void * a0, unsigned short const & a1, unsigned short const & a2, enum bgfx::TextureFormat::Enum const & a3) -> bgfx::FrameBufferHandle { return bgfx::createFrameBuffer(a0, a1, a2, a3); }, "", pybind11::arg("_nwh"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_frame_buffer", (struct bgfx::FrameBufferHandle (*)(void *, unsigned short, unsigned short, enum bgfx::TextureFormat::Enum, enum bgfx::TextureFormat::Enum)) &bgfx::createFrameBuffer, "Create frame buffer for multiple window rendering.\n\n \n OS' target native window handle.\n \n\n Window back buffer width.\n \n\n Window back buffer height.\n \n\n Window back buffer color format.\n \n\n Window back buffer depth format.\n\n \n Handle to frame buffer object.\n\n \n\n   Frame buffer cannot be used for sampling.\n\n \n C99 equivalent is `bgfx_create_frame_buffer_from_nwh`.\n\nC++: bgfx::createFrameBuffer(void *, unsigned short, unsigned short, enum bgfx::TextureFormat::Enum, enum bgfx::TextureFormat::Enum) --> struct bgfx::FrameBufferHandle", pybind11::arg("_nwh"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_format"), pybind11::arg("_depthFormat"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setName(struct bgfx::FrameBufferHandle, const char *, int) file:bgfx.h line:3034
	M("bgfx").def("set_name", [](struct bgfx::FrameBufferHandle const & a0, const char * a1) -> void { return bgfx::setName(a0, a1); }, "", pybind11::arg("_handle"), pybind11::arg("_name"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_name", (void (*)(struct bgfx::FrameBufferHandle, const char *, int)) &bgfx::setName, "Set frame buffer debug name.\n\n \n frame buffer handle.\n \n\n frame buffer name.\n \n\n frame buffer name length (if length is INT32_MAX, it's expected\n   that _name is zero terminated string.\n\n \n C99 equivalent is `bgfx_set_frame_buffer_name`.\n\nC++: bgfx::setName(struct bgfx::FrameBufferHandle, const char *, int) --> void", pybind11::arg("_handle"), pybind11::arg("_name"), pybind11::arg("_len"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::getTexture(struct bgfx::FrameBufferHandle, unsigned char) file:bgfx.h line:3050
	M("bgfx").def("get_texture", [](struct bgfx::FrameBufferHandle const & a0) -> bgfx::TextureHandle { return bgfx::getTexture(a0); }, "", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("get_texture", (struct bgfx::TextureHandle (*)(struct bgfx::FrameBufferHandle, unsigned char)) &bgfx::getTexture, "Obtain texture handle of frame buffer attachment.\n\n \n Frame buffer handle.\n \n\n Frame buffer attachment index.\n\n \n Returns invalid texture handle if attachment index is not\n   correct, or frame buffer is created with native window handle.\n\n \n C99 equivalent is `bgfx_get_texture`.\n\nC++: bgfx::getTexture(struct bgfx::FrameBufferHandle, unsigned char) --> struct bgfx::TextureHandle", pybind11::arg("_handle"), pybind11::arg("_attachment"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::destroy(struct bgfx::FrameBufferHandle) file:bgfx.h line:3061
	M("bgfx").def("destroy", (void (*)(struct bgfx::FrameBufferHandle)) &bgfx::destroy, "Destroy frame buffer.\n\n \n Frame buffer handle.\n\n \n C99 equivalent is `bgfx_destroy_frame_buffer`.\n\nC++: bgfx::destroy(struct bgfx::FrameBufferHandle) --> void", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::createUniform(const char *, enum bgfx::UniformType::Enum, unsigned short) file:bgfx.h line:3097
	M("bgfx").def("create_uniform", [](const char * a0, enum bgfx::UniformType::Enum const & a1) -> bgfx::UniformHandle { return bgfx::createUniform(a0, a1); }, "", pybind11::arg("_name"), pybind11::arg("_type"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("create_uniform", (struct bgfx::UniformHandle (*)(const char *, enum bgfx::UniformType::Enum, unsigned short)) &bgfx::createUniform, "Create shader uniform parameter.\n\n \n Uniform name in shader.\n \n\n Type of uniform (See: `bgfx::UniformType`).\n \n\n Number of elements in array.\n\n \n Handle to uniform object.\n\n \n\n   1. Uniform names are unique. It's valid to call `bgfx::createUniform`\n      multiple times with the same uniform name. The library will always\n      return the same handle, but the handle reference count will be\n      incremented. This means that the same number of `bgfx::destroyUniform`\n      must be called to properly destroy the uniform.\n\n   2. Predefined uniforms (declared in `bgfx_shader.sh`):\n      - `u_viewRect vec4(x, y, width, height)` - view rectangle for current\n        view, in pixels.\n      - `u_viewTexel vec4(1.0/width, 1.0/height, undef, undef)` - inverse\n        width and height\n      - `u_view mat4` - view matrix\n      - `u_invView mat4` - inverted view matrix\n      - `u_proj mat4` - projection matrix\n      - `u_invProj mat4` - inverted projection matrix\n      - `u_viewProj mat4` - concatenated view projection matrix\n      - `u_invViewProj mat4` - concatenated inverted view projection matrix\n      - `u_model mat4[BGFX_CONFIG_MAX_BONES]` - array of model matrices.\n      - `u_modelView mat4` - concatenated model view matrix, only first\n        model matrix from array is used.\n      - `u_modelViewProj mat4` - concatenated model view projection matrix.\n      - `u_alphaRef float` - alpha reference value for alpha test.\n\n \n C99 equivalent is `bgfx_create_uniform`.\n\nC++: bgfx::createUniform(const char *, enum bgfx::UniformType::Enum, unsigned short) --> struct bgfx::UniformHandle", pybind11::arg("_name"), pybind11::arg("_type"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::getUniformInfo(struct bgfx::UniformHandle, struct bgfx::UniformInfo &) file:bgfx.h line:3110
	M("bgfx").def("get_uniform_info", (void (*)(struct bgfx::UniformHandle, struct bgfx::UniformInfo &)) &bgfx::getUniformInfo, "Retrieve uniform info.\n\n \n Handle to uniform object.\n \n\n Uniform info.\n\n \n C99 equivalent is `bgfx_get_uniform_info`.\n\nC++: bgfx::getUniformInfo(struct bgfx::UniformHandle, struct bgfx::UniformInfo &) --> void", pybind11::arg("_handle"), pybind11::arg("_info"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::destroy(struct bgfx::UniformHandle) file:bgfx.h line:3121
	M("bgfx").def("destroy", (void (*)(struct bgfx::UniformHandle)) &bgfx::destroy, "Destroy shader uniform parameter.\n\n \n Handle to uniform object.\n\n \n C99 equivalent is `bgfx_destroy_uniform`.\n\nC++: bgfx::destroy(struct bgfx::UniformHandle) --> void", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::createOcclusionQuery() file:bgfx.h line:3129
	M("bgfx").def("create_occlusion_query", (struct bgfx::OcclusionQueryHandle (*)()) &bgfx::createOcclusionQuery, "Create occlusion query.\n\n \n Handle to occlusion query object.\n\n \n C99 equivalent is `bgfx_create_occlusion_query`.\n\nC++: bgfx::createOcclusionQuery() --> struct bgfx::OcclusionQueryHandle", pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::getResult(struct bgfx::OcclusionQueryHandle, int *) file:bgfx.h line:3140
	M("bgfx").def("get_result", [](struct bgfx::OcclusionQueryHandle const & a0) -> bgfx::OcclusionQueryResult::Enum { return bgfx::getResult(a0); }, "", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("get_result", (enum bgfx::OcclusionQueryResult::Enum (*)(struct bgfx::OcclusionQueryHandle, int *)) &bgfx::getResult, "Retrieve occlusion query result from previous frame.\n\n \n Handle to occlusion query object.\n \n\n Number of pixels that passed test. This argument\n   can be `NULL` if result of occlusion query is not needed.\n \n\n Occlusion query result.\n\n \n C99 equivalent is `bgfx_get_result`.\n\nC++: bgfx::getResult(struct bgfx::OcclusionQueryHandle, int *) --> enum bgfx::OcclusionQueryResult::Enum", pybind11::arg("_handle"), pybind11::arg("_result"), pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: bgfx_7.cpp
#include <bgfx.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_bgfx_7(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// bgfx::destroy(struct bgfx::OcclusionQueryHandle) file:bgfx.h line:3151
	M("bgfx").def("destroy", (void (*)(struct bgfx::OcclusionQueryHandle)) &bgfx::destroy, "Destroy occlusion query.\n\n \n Handle to occlusion query object.\n\n \n C99 equivalent is `bgfx_destroy_occlusion_query`.\n\nC++: bgfx::destroy(struct bgfx::OcclusionQueryHandle) --> void", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setPaletteColor(unsigned char, unsigned int) file:bgfx.h line:3160
	M("bgfx").def("set_palette_color", (void (*)(unsigned char, unsigned int)) &bgfx::setPaletteColor, "Set palette color value.\n\n \n Index into palette.\n \n\n Packed 32-bit RGBA value.\n\n \n C99 equivalent is `bgfx_set_palette_color`.\n\nC++: bgfx::setPaletteColor(unsigned char, unsigned int) --> void", pybind11::arg("_index"), pybind11::arg("_rgba"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setPaletteColor(unsigned char, float, float, float, float) file:bgfx.h line:3172
	M("bgfx").def("set_palette_color", (void (*)(unsigned char, float, float, float, float)) &bgfx::setPaletteColor, "Set palette color value.\n\n \n Index into palette.\n \n\n _g, _b, _a RGBA floating point values.\n\n \n C99 equivalent is `bgfx_set_palette_color`.\n\nC++: bgfx::setPaletteColor(unsigned char, float, float, float, float) --> void", pybind11::arg("_index"), pybind11::arg("_r"), pybind11::arg("_g"), pybind11::arg("_b"), pybind11::arg("_a"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setViewName(unsigned short, const char *) file:bgfx.h line:3210
	M("bgfx").def("set_view_name", (void (*)(unsigned short, const char *)) &bgfx::setViewName, "Set view name.\n\n \n View id.\n \n\n View name.\n\n \n\n   This is debug only feature.\n\n   In graphics debugger view name will appear as:\n\n       \"nnnce <view name>\"\n        ^  ^^ ^\n        |  |+-- eye (L/R)\n        |  +--- compute (C)\n        +------ view id\n\n \n C99 equivalent is `bgfx_set_view_name`.\n\nC++: bgfx::setViewName(unsigned short, const char *) --> void", pybind11::arg("_id"), pybind11::arg("_name"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setViewRect(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short) file:bgfx.h line:3225
	M("bgfx").def("set_view_rect", (void (*)(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short)) &bgfx::setViewRect, "Set view rectangle. Draw primitive outside view will be clipped.\n\n \n View id.\n \n\n Position x from the left corner of the window.\n \n\n Position y from the top corner of the window.\n \n\n Width of view port region.\n \n\n Height of view port region.\n\n \n C99 equivalent is `bgfx_set_view_rect`.\n\nC++: bgfx::setViewRect(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short) --> void", pybind11::arg("_id"), pybind11::arg("_x"), pybind11::arg("_y"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setViewRect(unsigned short, unsigned short, unsigned short, enum bgfx::BackbufferRatio::Enum) file:bgfx.h line:3243
	M("bgfx").def("set_view_rect", (void (*)(unsigned short, unsigned short, unsigned short, enum bgfx::BackbufferRatio::Enum)) &bgfx::setViewRect, "Set view rectangle. Draw primitive outside view will be clipped.\n\n \n View id.\n \n\n Position x from the left corner of the window.\n \n\n Position y from the top corner of the window.\n \n\n Width and height will be set in respect to back-buffer size. See:\n   `BackbufferRatio::Enum`.\n\n \n C99 equivalent is `bgfx_set_view_rect_auto`.\n\nC++: bgfx::setViewRect(unsigned short, unsigned short, unsigned short, enum bgfx::BackbufferRatio::Enum) --> void", pybind11::arg("_id"), pybind11::arg("_x"), pybind11::arg("_y"), pybind11::arg("_ratio"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setViewScissor(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short) file:bgfx.h line:3261
	M("bgfx").def("set_view_scissor", [](unsigned short const & a0) -> void { return bgfx::setViewScissor(a0); }, "", pybind11::arg("_id"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_view_scissor", [](unsigned short const & a0, unsigned short const & a1) -> void { return bgfx::setViewScissor(a0, a1); }, "", pybind11::arg("_id"), pybind11::arg("_x"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_view_scissor", [](unsigned short const & a0, unsigned short const & a1, unsigned short const & a2) -> void { return bgfx::setViewScissor(a0, a1, a2); }, "", pybind11::arg("_id"), pybind11::arg("_x"), pybind11::arg("_y"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_view_scissor", [](unsigned short const & a0, unsigned short const & a1, unsigned short const & a2, unsigned short const & a3) -> void { return bgfx::setViewScissor(a0, a1, a2, a3); }, "", pybind11::arg("_id"), pybind11::arg("_x"), pybind11::arg("_y"), pybind11::arg("_width"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_view_scissor", (void (*)(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short)) &bgfx::setViewScissor, "Set view scissor. Draw primitive outside view will be clipped. When\n _x, _y, _width and _height are set to 0, scissor will be disabled.\n\n \n View id.\n \n\n Position x from the left corner of the window.\n \n\n Position y from the top corner of the window.\n \n\n Width of scissor region.\n \n\n Height of scissor region.\n\n \n C99 equivalent is `bgfx_set_view_scissor`.\n\nC++: bgfx::setViewScissor(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short) --> void", pybind11::arg("_id"), pybind11::arg("_x"), pybind11::arg("_y"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setViewClear(unsigned short, unsigned short, unsigned int, float, unsigned char) file:bgfx.h line:3280
	M("bgfx").def("set_view_clear", [](unsigned short const & a0, unsigned short const & a1) -> void { return bgfx::setViewClear(a0, a1); }, "", pybind11::arg("_id"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_view_clear", [](unsigned short const & a0, unsigned short const & a1, unsigned int const & a2) -> void { return bgfx::setViewClear(a0, a1, a2); }, "", pybind11::arg("_id"), pybind11::arg("_flags"), pybind11::arg("_rgba"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_view_clear", [](unsigned short const & a0, unsigned short const & a1, unsigned int const & a2, float const & a3) -> void { return bgfx::setViewClear(a0, a1, a2, a3); }, "", pybind11::arg("_id"), pybind11::arg("_flags"), pybind11::arg("_rgba"), pybind11::arg("_depth"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_view_clear", (void (*)(unsigned short, unsigned short, unsigned int, float, unsigned char)) &bgfx::setViewClear, "Set view clear flags.\n\n \n View id.\n \n\n Clear flags. Use `BGFX_CLEAR_NONE` to remove any clear\n   operation. See: `BGFX_CLEAR_*`.\n \n\n Color clear value.\n \n\n Depth clear value.\n \n\n Stencil clear value.\n\n \n C99 equivalent is `bgfx_set_view_clear`.\n\nC++: bgfx::setViewClear(unsigned short, unsigned short, unsigned int, float, unsigned char) --> void", pybind11::arg("_id"), pybind11::arg("_flags"), pybind11::arg("_rgba"), pybind11::arg("_depth"), pybind11::arg("_stencil"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setViewClear(unsigned short, unsigned short, float, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char) file:bgfx.h line:3308
	M("bgfx").def("set_view_clear", [](unsigned short const & a0, unsigned short const & a1, float const & a2, unsigned char const & a3) -> void { return bgfx::setViewClear(a0, a1, a2, a3); }, "", pybind11::arg("_id"), pybind11::arg("_flags"), pybind11::arg("_depth"), pybind11::arg("_stencil"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_view_clear", [](unsigned short const & a0, unsigned short const & a1, float const & a2, unsigned char const & a3, unsigned char const & a4) -> void { return bgfx::setViewClear(a0, a1, a2, a3, a4); }, "", pybind11::arg("_id"), pybind11::arg("_flags"), pybind11::arg("_depth"), pybind11::arg("_stencil"), pybind11::arg("_0"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_view_clear", [](unsigned short const & a0, unsigned short const & a1, float const & a2, unsigned char const & a3, unsigned char const & a4, unsigned char const & a5) -> void { return bgfx::setViewClear(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("_id"), pybind11::arg("_flags"), pybind11::arg("_depth"), pybind11::arg("_stencil"), pybind11::arg("_0"), pybind11::arg("_1"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_view_clear", [](unsigned short const & a0, unsigned short const & a1, float const & a2, unsigned char const & a3, unsigned char const & a4, unsigned char const & a5, unsigned char const & a6) -> void { return bgfx::setViewClear(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("_id"), pybind11::arg("_flags"), pybind11::arg("_depth"), pybind11::arg("_stencil"), pybind11::arg("_0"), pybind11::arg("_1"), pybind11::arg("_2"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_view_clear", [](unsigned short const & a0, unsigned short const & a1, float const & a2, unsigned char const & a3, unsigned char const & a4, unsigned char const & a5, unsigned char const & a6, unsigned char const & a7) -> void { return bgfx::setViewClear(a0, a1, a2, a3, a4, a5, a6, a7); }, "", pybind11::arg("_id"), pybind11::arg("_flags"), pybind11::arg("_depth"), pybind11::arg("_stencil"), pybind11::arg("_0"), pybind11::arg("_1"), pybind11::arg("_2"), pybind11::arg("_3"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_view_clear", [](unsigned short const & a0, unsigned short const & a1, float const & a2, unsigned char const & a3, unsigned char const & a4, unsigned char const & a5, unsigned char const & a6, unsigned char const & a7, unsigned char const & a8) -> void { return bgfx::setViewClear(a0, a1, a2, a3, a4, a5, a6, a7, a8); }, "", pybind11::arg("_id"), pybind11::arg("_flags"), pybind11::arg("_depth"), pybind11::arg("_stencil"), pybind11::arg("_0"), pybind11::arg("_1"), pybind11::arg("_2"), pybind11::arg("_3"), pybind11::arg("_4"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_view_clear", [](unsigned short const & a0, unsigned short const & a1, float const & a2, unsigned char const & a3, unsigned char const & a4, unsigned char const & a5, unsigned char const & a6, unsigned char const & a7, unsigned char const & a8, unsigned char const & a9) -> void { return bgfx::setViewClear(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9); }, "", pybind11::arg("_id"), pybind11::arg("_flags"), pybind11::arg("_depth"), pybind11::arg("_stencil"), pybind11::arg("_0"), pybind11::arg("_1"), pybind11::arg("_2"), pybind11::arg("_3"), pybind11::arg("_4"), pybind11::arg("_5"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_view_clear", [](unsigned short const & a0, unsigned short const & a1, float const & a2, unsigned char const & a3, unsigned char const & a4, unsigned char const & a5, unsigned char const & a6, unsigned char const & a7, unsigned char const & a8, unsigned char const & a9, unsigned char const & a10) -> void { return bgfx::setViewClear(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); }, "", pybind11::arg("_id"), pybind11::arg("_flags"), pybind11::arg("_depth"), pybind11::arg("_stencil"), pybind11::arg("_0"), pybind11::arg("_1"), pybind11::arg("_2"), pybind11::arg("_3"), pybind11::arg("_4"), pybind11::arg("_5"), pybind11::arg("_6"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_view_clear", (void (*)(unsigned short, unsigned short, float, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char)) &bgfx::setViewClear, "Set view clear flags with different clear color for each\n frame buffer texture. Must use `bgfx::setPaletteColor` to setup clear color\n palette.\n\n \n View id.\n \n\n Clear flags. Use `BGFX_CLEAR_NONE` to remove any clear\n   operation. See: `BGFX_CLEAR_*`.\n \n\n Depth clear value.\n \n\n Stencil clear value.\n \n\n Palette index for frame buffer attachment 0.\n \n\n Palette index for frame buffer attachment 1.\n \n\n Palette index for frame buffer attachment 2.\n \n\n Palette index for frame buffer attachment 3.\n \n\n Palette index for frame buffer attachment 4.\n \n\n Palette index for frame buffer attachment 5.\n \n\n Palette index for frame buffer attachment 6.\n \n\n Palette index for frame buffer attachment 7.\n\n \n C99 equivalent is `bgfx_set_view_clear_mrt`.\n\nC++: bgfx::setViewClear(unsigned short, unsigned short, float, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char) --> void", pybind11::arg("_id"), pybind11::arg("_flags"), pybind11::arg("_depth"), pybind11::arg("_stencil"), pybind11::arg("_0"), pybind11::arg("_1"), pybind11::arg("_2"), pybind11::arg("_3"), pybind11::arg("_4"), pybind11::arg("_5"), pybind11::arg("_6"), pybind11::arg("_7"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setViewMode(unsigned short, enum bgfx::ViewMode::Enum) file:bgfx.h line:3333
	M("bgfx").def("set_view_mode", [](unsigned short const & a0) -> void { return bgfx::setViewMode(a0); }, "", pybind11::arg("_id"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_view_mode", (void (*)(unsigned short, enum bgfx::ViewMode::Enum)) &bgfx::setViewMode, "Set view sorting mode.\n\n \n View id.\n \n\n View sort mode. See `ViewMode::Enum`.\n\n \n\n   View mode must be set prior calling `bgfx::submit` for the view.\n\n \n C99 equivalent is `bgfx_set_view_mode`.\n\nC++: bgfx::setViewMode(unsigned short, enum bgfx::ViewMode::Enum) --> void", pybind11::arg("_id"), pybind11::arg("_mode"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setViewFrameBuffer(unsigned short, struct bgfx::FrameBufferHandle) file:bgfx.h line:3350
	M("bgfx").def("set_view_frame_buffer", (void (*)(unsigned short, struct bgfx::FrameBufferHandle)) &bgfx::setViewFrameBuffer, "Set view frame buffer.\n\n \n View id.\n \n\n Frame buffer handle. Passing `BGFX_INVALID_HANDLE` as\n   frame buffer handle will draw primitives from this view into\n   default back buffer.\n\n \n\n   Not persistent after `bgfx::reset` call.\n\n \n C99 equivalent is `bgfx_set_view_frame_buffer`.\n\nC++: bgfx::setViewFrameBuffer(unsigned short, struct bgfx::FrameBufferHandle) --> void", pybind11::arg("_id"), pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setViewTransform(unsigned short, const void *, const void *) file:bgfx.h line:3364
	M("bgfx").def("set_view_transform", (void (*)(unsigned short, const void *, const void *)) &bgfx::setViewTransform, "Set view view and projection matrices, all draw primitives in this\n view will use these matrices.\n\n \n View id.\n \n\n View matrix.\n \n\n Projection matrix.\n\n \n C99 equivalent is `bgfx_set_view_transform`.\n\nC++: bgfx::setViewTransform(unsigned short, const void *, const void *) --> void", pybind11::arg("_id"), pybind11::arg("_view"), pybind11::arg("_proj"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setViewOrder(unsigned short, unsigned short, const unsigned short *) file:bgfx.h line:3379
	M("bgfx").def("set_view_order", []() -> void { return bgfx::setViewOrder(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_view_order", [](unsigned short const & a0) -> void { return bgfx::setViewOrder(a0); }, "", pybind11::arg("_id"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_view_order", [](unsigned short const & a0, unsigned short const & a1) -> void { return bgfx::setViewOrder(a0, a1); }, "", pybind11::arg("_id"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_view_order", (void (*)(unsigned short, unsigned short, const void *)) &bgfx::setViewOrder, "Post submit view reordering.\n\n \n First view id.\n \n\n Number of views to remap.\n \n\n View remap id table. Passing `NULL` will reset view ids\n   to default state.\n\n \n C99 equivalent is `bgfx_set_view_order`.\n\nC++: bgfx::setViewOrder(unsigned short, unsigned short, const unsigned short *) --> void", pybind11::arg("_id"), pybind11::arg("_num"), pybind11::arg("_remap"), pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: bgfx_8.cpp
#include <bgfx.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_bgfx_8(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// bgfx::resetView(unsigned short) file:bgfx.h line:3391
	M("bgfx").def("reset_view", (void (*)(unsigned short)) &bgfx::resetView, "Reset all view settings to default.\n\n \n View id.\n\n \n C99 equivalent is `bgfx_reset_view`.\n\nC++: bgfx::resetView(unsigned short) --> void", pybind11::arg("_id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setMarker(const char *) file:bgfx.h line:3397
	M("bgfx").def("set_marker", (void (*)(const char *)) &bgfx::setMarker, "Sets debug marker.\n\n \n C99 equivalent is `bgfx_set_marker`.\n\nC++: bgfx::setMarker(const char *) --> void", pybind11::arg("_marker"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setState(uint64_t, unsigned int) file:bgfx.h line:3427
	M("bgfx").def("set_state", [](uint64_t const & a0) -> void { return bgfx::setState(a0); }, "", pybind11::arg("_state"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_state", (void (*)(uint64_t, unsigned int)) &bgfx::setState, "Set render states for draw primitive.\n\n \n State flags. Default state for primitive type is\n   triangles. See: `BGFX_STATE_DEFAULT`.\n   - `BGFX_STATE_DEPTH_TEST_*` - Depth test function.\n   - `BGFX_STATE_BLEND_*` - See remark 1 about BGFX_STATE_BLEND_FUNC.\n   - `BGFX_STATE_BLEND_EQUATION_*` - See remark 2.\n   - `BGFX_STATE_CULL_*` - Backface culling mode.\n   - `BGFX_STATE_WRITE_*` - Enable R, G, B, A or Z write.\n   - `BGFX_STATE_MSAA` - Enable MSAA.\n   - `BGFX_STATE_PT_[TRISTRIP/LINES/POINTS]` - Primitive type.\n\n \n Sets blend factor used by `BGFX_STATE_BLEND_FACTOR` and\n   `BGFX_STATE_BLEND_INV_FACTOR` blend modes.\n\n \n\n   1. To setup more complex states use:\n      `BGFX_STATE_ALPHA_REF(_ref)`,\n      `BGFX_STATE_POINT_SIZE(_size)`,\n      `BGFX_STATE_BLEND_FUNC(_src, _dst)`,\n      `BGFX_STATE_BLEND_FUNC_SEPARATE(_srcRGB, _dstRGB, _srcA, _dstA)`\n      `BGFX_STATE_BLEND_EQUATION(_equation)`\n      `BGFX_STATE_BLEND_EQUATION_SEPARATE(_equationRGB, _equationA)`\n   2. `BGFX_STATE_BLEND_EQUATION_ADD` is set when no other blend\n      equation is specified.\n\n \n C99 equivalent is `bgfx_set_state`.\n\nC++: bgfx::setState(uint64_t, unsigned int) --> void", pybind11::arg("_state"), pybind11::arg("_rgba"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setCondition(struct bgfx::OcclusionQueryHandle, bool) file:bgfx.h line:3439
	M("bgfx").def("set_condition", (void (*)(struct bgfx::OcclusionQueryHandle, bool)) &bgfx::setCondition, "Set condition for rendering.\n\n \n Occlusion query handle.\n \n\n Render if occlusion query is visible.\n\n \n C99 equivalent is `bgfx_set_condition`.\n\nC++: bgfx::setCondition(struct bgfx::OcclusionQueryHandle, bool) --> void", pybind11::arg("_handle"), pybind11::arg("_visible"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setStencil(unsigned int, unsigned int) file:bgfx.h line:3452
	M("bgfx").def("set_stencil", [](unsigned int const & a0) -> void { return bgfx::setStencil(a0); }, "", pybind11::arg("_fstencil"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_stencil", (void (*)(unsigned int, unsigned int)) &bgfx::setStencil, "Set stencil test state.\n\n \n Front stencil state.\n \n\n Back stencil state. If back is set to `BGFX_STENCIL_NONE`\n   _fstencil is applied to both front and back facing primitives.\n\n \n C99 equivalent is `bgfx_set_stencil`.\n\nC++: bgfx::setStencil(unsigned int, unsigned int) --> void", pybind11::arg("_fstencil"), pybind11::arg("_bstencil"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setScissor(unsigned short, unsigned short, unsigned short, unsigned short) file:bgfx.h line:3468
	M("bgfx").def("set_scissor", (unsigned short (*)(unsigned short, unsigned short, unsigned short, unsigned short)) &bgfx::setScissor, "Set scissor for draw primitive. For scissor for all primitives in\n view see `bgfx::setViewScissor`.\n\n \n Position x from the left corner of the window.\n \n\n Position y from the top corner of the window.\n \n\n Width of scissor region.\n \n\n Height of scissor region.\n \n\n Scissor cache index.\n\n \n C99 equivalent is `bgfx_set_scissor`.\n\nC++: bgfx::setScissor(unsigned short, unsigned short, unsigned short, unsigned short) --> unsigned short", pybind11::arg("_x"), pybind11::arg("_y"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setScissor(unsigned short) file:bgfx.h line:3482
	M("bgfx").def("set_scissor", []() -> void { return bgfx::setScissor(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_scissor", (void (*)(unsigned short)) &bgfx::setScissor, "Set scissor from cache for draw primitive.\n\n \n Index in scissor cache. Passing UINT16_MAX unset primitive\n   scissor and primitive will use view scissor instead.\n\n \n C99 equivalent is `bgfx_set_scissor_cached`.\n\nC++: bgfx::setScissor(unsigned short) --> void", pybind11::arg("_cache"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setTransform(const void *, unsigned short) file:bgfx.h line:3494
	M("bgfx").def("set_transform", [](const void * a0) -> unsigned int { return bgfx::setTransform(a0); }, "", pybind11::arg("_mtx"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_transform", (unsigned int (*)(const void *, unsigned short)) &bgfx::setTransform, "Set model matrix for draw primitive. If it is not called,\n the model will be rendered with an identity model matrix.\n\n \n Pointer to first matrix in array.\n \n\n Number of matrices in array.\n \n\n index into matrix cache in case the same model matrix has\n   to be used for other draw primitive call.\n\n \n C99 equivalent is `bgfx_set_transform`.\n\nC++: bgfx::setTransform(const void *, unsigned short) --> unsigned int", pybind11::arg("_mtx"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::allocTransform(struct bgfx::Transform *, unsigned short) file:bgfx.h line:3508
	M("bgfx").def("alloc_transform", (unsigned int (*)(struct bgfx::Transform *, unsigned short)) &bgfx::allocTransform, "Reserve `_num` matrices in internal matrix cache.\n\n \n Pointer to `Transform` structure.\n \n\n Number of matrices.\n \n\n index into matrix cache.\n\n \n Pointer returned can be modifed until `bgfx::frame` is called.\n \n\n C99 equivalent is `bgfx_alloc_transform`.\n\nC++: bgfx::allocTransform(struct bgfx::Transform *, unsigned short) --> unsigned int", pybind11::arg("_transform"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setTransform(unsigned int, unsigned short) file:bgfx.h line:3520
	M("bgfx").def("set_transform", [](unsigned int const & a0) -> void { return bgfx::setTransform(a0); }, "", pybind11::arg("_cache"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_transform", (void (*)(unsigned int, unsigned short)) &bgfx::setTransform, "Set model matrix from matrix cache for draw primitive.\n\n \n Index in matrix cache.\n \n\n Number of matrices from cache.\n\n \n C99 equivalent is `bgfx_set_transform_cached`.\n\nC++: bgfx::setTransform(unsigned int, unsigned short) --> void", pybind11::arg("_cache"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setUniform(struct bgfx::UniformHandle, const void *, unsigned short) file:bgfx.h line:3534
	M("bgfx").def("set_uniform", [](struct bgfx::UniformHandle const & a0, const void * a1) -> void { return bgfx::setUniform(a0, a1); }, "", pybind11::arg("_handle"), pybind11::arg("_value"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_uniform", (void (*)(struct bgfx::UniformHandle, const void *, unsigned short)) &bgfx::setUniform, "Set shader uniform parameter for draw primitive.\n\n \n Uniform.\n \n\n Pointer to uniform data.\n \n\n Number of elements. Passing `UINT16_MAX` will\n   use the _num passed on uniform creation.\n\n \n C99 equivalent is `bgfx_set_uniform`.\n\nC++: bgfx::setUniform(struct bgfx::UniformHandle, const void *, unsigned short) --> void", pybind11::arg("_handle"), pybind11::arg("_value"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setIndexBuffer(struct bgfx::IndexBufferHandle) file:bgfx.h line:3546
	M("bgfx").def("set_index_buffer", (void (*)(struct bgfx::IndexBufferHandle)) &bgfx::setIndexBuffer, "Set index buffer for draw primitive.\n\n \n Index buffer.\n\n \n C99 equivalent is `bgfx_set_index_buffer`.\n\nC++: bgfx::setIndexBuffer(struct bgfx::IndexBufferHandle) --> void", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setIndexBuffer(struct bgfx::IndexBufferHandle, unsigned int, unsigned int) file:bgfx.h line:3556
	M("bgfx").def("set_index_buffer", (void (*)(struct bgfx::IndexBufferHandle, unsigned int, unsigned int)) &bgfx::setIndexBuffer, "Set index buffer for draw primitive.\n\n \n Index buffer.\n \n\n First index to render.\n \n\n Number of indices to render.\n\n \n C99 equivalent is `bgfx_set_index_buffer`.\n\nC++: bgfx::setIndexBuffer(struct bgfx::IndexBufferHandle, unsigned int, unsigned int) --> void", pybind11::arg("_handle"), pybind11::arg("_firstIndex"), pybind11::arg("_numIndices"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setIndexBuffer(struct bgfx::DynamicIndexBufferHandle) file:bgfx.h line:3568
	M("bgfx").def("set_index_buffer", (void (*)(struct bgfx::DynamicIndexBufferHandle)) &bgfx::setIndexBuffer, "Set index buffer for draw primitive.\n\n \n Dynamic index buffer.\n\n \n C99 equivalent is `bgfx_set_dynamic_index_buffer`.\n\nC++: bgfx::setIndexBuffer(struct bgfx::DynamicIndexBufferHandle) --> void", pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setIndexBuffer(struct bgfx::DynamicIndexBufferHandle, unsigned int, unsigned int) file:bgfx.h line:3578
	M("bgfx").def("set_index_buffer", (void (*)(struct bgfx::DynamicIndexBufferHandle, unsigned int, unsigned int)) &bgfx::setIndexBuffer, "Set index buffer for draw primitive.\n\n \n Dynamic index buffer.\n \n\n First index to render.\n \n\n Number of indices to render.\n\n \n C99 equivalent is `bgfx_set_dynamic_index_buffer`.\n\nC++: bgfx::setIndexBuffer(struct bgfx::DynamicIndexBufferHandle, unsigned int, unsigned int) --> void", pybind11::arg("_handle"), pybind11::arg("_firstIndex"), pybind11::arg("_numIndices"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setIndexBuffer(const struct bgfx::TransientIndexBuffer *) file:bgfx.h line:3590
	M("bgfx").def("set_index_buffer", (void (*)(const struct bgfx::TransientIndexBuffer *)) &bgfx::setIndexBuffer, "Set index buffer for draw primitive.\n\n \n Transient index buffer.\n\n \n C99 equivalent is `bgfx_set_transient_index_buffer`.\n\nC++: bgfx::setIndexBuffer(const struct bgfx::TransientIndexBuffer *) --> void", pybind11::arg("_tib"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setIndexBuffer(const struct bgfx::TransientIndexBuffer *, unsigned int, unsigned int) file:bgfx.h line:3600
	M("bgfx").def("set_index_buffer", (void (*)(const struct bgfx::TransientIndexBuffer *, unsigned int, unsigned int)) &bgfx::setIndexBuffer, "Set index buffer for draw primitive.\n\n \n Transient index buffer.\n \n\n First index to render.\n \n\n Number of indices to render.\n\n \n C99 equivalent is `bgfx_set_transient_index_buffer`.\n\nC++: bgfx::setIndexBuffer(const struct bgfx::TransientIndexBuffer *, unsigned int, unsigned int) --> void", pybind11::arg("_tib"), pybind11::arg("_firstIndex"), pybind11::arg("_numIndices"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setVertexBuffer(unsigned char, struct bgfx::VertexBufferHandle) file:bgfx.h line:3613
	M("bgfx").def("set_vertex_buffer", (void (*)(unsigned char, struct bgfx::VertexBufferHandle)) &bgfx::setVertexBuffer, "Set vertex buffer for draw primitive.\n\n \n Vertex stream.\n \n\n Vertex buffer.\n\n \n C99 equivalent is `bgfx_set_vertex_buffer`.\n\nC++: bgfx::setVertexBuffer(unsigned char, struct bgfx::VertexBufferHandle) --> void", pybind11::arg("_stream"), pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setVertexBuffer(unsigned char, struct bgfx::VertexBufferHandle, unsigned int, unsigned int, struct bgfx::VertexLayoutHandle) file:bgfx.h line:3628
	M("bgfx").def("set_vertex_buffer", [](unsigned char const & a0, struct bgfx::VertexBufferHandle const & a1, unsigned int const & a2, unsigned int const & a3) -> void { return bgfx::setVertexBuffer(a0, a1, a2, a3); }, "", pybind11::arg("_stream"), pybind11::arg("_handle"), pybind11::arg("_startVertex"), pybind11::arg("_numVertices"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_vertex_buffer", (void (*)(unsigned char, struct bgfx::VertexBufferHandle, unsigned int, unsigned int, struct bgfx::VertexLayoutHandle)) &bgfx::setVertexBuffer, "Set vertex buffer for draw primitive.\n\n \n Vertex stream.\n \n\n Vertex buffer.\n \n\n First vertex to render.\n \n\n Number of vertices to render.\n \n\n Vertex layout for aliasing vertex buffer.\n\n \n C99 equivalent is `bgfx_set_vertex_buffer`.\n\nC++: bgfx::setVertexBuffer(unsigned char, struct bgfx::VertexBufferHandle, unsigned int, unsigned int, struct bgfx::VertexLayoutHandle) --> void", pybind11::arg("_stream"), pybind11::arg("_handle"), pybind11::arg("_startVertex"), pybind11::arg("_numVertices"), pybind11::arg("_layoutHandle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setVertexBuffer(unsigned char, struct bgfx::DynamicVertexBufferHandle) file:bgfx.h line:3643
	M("bgfx").def("set_vertex_buffer", (void (*)(unsigned char, struct bgfx::DynamicVertexBufferHandle)) &bgfx::setVertexBuffer, "Set vertex buffer for draw primitive.\n\n \n Vertex stream.\n \n\n Dynamic vertex buffer.\n\n \n C99 equivalent is `bgfx_set_dynamic_vertex_buffer`.\n\nC++: bgfx::setVertexBuffer(unsigned char, struct bgfx::DynamicVertexBufferHandle) --> void", pybind11::arg("_stream"), pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setVertexBuffer(unsigned char, struct bgfx::DynamicVertexBufferHandle, unsigned int, unsigned int, struct bgfx::VertexLayoutHandle) file:bgfx.h line:3658
	M("bgfx").def("set_vertex_buffer", [](unsigned char const & a0, struct bgfx::DynamicVertexBufferHandle const & a1, unsigned int const & a2, unsigned int const & a3) -> void { return bgfx::setVertexBuffer(a0, a1, a2, a3); }, "", pybind11::arg("_stream"), pybind11::arg("_handle"), pybind11::arg("_startVertex"), pybind11::arg("_numVertices"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_vertex_buffer", (void (*)(unsigned char, struct bgfx::DynamicVertexBufferHandle, unsigned int, unsigned int, struct bgfx::VertexLayoutHandle)) &bgfx::setVertexBuffer, "Set vertex buffer for draw primitive.\n\n \n Vertex stream.\n \n\n Dynamic vertex buffer.\n \n\n First vertex to render.\n \n\n Number of vertices to render.\n \n\n Vertex layout for aliasing vertex buffer.\n\n \n C99 equivalent is `bgfx_set_dynamic_vertex_buffer`.\n\nC++: bgfx::setVertexBuffer(unsigned char, struct bgfx::DynamicVertexBufferHandle, unsigned int, unsigned int, struct bgfx::VertexLayoutHandle) --> void", pybind11::arg("_stream"), pybind11::arg("_handle"), pybind11::arg("_startVertex"), pybind11::arg("_numVertices"), pybind11::arg("_layoutHandle"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setVertexBuffer(unsigned char, const struct bgfx::TransientVertexBuffer *) file:bgfx.h line:3673
	M("bgfx").def("set_vertex_buffer", (void (*)(unsigned char, const struct bgfx::TransientVertexBuffer *)) &bgfx::setVertexBuffer, "Set vertex buffer for draw primitive.\n\n \n Vertex stream.\n \n\n Transient vertex buffer.\n\n \n C99 equivalent is `bgfx_set_transient_vertex_buffer`.\n\nC++: bgfx::setVertexBuffer(unsigned char, const struct bgfx::TransientVertexBuffer *) --> void", pybind11::arg("_stream"), pybind11::arg("_tvb"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setVertexBuffer(unsigned char, const struct bgfx::TransientVertexBuffer *, unsigned int, unsigned int, struct bgfx::VertexLayoutHandle) file:bgfx.h line:3688
	M("bgfx").def("set_vertex_buffer", [](unsigned char const & a0, const struct bgfx::TransientVertexBuffer * a1, unsigned int const & a2, unsigned int const & a3) -> void { return bgfx::setVertexBuffer(a0, a1, a2, a3); }, "", pybind11::arg("_stream"), pybind11::arg("_tvb"), pybind11::arg("_startVertex"), pybind11::arg("_numVertices"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_vertex_buffer", (void (*)(unsigned char, const struct bgfx::TransientVertexBuffer *, unsigned int, unsigned int, struct bgfx::VertexLayoutHandle)) &bgfx::setVertexBuffer, "Set vertex buffer for draw primitive.\n\n \n Vertex stream.\n \n\n Transient vertex buffer.\n \n\n First vertex to render.\n \n\n Number of vertices to render.\n \n\n Vertex layout for aliasing vertex buffer.\n\n \n C99 equivalent is `bgfx_set_transient_vertex_buffer`.\n\nC++: bgfx::setVertexBuffer(unsigned char, const struct bgfx::TransientVertexBuffer *, unsigned int, unsigned int, struct bgfx::VertexLayoutHandle) --> void", pybind11::arg("_stream"), pybind11::arg("_tvb"), pybind11::arg("_startVertex"), pybind11::arg("_numVertices"), pybind11::arg("_layoutHandle"), pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: bgfx_9.cpp
#include <bgfx.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_bgfx_9(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// bgfx::setVertexCount(unsigned int) file:bgfx.h line:3704
	M("bgfx").def("set_vertex_count", (void (*)(unsigned int)) &bgfx::setVertexCount, "Set number of vertices for auto generated vertices use in conjuction\n with gl_VertexID.\n\n \n Number of vertices.\n\n \n Availability depends on: `BGFX_CAPS_VERTEX_ID`.\n \n\n C99 equivalent is `bgfx_set_vertex_count`.\n\nC++: bgfx::setVertexCount(unsigned int) --> void", pybind11::arg("_numVertices"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setInstanceDataBuffer(const struct bgfx::InstanceDataBuffer *) file:bgfx.h line:3712
	M("bgfx").def("set_instance_data_buffer", (void (*)(const struct bgfx::InstanceDataBuffer *)) &bgfx::setInstanceDataBuffer, "Set instance data buffer for draw primitive.\n\n \n Transient instance data buffer.\n\n \n C99 equivalent is `bgfx_set_instance_data_buffer`.\n\nC++: bgfx::setInstanceDataBuffer(const struct bgfx::InstanceDataBuffer *) --> void", pybind11::arg("_idb"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setInstanceDataBuffer(const struct bgfx::InstanceDataBuffer *, unsigned int, unsigned int) file:bgfx.h line:3722
	M("bgfx").def("set_instance_data_buffer", (void (*)(const struct bgfx::InstanceDataBuffer *, unsigned int, unsigned int)) &bgfx::setInstanceDataBuffer, "Set instance data buffer for draw primitive.\n\n \n Transient instance data buffer.\n \n\n First instance data.\n \n\n Number of data instances.\n\n \n C99 equivalent is `bgfx_set_instance_data_buffer`.\n\nC++: bgfx::setInstanceDataBuffer(const struct bgfx::InstanceDataBuffer *, unsigned int, unsigned int) --> void", pybind11::arg("_idb"), pybind11::arg("_start"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setInstanceDataBuffer(struct bgfx::VertexBufferHandle, unsigned int, unsigned int) file:bgfx.h line:3736
	M("bgfx").def("set_instance_data_buffer", (void (*)(struct bgfx::VertexBufferHandle, unsigned int, unsigned int)) &bgfx::setInstanceDataBuffer, "Set instance data buffer for draw primitive.\n\n \n Vertex buffer.\n \n\n First instance data.\n \n\n Number of data instances.\n\n \n C99 equivalent is `bgfx_set_instance_data_from_vertex_buffer`.\n\nC++: bgfx::setInstanceDataBuffer(struct bgfx::VertexBufferHandle, unsigned int, unsigned int) --> void", pybind11::arg("_handle"), pybind11::arg("_start"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setInstanceDataBuffer(struct bgfx::DynamicVertexBufferHandle, unsigned int, unsigned int) file:bgfx.h line:3750
	M("bgfx").def("set_instance_data_buffer", (void (*)(struct bgfx::DynamicVertexBufferHandle, unsigned int, unsigned int)) &bgfx::setInstanceDataBuffer, "Set instance data buffer for draw primitive.\n\n \n Vertex buffer.\n \n\n First instance data.\n \n\n Number of data instances.\n\n \n C99 equivalent is `bgfx_set_instance_data_from_dynamic_vertex_buffer`.\n\nC++: bgfx::setInstanceDataBuffer(struct bgfx::DynamicVertexBufferHandle, unsigned int, unsigned int) --> void", pybind11::arg("_handle"), pybind11::arg("_start"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setInstanceCount(unsigned int) file:bgfx.h line:3764
	M("bgfx").def("set_instance_count", (void (*)(unsigned int)) &bgfx::setInstanceCount, "Set number of instances for auto generated instances use in conjuction\n with gl_InstanceID.\n\n \n Number of instances.\n\n \n Availability depends on: `BGFX_CAPS_VERTEX_ID`.\n \n\n C99 equivalent is `bgfx_set_instance_count`.\n\nC++: bgfx::setInstanceCount(unsigned int) --> void", pybind11::arg("_numInstances"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setTexture(unsigned char, struct bgfx::UniformHandle, struct bgfx::TextureHandle, unsigned int) file:bgfx.h line:3780
	M("bgfx").def("set_texture", [](unsigned char const & a0, struct bgfx::UniformHandle const & a1, struct bgfx::TextureHandle const & a2) -> void { return bgfx::setTexture(a0, a1, a2); }, "", pybind11::arg("_stage"), pybind11::arg("_sampler"), pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_texture", (void (*)(unsigned char, struct bgfx::UniformHandle, struct bgfx::TextureHandle, unsigned int)) &bgfx::setTexture, "Set texture stage for draw primitive.\n\n \n Texture unit.\n \n\n Program sampler.\n \n\n Texture handle.\n \n\n Texture sampling mode. Default value UINT32_MAX uses\n   texture sampling settings from the texture.\n   - `BGFX_SAMPLER_[U/V/W]_[MIRROR/CLAMP]` - Mirror or clamp to edge wrap\n     mode.\n   - `BGFX_SAMPLER_[MIN/MAG/MIP]_[POINT/ANISOTROPIC]` - Point or anisotropic\n     sampling.\n\n \n C99 equivalent is `bgfx_set_texture`.\n\nC++: bgfx::setTexture(unsigned char, struct bgfx::UniformHandle, struct bgfx::TextureHandle, unsigned int) --> void", pybind11::arg("_stage"), pybind11::arg("_sampler"), pybind11::arg("_handle"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::touch(unsigned short) file:bgfx.h line:3796
	M("bgfx").def("touch", (void (*)(unsigned short)) &bgfx::touch, "Submit an empty primitive for rendering. Uniforms and draw state\n will be applied but no geometry will be submitted.\n\n These empty draw calls will sort before ordinary draw calls.\n\n \n View id.\n\n \n C99 equivalent is `bgfx_touch`.\n\nC++: bgfx::touch(unsigned short) --> void", pybind11::arg("_id"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::submit(unsigned short, struct bgfx::ProgramHandle, unsigned int, unsigned char) file:bgfx.h line:3834
	M("bgfx").def("submit", [](unsigned short const & a0, struct bgfx::ProgramHandle const & a1) -> void { return bgfx::submit(a0, a1); }, "", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("submit", [](unsigned short const & a0, struct bgfx::ProgramHandle const & a1, unsigned int const & a2) -> void { return bgfx::submit(a0, a1, a2); }, "", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::arg("_depth"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("submit", (void (*)(unsigned short, struct bgfx::ProgramHandle, unsigned int, unsigned char)) &bgfx::submit, "Submit primitive for rendering.\n\n \n View id.\n \n\n Program.\n \n\n Depth for sorting.\n \n\n Discard or preserve states. See `BGFX_DISCARD_*`.\n\n \n C99 equivalent is `bgfx_submit`.\n\nC++: bgfx::submit(unsigned short, struct bgfx::ProgramHandle, unsigned int, unsigned char) --> void", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::arg("_depth"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::submit(unsigned short, struct bgfx::ProgramHandle, struct bgfx::OcclusionQueryHandle, unsigned int, unsigned char) file:bgfx.h line:3851
	M("bgfx").def("submit", [](unsigned short const & a0, struct bgfx::ProgramHandle const & a1, struct bgfx::OcclusionQueryHandle const & a2) -> void { return bgfx::submit(a0, a1, a2); }, "", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::arg("_occlusionQuery"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("submit", [](unsigned short const & a0, struct bgfx::ProgramHandle const & a1, struct bgfx::OcclusionQueryHandle const & a2, unsigned int const & a3) -> void { return bgfx::submit(a0, a1, a2, a3); }, "", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::arg("_occlusionQuery"), pybind11::arg("_depth"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("submit", (void (*)(unsigned short, struct bgfx::ProgramHandle, struct bgfx::OcclusionQueryHandle, unsigned int, unsigned char)) &bgfx::submit, "Submit primitive with occlusion query for rendering.\n\n \n View id.\n \n\n Program.\n \n\n Occlusion query.\n \n\n Depth for sorting.\n \n\n Discard or preserve states. See `BGFX_DISCARD_*`.\n\n \n C99 equivalent is `bgfx_submit_occlusion_query`.\n\nC++: bgfx::submit(unsigned short, struct bgfx::ProgramHandle, struct bgfx::OcclusionQueryHandle, unsigned int, unsigned char) --> void", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::arg("_occlusionQuery"), pybind11::arg("_depth"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::submit(unsigned short, struct bgfx::ProgramHandle, struct bgfx::IndirectBufferHandle, unsigned short, unsigned short, unsigned int, unsigned char) file:bgfx.h line:3872
	M("bgfx").def("submit", [](unsigned short const & a0, struct bgfx::ProgramHandle const & a1, struct bgfx::IndirectBufferHandle const & a2) -> void { return bgfx::submit(a0, a1, a2); }, "", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::arg("_indirectHandle"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("submit", [](unsigned short const & a0, struct bgfx::ProgramHandle const & a1, struct bgfx::IndirectBufferHandle const & a2, unsigned short const & a3) -> void { return bgfx::submit(a0, a1, a2, a3); }, "", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::arg("_indirectHandle"), pybind11::arg("_start"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("submit", [](unsigned short const & a0, struct bgfx::ProgramHandle const & a1, struct bgfx::IndirectBufferHandle const & a2, unsigned short const & a3, unsigned short const & a4) -> void { return bgfx::submit(a0, a1, a2, a3, a4); }, "", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::arg("_indirectHandle"), pybind11::arg("_start"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("submit", [](unsigned short const & a0, struct bgfx::ProgramHandle const & a1, struct bgfx::IndirectBufferHandle const & a2, unsigned short const & a3, unsigned short const & a4, unsigned int const & a5) -> void { return bgfx::submit(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::arg("_indirectHandle"), pybind11::arg("_start"), pybind11::arg("_num"), pybind11::arg("_depth"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("submit", (void (*)(unsigned short, struct bgfx::ProgramHandle, struct bgfx::IndirectBufferHandle, unsigned short, unsigned short, unsigned int, unsigned char)) &bgfx::submit, "Submit primitive for rendering with index and instance data info from\n indirect buffer.\n\n \n View id.\n \n\n Program.\n \n\n Indirect buffer.\n \n\n First element in indirect buffer.\n \n\n Number of dispatches.\n \n\n Depth for sorting.\n \n\n Discard or preserve states. See `BGFX_DISCARD_*`.\n\n \n C99 equivalent is `bgfx_submit_indirect`.\n\nC++: bgfx::submit(unsigned short, struct bgfx::ProgramHandle, struct bgfx::IndirectBufferHandle, unsigned short, unsigned short, unsigned int, unsigned char) --> void", pybind11::arg("_id"), pybind11::arg("_program"), pybind11::arg("_indirectHandle"), pybind11::arg("_start"), pybind11::arg("_num"), pybind11::arg("_depth"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setBuffer(unsigned char, struct bgfx::IndexBufferHandle, enum bgfx::Access::Enum) file:bgfx.h line:3866
	M("bgfx").def("set_buffer", (void (*)(unsigned char, struct bgfx::IndexBufferHandle, enum bgfx::Access::Enum)) &bgfx::setBuffer, "Set compute index buffer.\n\n \n Compute stage.\n \n\n Index buffer handle.\n \n\n Buffer access. See `Access::Enum`.\n\n \n C99 equivalent is `bgfx_set_compute_index_buffer`.\n\nC++: bgfx::setBuffer(unsigned char, struct bgfx::IndexBufferHandle, enum bgfx::Access::Enum) --> void", pybind11::arg("_stage"), pybind11::arg("_handle"), pybind11::arg("_access"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setBuffer(unsigned char, struct bgfx::VertexBufferHandle, enum bgfx::Access::Enum) file:bgfx.h line:3880
	M("bgfx").def("set_buffer", (void (*)(unsigned char, struct bgfx::VertexBufferHandle, enum bgfx::Access::Enum)) &bgfx::setBuffer, "Set compute vertex buffer.\n\n \n Compute stage.\n \n\n Vertex buffer handle.\n \n\n Buffer access. See `Access::Enum`.\n\n \n C99 equivalent is `bgfx_set_compute_vertex_buffer`.\n\nC++: bgfx::setBuffer(unsigned char, struct bgfx::VertexBufferHandle, enum bgfx::Access::Enum) --> void", pybind11::arg("_stage"), pybind11::arg("_handle"), pybind11::arg("_access"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setBuffer(unsigned char, struct bgfx::DynamicIndexBufferHandle, enum bgfx::Access::Enum) file:bgfx.h line:3894
	M("bgfx").def("set_buffer", (void (*)(unsigned char, struct bgfx::DynamicIndexBufferHandle, enum bgfx::Access::Enum)) &bgfx::setBuffer, "Set compute dynamic index buffer.\n\n \n Compute stage.\n \n\n Dynamic index buffer handle.\n \n\n Buffer access. See `Access::Enum`.\n\n \n C99 equivalent is `bgfx_set_compute_dynamic_index_buffer`.\n\nC++: bgfx::setBuffer(unsigned char, struct bgfx::DynamicIndexBufferHandle, enum bgfx::Access::Enum) --> void", pybind11::arg("_stage"), pybind11::arg("_handle"), pybind11::arg("_access"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setBuffer(unsigned char, struct bgfx::DynamicVertexBufferHandle, enum bgfx::Access::Enum) file:bgfx.h line:3908
	M("bgfx").def("set_buffer", (void (*)(unsigned char, struct bgfx::DynamicVertexBufferHandle, enum bgfx::Access::Enum)) &bgfx::setBuffer, "Set compute dynamic vertex buffer.\n\n \n Compute stage.\n \n\n Dynamic vertex buffer handle.\n \n\n Buffer access. See `Access::Enum`.\n\n \n C99 equivalent is `bgfx_set_compute_dynamic_vertex_buffer`.\n\nC++: bgfx::setBuffer(unsigned char, struct bgfx::DynamicVertexBufferHandle, enum bgfx::Access::Enum) --> void", pybind11::arg("_stage"), pybind11::arg("_handle"), pybind11::arg("_access"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setBuffer(unsigned char, struct bgfx::IndirectBufferHandle, enum bgfx::Access::Enum) file:bgfx.h line:3922
	M("bgfx").def("set_buffer", (void (*)(unsigned char, struct bgfx::IndirectBufferHandle, enum bgfx::Access::Enum)) &bgfx::setBuffer, "Set compute indirect buffer.\n\n \n Compute stage.\n \n\n Indirect buffer handle.\n \n\n Buffer access. See `Access::Enum`.\n\n \n C99 equivalent is `bgfx_set_compute_indirect_buffer`.\n\nC++: bgfx::setBuffer(unsigned char, struct bgfx::IndirectBufferHandle, enum bgfx::Access::Enum) --> void", pybind11::arg("_stage"), pybind11::arg("_handle"), pybind11::arg("_access"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setImage(unsigned char, struct bgfx::TextureHandle, unsigned char, enum bgfx::Access::Enum, enum bgfx::TextureFormat::Enum) file:bgfx.h line:3938
	M("bgfx").def("set_image", [](unsigned char const & a0, struct bgfx::TextureHandle const & a1, unsigned char const & a2, enum bgfx::Access::Enum const & a3) -> void { return bgfx::setImage(a0, a1, a2, a3); }, "", pybind11::arg("_stage"), pybind11::arg("_handle"), pybind11::arg("_mip"), pybind11::arg("_access"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("set_image", (void (*)(unsigned char, struct bgfx::TextureHandle, unsigned char, enum bgfx::Access::Enum, enum bgfx::TextureFormat::Enum)) &bgfx::setImage, "Set compute image from texture.\n\n \n Texture unit.\n \n\n Texture handle.\n \n\n Mip level.\n \n\n Texture access. See `Access::Enum`.\n \n\n Texture format. See: `TextureFormat::Enum`.\n\n \n C99 equivalent is `bgfx_set_image`.\n\nC++: bgfx::setImage(unsigned char, struct bgfx::TextureHandle, unsigned char, enum bgfx::Access::Enum, enum bgfx::TextureFormat::Enum) --> void", pybind11::arg("_stage"), pybind11::arg("_handle"), pybind11::arg("_mip"), pybind11::arg("_access"), pybind11::arg("_format"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::dispatch(unsigned short, struct bgfx::ProgramHandle, unsigned int, unsigned int, unsigned int, unsigned char) file:bgfx.h line:3981
	M("bgfx").def("dispatch", [](unsigned short const & a0, struct bgfx::ProgramHandle const & a1) -> void { return bgfx::dispatch(a0, a1); }, "", pybind11::arg("_id"), pybind11::arg("_handle"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("dispatch", [](unsigned short const & a0, struct bgfx::ProgramHandle const & a1, unsigned int const & a2) -> void { return bgfx::dispatch(a0, a1, a2); }, "", pybind11::arg("_id"), pybind11::arg("_handle"), pybind11::arg("_numX"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("dispatch", [](unsigned short const & a0, struct bgfx::ProgramHandle const & a1, unsigned int const & a2, unsigned int const & a3) -> void { return bgfx::dispatch(a0, a1, a2, a3); }, "", pybind11::arg("_id"), pybind11::arg("_handle"), pybind11::arg("_numX"), pybind11::arg("_numY"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("dispatch", [](unsigned short const & a0, struct bgfx::ProgramHandle const & a1, unsigned int const & a2, unsigned int const & a3, unsigned int const & a4) -> void { return bgfx::dispatch(a0, a1, a2, a3, a4); }, "", pybind11::arg("_id"), pybind11::arg("_handle"), pybind11::arg("_numX"), pybind11::arg("_numY"), pybind11::arg("_numZ"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("dispatch", (void (*)(unsigned short, struct bgfx::ProgramHandle, unsigned int, unsigned int, unsigned int, unsigned char)) &bgfx::dispatch, "Dispatch compute.\n\n \n View id.\n \n\n Compute program.\n \n\n Number of groups X.\n \n\n Number of groups Y.\n \n\n Number of groups Z.\n \n\n Discard or preserve states. See `BGFX_DISCARD_*`.\n\n \n C99 equivalent is `bgfx_dispatch`.\n\nC++: bgfx::dispatch(unsigned short, struct bgfx::ProgramHandle, unsigned int, unsigned int, unsigned int, unsigned char) --> void", pybind11::arg("_id"), pybind11::arg("_handle"), pybind11::arg("_numX"), pybind11::arg("_numY"), pybind11::arg("_numZ"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());
}


// File: bgfx_10.cpp
#include <bgfx.h>
#include <platform.h>
#include <sstream> // __str__

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_bgfx_10(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
   // bgfx::dispatch(unsigned short, struct bgfx::ProgramHandle, struct bgfx::IndirectBufferHandle, unsigned short, unsigned short, unsigned char) file:bgfx.h line:4001
	M("bgfx").def("dispatch", [](unsigned short const & a0, struct bgfx::ProgramHandle const & a1, struct bgfx::IndirectBufferHandle const & a2) -> void { return bgfx::dispatch(a0, a1, a2); }, "", pybind11::arg("_id"), pybind11::arg("_handle"), pybind11::arg("_indirectHandle"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("dispatch", [](unsigned short const & a0, struct bgfx::ProgramHandle const & a1, struct bgfx::IndirectBufferHandle const & a2, unsigned short const & a3) -> void { return bgfx::dispatch(a0, a1, a2, a3); }, "", pybind11::arg("_id"), pybind11::arg("_handle"), pybind11::arg("_indirectHandle"), pybind11::arg("_start"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("dispatch", [](unsigned short const & a0, struct bgfx::ProgramHandle const & a1, struct bgfx::IndirectBufferHandle const & a2, unsigned short const & a3, unsigned short const & a4) -> void { return bgfx::dispatch(a0, a1, a2, a3, a4); }, "", pybind11::arg("_id"), pybind11::arg("_handle"), pybind11::arg("_indirectHandle"), pybind11::arg("_start"), pybind11::arg("_num"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("dispatch", (void (*)(unsigned short, struct bgfx::ProgramHandle, struct bgfx::IndirectBufferHandle, unsigned short, unsigned short, unsigned char)) &bgfx::dispatch, "Dispatch compute indirect.\n\n \n View id.\n \n\n Compute program.\n \n\n Indirect buffer.\n \n\n First element in indirect buffer.\n \n\n Number of dispatches.\n \n\n Discard or preserve states. See `BGFX_DISCARD_*`.\n\n \n C99 equivalent is `bgfx_dispatch_indirect`.\n\nC++: bgfx::dispatch(unsigned short, struct bgfx::ProgramHandle, struct bgfx::IndirectBufferHandle, unsigned short, unsigned short, unsigned char) --> void", pybind11::arg("_id"), pybind11::arg("_handle"), pybind11::arg("_indirectHandle"), pybind11::arg("_start"), pybind11::arg("_num"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::discard() file:bgfx.h line:3986
	M("bgfx").def("discard", (void (*)()) &bgfx::discard, "Discard all previously set state for draw or compute call.\n\n \n C99 equivalent is `bgfx_discard`.\n\nC++: bgfx::discard() --> void", pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::blit(unsigned short, struct bgfx::TextureHandle, unsigned short, unsigned short, struct bgfx::TextureHandle, unsigned short, unsigned short, unsigned short, unsigned short) file:bgfx.h line:4004
	M("bgfx").def("blit", [](unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned short const & a2, unsigned short const & a3, struct bgfx::TextureHandle const & a4) -> void { return bgfx::blit(a0, a1, a2, a3, a4); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_src"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("blit", [](unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned short const & a2, unsigned short const & a3, struct bgfx::TextureHandle const & a4, unsigned short const & a5) -> void { return bgfx::blit(a0, a1, a2, a3, a4, a5); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_src"), pybind11::arg("_srcX"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("blit", [](unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned short const & a2, unsigned short const & a3, struct bgfx::TextureHandle const & a4, unsigned short const & a5, unsigned short const & a6) -> void { return bgfx::blit(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_src"), pybind11::arg("_srcX"), pybind11::arg("_srcY"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("blit", [](unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned short const & a2, unsigned short const & a3, struct bgfx::TextureHandle const & a4, unsigned short const & a5, unsigned short const & a6, unsigned short const & a7) -> void { return bgfx::blit(a0, a1, a2, a3, a4, a5, a6, a7); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_src"), pybind11::arg("_srcX"), pybind11::arg("_srcY"), pybind11::arg("_width"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("blit", (void (*)(unsigned short, struct bgfx::TextureHandle, unsigned short, unsigned short, struct bgfx::TextureHandle, unsigned short, unsigned short, unsigned short, unsigned short)) &bgfx::blit, "Blit 2D texture region between two 2D textures.\n\n \n View id.\n \n\n Destination texture handle.\n \n\n Destination texture X position.\n \n\n Destination texture Y position.\n \n\n Source texture handle.\n \n\n Source texture X position.\n \n\n Source texture Y position.\n \n\n Width of region.\n \n\n Height of region.\n\n \n Destination texture must be created with `BGFX_TEXTURE_BLIT_DST` flag.\n \n\n Availability depends on: `BGFX_CAPS_TEXTURE_BLIT`.\n \n\n C99 equivalent is `bgfx_blit`.\n\nC++: bgfx::blit(unsigned short, struct bgfx::TextureHandle, unsigned short, unsigned short, struct bgfx::TextureHandle, unsigned short, unsigned short, unsigned short, unsigned short) --> void", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_src"), pybind11::arg("_srcX"), pybind11::arg("_srcY"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::blit(unsigned short, struct bgfx::TextureHandle, unsigned char, unsigned short, unsigned short, unsigned short, struct bgfx::TextureHandle, unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short) file:bgfx.h line:4042
	M("bgfx").def("blit", [](unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned char const & a2, unsigned short const & a3, unsigned short const & a4, unsigned short const & a5, struct bgfx::TextureHandle const & a6) -> void { return bgfx::blit(a0, a1, a2, a3, a4, a5, a6); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstMip"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_dstZ"), pybind11::arg("_src"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("blit", [](unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned char const & a2, unsigned short const & a3, unsigned short const & a4, unsigned short const & a5, struct bgfx::TextureHandle const & a6, unsigned char const & a7) -> void { return bgfx::blit(a0, a1, a2, a3, a4, a5, a6, a7); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstMip"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_dstZ"), pybind11::arg("_src"), pybind11::arg("_srcMip"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("blit", [](unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned char const & a2, unsigned short const & a3, unsigned short const & a4, unsigned short const & a5, struct bgfx::TextureHandle const & a6, unsigned char const & a7, unsigned short const & a8) -> void { return bgfx::blit(a0, a1, a2, a3, a4, a5, a6, a7, a8); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstMip"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_dstZ"), pybind11::arg("_src"), pybind11::arg("_srcMip"), pybind11::arg("_srcX"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("blit", [](unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned char const & a2, unsigned short const & a3, unsigned short const & a4, unsigned short const & a5, struct bgfx::TextureHandle const & a6, unsigned char const & a7, unsigned short const & a8, unsigned short const & a9) -> void { return bgfx::blit(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstMip"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_dstZ"), pybind11::arg("_src"), pybind11::arg("_srcMip"), pybind11::arg("_srcX"), pybind11::arg("_srcY"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("blit", [](unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned char const & a2, unsigned short const & a3, unsigned short const & a4, unsigned short const & a5, struct bgfx::TextureHandle const & a6, unsigned char const & a7, unsigned short const & a8, unsigned short const & a9, unsigned short const & a10) -> void { return bgfx::blit(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstMip"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_dstZ"), pybind11::arg("_src"), pybind11::arg("_srcMip"), pybind11::arg("_srcX"), pybind11::arg("_srcY"), pybind11::arg("_srcZ"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("blit", [](unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned char const & a2, unsigned short const & a3, unsigned short const & a4, unsigned short const & a5, struct bgfx::TextureHandle const & a6, unsigned char const & a7, unsigned short const & a8, unsigned short const & a9, unsigned short const & a10, unsigned short const & a11) -> void { return bgfx::blit(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstMip"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_dstZ"), pybind11::arg("_src"), pybind11::arg("_srcMip"), pybind11::arg("_srcX"), pybind11::arg("_srcY"), pybind11::arg("_srcZ"), pybind11::arg("_width"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("blit", [](unsigned short const & a0, struct bgfx::TextureHandle const & a1, unsigned char const & a2, unsigned short const & a3, unsigned short const & a4, unsigned short const & a5, struct bgfx::TextureHandle const & a6, unsigned char const & a7, unsigned short const & a8, unsigned short const & a9, unsigned short const & a10, unsigned short const & a11, unsigned short const & a12) -> void { return bgfx::blit(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12); }, "", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstMip"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_dstZ"), pybind11::arg("_src"), pybind11::arg("_srcMip"), pybind11::arg("_srcX"), pybind11::arg("_srcY"), pybind11::arg("_srcZ"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("blit", (void (*)(unsigned short, struct bgfx::TextureHandle, unsigned char, unsigned short, unsigned short, unsigned short, struct bgfx::TextureHandle, unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short)) &bgfx::blit, "Blit texture region between two textures.\n\n \n View id.\n \n\n Destination texture handle.\n \n\n Destination texture mip level.\n \n\n Destination texture X position.\n \n\n Destination texture Y position.\n \n\n If texture is 2D this argument should be 0. If destination texture is cube\n   this argument represents destination texture cube face. For 3D texture this argument\n   represents destination texture Z position.\n \n\n Source texture handle.\n \n\n Source texture mip level.\n \n\n Source texture X position.\n \n\n Source texture Y position.\n \n\n If texture is 2D this argument should be 0. If source texture is cube\n   this argument represents source texture cube face. For 3D texture this argument\n   represents source texture Z position.\n \n\n Width of region.\n \n\n Height of region.\n \n\n If texture is 3D this argument represents depth of region, otherwise it's\n   unused.\n\n \n Destination texture must be created with `BGFX_TEXTURE_BLIT_DST` flag.\n \n\n Availability depends on: `BGFX_CAPS_TEXTURE_BLIT`.\n \n\n C99 equivalent is `bgfx_blit`.\n\nC++: bgfx::blit(unsigned short, struct bgfx::TextureHandle, unsigned char, unsigned short, unsigned short, unsigned short, struct bgfx::TextureHandle, unsigned char, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short) --> void", pybind11::arg("_id"), pybind11::arg("_dst"), pybind11::arg("_dstMip"), pybind11::arg("_dstX"), pybind11::arg("_dstY"), pybind11::arg("_dstZ"), pybind11::arg("_src"), pybind11::arg("_srcMip"), pybind11::arg("_srcX"), pybind11::arg("_srcY"), pybind11::arg("_srcZ"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_depth"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::requestScreenShot(struct bgfx::FrameBufferHandle, const char *) file:bgfx.h line:4071
	M("bgfx").def("request_screenshot", (void (*)(struct bgfx::FrameBufferHandle, const char *)) &bgfx::requestScreenShot, "Request screen shot of window back buffer.\n\n \n Frame buffer handle. If handle is `BGFX_INVALID_HANDLE` request will be\n   made for main window back buffer.\n \n\n Will be passed to `bgfx::CallbackI::screenShot` callback.\n\n \n\n   `bgfx::CallbackI::screenShot` must be implemented.\n\n \n Frame buffer handle must be created with OS' target native window handle.\n \n\n C99 equivalent is `bgfx_request_screen_shot`.\n\nC++: bgfx::requestScreenShot(struct bgfx::FrameBufferHandle, const char *) --> void", pybind11::arg("_handle"), pybind11::arg("_filePath"), pybind11::call_guard<pybind11::gil_scoped_release>());

	{ // bgfx::RenderFrame file:platform.h line:22
		pybind11::class_<bgfx::RenderFrame, std::shared_ptr<bgfx::RenderFrame>> cl(M("bgfx"), "RenderFrame", "Render frame enum.\n\n \n C99 equivalent is `bgfx_render_frame_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::RenderFrame(); } ) );

		pybind11::enum_<bgfx::RenderFrame::Enum>(cl, "Enum", pybind11::arithmetic(), "")
			.value("NO_CONTEXT", bgfx::RenderFrame::Enum::NoContext)
			.value("RENDER", bgfx::RenderFrame::Enum::Render)
			.value("TIMEOUT", bgfx::RenderFrame::Enum::Timeout)
			.value("EXITING", bgfx::RenderFrame::Enum::Exiting)
			.value("COUNT", bgfx::RenderFrame::Enum::Count)
			.export_values();

	}
	// bgfx::renderFrame(int) file:platform.h line:52
	M("bgfx").def("render_frame", []() -> bgfx::RenderFrame::Enum { return bgfx::renderFrame(); }, "", pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("render_frame", (enum bgfx::RenderFrame::Enum (*)(int)) &bgfx::renderFrame, "Render frame.\n\n \n Timeout in milliseconds.\n\n \n Current renderer state. See: `bgfx::RenderFrame`.\n\n \n `bgfx::renderFrame` is blocking call. It waits for\n   `bgfx::frame` to be called from API thread to process frame.\n   If timeout value is passed call will timeout and return even\n   if `bgfx::frame` is not called.\n\n \n This call should be only used on platforms that don't\n   allow creating separate rendering thread. If it is called before\n   to bgfx::init, render thread won't be created by bgfx::init call.\n\n \n C99 equivalent is `bgfx_render_frame`.\n\nC++: bgfx::renderFrame(int) --> enum bgfx::RenderFrame::Enum", pybind11::arg("_msecs"), pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::setPlatformData(const struct bgfx::PlatformData &) file:platform.h line:60
	M("bgfx").def("set_platform_data", (void (*)(const struct bgfx::PlatformData &)) &bgfx::setPlatformData, "Set platform data.\n\n \n Must be called before `bgfx::init`.\n\n \n C99 equivalent is `bgfx_set_platform_data`.\n\nC++: bgfx::setPlatformData(const struct bgfx::PlatformData &) --> void", pybind11::arg("_data"), pybind11::call_guard<pybind11::gil_scoped_release>());

	{ // bgfx::InternalData file:platform.h line:66
		pybind11::class_<bgfx::InternalData, std::shared_ptr<bgfx::InternalData>> cl(M("bgfx"), "InternalData", "Internal data.\n\n \n C99 equivalent is `bgfx_internal_data_t`.");
		pybind11::handle cl_type = cl;

		cl.def( pybind11::init( [](){ return new bgfx::InternalData(); } ) );
	}
	// bgfx::getInternalData() file:platform.h line:81
	M("bgfx").def("get_internal_data", (const struct bgfx::InternalData * (*)()) &bgfx::getInternalData, "Get internal data for interop.\n\n \n It's expected you understand some bgfx internals before you\n   use this call.\n\n \n Must be called only on render thread.\n\n \n C99 equivalent is `bgfx_get_internal_data`.\n\nC++: bgfx::getInternalData() --> const struct bgfx::InternalData *", pybind11::return_value_policy::reference, pybind11::call_guard<pybind11::gil_scoped_release>());

	// bgfx::overrideInternal(struct bgfx::TextureHandle, uintptr_t) file:platform.h line:99
	M("bgfx").def("override_internal", (uintptr_t (*)(struct bgfx::TextureHandle, uintptr_t)) &bgfx::overrideInternal, "Override internal texture with externally created texture. Previously\n created internal texture will released.\n\n \n It's expected you understand some bgfx internals before you\n   use this call.\n\n \n Texture handle.\n \n\n Native API pointer to texture.\n\n \n Native API pointer to texture. If result is 0, texture is not created yet from the\n   main thread.\n\n \n Must be called only on render thread.\n\n \n C99 equivalent is `bgfx_override_internal_texture_ptr`.\n\nC++: bgfx::overrideInternal(struct bgfx::TextureHandle, uintptr_t) --> uintptr_t", pybind11::arg("_handle"), pybind11::arg("_ptr"), pybind11::call_guard<pybind11::gil_scoped_release>());

}


// File: platform.cpp
#include <bgfx.h>
#include <platform.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>
#include <pybind11/stl.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>);
#endif

void bind_platform(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// bgfx::overrideInternal(struct bgfx::TextureHandle, unsigned short, unsigned short, unsigned char, enum bgfx::TextureFormat::Enum, uint64_t) file:platform.h line:126
	M("bgfx").def("override_internal", [](struct bgfx::TextureHandle const & a0, unsigned short const & a1, unsigned short const & a2, unsigned char const & a3, enum bgfx::TextureFormat::Enum const & a4) -> uintptr_t { return bgfx::overrideInternal(a0, a1, a2, a3, a4); }, "", pybind11::arg("_handle"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_numMips"), pybind11::arg("_format"), pybind11::call_guard<pybind11::gil_scoped_release>());
	M("bgfx").def("override_internal", (uintptr_t (*)(struct bgfx::TextureHandle, unsigned short, unsigned short, unsigned char, enum bgfx::TextureFormat::Enum, uint64_t)) &bgfx::overrideInternal, "Override internal texture by creating new texture. Previously created\n internal texture will released.\n\n \n It's expected you understand some bgfx internals before you\n   use this call.\n\n \n Texture handle.\n \n\n Width.\n \n\n Height.\n \n\n Number of mip-maps.\n \n\n Texture format. See: `TextureFormat::Enum`.\n \n\n Default texture sampling mode is linear, and wrap mode\n   is repeat.\n   - `BGFX_TEXTURE_[U/V/W]_[MIRROR/CLAMP]` - Mirror or clamp to edge wrap\n     mode.\n   - `BGFX_TEXTURE_[MIN/MAG/MIP]_[POINT/ANISOTROPIC]` - Point or anisotropic\n     sampling.\n\n \n Native API pointer to texture. If result is 0, texture is not created yet from the\n   main thread.\n\n \n Must be called only on render thread.\n\n \n C99 equivalent is `bgfx_override_internal_texture`.\n\nC++: bgfx::overrideInternal(struct bgfx::TextureHandle, unsigned short, unsigned short, unsigned char, enum bgfx::TextureFormat::Enum, uint64_t) --> uintptr_t", pybind11::arg("_handle"), pybind11::arg("_width"), pybind11::arg("_height"), pybind11::arg("_numMips"), pybind11::arg("_format"), pybind11::arg("_flags"), pybind11::call_guard<pybind11::gil_scoped_release>());

}
