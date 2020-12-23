import os
from ctypes import Structure, c_float, c_uint32, sizeof, c_bool, c_int
from pathlib import Path

import numpy as np

# noinspection PyUnresolvedReferences
from pybgfx import bgfx, ImGui

from pybgfx.utils.imgui_utils import ImGuiExtra
from pybgfx.utils import as_void_ptr
from pybgfx.utils.shaders_utils import ShaderType, load_shader
from pybgfx.constants import (
    BGFX_CLEAR_COLOR,
    BGFX_CLEAR_DEPTH,
    BGFX_DEBUG_TEXT,
    BGFX_RESET_VSYNC,
    BGFX_STATE_WRITE_R,
    BGFX_STATE_WRITE_G,
    BGFX_STATE_WRITE_B,
    BGFX_STATE_WRITE_A,
    BGFX_STATE_WRITE_Z,
    BGFX_STATE_DEPTH_TEST_LESS,
    BGFX_STATE_CULL_CW,
    BGFX_STATE_MSAA,
    BGFX_STATE_PT_POINTS,
    BGFX_STATE_PT_LINES,
    BGFX_STATE_PT_TRISTRIP,
    BGFX_STATE_PT_LINESTRIP,
)
from examples.example_window import ExampleWindow
from examples.utils.imgui_utils import show_example_dialog
from examples.utils.matrix_utils import look_at, proj, rotate_xy
from loguru import logger

logger.enable("bgfx")


class PosColorVertex(Structure):
    _fields_ = [
        ("m_x", c_float),
        ("m_y", c_float),
        ("m_z", c_float),
        ("m_abgr", c_uint32),
    ]


num_vertices = 8

cube_vertices = (PosColorVertex * num_vertices)(
    PosColorVertex(-1.0, 1.0, 1.0, 0xFF000000),
    PosColorVertex(1.0, 1.0, 1.0, 0xFF0000FF),
    PosColorVertex(-1.0, -1.0, 1.0, 0xFF00FF00),
    PosColorVertex(1.0, -1.0, 1.0, 0xFF00FFFF),
    PosColorVertex(-1.0, 1.0, -1.0, 0xFFFF0000),
    PosColorVertex(1.0, 1.0, -1.0, 0xFFFF00FF),
    PosColorVertex(-1.0, -1.0, -1.0, 0xFFFFFF00),
    PosColorVertex(1.0, -1.0, -1.0, 0xFFFFFFFF),
)


primitives = (
    np.array(
        [
            0,
            1,
            2,  # 0
            1,
            3,
            2,
            4,
            6,
            5,  # 2
            5,
            6,
            7,
            0,
            2,
            4,  # 4
            4,
            2,
            6,
            1,
            5,
            3,  # 6
            5,
            7,
            3,
            0,
            4,
            1,  # 8
            4,
            5,
            1,
            2,
            3,
            6,  # 10
            6,
            3,
            7,
        ],
        dtype=np.uint16,
    ),
    np.array([0, 1, 2, 3, 7, 1, 5, 0, 4, 2, 6, 7, 4, 5,], dtype=np.uint16),
    np.array(
        [0, 1, 0, 2, 0, 4, 1, 3, 1, 5, 2, 3, 2, 6, 3, 7, 4, 5, 4, 6, 5, 7, 6, 7,],
        dtype=np.uint16,
    ),
    np.array([0, 2, 3, 1, 5, 7, 6, 4, 0, 2, 6, 4, 5, 7, 3, 1, 0,], dtype=np.uint16),
    np.array([0, 1, 2, 3, 4, 5, 6, 7], dtype=np.uint16),
)

bgfx_states = (
    0,
    BGFX_STATE_PT_TRISTRIP,
    BGFX_STATE_PT_LINES,
    BGFX_STATE_PT_LINESTRIP,
    BGFX_STATE_PT_POINTS,
)

root_path = Path(__file__).parent.parent / "assets" / "shaders"


class Cubes(ExampleWindow):
    def __init__(self, width, height, title):
        super().__init__(width, height, title)

        self.elapsed_time = 0
        self.write_r = c_bool(True)
        self.write_g = c_bool(True)
        self.write_b = c_bool(True)
        self.write_a = c_bool(True)
        self.primitive_geometry = c_int(0)

        self.init_conf = bgfx.Init()
        self.init_conf.debug = True
        self.init_conf.resolution.width = self.width
        self.init_conf.resolution.height = self.height
        self.init_conf.resolution.reset = BGFX_RESET_VSYNC

    def init(self, platform_data):
        bgfx.setPlatformData(platform_data)
        bgfx.renderFrame()
        bgfx.init(self.init_conf)
        bgfx.reset(
            self.width, self.height, BGFX_RESET_VSYNC, self.init_conf.resolution.format,
        )

        bgfx.setDebug(BGFX_DEBUG_TEXT)
        bgfx.setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0, 0)

        self.vertex_layout = bgfx.VertexLayout()
        self.vertex_layout.begin().add(
            bgfx.Attrib.Position, 3, bgfx.AttribType.Float
        ).add(bgfx.Attrib.Color0, 4, bgfx.AttribType.Uint8, True).end()

        # Create static vertex buffer
        vb_memory = bgfx.copy(
            as_void_ptr(cube_vertices), sizeof(PosColorVertex) * num_vertices
        )
        self.vertex_buffer = bgfx.createVertexBuffer(vb_memory, self.vertex_layout)

        self.index_buffers = []

        for i in range(0, len(primitives)):
            ib_memory = bgfx.copy(as_void_ptr(primitives[i]), primitives[i].nbytes)
            self.index_buffers.append(bgfx.createIndexBuffer(ib_memory))

        # Create program from shaders.
        self.main_program = bgfx.createProgram(
            load_shader(
                "cubes.VertexShader.vert", ShaderType.VERTEX, root_path=root_path
            ),
            load_shader(
                "cubes.FragmentShader.frag", ShaderType.FRAGMENT, root_path=root_path
            ),
            True,
        )

        ImGuiExtra.create()

    def shutdown(self):
        ImGuiExtra.destroy()
        for index_buffer in self.index_buffers:
            bgfx.destroy(index_buffer)
        bgfx.destroy(self.vertex_buffer)
        bgfx.destroy(self.main_program)
        bgfx.shutdown()

    def update(self, dt):
        self.elapsed_time += dt
        mouse_x, mouse_y, buttons_states = self.get_mouse_state()
        ImGuiExtra.begin_frame(
            int(mouse_x), int(mouse_y), buttons_states, 0, self.width, self.height
        )

        show_example_dialog()
        self._create_imgui_cubes_selection_dialog()

        ImGuiExtra.end_frame()

        at = (c_float * 3)(*[0.0, 0.0, 0.0])
        eye = (c_float * 3)(*[0.0, 0.0, -35.0])
        up = (c_float * 3)(*[0.0, 1.0, 0.0])

        view = look_at(eye, at, up)
        projection = proj(60.0, self.width / self.height, 0.1, 100.0)

        bgfx.setViewTransform(0, as_void_ptr(view), as_void_ptr(projection))
        bgfx.setViewRect(0, 0, 0, self.width, self.height)

        bgfx.touch(0)

        for yy in range(0, 11):
            for xx in range(0, 11):
                mtx = rotate_xy(
                    self.elapsed_time + xx * 0.21, self.elapsed_time + yy * 0.37
                )
                mtx[3, 0] = -15.0 + xx * 3.0
                mtx[3, 1] = -15.0 + yy * 3.0
                mtx[3, 2] = 0.0
                bgfx.setTransform(as_void_ptr(mtx), 1)

                # Set vertex and index buffer.
                bgfx.setVertexBuffer(0, self.vertex_buffer, 0, num_vertices)
                bgfx.setIndexBuffer(
                    self.index_buffers[self.primitive_geometry.value],
                    0,
                    primitives[self.primitive_geometry.value].size,
                )

                bgfx.setState(
                    bgfx_states[self.primitive_geometry.value]
                    | (BGFX_STATE_WRITE_R if self.write_r.value else 0)
                    | (BGFX_STATE_WRITE_G if self.write_g.value else 0)
                    | (BGFX_STATE_WRITE_B if self.write_b.value else 0)
                    | (BGFX_STATE_WRITE_A if self.write_a.value else 0)
                    | BGFX_STATE_WRITE_Z
                    | BGFX_STATE_DEPTH_TEST_LESS
                    | BGFX_STATE_CULL_CW
                    | BGFX_STATE_MSAA,
                    0,
                )

                bgfx.submit(0, self.main_program, 0, False)

        bgfx.frame()

    def resize(self, width, height):
        bgfx.reset(
            self.width, self.height, BGFX_RESET_VSYNC, self.init_conf.resolution.format
        )

    def _create_imgui_cubes_selection_dialog(self):
        ImGui.SetNextWindowPos(
            ImGui.ImVec2(self.width - self.width / 5.0 - 10.0, 10.0),
            ImGui.ImGuiCond_FirstUseEver,
        )
        ImGui.SetNextWindowSize(
            ImGui.ImVec2(self.width / 5.0, self.height / 3.5),
            ImGui.ImGuiCond_FirstUseEver,
        )
        ImGui.Begin("Settings")

        ImGui.Checkbox("Write R", self.write_r)
        ImGui.Checkbox("Write G", self.write_g)
        ImGui.Checkbox("Write B", self.write_b)
        ImGui.Checkbox("Write A", self.write_a)

        ImGui.Text("Primitive topology:")
        ImGui.Combo(
            "",
            self.primitive_geometry,
            ["Triangle List", "Triangle Strip", "Lines", "Line Strip", "Points"],
            5,
        )

        ImGui.End()


if __name__ == "__main__":
    cubes = Cubes(1280, 720, "examples/cubes")
    cubes.run()
