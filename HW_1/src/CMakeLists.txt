cmake_minimum_required(VERSION 3.15)

project(MyQueueDemo VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib)

add_executable(CaesarCipher main.cpp)

target_link_libraries(CaesarCipher PUBLIC caesarcipher)

target_include_directories(CaesarCipher PUBLIC
                           "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/lib"
                           )    