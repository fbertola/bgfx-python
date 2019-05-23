project(bgfx_python)
cmake_minimum_required(VERSION 3.11.0)

find_package(Python3 COMPONENTS Development)
find_package(PythonExtensions REQUIRED)

message(STATUS "PYTHON_LIBRARIES = ${PYTHON_LIBRARIES}")
message(STATUS "PYTHON_INCLUDE_DIRS = ${PYTHON_INCLUDE_DIRS}")

set(BX_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/bx" CACHE PATH "BX dir" FORCE)
set(BIMG_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/bimg" CACHE PATH "BIMG dir" FORCE)
set(BGFX_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/bgfx" CACHE PATH "BGFX dir" FORCE)
set(PYBIND11_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/pybind11" CACHE PATH "PYBIND11 dir" FORCE)

if (APPLE)
    set(BGFX_BUILD_DIR osx64_clang)
    set(BGFX_BUILD_PROJ_DIR gmake-osx)
elseif (WIN32)
    set(BGFX_BUILD_DIR win64_vs2017)
    set(BGFX_BUILD_PROJ_DIR vs2017)
else()
    set(BGFX_BUILD_DIR linux64_gcc)
    set(BGFX_BUILD_PROJ_DIR gmake-linux)
endif()

message(STATUS "BX_DIR = ${BX_DIR}")
message(STATUS "BIMG_DIR = ${BIMG_DIR}")
message(STATUS "BGFX_DIR = ${BGFX_DIR}")
message(STATUS "PYBIND11_DIR = ${PYBIND11_DIR}")

include_directories("${BX_DIR}/include")
include_directories("${BIMG_DIR}/include")
include_directories("${BGFX_DIR}/include")
include_directories("${BGFX_DIR}/include/bgfx")
include_directories("${PYBIND11_DIR}/include")

set_property(GLOBAL PROPERTY POSITION_INDEPENDENT_CODE ON)

if (APPLE)
    set(CMAKE_MODULE_LINKER_FLAGS "-framework Cocoa -framework QuartzCore -framework OpenGL -weak_framework Metal -weak_framework MetalKit ")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 ")

execute_process(COMMAND make -e projgen WORKING_DIRECTORY ${BGFX_DIR})
execute_process(COMMAND make -e config=release64 bx bimg bgfx CFLAGS=-fPIC WORKING_DIRECTORY "${BGFX_DIR}/.build/projects/${BGFX_BUILD_PROJ_DIR}")

add_library(bgfx_python MODULE bgfx_python.cpp)

target_link_libraries(bgfx_python "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/libbimgRelease.a")
target_link_libraries(bgfx_python "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/libbxRelease.a")
target_link_libraries(bgfx_python "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/libbgfxRelease.a")

python_extension_module(bgfx_python)
install(TARGETS bgfx_python LIBRARY DESTINATION bgfx_python)