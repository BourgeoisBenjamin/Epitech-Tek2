cmake_minimum_required(VERSION 3.15)
project(lib1 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
add_library(lib1 SHARED library.c library.h)