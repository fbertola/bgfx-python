#include "bgfx_extra.h"

#include <bx/file.h>


bx::DefaultAllocator default_allocator;
bx::AllocatorI * allocator = & default_allocator;


Mesh* meshLoadInternal(const char* _filePath, bool _ramcopy)
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

Mesh* _MeshLoader::load(const char* _filePath, bool _ramcopy)
{
    return meshLoadInternal(_filePath, _ramcopy);
}

void _MeshLoader::destroy(Mesh* _mesh)
{
    _mesh->unload();
    delete _mesh;
}
