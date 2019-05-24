import ctypes
import time
import sys

# noinspection PyPackageRequirements
import glfw

# noinspection PyUnresolvedReferences
from bgfx import bgfx, as_void_ptr

# noinspection PyPackageRequirements,PyProtectedMember
from glfw import _glfw as glfw_native


class ExampleWindow(object):
    def __init__(self, width, height, title):
        self.title = title
        self.height = height
        self.width = width

    def init(self):
        pass

    def shutdown(self):
        pass

    def update(self, dt):
        pass

    # noinspection PyProtectedMember
    def run(self):
        glfw_native.glfwGetCocoaWindow.argtypes = [ctypes.POINTER(glfw._GLFWwindow)]
        glfw_native.glfwGetCocoaWindow.restype = ctypes.c_void_p
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

        # glfw.window_hint(glfw.CLIENT_API, glfw.NO_API)
        window = glfw.create_window(self.width, self.height, self.title, None, None)
        glfw.make_context_current(window)

        bgfx.renderFrame()

        handle, display = None, None

        if sys.platform == "darwin":
            glfw_native.glfwGetCocoaWindow.argtypes = [ctypes.POINTER(glfw._GLFWwindow)]
            glfw_native.glfwGetCocoaWindow.restype = ctypes.c_void_p
            handle = glfw_native.glfwGetCocoaWindow(window)
        elif sys.platform == "windows":
            glfw_native.glfwGetWin32Window.argtypes = [ctypes.POINTER(glfw._GLFWwindow)]
            glfw_native.glfwGetWin32Window.restype = ctypes.c_void_p
            handle = glfw_native.glfwGetWin32Window(window)
        elif sys.platform == "linux":
            glfw_native.glfwGetX11Window.argtypes = [ctypes.POINTER(glfw._GLFWwindow)]
            glfw_native.glfwGetX11Window.restype = ctypes.c_void_p
            handle = glfw_native.glfwGetX11Window(window)
            display = glfw_native.glfwGetX11Display()

        data = bgfx.PlatformData()
        data.ndt = display
        data.nwh = as_void_ptr(handle)
        data.context = None
        data.backBuffer = None
        data.backBufferDS = None
        bgfx.setPlatformData(data)

        self.init()

        last_time = None

        while not glfw.window_should_close(window):
            glfw.poll_events()

            now = time.perf_counter()
            if not last_time:
                last_time = now

            frame_time = now - last_time
            last_time = now

            self.update(frame_time)

        self.shutdown()
        glfw.terminate()
