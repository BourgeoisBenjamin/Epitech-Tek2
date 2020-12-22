cmake_minimum_required(VERSION 3.15)
project(PSU_2019_malloc C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
include_directories(tests)

add_executable(PSU_2019_malloc
        include/calloc.h
        include/error.h
        include/free.h
        include/malloc.h
        include/realloc.h
        include/reallocarray.h
        src/calloc.c
        src/error.c
        src/free.c
        src/get_mem_block.c
        src/init_malloc_session.c
        src/malloc.c
        src/realloc.c
        src/reallocarray.c
        tests/tests_free.c
        tests/tests_malloc.c
        tests/tests_redirect.c
        tests/unittest.h)
