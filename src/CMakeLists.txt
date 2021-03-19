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
set(EXAMPLES_COMMON_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/bgfx/examples/common"
    CACHE PATH "EXAMPLES_COMMON dir" FORCE)

if(APPLE)
  set(BGFX_BUILD_DIR osx64_clang)
  set(BGFX_BUILD_PROJ_DIR gmake-osx)
  set(CLING_LIB_SUFFIX ".so")
elseif(WIN32)
  set(BGFX_BUILD_DIR win64_vs2017)
  set(BGFX_BUILD_PROJ_DIR vs2017)
  set(CMAKE_STATIC_LIBRARY_PREFIX "")
  set(CMAKE_STATIC_LIBRARY_SUFFIX ".lib")
  set(CLING_LIB_SUFFIX ".lib")
else()
  set(BGFX_BUILD_DIR linux64_gcc)
  set(BGFX_BUILD_PROJ_DIR gmake-linux)
  set(CLING_LIB_SUFFIX ".so")
endif()

message(STATUS "BX_DIR = ${BX_DIR}")
message(STATUS "BIMG_DIR = ${BIMG_DIR}")
message(STATUS "BGFX_DIR = ${BGFX_DIR}")

string(TOLOWER ${CMAKE_BUILD_TYPE} GENIE_BUILD_TYPE)

if(APPLE)
  set(DIST_COMMAND osx-x64-${GENIE_BUILD_TYPE})
  set(SDKROOT /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk)
  set(LINKER_OPTIONS
      "-framework Cocoa;-framework QuartzCore;-framework OpenGL;-weak_framework Metal;-weak_framework MetalKit;-Wl,-U,__main_"
  )
elseif(WIN32)
  include(FindWindowsSDK)
  set(LINKER_OPTIONS "d3d12.lib;d3d11.lib;dxgi.lib;psapi.lib;d3dcompiler.lib;/FORCE:UNRESOLVED")
  # get_windowssdk_include_dirs("${WINDOWSSDK_LATEST_DIR}" WINSDK_INCLUDE_DIRS) foreach(X IN LISTS WINSDK_INCLUDE_DIRS)
  # include_directories("${X}") endforeach()
else()
  set(DIST_COMMAND linux-${GENIE_BUILD_TYPE}64)
  set(LINKER_OPTIONS "-lGL;-lGLU;-lglut;-lpthread;-lrt;-ldl;-Wl,--start-group;-Wl,--undefined,__main_")
endif()

if(WIN32)
  set(MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")
  set(CMAKE_CXX_FLAGS_OLD "${CMAKE_CXX_FLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++14 /bigobj /D__STDC_FORMAT_MACROS /D_CRT_SECURE_NO_WARNINGS ")

  execute_process(COMMAND ../bx/tools/bin/windows/genie --with-tools ${BGFX_BUILD_PROJ_DIR}
                  WORKING_DIRECTORY ${BGFX_DIR})

  execute_process(COMMAND cmd /c ${CMAKE_CURRENT_SOURCE_DIR}/scripts/rename_runtime.bat
                          "${BGFX_DIR}/.build/projects/${BGFX_BUILD_PROJ_DIR}" COMMAND_ECHO STDOUT)

  execute_process(COMMAND msbuild bgfx.sln /p:Configuration=Release
                  WORKING_DIRECTORY "${BGFX_DIR}/.build/projects/${BGFX_BUILD_PROJ_DIR}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_OLD}")
else()
  if(APPLE)
    execute_process(COMMAND ${BX_DIR}/tools/bin/darwin/genie --with-tools --with-shared-lib --gcc=osx-x64 gmake
                    WORKING_DIRECTORY ${BGFX_DIR})
  else()
    execute_process(COMMAND ${BX_DIR}/tools/bin/linux/genie --with-tools --with-shared-lib --gcc=linux-gcc gmake
                    WORKING_DIRECTORY ${BGFX_DIR})
  endif()

  execute_process(COMMAND make -e ${DIST_COMMAND} CFLAGS+="-fPIC" WORKING_DIRECTORY ${BGFX_DIR})
endif()

if(NOT WIN32)
  set(CMAKE_MACOSX_RPATH ON)
  set(CMAKE_SKIP_BUILD_RPATH FALSE)
  set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
  set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
  set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

  file(COPY "${Cppyy_DIR}/lib/libCling${CLING_LIB_SUFFIX}" DESTINATION "/tmp/lib")
  file(COPY "${Cppyy_DIR}/lib/libCoreLegacy${CLING_LIB_SUFFIX}" DESTINATION "/tmp/lib")

  set(Cppyy_DIR "/tmp")
endif()

string(
  CONCAT
    LINKER_LIBRARIES
    "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/${CMAKE_STATIC_LIBRARY_PREFIX}bimg${CMAKE_BUILD_TYPE}${CMAKE_STATIC_LIBRARY_SUFFIX};"
    "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/${CMAKE_STATIC_LIBRARY_PREFIX}bimg_encode${CMAKE_BUILD_TYPE}${CMAKE_STATIC_LIBRARY_SUFFIX};"
    "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/${CMAKE_STATIC_LIBRARY_PREFIX}bimg_decode${CMAKE_BUILD_TYPE}${CMAKE_STATIC_LIBRARY_SUFFIX};"
    "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/${CMAKE_STATIC_LIBRARY_PREFIX}bx${CMAKE_BUILD_TYPE}${CMAKE_STATIC_LIBRARY_SUFFIX};"
    "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/${CMAKE_STATIC_LIBRARY_PREFIX}bgfx${CMAKE_BUILD_TYPE}${CMAKE_STATIC_LIBRARY_SUFFIX};"
    "${BGFX_DIR}/.build/${BGFX_BUILD_DIR}/bin/${CMAKE_STATIC_LIBRARY_PREFIX}example-common${CMAKE_BUILD_TYPE}${CMAKE_STATIC_LIBRARY_SUFFIX};"
    "${Cppyy_DIR}/lib/libCling${CLING_LIB_SUFFIX};"
    "${Cppyy_DIR}/lib/libCoreLegacy${CLING_LIB_SUFFIX}")

string(
  CONCAT INCLUDE_DIRS
         "${BX_DIR}/include;"
         "${BIMG_DIR}/include;"
         "${BGFX_DIR}/include;"
         "${BGFX_DIR}/include/bgfx;"
         "${IMGUI_DIR};"
         "${EXAMPLES_COMMON_DIR};"
         "${3RDPARTY_DIR};"
         "${CMAKE_CURRENT_SOURCE_DIR}/include")

if(WIN32)
  string(CONCAT INCLUDE_DIRS "${BX_DIR}/include/compat/msvc;" "${INCLUDE_DIRS}")
endif()

string(
  CONCAT H_DIRS
         "${BGFX_DIR}/include;"
         "${BX_DIR}/include;"
         "${BGFX_DIR}/include/bgfx;"
         "${IMGUI_DIR};"
         "${3RDPARTY_DIR};"
         "${EXAMPLES_COMMON_DIR};"
         "${CMAKE_CURRENT_SOURCE_DIR}/include")

string(CONCAT H_FILES "bgfx.h;" "bgfx/platform.h;" "imgui.h;" "imgui/imgui.h;" "bgfx_extra_utils.h")

if(DEFINED ENV{MANYLINUX_BUILD})
  file(COPY "${Cppyy_DIR}/lib/libCling${CLING_LIB_SUFFIX}" DESTINATION "/usr/lib")
  file(COPY "${Cppyy_DIR}/lib/libCoreLegacy${CLING_LIB_SUFFIX}" DESTINATION "/usr/lib")
endif()

# cmake-format: off
cppyy_add_bindings(
   "bgfx_python"
   LANGUAGE_STANDARD "14"
   TARGET_DIR "pybgfx"
   INCLUDE_DIRS ${INCLUDE_DIRS}
   LINK_OPTIONS ${LINKER_OPTIONS}
   LINK_LIBRARIES ${LINKER_LIBRARIES}
   H_DIRS ${H_DIRS}
   H_FILES ${H_FILES}
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

file(GLOB bgfx_headers "${BGFX_DIR}/include/bgfx/*.h")
install(FILES ${bgfx_headers} DESTINATION "pybgfx/include/bgfx")

file(GLOB bx_headers "${BX_DIR}/include/bx/*.h")
install(FILES ${bx_headers} DESTINATION "pybgfx/include/bx")

file(GLOB bx_inline_headers "${BX_DIR}/include/bx/inline/*.inl")
install(FILES ${bx_inline_headers} DESTINATION "pybgfx/include/bx/inline")

file(GLOB tinystl_headers "${BX_DIR}/include/tinystl/*.h")
install(FILES ${tinystl_headers} DESTINATION "pybgfx/include/tinystl")

file(GLOB bimg_headers "${BIMG_DIR}/include/bimg/*.h")
install(FILES ${bimg_headers} DESTINATION "pybgfx/include/bimg")

file(GLOB bgfx_examples_common_headers "${CMAKE_CURRENT_SOURCE_DIR}/examples/common/*.h")
install(FILES ${bgfx_examples_common_headers} "${CMAKE_CURRENT_SOURCE_DIR}/include/bgfx_extra_utils.h"
        DESTINATION "pybgfx/include/examples/common")

install(FILES "${BGFX_DIR}/src/bgfx_compute.sh" DESTINATION "pybgfx/include/shaders")
install(FILES "${BGFX_DIR}/src/bgfx_shader.sh" DESTINATION "pybgfx/include/shaders")

file(GLOB imgui_headers "${IMGUI_DIR}/*.h")
file(GLOB imgui_widgets_headers "${IMGUI_DIR}/widgets/*.h")
install(FILES ${imgui_headers} DESTINATION "pybgfx/include/imgui")
install(FILES ${imgui_widgets_headers} DESTINATION "pybgfx/include/imgui/widgets")
