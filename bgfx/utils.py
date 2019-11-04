import ctypes
from array import ArrayType

import os
import platform
import tempfile
from bgfx.bgfx_lib import *
from bgfx.shaderc import *
from enum import Enum
from pathlib import Path

try:
    import numpy as np

    _is_numpy_array = lambda obj: type(obj) is np.ndarray
except ImportError:
    _is_numpy_array = lambda obj: False

try:
    import importlib.resources as pkg_resources
except ImportError:
    # Try backported to PY<37 `importlib_resources`.
    import importlib_resources as pkg_resources

import bgfx as _bgfx

with pkg_resources.path(_bgfx, "bgfx_shader.sh") as path:
    default_include_dir = str(path.parent)


class ShaderType(Enum):
    FRAGMENT = "f"
    VERTEX = "v"
    COMPUTE = "c"


def _get_platform():
    platforms = {"Windows": "windows", "Linux": "linux", "Darwin": "osx"}

    return platforms.get(platform.system())


def _get_profile(shader_type):
    renderer_type = bgfx.getRendererType()
    sys_platform = platform.system()
    windows_shader_types = {
        ShaderType.FRAGMENT: "ps_",
        ShaderType.VERTEX: "vs_",
        ShaderType.COMPUTE: "cs_",
    }

    if sys_platform == "Darwin":
        return "metal"

    if sys_platform == "Linux":
        if renderer_type == bgfx.RendererType.Vulkan:
            return "spirv"
        else:
            if shader_type == ShaderType.COMPUTE:
                return "430"
            else:
                return "120"

    if sys_platform == "Windows":
        if renderer_type == bgfx.RendererType.Direct3D9:
            return windows_shader_types.get(shader_type) + "3_0"
        else:
            return windows_shader_types.get(shader_type) + "5_0"


def as_void_ptr(obj):
    ctypes.pythonapi.PyCapsule_New.restype = ctypes.py_object
    ctypes.pythonapi.PyCapsule_New.argtypes = [
        ctypes.c_void_p,
        ctypes.c_char_p,
        ctypes.c_void_p,
    ]

    if type(obj) == ArrayType:
        obj = obj.buffer_info()[0]

    if _is_numpy_array(obj):
        obj = obj.ctypes.data_as(ctypes.POINTER(ctypes.c_void_p))

    if type(obj) != ctypes.c_void_p:
        obj = ctypes.cast(obj, ctypes.c_void_p)

    capsule = ctypes.pythonapi.PyCapsule_New(obj, None, None)

    return capsule


def load_mem(path):
    with open(path, "rb") as f:
        read_data = f.read()
        size = len(read_data)
        memory = bgfx.copy(as_void_ptr(read_data), size)
        return memory


def load_shader(
    name: str, shader_type, include_dirs=(default_include_dir,), root_path=None
):
    path = Path(".") if not root_path else root_path
    complete_path = Path(path) / name

    temp_file = tempfile.NamedTemporaryFile(delete=False)
    options = shaderc.Options()
    options.shaderType = str(shader_type.value)[0]
    options.inputFilePath = str(complete_path)
    options.outputFilePath = temp_file.name
    options.includeDirs = include_dirs
    options.platform = _get_platform()
    options.profile = _get_profile(shader_type)
    options.debugInformation = False
    options.avoidFlowControl = False
    options.noPreshader = False
    options.partialPrecision = False
    options.preferFlowControl = False
    options.backwardsCompatibility = False
    options.warningsAreErrors = False
    options.keepIntermediate = False

    if platform.system() == "Windows":
        options.optimize = True
        options.optimizationLevel = 1 if shader_type == ShaderType.COMPUTE else 3

    temp_file.close()

    shaderc.compileShader(options)

    handle = bgfx.createShader(load_mem(temp_file.name))
    bgfx.setName(handle, name)

    os.unlink(temp_file.name)

    return handle
