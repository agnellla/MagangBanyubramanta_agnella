# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_tugasopencv_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED tugasopencv_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(tugasopencv_FOUND FALSE)
  elseif(NOT tugasopencv_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(tugasopencv_FOUND FALSE)
  endif()
  return()
endif()
set(_tugasopencv_CONFIG_INCLUDED TRUE)

# output package information
if(NOT tugasopencv_FIND_QUIETLY)
  message(STATUS "Found tugasopencv: 0.0.0 (${tugasopencv_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'tugasopencv' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${tugasopencv_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(tugasopencv_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${tugasopencv_DIR}/${_extra}")
endforeach()
