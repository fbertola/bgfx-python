# .rst: FindLibClang
# ------------
#
# Find LibClang
#
# Find LibClang headers and library
#
# ::
#
# LibClang_FOUND             - True if libclang is found. LibClang_LIBRARY           - Clang library to link against.
# LibClang_VERSION           - Version number as a string (e.g. "3.9"). LibClang_PYTHON_EXECUTABLE - Compatible python
# version.

#
# Python support for clang might not be available for Python3. We need to find what we have.
#
set(LIBCLANG_KNOWN_LLVM_VERSIONS
    11.1.0
    11.0.0
    9.0.0
    9.0
    9
    8.0.0
    8.0
    8
    7.0.1
    7.0.0
    7.0
    7
    6.0.1
    6.0.0
    6.0
    6
    5.0.2
    5.0.1
    5.0.0
    5.0
    5
    4.0.1
    4.0.0
    4.0
    4
    3.9.1
    3.9.0
    3.9
    3.8.1
    3.8.0
    3.8
    3.7.1
    3.7.0
    3.7
    3.6.2
    3.6.1
    3.6.0
    3.6
    3.5.2
    3.5.1
    3.5.0
    3.5
    3.4.2
    3.4.1
    3.4
    3.3
    3.2
    3.1)

set(libclang_llvm_header_search_paths)
set(libclang_llvm_lib_search_paths # LLVM Fedora
    /usr/lib/llvm)

foreach(version ${LIBCLANG_KNOWN_LLVM_VERSIONS})
  string(REPLACE "." "" undotted_version "${version}")
  list(
    APPEND
    libclang_llvm_header_search_paths
    # LLVM Debian/Ubuntu nightly packages: http://llvm.org/apt/
    "/usr/lib/llvm-${version}/include/"
    # LLVM MacPorts
    "/opt/local/libexec/llvm-${version}/include"
    # LLVM Homebrew
    "/usr/local/Cellar/llvm/${version}/include"
    # LLVM Homebrew/versions
    "/usr/local/lib/llvm-${version}/include"
    # FreeBSD ports versions
    "/usr/local/llvm${undotted_version}/include"
    # Gentoo clang-4
    "/usr/lib/llvm/${version}/include")

  list(
    APPEND
    libclang_llvm_lib_search_paths
    # LLVM Debian/Ubuntu nightly packages: http://llvm.org/apt/
    "/usr/lib/llvm-${version}/lib/"
    # LLVM MacPorts
    "/opt/local/libexec/llvm-${version}/lib"
    # LLVM Homebrew
    "/usr/local/Cellar/llvm/${version}/lib"
    # LLVM Homebrew/versions
    "/usr/local/lib/llvm-${version}/lib"
    # FreeBSD ports versions
    "/usr/local/llvm${undotted_version}/lib"
    # Gentoo clang-4
    "/usr/lib/llvm/${version}/lib")
endforeach()

find_path(
  LibClang_INCLUDE_DIR clang-c/Index.h
  PATHS ${libclang_llvm_header_search_paths}
  PATH_SUFFIXES LLVM/include # Windows package from http://llvm.org/releases/
  DOC "The path to the directory that contains clang-c/Index.h")

find_library(
  LibClang_LIBRARY
  NAMES # On Windows with MSVC, the import library uses the ".imp" file extension instead of the comon ".lib"
        libclang.imp libclang clang
  PATHS ${libclang_llvm_lib_search_paths}
  PATH_SUFFIXES LLVM/lib # Windows package from http://llvm.org/releases/
  DOC "The file that corresponds to the libclang library.")

get_filename_component(LibClang_LIBRARY_DIR ${LibClang_LIBRARY} PATH)

function(_find_libclang_python python_executable)
  #
  # Prefer python3 explicitly or implicitly over python2.
  #
  foreach(exe IN ITEMS python3 python python2)
    execute_process(
      COMMAND ${exe} -c
              "from clang.cindex import Config; Config.set_library_file(\"${LibClang_LIBRARY}\"); Config().lib"
      ERROR_VARIABLE _stderr
      RESULT_VARIABLE _rc
      OUTPUT_STRIP_TRAILING_WHITESPACE)
    if("${_rc}" STREQUAL "0")
      set(pyexe ${exe})
      break()
    endif()
  endforeach()
  set(${python_executable}
      "${pyexe}"
      PARENT_SCOPE)
endfunction(_find_libclang_python)

# _find_libclang_python(LibClang_PYTHON_EXECUTABLE)
set(LibClang_PYTHON_EXECUTABLE "python")
if(LibClang_LIBRARY)
  set(LibClang_LIBRARY ${LibClang_LIBRARY})
  string(REGEX REPLACE ".*clang-\([0-9]+.[0-9]+\).*" "\\1" LibClang_VERSION_TMP "${LibClang_LIBRARY}")
  set(LibClang_VERSION
      ${LibClang_VERSION_TMP}
      CACHE STRING "LibClang version" FORCE)
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
  LibClang
  REQUIRED_VARS LibClang_LIBRARY
  VERSION_VAR LibClang_VERSION)

find_program(CLANG_EXE clang++)
execute_process(COMMAND ${CLANG_EXE} --version OUTPUT_VARIABLE clang_full_version_string)
string(REGEX REPLACE ".*clang version ([0-9]+\\.[0-9]+\\.[0-9]+).*" "\\1" CLANG_VERSION_STRING
                     "${clang_full_version_string}")

set(CLANG_VERSION_STRING
    ${CLANG_VERSION_STRING}
    PARENT_SCOPE)

mark_as_advanced(LibClang_VERSION)
unset(_filename)
unset(_find_libclang_filename)
