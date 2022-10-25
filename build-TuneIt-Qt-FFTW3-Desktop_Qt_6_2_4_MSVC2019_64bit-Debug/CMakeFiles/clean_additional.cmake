# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TuneIt_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TuneIt_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\rtaudio_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\rtaudio_autogen.dir\\ParseCache.txt"
  "TuneIt_autogen"
  "rtaudio_autogen"
  )
endif()
