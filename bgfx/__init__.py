import os
import cppyy
from .initializor import initialise
from .constants import *
from .utils import *
from bgfx.bgfx_lib import *


initialise('bgfx_python', 'libbgfx_pythonCppyy.dylib', 'bgfx_python.map')
del initialise

