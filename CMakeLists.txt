cmake_minimum_required(VERSION 3.19)
project(SortAlgorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(SortAlgorithm
        main.cpp
        bubble_sort.cpp
        selection_sort.cpp
        insertion_sort.cpp insertion_sort.h shell_sort.cpp shell_sort.h)