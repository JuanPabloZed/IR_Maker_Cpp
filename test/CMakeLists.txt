cmake_minimum_required(VERSION 3.25)

project(test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set path to FFTW include directory (replace with actual path)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/fftw"
                    "${CMAKE_CURRENT_SOURCE_DIR}")

# Set path to FFTW library directory (replace with actual path)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/fftw)
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/bin")
# Add executable
add_executable(test test.cpp)

# Link FFTW static library (or dynamic if using DLL)
target_link_libraries(test "${CMAKE_CURRENT_SOURCE_DIR}/fftw/libfftw3-3.lib")

# Copie des DLL nécessaires dans le dossier de l'exécutable
add_custom_command(TARGET test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/fftw/libfftw3-3.dll"  # Chemin vers la DLL de FFTW
        "${EXECUTABLE_OUTPUT_PATH}/Debug/libfftw3-3.dll"  # Dossier où se trouve l'exécutable
)

add_custom_command(TARGET test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/fftw/libfftw3-3.dll"  # Chemin vers la DLL de FFTW
        "${EXECUTABLE_OUTPUT_PATH}/Release/libfftw3-3.dll"  # Dossier où se trouve l'exécutable
)