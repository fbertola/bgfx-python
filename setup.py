import sys

from skbuild import setup
from skbuild.constants import skbuild_plat_name

cmake_args = []
if sys.platform == 'darwin':
    plat_name = skbuild_plat_name()
    sep = [pos for pos, char in enumerate(plat_name) if char == '-']
    assert len(sep) == 2
    cmake_args = ['-DCMAKE_OSX_DEPLOYMENT_TARGET:STRING=' + plat_name[sep[0] + 1:sep[1]],
                  '-DCMAKE_OSX_ARCHITECTURES:STRING=' + plat_name[sep[1] + 1:]]

setup(
    name="bgfx-python",
    version="0.0.1",
    description='Python wrapper for BGFX Library',
    author='Federico Bertola',
    url='https://github.com/fbertola/bgfx-python',
    license="BSD 2-Clause",
    packages=['bgfx_python'],
    cmake_source_dir="src",
    cmake_args=cmake_args,
)
