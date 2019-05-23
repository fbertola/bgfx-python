from bgfx import bgfx, BGFX_CLEAR_COLOR, BGFX_CLEAR_DEPTH, BGFX_RESET_VSYNC

from examples.example_window import ExampleWindow
from examples.helloworld import python_image


class Test(ExampleWindow):
    def __init__(self, width, height, title):
        super().__init__(width, height, title)

        self.init_conf = bgfx.Init()
        self.init_conf.resolution.width = self.width
        self.init_conf.resolution.height = self.height
        self.init_conf.resolution.reset = BGFX_RESET_VSYNC

    def init(self):
        bgfx.init(self.init_conf)
        bgfx.setDebug(0x8)
        bgfx.setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x303030FF, 1.0, 0)

    def shutdown(self):
        bgfx.shutdown()

    def update(self, dt):
        bgfx.setViewRect(
            0, 0, 0, bgfx.BackbufferRatio.Equal
        )
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

        bgfx.dbgTextPrintf(1, 1, 0x0F, "Color can be changed with ANSI \x1b[9;me\x1b[10;ms\x1b[11;mc\x1b[12;ma\x1b[13;mp\x1b[14;me\x1b[0m code too.")
        bgfx.dbgTextPrintf(80, 1, 0x0F, "\x1b[;0m    \x1b[;1m    \x1b[; 2m    \x1b[; 3m    \x1b[; 4m    \x1b[; 5m    \x1b[; 6m    \x1b[; 7m    \x1b[0m")
        bgfx.dbgTextPrintf(80, 2, 0x0F, "\x1b[;8m    \x1b[;9m    \x1b[;10m    \x1b[;11m    \x1b[;12m    \x1b[;13m    \x1b[;14m    \x1b[;15m    \x1b[0m")
        bgfx.dbgTextPrintf(1, 2, 0x0F, f"Backbuffer {stats.width}W x {stats.height}H in pixels, debug text {stats.textWidth}W x {stats.textHeight}H in characters.")

        bgfx.frame(False)


if __name__ == "__main__":
    test = Test(1280, 720, "examples/HelloWorld")
    test.run()
