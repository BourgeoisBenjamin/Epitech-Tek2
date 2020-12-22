cmake_minimum_required(VERSION 3.15)
project(ex03)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex03 main.cpp)
target_link_libraries(ex03 dl)