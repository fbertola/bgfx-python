project(bgfx_python)
cmake_minimum_required(VERSION 3.6.1)

find_package(Python3 COMPONENTS Development)
find_package(PythonExtensions REQUIRED)

message(STATUS "PYTHON_LIBRARIES = ${PYTHON_LIBRARIES}")
message(STATUS "PYTHON_INCLUDE_DIRS = ${PYTHON_INCLUDE_DIRS}")

set(BX_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/bx" CACHE PATH "BX dir" FORCE)
set(BIMG_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/bimg" CACHE PATH "BIMG dir" FORCE)
set(BGFX_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/bgfx" CACHE PATH "BGFX dir" FORCE)
set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/bgfx/3rdparty/dear-imgui" CACHE PATH "IMGUI dir" FORCE)
set(3RDPARTY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/bgfx/3rdparty" CACHE PATH "3RDPARTY dir" FORCE)
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
include_directories("${BGFX_DIR}/src")
include_directories("${BGFX_DIR}/include")
include_directories("${BGFX_DIR}/include/bgfx")
include_directories("${BGFX_DIR}/examples")
include_directories("${BGFX_DIR}/tools/shaderc")
include_directories("${BGFX_DIR}/3rdparty/fcpp")
include_directories("${BGFX_DIR}/3rdparty/dxsdk/include")
include_directories("${BGFX_DIR}/3rdparty/glslang")
include_directories("${BGFX_DIR}/3rdparty/glslang/StandAlone")
include_directories("${BGFX_DIR}/3rdparty/glslang/glslang/Public")
include_directories("${BGFX_DIR}/3rdparty/glsl-optimizer/include")
include_directories("${BGFX_DIR}/3rdparty/glsl-optimizer/src/glsl")
include_directories("${BGFX_DIR}/3rdparty/spirv-cross")
include_directories("${BGFX_DIR}/3rdparty/spirv-tools/include")
include_directories("${IMGUI_DIR}")
include_directories("${IMGUI_DIR}/widgets")
include_directories("${3RDPARTY_DIR}")
include_directories("${PYBIND11_DIR}/include")

set_property(GLOBAL PROPERTY POSITION_INDEPENDENT_CODE ON)

if (APPLE)
    set(DIST_COMMAND dist-darwin)
    set(SDKROOT /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk)
    set(CMAKE_MODULE_LINKER_FLAGS "-framework Cocoa -framework QuartzCore -framework OpenGL -weak_framework Metal -weak_framework MetalKit ")
elseif (WIN32)
else()
    set(DIST_COMMAND dist-linux)
    set(CMAKE_MODULE_LINKER_FLAGS "-lGL -lGLU -lglut -lpthread -lrt -ldl -Wl,--start-group")
endif()

add_library(bgfx_lib MODULE
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${BGFX_DIR}/examples/common/imgui/imgui.cpp
    bgfx_python.cpp
    imgui_python.cpp
    imgui_extra_python.cpp
    bgfx_module.cpp)

add_library(shaderc MODULE
    ${BGFX_DIR}/tools/shaderc/shaderc_glsl.cpp
    ${BGFX_DIR}/tools/shaderc/shaderc_hlsl.cpp
    ${BGFX_DIR}/tools/shaderc/shaderc_metal.cpp
    ${BGFX_DIR}/tools/shaderc/shaderc_pssl.cpp
    ${BGFX_DIR}/tools/shaderc/shaderc_spirv.cpp
    ${BGFX_DIR}/src/vertexdecl.cpp
    ${BGFX_DIR}/src/shader_spirv.cpp
    shaderc_python.cpp
    shaderc_module.cpp)

if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++14")
    execute_process(COMMAND ../bx/tools/bin/windows/genie ${BGFX_BUILD_PROJ_DIR} WORKING_DIRECTORY ${BGFX_DIR})

    execute_process(COMMAND sed -i -e 's/MultiThreaded/MultiThreadedDLL/g' bx.vcxproj WORKING_DIRECTORY "${BGFX_DIR}/.build/projects/${BGFX_BUILD_PROJ_DIR}")
    execute_process(COMMAND sed -i -e 's/MultiThreaded/MultiThreadedDLL/g' bimg.vcxproj WORKING_DIRECTORY "${BGFX_DIR}/.build/projects/${BGFX_BUILD_PROJ_DIR}")
    execute_process(COMMAND sed -i -e 's/MultiThreaded/MultiThreadedDLL/g' bgfx.vcxproj WORKING_DIRECTORY "${BGFX_DIR}/.build/projects/${BGFX_BUILD_PROJ_DIR}")

    execute_process(COMMAND msbuild shaderc.vcxproj WORKING_DIRECTORY "${BGFX_DIR}/.build/projects/${BGFX_BUILD_PROJ_DIR}")
    execute_process(COMMAND msbuild bx.vcxproj WORKING_DIRECTORY "${BGFX_DIR}/.build/projects/${BGFX_BUILD_PROJ_DIR}")
    execute_process(COMMAND msbuild bimg.vcxproj WORKING_DIRECTORY "${BGFX_DIR}/.build/projects/${BGFX_BUILD_PROJ_DIR}")
    execute_process(COMMAND msbuild bgfx.vcxproj WORKING_DIRECTORY "${BGFX_DIR}/.build/projects/${BGFX_BUILD_PROJ_DIR}")
    target_link_libraries(bgfx_lib "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/bimgRelease.lib")
    target_link_libraries(bgfx_lib "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/bxRelease.lib")
    target_link_libraries(bgfx_lib "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/bgfxRelease.lib")

    target_link_libraries(shaderc "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/bxRelease.lib")
    target_link_libraries(shaderc "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/libfcppRelease.lib")
    target_link_libraries(shaderc "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/libglslangRelease.lib")
    target_link_libraries(shaderc "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/libglsl-optimizerRelease.lib")
    target_link_libraries(shaderc "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/libspirv-optRelease.lib")
    target_link_libraries(shaderc "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/libspirv-crossRelease.lib")

else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fPIC -D__STDC_FORMAT_MACROS ")

    execute_process(COMMAND make -e projgen WORKING_DIRECTORY ${BGFX_DIR})
    execute_process(COMMAND make -e ${DIST_COMMAND} WORKING_DIRECTORY ${BGFX_DIR})
    target_link_libraries(bgfx_lib "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/libbgfxRelease.a")
    target_link_libraries(bgfx_lib "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/libbimgRelease.a")
    target_link_libraries(bgfx_lib "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/libbxRelease.a")

    target_link_libraries(shaderc "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/libbxRelease.a")
    target_link_libraries(shaderc "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/libfcppRelease.a")
    target_link_libraries(shaderc "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/libglslangRelease.a")
    target_link_libraries(shaderc "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/libglsl-optimizerRelease.a")
    target_link_libraries(shaderc "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/libspirv-optRelease.a")
    target_link_libraries(shaderc "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/libspirv-crossRelease.a")

endif()

python_extension_module(bgfx_lib)
python_extension_module(shaderc)

install(TARGETS bgfx_lib shaderc LIBRARY DESTINATION bgfx)
