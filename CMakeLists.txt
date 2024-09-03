cmake_minimum_required(VERSION 3.29)
project(CContainer C)

set(CMAKE_C_STANDARD 11)

add_compile_options(-g3  -Wextra -Wall -Wunused -Wshadow)

include_directories(./includes)

add_library(CContainer
        includes/ccontainer.h
        sources/stack/stack.c
        includes/cstack.h)

add_executable(Test includes/cstack.h
        sources/stack/stack.c
        tests/stack_test.c)
