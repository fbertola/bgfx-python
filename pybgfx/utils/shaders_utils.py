import os
import platform
import shelve
import subprocess
import tempfile
from enum import Enum
from hashlib import sha256
from pathlib import Path
from typing import List, Optional

from loguru import logger

from pybgfx import bgfx

logger.disable("pybgfx")

default_include_dir = os.path.dirname(__file__)


class ShaderType(Enum):
    FRAGMENT = "f"
    VERTEX = "v"
    COMPUTE = "c"


def _md5sum(filename, buf_size=8192):
    m = sha256()
    with open(filename, "rb") as f:
        data = f.read(buf_size)
        while data:
            m.update(data)
            data = f.read(buf_size)
    return m.hexdigest()


def _get_platform():
    platforms = {"Windows": "windows", "Linux": "linux", "Darwin": "osx"}

    return platforms.get(platform.system())


def _get_profile():
    renderer_type = bgfx.getRendererType()
    sys_platform = platform.system()

    if sys_platform == "Darwin":
        return "metal"

    elif sys_platform == "Linux":
        if renderer_type == bgfx.RendererType.Vulkan:
            return "spirv"
        else:
            return "glsl"

    elif sys_platform == "Windows":
        if renderer_type == bgfx.RendererType.Direct3D9:
            return "s_3"
        else:
            return "s_5"

    else:
        raise ValueError("'{}' is not supported!".format(sys_platform))


def _load_mem(content):
    size = len(content)
    memory = bgfx.copy(as_void_ptr(content), size)
    return memory


def load_shader(
    name: str,
    shader_type: ShaderType,
    include_dirs: Optional[List[str]] = (),
    root_path: Optional[str] = None,
):
    shaders_root_path = Path(".") if not root_path else root_path
    complete_path = str(Path(shaders_root_path) / name)
    md5 = _md5sum(complete_path)

    logger.debug("Loading shader '{}': {}".format(name, md5))

    with shelve.open("shaders_cache") as cache:
        if complete_path in cache and cache[complete_path]["md5"] == md5:
            logger.debug(
                "Shader '{}' found in cache, skipping compilation".format(name)
            )
            memory = _load_mem(cache[complete_path]["content"])
        else:
            logger.debug("Shader '{}' not found in cache, compiling...".format(name))
            temp_file = compile_shader(complete_path, include_dirs, shader_type)

            with open(temp_file, "rb") as f:
                read_data = f.read()
                cache[complete_path] = {"md5": md5, "content": read_data}
            memory = _load_mem(read_data)

            os.unlink(temp_file)

    handle = bgfx.createShader(memory)
    bgfx.setName(handle, name)

    return handle


def compile_shader(
    complete_path: str, shader_type: ShaderType, include_dirs: Optional[List[str]] = ()
):
    temp_file = tempfile.NamedTemporaryFile(delete=False)
    options = []

    options.extend(("-f", complete_path))
    options.extend(("-o", temp_file.name))
    options.extend(("-i", default_include_dir))

    for include_dir in include_dirs:
        options.extend(["-i", include_dir])

    options.extend(("--platform", _get_platform()))
    options.extend(("--profile", _get_profile()))
    options.extend(("--type", shader_type.value))

    if platform.system() == "Windows":
        options.extend(["-O", "1" if shader_type == ShaderType.COMPUTE else "3"])

    temp_file.close()

    shaderc_bin = "{}/bin/shadercRelease".format(default_include_dir)
    os.chmod(shaderc_bin, 0o774)

    run_args = [shaderc_bin] + options
    run_info = subprocess.run(run_args, capture_output=True, text=True)

    if run_info.returncode != 0:
        print(run_info.stderr)

    return temp_file.name


# class Mesh:
#     def __init__(self, file_path: Path, ram_copy=False):
#         logger.debug(f"Loading mesh (RAM {ram_copy}): {file_path}")
#         self.internal_mesh = bgfx_lib.bgfx.mesh_load(str(file_path), ram_copy)
#
#     def submit(
#         self,
#         view_id: int,
#         program: bgfx_lib.bgfx.ProgramHandle,
#         matrix: List[float],
#         state=_bgfx.BGFX_STATE_MASK,
#     ):
#         self.internal_mesh.submit(view_id, program, as_void_ptr(matrix), state)
#
#     def destroy(self):
#         self.internal_mesh.unload()
