import platform
from .initializor import initialise

sys_platform = platform.system()

if sys_platform == "Darwin":
    _lib_name = "libbgfx_pythonCppyy.dylib"
elif sys_platform == "Linux":
    _lib_name = "libbgfx_pythonCppyy.so"
else:
    _lib_name = "bgfx_pythonCppyy.dll"

initialise("pybgfx", _lib_name, "bgfx_python.map")
del initialise
