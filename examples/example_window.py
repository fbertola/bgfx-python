import ctypes
import time
import sys

# noinspection PyPackageRequirements
import glfw

# noinspection PyUnresolvedReferences
from bgfx import bgfx, ImGuiExtra, as_void_ptr

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
            glfw_native.glfwGetCocoaWindow.argtypes = [ctypes.POINTER(glfw._GLFWwindow)]
            glfw_native.glfwGetCocoaWindow.restype = ctypes.c_void_p
            handle = glfw_native.glfwGetCocoaWindow(self.window)
        elif sys.platform == "win32":
            glfw_native.glfwGetWin32Window.argtypes = [ctypes.POINTER(glfw._GLFWwindow)]
            glfw_native.glfwGetWin32Window.restype = ctypes.c_void_p
            handle = glfw_native.glfwGetWin32Window(self.window)
        elif sys.platform == "linux":
            glfw_native.glfwGetX11Window.argtypes = [ctypes.POINTER(glfw._GLFWwindow)]
            glfw_native.glfwGetX11Window.restype = ctypes.c_void_p
            handle = glfw_native.glfwGetX11Window(self.window)
            display = glfw_native.glfwGetX11Display()

        data = bgfx.PlatformData()
        data.ndt = display
        data.nwh = as_void_ptr(handle)
        data.context = None
        data.back_buffer = None
        data.back_buffer_ds = None

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
        glfw.terminate()

    def _handle_window_resize(self, window, width, height):
        self.width = width
        self.height = height

        self.resize(width, height)

