<h1 align="center"> 
  <br>
  BGFX Python
  <br>
</h1>

<h4 align="center">Python 3.6+ wrapper for the BGFX library.</h4>

<p align="center">
  <img src="https://img.shields.io/badge/python-v3.6+-blue.svg">
  <a href="https://travis-ci.com/fbertola/bgfx-python"><img src="https://travis-ci.com/fbertola/bgfx-python.svg?branch=master"></a>
  <img src="https://img.shields.io/badge/dependencies-up%20to%20date-brightgreen.svg">
  <a href="https://github.com/fbertola/bgfx-python/issues"><img src="https://img.shields.io/github/issues/fbertola/bgfx-python.svg"></a>
  <img src="https://img.shields.io/badge/contributions-welcome-orange.svg">
  <a href="https://opensource.org/licenses/BSD"><img src="https://img.shields.io/badge/license-BSD-blue.svg"></a>
</p>

<p align="center">
  <a href="#key-features">Key Features</a> •
  <a href="#how-to-use">How To Use</a> •
  <a href="#build-cpp-bindings">Build CPP bindings</a> •
  <a href="#examples">Examples</a> •
  <a href="#credits">Credits</a> •
  <a href="#license">License</a>
</p>

<p align="center">
  <img src="https://raw.githubusercontent.com/fbertola/bgfx-python/master/examples/helloworld/screenshot.png">
</p>

## Key Features

* Uses _Pyind11_ and _Builder_ to natively wrap the C++ interface. No _CTypes_ or ugly C interfaces.
* Unless specified, the GIL is released for every invocation and pointers are passed by reference. This will ensure great overall performances.
* Maintains the original documentation; use `help()` on a class or function to view it.
* On-the-fly compiles shaders, so you don't have to.
* Ships with [ImGui](https://github.com/ocornut/imgui), integrated with BGFX's rendering pipeline.  

## How To Use

To install the latest version, you'll need to clone this repository and its submodules:

```bash
$ git clone --depth=1 https://github.com/fbertola/bgfx-python
$ git submodule update --init --recursive
```

Then, make sure to have `make`, `cmake` and `ninja` installed in your system.

Finally, simply build and install the wheel.

```bash
$ python setup.py install
``` 

### Installing on MacOS 

Building on MacOS X > 10.14 requires you to also install the SDK headers:

```bash
xcode-select --install
open /Library/Developer/CommandLineTools/Packages/macOS_SDK_headers_for_macOS_10.14.pkg
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

## Examples

You will find some examples in the `examples` folder, be sure to check them out.

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
