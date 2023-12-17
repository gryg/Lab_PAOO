cmake_minimum_required(VERSION 3.10)
project(FractalGenerator) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#include directory for header files
include_directories(${CMAKE_SOURCE_DIR}/include)

#include directory for STB library
include_directories(${PROJECT_SOURCE_DIR}/lib/stb)

#add source files to the executable
add_executable(FractalGenerator src/main.cpp src/fractal_generator.cpp src/raii_mutex.cpp)