cmake_minimum_required(VERSION 3.10)
project(leet VERSION 1.0)
add_executable(leet main.c src/test.c)

target_include_directories(leet PRIVATE include)

