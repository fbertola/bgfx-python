import gettext
import glob
import importlib.util
import inspect
import json
import os
import re
import sys

import cppyy
from loguru import logger

logger.disable("pybgfx")


def load_source(module_name, file_path, add_to_sys=False):
    spec = importlib.util.spec_from_file_location(module_name, file_path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    # Optional; only necessary if you want to be able to import the module
    # by name later.
    if add_to_sys:
        sys.modules[module_name] = module
    return module


gettext.install(__name__)

# Keep PyCharm happy.
_ = _

PRIMITIVE_TYPES = re.compile(r"\b(bool|char|short|int|unsigned|long|float|double)\b")


def add_pythonizations(py_files):
    for py_file in py_files:
        logger.debug("check {} for pythonizors".format(py_file))

        if not os.path.basename(py_file).startswith("pythonize"):
            continue

        module_name = inspect.getmodulename(py_file)
        module = load_source(module_name, py_file)
        funcs = inspect.getmembers(module, predicate=inspect.isroutine)

        for name, func in funcs:
            if not name.startswith("pythonize"):
                continue

            tokens = name.split("_")

            if len(tokens) > 1:
                namespace = tokens[1]

                logger.debug(
                    "added pythonization {} to namespace {}".format(func, namespace)
                )

                if namespace == "gbl":
                    cppyy.py.add_pythonization(func)
                else:
                    cppyy.py.add_pythonization(func, namespace)


def initialise(pkg, lib_file, map_file):
    pkg_dir = os.path.dirname(__file__)
    pkg_module = sys.modules[pkg]

    #
    # Load the library.
    #
    cppyy.add_include_path(pkg_dir + "/include")
    cppyy.add_include_path(pkg_dir + "/include/bx")
    cppyy.add_include_path(pkg_dir + "/include/bimg")
    cppyy.add_include_path(pkg_dir + "/include/bgfx")
    cppyy.add_include_path(pkg_dir + "/include/imgui")
    cppyy.add_include_path(pkg_dir + "/include/examples/common")
    cppyy.load_reflection_info(os.path.join(pkg_dir, lib_file))

    #
    # Load pythonizations
    #
    try:
        pythonization_files = glob.glob(
            os.path.join(pkg_dir, "**/pythonize*.py"), recursive=True
        )
    except TypeError:
        # versions older than 3.5 do not support 'recursive'
        # TODO: below is good enough for most cases, but not recursive
        pythonization_files = glob.glob(os.path.join(pkg_dir, "pythonize*.py"))
    add_pythonizations(pythonization_files)

    with open(os.path.join(pkg_dir, map_file), "r") as map_file:
        files = json.load(map_file)

    for file in files:
        add_after_namespaces = []

        for child in file["children"]:
            simple_name = child["name"].split("::")[0]

            if child["kind"] == "namespace":
                entity = getattr(cppyy.gbl, simple_name)
                if getattr(entity, "__module__", None) == "cppyy.gbl":
                    setattr(entity, "__module__", pkg)
                setattr(pkg_module, simple_name, entity)
            else:
                add_after_namespaces.append(child)

        for child in add_after_namespaces:
            simple_name = child["name"].split("::")[0]
            if child["kind"] == "enum":
                for enum_value in child["enumerations"]:
                    enum_value_name = enum_value["name"]
                    entity = getattr(cppyy.gbl, enum_value_name)
                    setattr(entity, "__module__", pkg + ".ImGui")
                    setattr(pkg_module.ImGui, enum_value_name, entity)
            elif child["kind"] not in (
                "typedef",
                "function",
            ) and simple_name.startswith("Im"):
                entity = getattr(cppyy.gbl, simple_name)
                setattr(entity, "__module__", pkg + ".ImGui")
                setattr(pkg_module.ImGui, simple_name, entity)
