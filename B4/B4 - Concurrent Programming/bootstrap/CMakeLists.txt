cmake_minimum_required(VERSION 3.15)
project(bootstrap)

set(CMAKE_CXX_STANDARD 14)

add_executable(bootstrap ex01/main.cpp ex02/ex02.hpp ex02/ex02.cpp
        ex02/main.cpp ex03/ScopedLock.hpp ex03/ScopedLock.cpp ex03/main.cpp
        ex04/Thread.hpp ex04/Thread.cpp ex04/main.cpp draft/SafeQueue.hpp
        ex05/Queue.cpp ex05/Queue.hpp ex05/SafeQueue.cpp ex05/SafeQueue.hpp)