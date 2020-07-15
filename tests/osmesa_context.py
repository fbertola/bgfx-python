# noinspection PyPackageRequirements
import ctypes
import sys

# noinspection PyUnresolvedReferences
from bgfx import as_void_ptr, bgfx
import glfw

# noinspection PyProtectedMember
from glfw import _glfw as glfw_native


class OSMesaContext(object):
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

    # noinspection PyMethodMayBeStatic
    def get_mouse_state(self):
        return 0, 0, 0

    # noinspection PyProtectedMember
    def run(self):
        glfw.init()

        glfw.window_hint(glfw.CLIENT_API, glfw.OPENGL_API)
        glfw.window_hint(glfw.CONTEXT_VERSION_MINOR, 3)
        glfw.window_hint(glfw.CONTEXT_VERSION_MAJOR, 3)
        glfw.window_hint(glfw.OPENGL_PROFILE, glfw.OPENGL_CORE_PROFILE)
        glfw.window_hint(glfw.CONTEXT_CREATION_API, glfw.OSMESA_CONTEXT_API)

        self.window = glfw.create_window(
            self.width, self.height, self.title, None, None
        )

        handle, display = None, None

        if sys.platform == "linux":
            glfw_native.glfwGetX11Window.argtypes = [ctypes.POINTER(glfw._GLFWwindow)]
            glfw_native.glfwGetX11Window.restype = ctypes.c_void_p
            handle = glfw_native.glfwGetX11Window(self.window)
            display = glfw_native.glfwGetX11Display()

        glfw.make_context_current(self.window)

        data = bgfx.PlatformData()
        data.ndt = as_void_ptr(display)
        data.nwh = as_void_ptr(handle)
        data.context = as_void_ptr(glfw.get_os_mesa_context(self.window))
        data.back_buffer = None
        data.back_buffer_ds = None

        self.init(data)

        for _ in range(0, 10):
            self.update(1.0)

        self.shutdown()
        glfw.terminate()
