import ctypes
import time
import sys

# noinspection PyPackageRequirements
import cppyy
import glfw

# noinspection PyUnresolvedReferences
from pybgfx import bgfx

from pybgfx.utils import as_void_ptr

# noinspection PyPackageRequirements,PyProtectedMember
from glfw import _glfw as glfw_native


class ExampleWindow(object):
    def __init__(self, width, height, title):
        self.title = title
        self.height = height
        self.width = width
        self.ctx = None
        self.window = None

    def init(self, platform_data):
        pass

    def shutdown(self):
        pass

    def update(self, dt):
        pass

    def resize(self, width, height):
        pass

    def get_mouse_state(self):
        mouse_x, mouse_y = glfw.get_cursor_pos(self.window)
        state_mbl = glfw.get_mouse_button(self.window, glfw.MOUSE_BUTTON_LEFT)
        state_mbm = glfw.get_mouse_button(self.window, glfw.MOUSE_BUTTON_MIDDLE)
        state_mbr = glfw.get_mouse_button(self.window, glfw.MOUSE_BUTTON_RIGHT)

        return (
            mouse_x,
            mouse_y,
            1
            if state_mbl == glfw.PRESS
            else 0 | 1
            if state_mbm == glfw.PRESS
            else 0 | 1
            if state_mbr == glfw.PRESS
            else 0,
        )

    # noinspection PyProtectedMember
    def run(self):
        glfw_native.glfwCreateWindow.argtypes = [
            ctypes.c_int,
            ctypes.c_int,
            ctypes.c_char_p,
        ]
        glfw_native.glfwCreateWindow.restype = ctypes.POINTER(glfw._GLFWwindow)
        glfw_native.glfwMakeContextCurrent.argtypes = [ctypes.POINTER(glfw._GLFWwindow)]
        glfw_native.glfwWindowShouldClose.argtypes = [ctypes.POINTER(glfw._GLFWwindow)]
        glfw_native.glfwWindowShouldClose.restype = ctypes.c_int

        glfw.init()

        glfw.window_hint(glfw.CLIENT_API, glfw.NO_API)

        self.window = glfw.create_window(
            self.width, self.height, self.title, None, None
        )

        glfw.set_window_size_callback(self.window, self._handle_window_resize)

        handle, display = None, None

        if sys.platform == "darwin":
            handle = glfw.get_cocoa_window(self.window)
        elif sys.platform == "win32":
            handle = glfw.get_win32_window(self.window)
        elif sys.platform == "linux":
            handle = glfw.get_x11_window(self.window)
            display = glfw.get_x11_display()

        data = bgfx.PlatformData()
        data.ndt = as_void_ptr(display) if display else cppyy.nullptr
        data.nwh = as_void_ptr(handle)
        data.context = cppyy.nullptr
        data.backBuffer = cppyy.nullptr
        data.backBufferDS = cppyy.nullptr

        self.init(data)

        last_time = None

        while not glfw.window_should_close(self.window):
            glfw.poll_events()

            now = time.perf_counter()
            if not last_time:
                last_time = now

            frame_time = now - last_time
            last_time = now

            self.update(frame_time)

        self.shutdown()
        glfw.destroy_window(self.window)
        glfw.terminate()

    def _handle_window_resize(self, window, width, height):
        self.width = width
        self.height = height

        self.resize(width, height)
