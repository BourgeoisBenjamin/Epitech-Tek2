cmake_minimum_required(VERSION 3.15)
project(lib3)

set(CMAKE_CXX_STANDARD 14)

add_library(lib3 SHARED library.cpp library.h)