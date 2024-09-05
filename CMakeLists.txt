cmake_minimum_required(VERSION 3.29)
project(CContainer C)

set(CMAKE_C_STANDARD 11)

add_compile_options(-g3  -Wextra -Wall -Wunused -Wshadow)

include_directories(./includes)

add_library(CContainer
		includes/ccontainer.h
		includes/cstack.h
		includes/cqueue.h
		includes/clist.h
		sources/stack.c
		sources/queue.c
		sources/list.c)

add_executable(Test 
		includes/ccontainer.h
		includes/cstack.h
		includes/cqueue.h
		includes/clist.h
		sources/stack.c
		sources/queue.c
		sources/list.c
		tests/stack_test.c)
