cmake_minimum_required(VERSION 3.15)
project(Bootstrap C)

set(CMAKE_C_STANDARD 99)

add_executable(Bootstrap server/main.c server/main2.c client/main.c)