cmake_minimum_required(VERSION 3.25)

project(test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set path to FFTW include directory (replace with actual path)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/fftw")

# Set path to FFTW library directory (replace with actual path)
link_directories("${CMAKE_CURRENT_SOURCE_DIR}/fftw")

# Add executable
add_executable(test test.cpp)

# Link FFTW static library (or dynamic if using DLL)
target_link_libraries(test "${CMAKE_CURRENT_SOURCE_DIR}/fftw/libfftw3-3.lib")