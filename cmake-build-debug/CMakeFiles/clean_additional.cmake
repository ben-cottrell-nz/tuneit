# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/TuneIt_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/TuneIt_autogen.dir/ParseCache.txt"
  "CMakeFiles/fftw3api_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/fftw3api_autogen.dir/ParseCache.txt"
  "CMakeFiles/fftw3dft_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/fftw3dft_autogen.dir/ParseCache.txt"
  "CMakeFiles/fftw3kernel_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/fftw3kernel_autogen.dir/ParseCache.txt"
  "CMakeFiles/fftw3rdft_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/fftw3rdft_autogen.dir/ParseCache.txt"
  "CMakeFiles/fftw3reodft_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/fftw3reodft_autogen.dir/ParseCache.txt"
  "CMakeFiles/fftw3threads_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/fftw3threads_autogen.dir/ParseCache.txt"
  "CMakeFiles/rtaudio_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/rtaudio_autogen.dir/ParseCache.txt"
  "TuneIt_autogen"
  "fftw3api_autogen"
  "fftw3dft_autogen"
  "fftw3kernel_autogen"
  "fftw3rdft_autogen"
  "fftw3reodft_autogen"
  "fftw3threads_autogen"
  "rtaudio_autogen"
  )
endif()
