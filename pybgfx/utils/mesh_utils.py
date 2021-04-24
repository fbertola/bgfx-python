from array import array
from typing import List

import cppyy

# noinspection PyUnresolvedReferences
from pybgfx import bgfx

from loguru import logger
from pathlib import Path
from pybgfx.constants import BGFX_STATE_MASK


class Mesh:
    def __init__(self, file_path: Path, ram_copy=False):
        logger.debug(f"Loading mesh (RAM {ram_copy}): {file_path}")
        str_file_path = str(file_path)
        self.internal_mesh = cppyy.gbl._MeshLoader().load(str_file_path, ram_copy)

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
