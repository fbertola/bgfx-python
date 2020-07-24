import os
from ctypes import Structure, c_float, c_uint32, sizeof
from pathlib import Path
from PIL import Image 
import numpy as np

from bgfx import (
    bgfx,
    ImGuiExtra,
    ImGui,
    BGFX_CLEAR_COLOR,
    BGFX_CLEAR_DEPTH,
    BGFX_DEBUG_TEXT,
    BGFX_RESET_VSYNC,
    as_void_ptr,
    ShaderType,
    load_shader,
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
    BGFX_TEXTURE_RT,
    BGFX_SAMPLER_MAG_ANISOTROPIC, 
    BGFX_SAMPLER_U_MIRROR, 
    BGFX_SAMPLER_V_MIRROR,
    BGFX_SAMPLER_U_MIRROR, 
    BGFX_SAMPLER_V_MIRROR,
    BGFX_STATE_WRITE_RGB 
    
)
from examples.example_window import ExampleWindow
from examples.utils.imgui_utils import show_example_dialog
from examples.utils.matrix_utils import look_at, proj, rotate_xy
from loguru import logger

logger.enable("bgfx")


class PosColorTexVertex(Structure):
    _fields_ = [
        ("m_x", c_float),
        ("m_y", c_float),
        ("m_z", c_float),
        ("m_abgr", c_uint32),
        ("m_tex_u",c_float),
        ("m_tex_v",c_float)
    ]


num_vertices = 24

cube_vertices = (PosColorTexVertex * num_vertices)(
    PosColorTexVertex(-1.0, 1.0, 1.0, 0xFF000000,0,1),
    PosColorTexVertex(1.0, 1.0, 1.0, 0xFF0000FF,1,1),
    PosColorTexVertex(-1.0, -1.0, 1.0, 0xFF00FF00,0,0),
    PosColorTexVertex(1.0, -1.0, 1.0, 0xFF00FFFF,1,0),
    PosColorTexVertex(-1.0, 1.0, -1.0, 0xFFFF0000,0,1),
    PosColorTexVertex(1.0, 1.0, -1.0, 0xFFFF00FF,1,1),
    PosColorTexVertex(-1.0, -1.0, -1.0, 0xFFFFFF00,0,0),
    PosColorTexVertex(1.0, -1.0, -1.0, 0xFFFFFFFF,0,1),
)

cube_vertices = (PosColorTexVertex * 24)(
    PosColorTexVertex(-1.0,   1.0,  1.0,  0xFF000000,       0,     0    ),
    PosColorTexVertex( 1.0,   1.0,  1.0,  0xFF000000,       1,     0    ),
    PosColorTexVertex(-1.0,  -1.0,  1.0,  0xFF000000,       0,     1    ),
    PosColorTexVertex( 1.0,  -1.0,  1.0,  0xFF000000,       1,     1    ),
    PosColorTexVertex(-1.0,   1.0, -1.0,  0xFF000000,       0,     0    ),
    PosColorTexVertex( 1.0,   1.0, -1.0,  0xFF000000,       1,     0    ),
    PosColorTexVertex(-1.0,  -1.0, -1.0,  0xFF000000,       0,     1    ),
    PosColorTexVertex( 1.0,  -1.0, -1.0,  0xFF000000,       1,     1    ),
    PosColorTexVertex(-1.0,   1.0,  1.0,  0xFF000000,       0,     0    ),
    PosColorTexVertex( 1.0,   1.0,  1.0,  0xFF000000,       1,     0    ),
    PosColorTexVertex(-1.0,   1.0, -1.0,  0xFF000000,       0,     1    ),
    PosColorTexVertex( 1.0,   1.0, -1.0,  0xFF000000,       1,     1    ),
    PosColorTexVertex(-1.0,  -1.0,  1.0,  0xFF000000,       0,     0    ),
    PosColorTexVertex( 1.0,  -1.0,  1.0,  0xFF000000,       1,     0    ),
    PosColorTexVertex(-1.0,  -1.0, -1.0,  0xFF000000,       0,     1    ),
    PosColorTexVertex( 1.0,  -1.0, -1.0,  0xFF000000,       1,     1    ),
    PosColorTexVertex( 1.0,  -1.0,  1.0,  0xFF000000,       0,     0    ),
    PosColorTexVertex( 1.0,   1.0,  1.0,  0xFF000000,       1,     0    ),
    PosColorTexVertex( 1.0,  -1.0, -1.0,  0xFF000000,       0,     1    ),
    PosColorTexVertex( 1.0,   1.0, -1.0,  0xFF000000,       1,     1    ),
    PosColorTexVertex(-1.0,  -1.0,  1.0,  0xFF000000,       0,     0    ),
    PosColorTexVertex(-1.0,   1.0,  1.0,  0xFF000000,       1,     0    ),
    PosColorTexVertex(-1.0,  -1.0, -1.0,  0xFF000000,       0,     1    ),
    PosColorTexVertex(-1.0,   1.0, -1.0,  0xFF000000,       1,     1    )
    )
	
	

cube_indices = (np.array([
     0,  2,  1,
	 1,  2,  3,
	 4,  5,  6,
	 5,  7,  6,

	 8, 10,  9,
	 9, 10, 11,
	12, 13, 14,
	13, 15, 14,

	16, 18, 17,
	17, 18, 19,
	20, 21, 22,
	21, 23, 22],dtype=np.uint16))
#    0, 1, 2,  # 0
#    1, 3, 2,
#    4, 6, 5,  # 2
#    5, 6, 7,
#    0, 2, 4,  # 4
#    4, 2, 6,
#    1, 5, 3,  # 6
#    5, 7, 3,
#    0, 4, 1,  # 8
#    4, 5, 1,
#    2, 3, 6,  # 10
#    6, 3, 7,



root_path = Path(__file__).parent.parent / "shaders"


class Textures(ExampleWindow):
    def __init__(self, width, height, title):
        super().__init__(width, height, title)

        self.elapsed_time = 0
        self.write_r = ImGui.Bool(True)
        self.write_g = ImGui.Bool(True)
        self.write_b = ImGui.Bool(True)
        self.write_a = ImGui.Bool(True)
        self.primitive_geometry = ImGui.Int(0)

        self.init_conf = bgfx.Init()
        self.init_conf.debug = True
        self.init_conf.resolution.width = self.width
        self.init_conf.resolution.height = self.height

        if "GITHUB_ACTIONS" in os.environ:
            self.init_conf.type = bgfx.RendererType.NOOP

        self.init_conf.resolution.reset = BGFX_RESET_VSYNC

    def init(self, platform_data):
        self.init_conf.platform_data = platform_data
        bgfx.render_frame()
        bgfx.init(self.init_conf)
        bgfx.reset(
            self.width, self.height, BGFX_RESET_VSYNC, self.init_conf.resolution.format,
        )

        bgfx.set_debug(BGFX_DEBUG_TEXT)
        bgfx.set_view_clear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0, 0)

        self.vertex_layout = bgfx.VertexLayout()
        self.vertex_layout.begin().add(
              bgfx.Attrib.POSITION, 3, bgfx.AttribType.FLOAT
        ).add(bgfx.Attrib.COLOR0, 4, bgfx.AttribType.UINT8, True
        ).add(bgfx.Attrib.TEXCOORD0, 2, bgfx.AttribType.FLOAT).end()

        # Create static vertex buffer
        vb_memory = bgfx.copy(
            as_void_ptr(cube_vertices), sizeof(PosColorTexVertex) * num_vertices
        )
        self.vertex_buffer = bgfx.create_vertex_buffer(vb_memory, self.vertex_layout)

       

        
        ib_memory = bgfx.copy(as_void_ptr(cube_indices), cube_indices.nbytes)
        self.index_buffer = bgfx.create_index_buffer(ib_memory)

        # Create texture
        self.texture_uniform = bgfx.create_uniform("s_tex",  bgfx.UniformType.SAMPLER)
       
        logo = Image.open(Path(__file__).parent /"python_logo.png")
        logo_memory = bgfx.copy(as_void_ptr(logo.tobytes()), len(logo.tobytes()))
        self.logo_texture = bgfx.create_texture2d(logo.width,logo.height,False,1,bgfx.TextureFormat.RGBA8, BGFX_TEXTURE_RT ,logo_memory)
        #bgfx.TextureFormat.R32F, BGFX_SAMPLER_MAG_ANISOTROPIC| BGFX_TEXTURE_RT| BGFX_SAMPLER_U_BORDER | BGFX_SAMPLER_V_BORDER,tex_memory) 


        # Create program from shaders.
        self.main_program = bgfx.create_program(
            load_shader(
                "textures.VertexShader.vert", ShaderType.VERTEX, root_path=root_path
            ),
            load_shader(
                "textures.FragmentShader.frag", ShaderType.FRAGMENT, root_path=root_path
            ),
            True,
        )

        ImGuiExtra.imgui_create()

    def shutdown(self):
        ImGuiExtra.imgui_destroy()
        for index_buffer in self.index_buffers:
            bgfx.destroy(index_buffer)
        bgfx.destroy(self.vertex_buffer)
        bgfx.destroy(self.main_program)
        bgfx.shutdown()

    def update(self, dt):
        self.elapsed_time += dt
        mouse_x, mouse_y, buttons_states = self.get_mouse_state()
        ImGuiExtra.imgui_begin_frame(
            int(mouse_x), int(mouse_y), buttons_states, 0, self.width, self.height
        )

        show_example_dialog()

        ImGuiExtra.imgui_end_frame()

        at = (c_float * 3)(*[0.0, 0.0, 0.0])
        eye = (c_float * 3)(*[0.0, 0.0, -15.0])
        up = (c_float * 3)(*[0.0, 1.0, 0.0])

        view = look_at(eye, at, up)
        projection = proj(60.0, self.width / self.height, 0.1, 100.0)

        bgfx.set_view_transform(0, as_void_ptr(view), as_void_ptr(projection))
        bgfx.set_view_rect(0, 0, 0, self.width, self.height)

        bgfx.touch(0)

        for yy in range(-2, 2):
            for xx in range(-2, 2):
                mtx = rotate_xy(
                    self.elapsed_time + xx * 0.21, self.elapsed_time + yy * 0.37
                )
                mtx[3, 0] =  4+ xx * 3.5
                mtx[3, 1] =  2 + yy * 3.5
                mtx[3, 2] =  0
                bgfx.set_transform(as_void_ptr(mtx), 1)

                # Set vertex and index buffer.
                bgfx.set_vertex_buffer(0, self.vertex_buffer, 0, num_vertices)
                bgfx.set_index_buffer(self.index_buffer,0,cube_indices.size)

                bgfx.set_texture(0, self.texture_uniform, self.logo_texture)

                bgfx.set_state(0
                    | BGFX_STATE_WRITE_RGB 
                    | BGFX_STATE_WRITE_A 
                    | BGFX_STATE_WRITE_Z
                    | BGFX_STATE_DEPTH_TEST_LESS
                    | BGFX_STATE_MSAA,
                    0,
                )

                bgfx.submit(0, self.main_program, 0, False)

        bgfx.frame()

    def resize(self, width, height):
        bgfx.reset(
            self.width, self.height, BGFX_RESET_VSYNC, self.init_conf.resolution.format
        )

if __name__ == "__main__":
    textures = Textures(1280, 720, "examples/textures")
    textures.run()
