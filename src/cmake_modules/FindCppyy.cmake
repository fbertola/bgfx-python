get_filename_component(BACKEND_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(BACKEND_PREFIX "${BACKEND_PREFIX}" PATH)
if(BACKEND_PREFIX STREQUAL "/")
  set(BACKEND_PREFIX "")
endif()

find_program(Cppyy_EXECUTABLE NAMES rootcling)

if(CPPYY_MODULE_PATH)
  #
  # Cppyy_DIR: one level above the installed cppyy cmake module path
  #
  set(Cppyy_DIR ${CPPYY_MODULE_PATH}/../)
  #
  # Cppyy_INCLUDE_DIRS: Directory with cppyy H_FILES
  #
  set(Cppyy_INCLUDE_DIRS ${Cppyy_DIR}/include)
  #
  # Cppyy_VERSION.
  #
  find_package(ROOT QUIET REQUIRED PATHS ${CPPYY_MODULE_PATH})
  if(ROOT_FOUND)
    set(Cppyy_VERSION ${ROOT_VERSION})
  endif()
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
  Cppyy
  REQUIRED_VARS Cppyy_EXECUTABLE Cppyy_DIR Cppyy_INCLUDE_DIRS CPPYY_MODULE_PATH
  VERSION_VAR Cppyy_VERSION)
mark_as_advanced(Cppyy_VERSION)

function(cppyy_add_bindings pkg)
  set(simple_args LANGUAGE_STANDARD TARGET_DIR)
  set(list_args
      IMPORTS
      GENERATE_OPTIONS
      COMPILE_OPTIONS
      INCLUDE_DIRS
      LINK_OPTIONS
      LINK_LIBRARIES
      CPPYY_LIBRARIES
      H_DIRS
      H_FILES
      LINKDEFS
      EXTRA_CODES
      EXTRA_HEADERS
      NAMESPACES)
  cmake_parse_arguments(ARG "" "${simple_args}" "${list_args}" ${ARGN})
  if(NOT "${ARG_UNPARSED_ARGUMENTS}" STREQUAL "")
    message(SEND_ERROR "Unexpected arguments specified '${ARG_UNPARSED_ARGUMENTS}'")
  endif()
  string(REGEX MATCH "[^\.]+$" pkg_simplename ${pkg})
  string(REGEX REPLACE "\.?${pkg_simplename}" "" pkg_namespace ${pkg})
  set(pkg_dir ${CMAKE_CURRENT_BINARY_DIR})
  string(REPLACE "." "/" tmp ${pkg})
  set(pkg_dir "${pkg_dir}/${tmp}")
  set(lib_name "${pkg_namespace}${pkg_simplename}Cppyy")
  set(lib_file ${CMAKE_SHARED_LIBRARY_PREFIX}${lib_name}${CMAKE_SHARED_LIBRARY_SUFFIX})
  set(cpp_file ${CMAKE_CURRENT_BINARY_DIR}/${pkg_simplename}.cpp)
  set(pcm_file ${pkg_dir}/${pkg_simplename}_rdict.pcm)
  set(rootmap_file ${pkg_dir}/${pkg_simplename}.rootmap)
  set(extra_map_file ${pkg_dir}/${pkg_simplename}.map)

  #
  # Language standard.
  #
  if("${ARG_LANGUAGE_STANDARD}" STREQUAL "")
    set(ARG_LANGUAGE_STANDARD "14")
  endif()

  if("${ARG_TARGET_DIR}" STREQUAL "")
    set(ARG_TARGET_DIR ${pkg})
  endif()

  # ####################################################################################################################
  #
  # Make H_FILES with absolute paths.
  #
  if("${ARG_H_FILES}" STREQUAL "")
    message(SEND_ERROR "No H_FILES specified")
  endif()

  if("${ARG_H_DIRS}" STREQUAL "")
    set(ARG_H_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
  endif()

  set(tmp)
  set(relative_h_files)
  foreach(h_file IN LISTS ARG_H_FILES)
    list(APPEND relative_h_files ${h_file})
    if(NOT IS_ABSOLUTE ${h_file})
      foreach(h_dir IN LISTS ARG_H_DIRS)
        if(EXISTS ${h_dir}/${h_file})
          set(h_file ${h_dir}/${h_file})
          break()
        endif()
      endforeach(h_dir)
    endif()
    if(NOT EXISTS ${h_file})
      message(WARNING "H_FILES ${h_file} does not exist")
    endif()
    list(APPEND tmp ${h_file})
  endforeach(h_file)
  set(ARG_H_FILES ${tmp})

  set(linker_args)
  foreach(link_option IN LISTS ARG_LINK_OPTIONS)
    list(APPEND linker_args "SHELL:${link_option}")
  endforeach()

  set(linker_libraries)
  foreach(cppyy_library IN LISTS ARG_CPPYY_LIBRARIES)
    list(APPEND linker_libraries "${cppyy_library}")
  endforeach()
  foreach(additional_library IN LISTS ARG_LINK_LIBRARIES)
    list(APPEND linker_libraries "${additional_library}")
  endforeach()

  # ####################################################################################################################
  #
  # Create the linkdef.h file with a line for each h_file.
  #
  set(out_linkdef ${CMAKE_CURRENT_BINARY_DIR}/linkdef.h)
  file(WRITE ${out_linkdef} "/* Per H_FILES entries: */\n")
  foreach(h_file IN LISTS ARG_H_FILES)
    #
    # Doubled-up path separators "//" causes errors in rootcling.
    #
    string(REGEX REPLACE "/+" "/" h_file ${h_file})
    file(APPEND ${out_linkdef} "#pragma link C++ defined_in ${h_file};\n")
  endforeach(h_file)
  foreach(h_file IN LISTS ARG_EXTRA_HEADERS)
    #
    # Doubled-up path separators "//" causes errors in rootcling.
    #
    string(REGEX REPLACE "/+" "/" h_file ${h_file})
    file(APPEND ${out_linkdef} "#pragma extra_include \"${h_file}\";\n")
  endforeach(h_file)

  #
  # Append any manually-provided linkdef.h content.
  #
  set(LINKDEF_EXTRACTS)
  string(REPLACE "\\" "\\\\" ARG_LINKDEFS "${ARG_LINKDEFS}")
  foreach(in_linkdef IN LISTS ARG_LINKDEFS)
    if("${in_linkdef}" STREQUAL "")
      continue()
    endif()
    if(NOT IS_ABSOLUTE "${in_linkdef}" AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${in_linkdef}")
      set(in_linkdef "${CMAKE_CURRENT_SOURCE_DIR}/${in_linkdef}")
    endif()
    if(EXISTS "${in_linkdef}")
      file(APPEND ${out_linkdef} "/* Copied from ${in_linkdef}: */\n")
      file(STRINGS ${in_linkdef} in_linkdef NEWLINE_CONSUME)
    else()
      file(APPEND ${out_linkdef} "/* Inlined: */\n")
    endif()
    string(REPLACE "\n" ";" in_linkdef "${in_linkdef}")
    foreach(line ${in_linkdef})
      file(APPEND ${out_linkdef} "${line}\n")
    endforeach()
    list(GET in_linkdef 0 in_linkdef)
    list(APPEND LINKDEFS_EXTRACTS ${in_linkdef})
  endforeach(in_linkdef)
  #
  # Record diagnostics.
  #
  file(APPEND ${out_linkdef} "//\n// Diagnostics.\n//\n")
  foreach(arg IN LISTS simple_args list_args)
    if(arg STREQUAL "LINKDEFS")
      file(APPEND ${out_linkdef} "// ${arg}=\n")
      foreach(in_linkdef IN LISTS LINKDEFS_EXTRACTS)
        file(APPEND ${out_linkdef} "//    ${in_linkdef}...\n")
      endforeach(in_linkdef)
    else()
      file(APPEND ${out_linkdef} "// ${arg}=${ARG_${arg}}\n")
    endif()
  endforeach(arg)
  # ####################################################################################################################
  #
  # Set up common args.
  #
  list(APPEND ARG_GENERATE_OPTIONS "-std=c++${ARG_LANGUAGE_STANDARD}")
  foreach(dir ${ARG_H_DIRS} ${ARG_INCLUDE_DIRS})
    list(APPEND ARG_GENERATE_OPTIONS "-I${dir}")
  endforeach(dir)

  #
  # Set up arguments for rootcling.
  #
  set(cling_args)
  list(APPEND cling_args "-f" ${cpp_file})
  list(APPEND cling_args "-s" ${pkg_simplename})
  list(APPEND cling_args "-rmf" ${rootmap_file} "-rml" ${lib_file})
  foreach(in_pcm IN LISTS ARG_IMPORTS)
    #
    # Create -m options for any imported .pcm files.
    #
    list(APPEND cling_args "-m" "${in_pcm}")
  endforeach(in_pcm)
  list(APPEND cling_args "${ARG_GENERATE_OPTIONS}")

  # run rootcling
  add_custom_command(
    OUTPUT ${cpp_file} ${pcm_file} ${rootmap_file}
    COMMAND ${Cppyy_EXECUTABLE} ${cling_args} ${relative_h_files} ${out_linkdef}
    WORKING_DIRECTORY ${pkg_dir})

  # ##############   #######################
  find_package(LibClang REQUIRED)
  get_filename_component(Cppyygen_EXECUTABLE ${Cppyy_EXECUTABLE} DIRECTORY)
  set(Cppyygen_EXECUTABLE ${Cppyygen_EXECUTABLE}/cppyy-generator${CMAKE_EXECUTABLE_SUFFIX})

  #
  # Set up arguments for cppyy-generator.
  #
  if(${CONDA_ACTIVE})
    set(CLANGDEV_INCLUDE $ENV{CONDA_PREFIX}/lib/clang/${CLANG_VERSION_STRING}/include)
    message(STATUS "adding conda clangdev includes to cppyy-generator options (${CLANGDEV_INCLUDE})")
    list(APPEND ARG_GENERATE_OPTIONS "-I${CLANGDEV_INCLUDE}")
  endif()

  #
  # Run cppyy-generator. First check dependencies.
  #
  set(generator_args)
  foreach(arg IN LISTS ARG_GENERATE_OPTIONS)
    string(REGEX REPLACE "^-" "\\\\-" arg ${arg})
    list(APPEND generator_args ${arg})
  endforeach()

  add_custom_command(
    OUTPUT ${extra_map_file}
    COMMAND ${LibClang_PYTHON_EXECUTABLE} ${Cppyygen_EXECUTABLE} --libclang ${LibClang_LIBRARY} --flags
            "\"${generator_args}\"" ${extra_map_file} ${ARG_H_FILES}
    WORKING_DIRECTORY ${pkg_dir}
    DEPENDS ${ARG_H_FILES}
    WORKING_DIRECTORY ${pkg_dir})

  # ####################################################################################################################

  #
  # Compile/link.
  #
  add_library(${lib_name} SHARED ${cpp_file} ${pcm_file} ${rootmap_file} ${extra_map_file} ${ARG_EXTRA_CODES})
  set_target_properties(${lib_name} PROPERTIES LINKER_LANGUAGE CXX)
  set_property(TARGET ${lib_name} PROPERTY VERSION ${version})
  set_property(TARGET ${lib_name} PROPERTY CXX_STANDARD ${ARG_LANGUAGE_STANDARD})
  set_property(TARGET ${lib_name} PROPERTY LIBRARY_OUTPUT_DIRECTORY ${pkg_dir})

  # if (UNIX)
  #   set_property(TARGET ${lib_name} PROPERTY LINK_WHAT_YOU_USE TRUE)
  # endif()

  include(ExportAllSymbolsWindows)

  string(CONCAT additional_objs_list
    "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/${lib_name}.dir/${pkg}.cpp.obj;"
    "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/${lib_name}.dir/extras/bgfx_extra.cpp.obj;"
    "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/${lib_name}.dir/extras/imgui_extra.cpp.obj;")

  export_all_symbols_windows(
    ${lib_name}
    EXPORT_LINK_LIBRARIES "${ARG_LINK_LIBRARIES};"
    ADDITIONAL_OBJS ${additional_objs_list}
  )
  list(APPEND linker_args "/DEF:${EXPORT_DEF_FILE}")

  target_include_directories(${lib_name} PRIVATE ${Cppyy_INCLUDE_DIRS} ${ARG_INCLUDE_DIRS})
  target_compile_options(${lib_name} PRIVATE ${ARG_COMPILE_OPTIONS})

  target_link_libraries(${lib_name} PUBLIC ${linker_libraries})
  target_link_options(${lib_name} PUBLIC ${linker_args})

  if(WIN32)
    install(TARGETS ${lib_name} RUNTIME DESTINATION ${ARG_TARGET_DIR})
  else()
    install(TARGETS ${lib_name} LIBRARY DESTINATION ${ARG_TARGET_DIR})
  endif()

  install(FILES ${pcm_file} ${rootmap_file} ${extra_map_file} DESTINATION ${ARG_TARGET_DIR})

  if(CMAKE_STRIP)
    if(APPLE)
      add_custom_command(
        TARGET ${lib_name}
        POST_BUILD
        COMMAND ${CMAKE_STRIP} -x $<TARGET_FILE:${lib_name}>)
    else()
      add_custom_command(
        TARGET ${lib_name}
        POST_BUILD
        COMMAND ${CMAKE_STRIP} -s $<TARGET_FILE:${lib_name}>)
    endif()
  endif()

  # For security reasons, delete the build RPATH
  if(APPLE)
    add_custom_command(
      TARGET ${lib_name}
      POST_BUILD
      COMMAND install_name_tool -delete_rpath /tmp/lib $<TARGET_FILE:${lib_name}>)
  endif()

endfunction(cppyy_add_bindings)
