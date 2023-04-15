# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/doTaskapp_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/doTaskapp_autogen.dir/ParseCache.txt"
  "doTaskapp_autogen"
  )
endif()
