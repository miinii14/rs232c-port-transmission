# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appRS232CPortTransmission_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appRS232CPortTransmission_autogen.dir\\ParseCache.txt"
  "appRS232CPortTransmission_autogen"
  )
endif()
