#!/usr/bin/env python3

import glob
import os
import shutil
import subprocess

# Overall script settings
binder_executable = glob.glob(
    f"{os.getcwd()}/../../binder/build/llvm-4.0.0/build_4.0.0*/bin/binder"
)[0]

bindings_dir = "tmp_bindings"
binder_source = f"{os.getcwd()}/../../binder/source"
pybind_source = f"{os.getcwd()}/../../binder/build/pybind11/include"
use_pybind_stl = True
this_project_source = f"{os.getcwd()}/../dependencies/bgfx/3rdparty/dear-imgui"
this_project_include = this_project_source
this_project_namespace_to_bind = "ImGui"
python_module_name = "bgfx_python"


def make_bindings_code(all_includes_file):
    shutil.rmtree(bindings_dir, ignore_errors=True)
    os.mkdir(bindings_dir)
    command = (
            f"{binder_executable} --root-module {python_module_name} "
            f"--prefix {os.getcwd()}/{bindings_dir}/ "
            f"--bind {this_project_namespace_to_bind} "
            "--single-file "
            + ("--config config.cfg " if use_pybind_stl else "")
            + f" {all_includes_file} -- -std=c++14 "
            f"-I{this_project_include} "
            f"-I{this_project_include}/widgets "
            f"-I{this_project_include}/../ "
            f"-DNDEBUG -v"
    ).split()

    print(" ".join(command))

    subprocess.call(command)


def main():
    all_includes_file = "../src/all_cmake_includes_imgui.hpp"
    make_bindings_code(all_includes_file)


if __name__ == "__main__":
    main()
