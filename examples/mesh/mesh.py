import os
from ctypes import c_float
from pathlib import Path

from loguru import logger

# noinspection PyUnresolvedReferences
from pybgfx import bgfx, ImGui

from pybgfx.utils.imgui_utils import ImGuiExtra
from pybgfx.utils import as_void_ptr
from pybgfx.utils.mesh_utils import Mesh
from pybgfx.utils.shaders_utils import ShaderType, load_shader
from pybgfx.constants import (
    BGFX_CLEAR_COLOR,
    BGFX_CLEAR_DEPTH,
    BGFX_DEBUG_TEXT,
    BGFX_RESET_VSYNC,
)
from examples.example_window import ExampleWindow
from examples.utils.imgui_utils import show_example_dialog
from examples.utils.matrix_utils import look_at, proj, rotate_xy

logger.enable("bgfx")

root_path = Path(__file__).parent.parent / "assets" / "shaders"


class MeshExample(ExampleWindow):
    def __init__(self, width, height, title):
        super().__init__(width, height, title)

        self.elapsed_time = 0

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

        # Create time uniform
        self.time_uniform = bgfx.createUniform("u_time", bgfx.UniformType.Vec4)

        # Load Bunny mesh
        self.mesh = Mesh(
            (
                Path(__file__).parent.parent / "assets" / "meshes" / "bunny.bin"
            ).absolute()
        )

        # Create program from shaders.
        self.main_program = bgfx.createProgram(
            load_shader(
                "mesh.VertexShader.vert", ShaderType.VERTEX, root_path=root_path
            ),
            load_shader(
                "mesh.FragmentShader.frag", ShaderType.FRAGMENT, root_path=root_path
            ),
            True,
        )

        ImGuiExtra.create()

    def shutdown(self):
        ImGuiExtra.destroy()
        self.mesh.destroy()
        bgfx.destroy(self.main_program)
        bgfx.destroy(self.time_uniform)
        bgfx.shutdown()

    def update(self, dt):
        self.elapsed_time += dt
        mouse_x, mouse_y, buttons_states = self.get_mouse_state()
        ImGuiExtra.begin_frame(
            int(mouse_x), int(mouse_y), buttons_states, 0, self.width, self.height
        )

        show_example_dialog()

        ImGuiExtra.end_frame()

        at = (c_float * 3)(*[0.0, 1.0, 0.0])
        eye = (c_float * 3)(*[0.0, 1.0, -2.5])
        up = (c_float * 3)(*[0.0, 1.0, 0.0])

        view = look_at(eye, at, up)
        projection = proj(60.0, self.width / self.height, 0.1, 100.0)

        bgfx.setViewTransform(0, as_void_ptr(view), as_void_ptr(projection))
        bgfx.setViewRect(0, 0, 0, self.width, self.height)

        bgfx.touch(0)

        mtx = rotate_xy(0, self.elapsed_time * 0.37)

        bgfx.setUniform(
            self.time_uniform,
            as_void_ptr((c_float * 4)(self.elapsed_time, 0.0, 0.0, 0.0)),
        )

        self.mesh.submit(0, self.main_program, mtx)

        bgfx.frame()

    def resize(self, width, height):
        bgfx.reset(
            self.width, self.height, BGFX_RESET_VSYNC, self.init_conf.resolution.format
        )


if __name__ == "__main__":
    textures = MeshExample(1280, 720, "examples/mesh")
    textures.run()
