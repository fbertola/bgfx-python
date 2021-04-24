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

# noinspection PyUnresolvedReferences
from pybgfx import bgfx
from pybgfx.utils import as_void_ptr

logger.disable("pybgfx")

_pkg_path = Path(os.path.dirname(__file__)).parent
_default_bin_path = _pkg_path / "bin"
_default_include_dir = _pkg_path / "include" / "shaders"
_os_exe_suffix = ".exe" if platform.system() == "Windows" else ""


class ShaderType(Enum):
    FRAGMENT = "f"
    VERTEX = "v"
    COMPUTE = "c"


def _md5sum(filename, buf_size=8192) -> str:
    m = sha256()
    with open(filename, "rb") as f:
        data = f.read(buf_size)
        while data:
            m.update(data)
            data = f.read(buf_size)
    return m.hexdigest()


def _get_platform() -> str:
    platforms = {"Windows": "windows", "Linux": "linux", "Darwin": "osx"}

    return platforms.get(platform.system())


def _get_profile(shader_type: ShaderType) -> str:
    renderer_type = bgfx.getRendererType()
    sys_platform = platform.system()
    windows_shader_type = {
        ShaderType.FRAGMENT: "ps_",
        ShaderType.VERTEX: "vs_",
        ShaderType.COMPUTE: "cs_",
    }

    if sys_platform == "Darwin":
        return "metal"

    elif sys_platform == "Linux":
        if renderer_type == bgfx.RendererType.Vulkan:
            return "spirv"
        else:
            return "glsl"

    elif sys_platform == "Windows":
        if renderer_type == bgfx.RendererType.Direct3D9:
            return windows_shader_type.get(shader_type) + "3_0"
        else:
            return windows_shader_type.get(shader_type) + "5_0"

    else:
        raise ValueError("'{}' is not supported!".format(sys_platform))


def _load_mem(content: bytes) -> bgfx.Memory:
    size = len(content)
    memory = bgfx.copy(as_void_ptr(content), size)
    return memory


def _make_paths_absolute(paths: List[str], root_path: str) -> List[str]:
    if not root_path:
        return paths

    absolute_paths = []

    for path in paths:
        if not os.path.abspath(path):
            absolute_paths.append(os.path.join(root_path, path))
        else:
            absolute_paths.append(path)

    return absolute_paths


def load_shader(
    name: str,
    shader_type: ShaderType,
    include_dirs: Optional[List[str]] = (),
    root_path: Optional[Path] = None,
) -> bgfx.ShaderHandle:
    """
    Compiles the given shader for the platform-specific driver and creates
    a bgfx::ShaderHandle object.

    :param name: the shader's file name
    :param shader_type: the shader's type (e.g. fragment, vertex, compute)
    :param include_dirs: additional absolute paths to resolve shader's #include directives
    :param root_path: the root path for shaders lookup
    :return: a bgfx::ShaderHandle for the compiled shader
    """

    shaders_root_path = Path(".") if not root_path else root_path
    complete_path = str((Path(shaders_root_path) / name).absolute())
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
            absolute_include_dir_paths = _make_paths_absolute(include_dirs, root_path)
            compiled_shader = compile_shader(
                complete_path, shader_type, absolute_include_dir_paths
            )

            with open(compiled_shader, mode="rb") as compiled_shader_fp:
                compiled_shader_source = compiled_shader_fp.read()
                cache[complete_path] = {"md5": md5, "content": compiled_shader_source}
                memory = _load_mem(compiled_shader_source)

            os.unlink(compiled_shader)

    handle = bgfx.createShader(memory)
    bgfx.setName(handle, name)

    return handle


def compile_shader(
    complete_path: str, shader_type: ShaderType, include_dirs: Optional[List[str]] = ()
) -> str:
    """
    Compiles the given shader for the platform-specific driver and saves it to
    a temporary file.

    :param complete_path: the absolute path of the shader to compile
    :param shader_type: the shader's type (e.g. fragment, vertex, compute)
    :param include_dirs: additional absolute paths to resolve shader's #include directives
    :return: the path of the temporary file containing the compiled shader's source
    """
    if not os.path.exists(complete_path):
        raise RuntimeError("Shader {} does not exists!".format(complete_path))

    options = []
    temp_file = tempfile.NamedTemporaryFile(delete=False)

    options.extend(("-f", complete_path))
    options.extend(("-o", temp_file.name))
    options.extend(("-i", str(_default_include_dir)))

    for include_dir in include_dirs:
        if not os.path.exists(include_dir) or os.path.isdir(include_dir):
            raise RuntimeError(
                "{} does not exists or is not a directory!".format(include_dir)
            )

        options.extend(["-i", include_dir])

    options.extend(("--platform", _get_platform()))
    options.extend(("--profile", _get_profile(shader_type)))
    options.extend(("--type", shader_type.value))

    if platform.system() == "Windows":
        options.extend(["-O", "1" if shader_type == ShaderType.COMPUTE else "3"])

    shaderc_bin = str(_default_bin_path / "shadercRelease{}".format(_os_exe_suffix))
    os.chmod(shaderc_bin, 0o774)

    run_args = [shaderc_bin] + options
    run_info = subprocess.run(run_args, capture_output=True, text=True)

    if run_info.returncode != 0:
        raise RuntimeError(
            "Error compiling shader {}:\n{}".format(complete_path, run_info.stdout)
        )

    return temp_file.name
