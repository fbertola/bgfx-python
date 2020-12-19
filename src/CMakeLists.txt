project(bgfx_python)
cmake_minimum_required(VERSION 3.6.1)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules")
execute_process(
  COMMAND cling-config --cmake
  OUTPUT_VARIABLE CPPYY_MODULE_PATH
  OUTPUT_STRIP_TRAILING_WHITESPACE)

include(FindCppyy)

message(STATUS "CPPYY_FOUND = ${Cppyy_FOUND}")

set(BX_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/bx"
    CACHE PATH "BX dir" FORCE)
set(BIMG_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/bimg"
    CACHE PATH "BIMG dir" FORCE)
set(BGFX_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/bgfx"
    CACHE PATH "BGFX dir" FORCE)
set(IMGUI_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/bgfx/3rdparty/dear-imgui"
    CACHE PATH "IMGUI dir" FORCE)
set(3RDPARTY_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/bgfx/3rdparty"
    CACHE PATH "3RDPARTY dir" FORCE)

if(APPLE)
  set(BGFX_BUILD_DIR osx64_clang)
  set(BGFX_BUILD_PROJ_DIR gmake-osx)
  set(CLING_LIB_SUFFIX ".so")
elseif(WIN32)
  set(BGFX_BUILD_DIR win64_vs2019)
  set(BGFX_BUILD_PROJ_DIR vs2019)
  set(CLING_LIB_SUFFIX ".dll")
else()
  set(BGFX_BUILD_DIR linux64_gcc)
  set(BGFX_BUILD_PROJ_DIR gmake-linux)
  set(CLING_LIB_SUFFIX ".so")
endif()

message(STATUS "BX_DIR = ${BX_DIR}")
message(STATUS "BIMG_DIR = ${BIMG_DIR}")
message(STATUS "BGFX_DIR = ${BGFX_DIR}")

if(APPLE)
  if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(DIST_COMMAND osx-release64)
  else()
    set(DIST_COMMAND osx-debug64)
  endif()
  set(SDKROOT /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk)
  set(LINKER_OPTIONS
      "-framework Cocoa;-framework QuartzCore;-framework OpenGL;-weak_framework Metal;-weak_framework MetalKit")
elseif(WIN32)
  include(FindWindowsSDK)
  set(LINKER_OPTIONS "d3d12.lib;d3d11.lib;dxgi.lib;psapi.lib;d3dcompiler.lib")
  # get_windowssdk_include_dirs("${WINDOWSSDK_LATEST_DIR}" WINSDK_INCLUDE_DIRS) foreach(X IN LISTS WINSDK_INCLUDE_DIRS)
  # include_directories("${X}") endforeach()
else()
  if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(DIST_COMMAND linux-release64)
  else()
    set(DIST_COMMAND linux-debug64)
  endif()
  set(LINKER_OPTIONS "-lGL;-lGLU;-lglut;-lpthread;-lrt;-ldl;-Wl,--start-group")
endif()

if(WIN32)
  set(MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++14 /bigobj /D__STDC_FORMAT_MACROS /D_CRT_SECURE_NO_WARNINGS ")

  execute_process(COMMAND ../bx/tools/bin/windows/genie --with-tools ${BGFX_BUILD_PROJ_DIR}
                  WORKING_DIRECTORY ${BGFX_DIR})

  execute_process(COMMAND cmd /c ${CMAKE_CURRENT_SOURCE_DIR}/scripts/rename_runtime.bat
                          "${BGFX_DIR}/.build/projects/${BGFX_BUILD_PROJ_DIR}" COMMAND_ECHO STDOUT)

  execute_process(COMMAND msbuild bgfx.sln /p:Configuration=Release
                  WORKING_DIRECTORY "${BGFX_DIR}/.build/projects/${BGFX_BUILD_PROJ_DIR}")
else()
  if(APPLE)
    set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -std=c++14 -fPIC -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -D__STDC_CONSTANT_MACROS -DNDEBUG -ffast-math -fomit-frame-pointer -g -O3 -msse2 "
    )
    execute_process(COMMAND ${BX_DIR}/tools/bin/darwin/genie --with-tools --with-shared-lib --gcc=osx gmake
                    WORKING_DIRECTORY ${BGFX_DIR})
  else()
    set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -std=c++14 -fPIC -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -D__STDC_CONSTANT_MACROS -DNDEBUG -ffast-math -fomit-frame-pointer -fno-var-tracking-assignments -g -O3 -msse2 "
    )
    execute_process(COMMAND ${BX_DIR}/tools/bin/linux/genie --with-tools --with-shared-lib --gcc=linux-gcc gmake
                    WORKING_DIRECTORY ${BGFX_DIR})
  endif()

  execute_process(COMMAND make -e ${DIST_COMMAND} CFLAGS+="-fPIC" WORKING_DIRECTORY ${BGFX_DIR})
endif()

string(
  CONCAT LINKER_LIBRARIES
         "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/libbimg${CMAKE_BUILD_TYPE}${CMAKE_STATIC_LIBRARY_SUFFIX};"
         "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/libbx${CMAKE_BUILD_TYPE}${CMAKE_STATIC_LIBRARY_SUFFIX};"
         "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/libbgfx${CMAKE_BUILD_TYPE}${CMAKE_STATIC_LIBRARY_SUFFIX};"
         "${Cppyy_DIR}/lib/libCling${CLING_LIB_SUFFIX};"
         "${Cppyy_DIR}/lib/libCoreLegacy${CLING_LIB_SUFFIX}")

# cmake-format: off
cppyy_add_bindings(
   "bgfx_python"
   LANGUAGE_STANDARD "17"
   TARGET_DIR "pybgfx"
   INCLUDE_DIRS "${BX_DIR}/include;${BIMG_DIR}/include;${BGFX_DIR}/include/bgfx"
   LINK_OPTIONS ${LINKER_OPTIONS}
   LINK_LIBRARIES ${LINKER_LIBRARIES}
   H_DIRS "${BGFX_DIR}/include/bgfx"
   H_FILES "bgfx.h;platform.h"
)
# cmake-format: on

install(FILES "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/shaderc${CMAKE_BUILD_TYPE}${CMAKE_EXECUTABLE_SUFFIX}"
        DESTINATION "pybgfx/bin")
install(FILES "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/geometryc${CMAKE_BUILD_TYPE}${CMAKE_EXECUTABLE_SUFFIX}"
        DESTINATION "pybgfx/bin")
install(FILES "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/geometryv${CMAKE_BUILD_TYPE}${CMAKE_EXECUTABLE_SUFFIX}"
        DESTINATION "pybgfx/bin")
install(FILES "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/texturec${CMAKE_BUILD_TYPE}${CMAKE_EXECUTABLE_SUFFIX}"
        DESTINATION "pybgfx/bin")
install(FILES "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/texturev${CMAKE_BUILD_TYPE}${CMAKE_EXECUTABLE_SUFFIX}"
        DESTINATION "pybgfx/bin")
install(FILES "${BGFX_DIR}/include/bgfx/bgfx.h" "${BGFX_DIR}/include/bgfx/defines.h" DESTINATION "pybgfx/include")
install(FILES "${BGFX_DIR}/include/bgfx/platform.h" DESTINATION "pybgfx/include/bx")

file(GLOB imgui_shaders_files "${BGFX_DIR}/examples/common/imgui/*.sc")
file(GLOB imgui_compiled_shaders_files "${BGFX_DIR}/examples/common/imgui/*.bin.h")
file(GLOB imgui_font_files "${BGFX_DIR}/examples/common/imgui/*.ttf.h")
install(FILES ${imgui_shaders_files} ${imgui_compiled_shaders_files} ${imgui_font_files} DESTINATION "pybgfx/utils/imgui")