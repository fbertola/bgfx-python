import ctypes
from array import ArrayType

import os
import platform
import tempfile
from bgfx.bgfx_lib import *
from bgfx.shaderc import *
from enum import Enum
from pathlib import Path
from hashlib import md5
from loguru import logger
import shelve

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

logger.disable("bgfx")

with pkg_resources.path(_bgfx, "bgfx_shader.sh") as path:
    default_include_dir = str(path.parent)


class ShaderType(Enum):
    FRAGMENT = "f"
    VERTEX = "v"
    COMPUTE = "c"


def _md5sum(filename, buf_size=8192):
    m = md5()
    with open(filename, 'rb') as f:
        data = f.read(buf_size)
        while data:
            m.update(data)
            data = f.read(buf_size)
    return m.hexdigest()


def _get_platform():
    platforms = {"Windows": "windows", "Linux": "linux", "Darwin": "osx"}

    return platforms.get(platform.system())


def _get_profile(shader_type):
    renderer_type = bgfx.get_renderer_type()
    sys_platform = platform.system()
    windows_shader_types = {
        ShaderType.FRAGMENT: "ps_",
        ShaderType.VERTEX: "vs_",
        ShaderType.COMPUTE: "cs_",
    }

    if sys_platform == "Darwin":
        return "metal"

    if sys_platform == "Linux":
        if renderer_type == bgfx.RendererType.VULKAN:
            return "spirv"
        else:
            if shader_type == ShaderType.COMPUTE:
                return "430"
            else:
                return "120"

    if sys_platform == "Win32":
        if renderer_type == bgfx.RendererType.DIRECT3D9:
            return windows_shader_types.get(shader_type) + "3_0"
        else:
            return windows_shader_types.get(shader_type) + "5_0"


def _load_mem(content):
    size = len(content)
    memory = bgfx.copy(as_void_ptr(content), size)
    return memory


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


def load_shader(
    name: str, shader_type: ShaderType, include_dirs=(), root_path=None
):
    path = Path(".") if not root_path else root_path
    complete_path = str(Path(path) / name)
    md5 = _md5sum(complete_path)

    logger.debug(f"Loading shader \"{name}\": {md5}")

    with shelve.open("shaders_cache") as cache:
        if complete_path in cache and cache[complete_path]["md5"] == md5:
            logger.debug(f"Shader \"{name}\" found in cache, skipping compilation")
            memory = _load_mem(cache[complete_path]["content"])
        else:
            logger.debug(f"Shader \"{name}\" not found in cache, compiling...")
            temp_file = compile_shader(complete_path, include_dirs, shader_type)

            with open(temp_file, "rb") as f:
                read_data = f.read()
                cache[complete_path] = {
                    "md5": md5,
                    "content": read_data
                }
            memory = _load_mem(read_data)

            os.unlink(temp_file)

    handle = bgfx.create_shader(memory)
    bgfx.set_name(handle, name)

    return handle


def compile_shader(complete_path, include_dirs, shader_type):
    all_include_dirs = (default_include_dir,) + include_dirs
    temp_file = tempfile.NamedTemporaryFile(delete=False)

    options = shaderc.Options()
    options.shader_type = str(shader_type.value)[0]
    options.input_file_path = complete_path
    options.output_file_path = temp_file.name
    options.include_dirs = all_include_dirs
    options.platform = _get_platform()
    options.profile = _get_profile(shader_type)
    options.debug_information = False
    options.avoid_flow_control = False
    options.no_preshader = False
    options.partial_precision = False
    options.prefer_flow_control = False
    options.backwards_compatibility = False
    options.warnings_are_errors = False
    options.keep_intermediate = False

    if platform.system() == "Win32":
        options.optimize = True
        options.optimization_level = 1 if shader_type == ShaderType.COMPUTE else 3

    temp_file.close()

    shaderc.compile_shader(options)

    return temp_file.name
