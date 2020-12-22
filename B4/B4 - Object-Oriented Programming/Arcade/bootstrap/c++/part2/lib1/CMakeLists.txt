cmake_minimum_required(VERSION 3.15)
project(lib1)

set(CMAKE_CXX_STANDARD 14)

add_library(lib1 SHARED library.cpp library.h)