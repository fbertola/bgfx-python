find_program(LIB_EXECUTABLE NAMES lib.exe REQUIRED)

function(export_all_symbols_windows target)
  set(list_args EXPORT_LINK_LIBRARIES ADDITIONAL_OBJS)
  cmake_parse_arguments(ARG "" "" "${list_args}" ${ARGN})
  if(NOT "${ARG_UNPARSED_ARGUMENTS}" STREQUAL "")
    message(SEND_ERROR "Unexpected arguments specified '${ARG_UNPARSED_ARGUMENTS}'")
  endif()

  # ####################################################################################################################
  #
  # Extract all OBJs paths from the given libraries.
  #
  foreach(link_library IN LISTS ARG_EXPORT_LINK_LIBRARIES)
    if(NOT EXISTS ${link_library})
      message(ERROR "${link_library} does not exist")
    endif()
    if(NOT IS_ABSOLUTE ${link_library})
      message(ERROR "${link_library} is not an absolute path")
    endif()

    execute_process(
      COMMAND ${LIB_EXECUTABLE} /nologo /list ${link_library}
      OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/exports.def.tmp
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

    file(STRINGS ${CMAKE_CURRENT_BINARY_DIR}/exports.def.tmp rel_obj_paths)

    foreach(rel_obj_path IN LISTS rel_obj_paths)
      get_filename_component(obj_base_path "${link_library}" DIRECTORY)
      get_filename_component(abs_obj_path "${rel_obj_path}" ABSOLUTE BASE_DIR "${obj_base_path}")
      file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/exports.def.objs "${abs_obj_path}\n")
    endforeach(rel_obj_path)

    message(STATUS "bindir = ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/bgfx_pythonCppyy.dir/extras")
  endforeach(link_library)

  foreach(additional_obj IN LISTS ARG_ADDITIONAL_OBJS)
    file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/exports.def.objs "${additional_obj}\n")
  endforeach(additional_obj)

  add_custom_command(
    TARGET ${target}
    PRE_LINK
    COMMAND ${CMAKE_COMMAND} -E __create_def exports.def exports.def.objs
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

  set(EXPORT_DEF_FILE
      "${CMAKE_CURRENT_BINARY_DIR}/exports.def"
      PARENT_SCOPE)

endfunction(export_all_symbols_windows)
