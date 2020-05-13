<h1 align="center"> 
  <br>
  BGFX Python
  <br>
</h1>

<h4 align="center">Python 3.6+ wrapper for the BGFX library.</h4>

<p align="center">
  <img src="https://img.shields.io/pypi/pyversions/bgfx-python">
  <img src="https://img.shields.io/pypi/v/bgfx-python">
  <img src="https://img.shields.io/pypi/wheel/bgfx-python">
  <br />
  <a href="https://github.com/fbertola/bgfx-python/issues"><img src="https://img.shields.io/github/issues/fbertola/bgfx-python.svg"></a>
  <img src="https://img.shields.io/badge/contributions-welcome-orange.svg">
  <a href="https://opensource.org/licenses/BSD"><img src="https://img.shields.io/badge/license-BSD--2%20clause-blue.svg"></a>
  <br />
  <a href="https://travis-ci.com/fbertola/bgfx-python"><img src="https://travis-ci.com/fbertola/bgfx-python.svg?branch=master"></a>
  <a href="https://ci.appveyor.com/project/fbertola/bgfx-python/branch/master"><img src="https://ci.appveyor.com/api/projects/status/bu72q2ybqb6eqhbq/branch/master?svg=true"></a>
</p>

<p align="center">
  <a href="#key-features">Key Features</a> •
  <a href="#how-to-use">How To Use</a> •
  <a href="#build-cpp-bindings">Build CPP bindings</a> •
  <a href="#using-imgui">Using ImGUI</a> •
  <a href="#examples">Examples</a> •
  <a href="#logging">Logging</a> •
  <a href="#credits">Credits</a> •
  <a href="#license">License</a>
</p>

<p align="center">
  <img src="https://raw.githubusercontent.com/fbertola/bgfx-python/master/examples/helloworld/screenshot.png">
</p>

## Key Features

* Uses _Pyind11_ and _Builder_ to natively wrap the C++ interface. No _CTypes_ or ugly C interfaces.
* Functions, classes and methods respect the PEP 8 notation.
* Unless specified, the GIL is released for every invocation and pointers are passed by reference. This will ensure great overall performances.
* Maintains the original documentation; use `help()` on a class or function to view it.
* Compiles shaders on-the-fly, so you don't have to.
* Ships with [ImGui](https://github.com/ocornut/imgui) integrated in the BGFX rendering pipeline.  

## How To Use

### Precompiled wheels

Precompiled wheels are available for Windows, Linux and MacOS.
To install the latest published release, simply run:

```bash
$ pip install bgfx-python
```

Linux wheels are built with the help of the [ManyLinux](https://github.com/pypa/manylinux) project and, unfortunately, are too large for the PyPi repository.
You can download those wheels from the [Bintray Repository](https://bintray.com/fbertola/bgfx-python-wheels/bgfx-python/).

### Install from source

To install the latest version, you'll need to clone this repository and its submodules:

```bash
$ git clone --depth=1 https://github.com/fbertola/bgfx-python
$ git submodule update --init --recursive
```

Then, make sure to have `make`, `cmake` and `ninja` installed in your system.

Finally, simply build and install the wheel.

```bash
$ pip setup.py install
``` 

### Installing on MacOS 

Building on MacOS X > 10.14 requires you to also install the SDK headers:

```bash
xcode-select --install
open /Library/Developer/CommandLineTools/Packages/macOS_SDK_headers_for_macOS_10.14.pkg
```

### Installing on Windows

The easiest way is to install [Visual Studio 2019 Community Edition](https://visualstudio.microsoft.com/it/vs/). If you have [Chocolatey](https://chocolatey.org/install) installed, then run:

```bash
choco install visualstudio2019community
```

Before building the package, make sure to activate all the environment variables required by the compiler:

```bash
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" x86_amd64
```

## Build CPP bindings

`bgfx-python` uses _Binder_ and _Pybind11_ to wrap the original library. A script to generate such binding is provided inside the `scripts` directory.
Make sure that all the paths are corrects then simply launch the various scripts, e.g:

```bash
$ python make_bindings_bgfx.py
``` 

Building on MacOS X could be a little trickier, since system headers are in the SDK location. Make sure to also include these paths; you can check where the headers are located running this command:

```bash
g++ -E -x c++ - -v < /dev/null
```

## Using ImGUI

Two modules are exposed:
* *ImGui*, which provides a standard wrapper around all the ImGui funcions and classes.
* *ImGuiExtra*, which provides some additional functions to integrate ImGui in the BGFX rendering pipline.

To use it in your application, simply follow this template:

```python
# Setup the application
def init():
    ImGuiExtra.imgui_create()

# Destroy the application
def destroy():
    ImGuiExtra.imgui_destroy()

# Update the application, rendering each fram
def update():
    ImGuiExtra.imgui_begin_frame(
        mouse_x, mouse_y, buttons_states, 0, width, height
    )

    # Other ImGui drawing directives...

    ImGuiExtra.imgui_end_frame()
```
 
All ImGui API that provides user input (such as _InputText_, _SliderFloat_, etc.) modifies their arguments by reference. However, in Python, such objects as integers, floats and strings are passed always by value. Because of this, *bgfx-python* provides special wrappers, that allow passing those variables by reference.

For example, to use _SliderFloat_, you will need first to create a variable that will hold the state:

```python
f = ImGui.Float();
```
You can access the value in the following way: `f.value`

To use it with _slider_float_ simply pass it to that function:

```python
ImGui.slider_float("float slider", f, 0.0, 1.0)
```

## Logging

[Loguru](https://github.com/Delgan/loguru) is used for logging inside `bgfx_python`. By default the logger is disabled; to enable it, use the following instructions:

```python
from loguru import logger

logger.enable("bgfx")
```

## Examples

You will find some examples in the `examples` folder, be sure to check them out.
For a more advanced example, see the [Natrix](https://github.com/fbertola/Natrix) project.

## Credits

This software uses the following open source packages:

- [bgfx](https://github.com/bkaradzic/bgfx)
- [pybind11](https://github.com/pybind/pybind11)
- [binder](https://github.com/RosettaCommons/binder)


[License (BSD 2-clause)](https://raw.githubusercontent.com/fbertola/bgfx-python/master/LICENSE)
-----------------------------------------------------------------------

<a href="http://opensource.org/licenses/BSD-2-Clause" target="_blank">
<img align="right" src="http://opensource.org/trademarks/opensource/OSI-Approved-License-100x137.png">
</a>

    BSD 2-Clause License
    
    Copyright (c) 2019, Federico Bertola
    All rights reserved.
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    
    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.
    
    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


---

> GitHub [@fbertola](https://github.com/fbertola)
