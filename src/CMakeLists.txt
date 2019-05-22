project(bgfx_python)
cmake_minimum_required(VERSION 3.11.0)

include(FindPython3)
find_package(Python3 COMPONENTS Development)
find_package(PythonExtensions REQUIRED)

message(STATUS "PYTHON_LIBRARIES = ${Python3_LIBRARIES}")
message(STATUS "PYTHON_INCLUDE_DIRS = ${Python3_INCLUDE_DIRS}}")

set(BX_DIR "${CMAKE_CURRENT_SOURCE_DIR}"/../dependencies/bx CACHE PATH "BX dir" FORCE)
set(BIMG_DIR "${CMAKE_CURRENT_SOURCE_DIR}"/../dependencies/bimg CACHE PATH "BIMG dir" FORCE)
set(BGFX_DIR "${CMAKE_CURRENT_SOURCE_DIR}"/../dependencies/bgfx CACHE PATH "BGFX dir" FORCE)
set(PYBIND11_DIR "${CMAKE_CURRENT_SOURCE_DIR}"/../dependencies/pybind11 CACHE PATH "PYBIND11 dir" FORCE)

include_directories("${BX_DIR}/include")
include_directories("${BIMG_DIR}/include")
include_directories("${BFDX_DIR}/include")
include_directories("${PYBIND11_DIR}/include")
include_directories(${Python3_INCLUDE_DIRS})

set_property(GLOBAL PROPERTY POSITION_INDEPENDENT_CODE ON)

if (APPLE)
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -framework Cocoa -framework QuartzCore -framework OpenGL -weak_framework Metal -weak_framework MetalKit ")
else

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 ")

add_library(bgfx_python MODULE bgfx_python.cpp)

target_link_libraries(bgfx_python ${BGFX_DIR}/osx64_clang/bin/libbimgRelease.a)
target_link_libraries(bgfx_python ${BGFX_DIR}/osx64_clang/bin/libbxRelease.a)
target_link_libraries(bgfx_python ${BGFX_DIR}/osx64_clang/bin/libbgfxRelease.a)
target_link_libraries(bgfx_python ${Python3_LIBRARIES})

python_extension_module(bgfx_python)
install(TARGETS bgfx_python LIBRARY DESTINATION bgfx_python)