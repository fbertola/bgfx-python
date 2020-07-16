# -*- coding: utf-8 -*-

import io
import os
import sys
from shutil import rmtree

from setuptools import Command
from skbuild import setup
from skbuild.constants import skbuild_plat_name

here = os.path.abspath(os.path.dirname(__file__))

try:
    with io.open(os.path.join(here, 'README.md'), encoding='utf-8') as f:
        long_description = '\n' + f.read()
except FileNotFoundError:
    long_description = ""

package_name = "bgfx-python"
version = "1.0.2"


class UploadCommand(Command):
    """Support setup.py upload."""

    description = 'Build and publish the package.'
    user_options = []

    @staticmethod
    def status(s):
        """Prints things in bold."""
        print('\033[1m{0}\033[0m'.format(s))

    def initialize_options(self):
        pass

    def finalize_options(self):
        pass

    def run(self):
        try:
            self.status('Removing previous builds.')
            rmtree(os.path.join(here, 'dist'))
        except OSError:
            pass

        self.status('Building Source and Wheel distribution.')
        os.system('{0} setup.py sdist bdist_wheel'.format(sys.executable))

        self.status('Uploading the package to PyPI via Twine.')
        os.system('twine upload dist/*')

        self.status('Pushing git tags.')
        os.system('git tag v{0}'.format(version))
        os.system('git push --tags')

        sys.exit()


cmake_args = []
if sys.platform == 'darwin':
    plat_name = skbuild_plat_name()
    sep = [pos for pos, char in enumerate(plat_name) if char == '-']
    assert len(sep) == 2
    cmake_args = ['-DCMAKE_OSX_DEPLOYMENT_TARGET:STRING=' + plat_name[sep[0] + 1:sep[1]],
                  '-DCMAKE_OSX_ARCHITECTURES:STRING=' + plat_name[sep[1] + 1:]]

setup(
    name=package_name,
    version=version,
    description='Python wrapper for BGFX Library',
    author='Federico Bertola',
    url='https://github.com/fbertola/bgfx-python',
    packages=['bgfx', 'examples'],
    cmake_source_dir="src",
    cmake_args=cmake_args,
    long_description=long_description,
    long_description_content_type='text/markdown',
    python_requires=">=3.6.0",
    include_package_data=True,
    zip_safe=False,
    license='BSD',
    install_requires=[
        'loguru'
    ],
    classifiers=[
        'License :: OSI Approved :: BSD License',
        'Intended Audience :: Developers',
        'Operating System :: OS Independent',
        'Programming Language :: Python',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.6',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: Implementation :: CPython',
        'Programming Language :: Python :: Implementation :: PyPy',
        'Topic :: Multimedia :: Graphics'
    ],
    cmdclass={
        'upload': UploadCommand,
    },
)
