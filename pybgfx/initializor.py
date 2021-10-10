import gettext
import glob
import importlib.util
import inspect
import json
import os
import re
from pathlib import Path

import sys

import cppyy
from loguru import logger

logger.disable("pybgfx")

gettext.install(__name__)


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
    cppyy.add_include_path(pkg_dir + "/include/extras")
    cppyy.add_include_path(pkg_dir + "/include/examples/common")

    files = fix_map_file_paths(pkg_dir, map_file)

    cppyy.load_reflection_info(os.path.join(pkg_dir, lib_file))

    add_types_to_namespaces(files, pkg, pkg_module)


def add_types_to_namespaces(files, pkg, pkg_module):
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


def fix_map_file_paths(pkg_dir, map_file):
    include_dir_map = {
        "bgfx": os.path.join(pkg_dir, "include/bgfx"),
        "dear-imgui": os.path.join(pkg_dir, "include/imgui"),
        "imgui": os.path.join(pkg_dir, "include/examples/common/imgui"),
        "extras": os.path.join(pkg_dir, "include/extras"),
    }
    with open(os.path.join(pkg_dir, map_file), "r") as map_file_pointer:
        files = json.load(map_file_pointer)

    for file in files:
        if file["kind"] == "file":
            file_path = Path(file["name"])

            if not str(file_path).startswith(pkg_dir):
                file_name = file_path.name
                folder_name = file_path.parent.name
                actual_folder = include_dir_map[folder_name]
                file["name"] = str((Path(actual_folder) / file_name).absolute())
                logger.info(f"Fixing MAP file entry: {file_path} -> {file['name']}")

    with open(os.path.join(pkg_dir, map_file), "w") as map_file_pointer:
        json.dump(files, map_file_pointer)

    return files
