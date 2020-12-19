from .initializor import initialise
from .constants import *

# FIXME: different platforms
initialise('bgfx', 'libbgfx_pythonCppyy.dylib', 'bgfx_python.map')
del initialise



