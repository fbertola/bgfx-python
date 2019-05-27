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

## Key Features

* Uses _Pyind11_ and _Builder_ to natively wrap the C++ interface. No _CTypes_ or ugly C interfaces.
* Unless specified, the GIL is released for every invocation and pointers are passed by reference. This will ensure great overall performances.
* Maintains the original documentation; use `help()` on a class or function to view it. 

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

## Build CPP bindings

`bgfx-python` uses _Binder_ and _Pybind11_ to wrap the original library. A script to generate such binding is provided inside the `scripts` directory.
Make sure that all the paths are corrects then simply launch the script.

```bash
$ python make_bindings.py
``` 

## Examples

You will find some examples in the `examples` folder, be sure to check them out.

## Credits

This software uses the following open source packages:

- [bgfx](https://github.com/bkaradzic/bgfx)
- [pybind11](https://github.com/pybind/pybind11)
- [binder](https://github.com/RosettaCommons/binder)

## License

BSD

---

> GitHub [@fbertola](https://github.com/fbertola)
