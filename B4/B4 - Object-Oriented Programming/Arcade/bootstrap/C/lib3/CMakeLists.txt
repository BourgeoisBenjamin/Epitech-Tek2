cmake_minimum_required(VERSION 3.15)
project(lib3 C)

set(CMAKE_C_STANDARD 99)

add_library(lib3 SHARED library.c library.h)