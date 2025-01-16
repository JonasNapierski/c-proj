cmake_minimum_required(VERSION 3.10)
project(hello_world VERSION 0.2)
add_executable(hello_world main.c)

configure_file(hello_world.h.in hello_world.h)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

target_include_directories(hello_world PUBLIC "${CMAKE_BINARY_DIR}")

