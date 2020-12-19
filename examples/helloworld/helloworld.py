import os

# noinspection PyUnresolvedReferences
from pybgfx import bgfx

from pybgfx.constants import (
    BGFX_CLEAR_COLOR,
    BGFX_CLEAR_DEPTH,
    BGFX_DEBUG_TEXT,
    BGFX_RESET_VSYNC,
)
from examples.example_window import ExampleWindow
from examples.helloworld import python_image

# from examples.utils.imgui_utils import show_example_dialog


class HelloWorld(ExampleWindow):
    def __init__(self, width, height, title):
        super().__init__(width, height, title)

        self.init_conf = bgfx.Init()
        self.init_conf.debug = True
        self.init_conf.resolution.width = self.width
        self.init_conf.resolution.height = self.height

        if "GITHUB_ACTIONS" in os.environ:
            self.init_conf.type = bgfx.RendererType.NOOP

        self.init_conf.resolution.reset = BGFX_RESET_VSYNC

    def init(self, platform_data):
        bgfx.renderFrame()
        bgfx.setPlatformData(platform_data)
        bgfx.init(self.init_conf)

        bgfx.setDebug(BGFX_DEBUG_TEXT)
        bgfx.setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0, 0)
        # ImGuiExtra.imgui_create()

    def shutdown(self):
        # ImGuiExtra.imgui_destroy()
        bgfx.shutdown()

    def update(self, dt):
        # mouse_x, mouse_y, buttons_states = self.get_mouse_state()
        # ImGuiExtra.imgui_begin_frame(
        #     int(mouse_x), int(mouse_y), buttons_states, 0, self.width, self.height
        # )
        #
        # show_example_dialog()
        #
        # ImGuiExtra.imgui_end_frame()

        bgfx.setViewRect(0, 0, 0, self.width, self.height)
        bgfx.touch(0)
        bgfx.dbgTextClear(0, False)
        bgfx.dbgTextImage(
            int(max(self.width / 2 / 8, 20)) - 20,
            int(max(self.height / 2 / 16, 6)) - 6,
            40,
            12,
            python_image.logo,
            160,
        )

        stats = bgfx.getStats()

        bgfx.dbgTextPrintf(
            1,
            1,
            0x0F,
            "Color can be changed with ANSI \x1b[9;me\x1b[10;ms\x1b[11;mc\x1b[12;ma\x1b[13;mp\x1b[14;me\x1b[0m code too.",
        )
        bgfx.dbgTextPrintf(
            80,
            1,
            0x0F,
            "\x1b[;0m    \x1b[;1m    \x1b[; 2m    \x1b[; 3m    \x1b[; 4m    \x1b[; 5m    \x1b[; 6m    \x1b[; 7m    \x1b[0m",
        )
        bgfx.dbgTextPrintf(
            80,
            2,
            0x0F,
            "\x1b[;8m    \x1b[;9m    \x1b[;10m    \x1b[;11m    \x1b[;12m    \x1b[;13m    \x1b[;14m    \x1b[;15m    \x1b[0m",
        )
        bgfx.dbgTextPrintf(
            1,
            2,
            0x0F,
            f"Backbuffer {stats.width}W x {stats.height}H in pixels, debug text {stats.textWidth}W x {stats.textHeight}H in characters.",
        )

        bgfx.frame()

    def resize(self, width, height):
        bgfx.reset(
            self.width, self.height, BGFX_RESET_VSYNC, self.init_conf.resolution.format
        )


if __name__ == "__main__":
    test = HelloWorld(1280, 720, "examples/helloworld")
    test.run()
