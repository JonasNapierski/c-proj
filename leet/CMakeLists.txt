cmake_minimum_required(VERSION 3.10)
project(leet VERSION 1.0)
add_executable(leet.out main.c
    src/roman2int.c
    src/palindrom.c
    src/csv.c
)
set(CMAKE_BUILD_TYPE Debug)

target_include_directories(leet.out PRIVATE include)


