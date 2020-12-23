from array import array
from typing import List

import cppyy

# noinspection PyUnresolvedReferences
from pybgfx import bgfx

from loguru import logger
from pathlib import Path
from pybgfx.constants import BGFX_STATE_MASK
from pybgfx.utils import as_void_ptr

cppyy.cppdef(
    """
#include <bx/file.h>
#include "bgfx_extra_utils.h"

bx::DefaultAllocator default_allocator;
bx::AllocatorI * allocator = & default_allocator;

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
"""
)


class Mesh:
    def __init__(self, file_path: Path, ram_copy=False):
        logger.debug(f"Loading mesh (RAM {ram_copy}): {file_path}")
        self.internal_mesh = cppyy.gbl.meshLoad(str(file_path), ram_copy)

    def submit(
        self,
        view_id: int,
        program: bgfx.ProgramHandle,
        matrix: List[float],
        state=BGFX_STATE_MASK,
    ):
        self.internal_mesh.submit(view_id, program, matrix, state)

    def destroy(self):
        self.internal_mesh.unload()
