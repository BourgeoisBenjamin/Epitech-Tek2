cmake_minimum_required(VERSION 3.16)
project(bootstrap C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

add_executable(bootstrap sources/main.c sources/on_command.c)