cmake_minimum_required(VERSION 3.19)
project(SortAlgorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(SortAlgorithm
        main.cpp
        bubble_sort.cpp
        selection_sort.cpp
        insertion_sort.cpp
        shell_sort.cpp
        merge_sort.cpp
        quick_sort.cpp
        heap_sort.cpp
        counting_sort.cpp
        bucket_sort.cpp
        radix_sort.cpp
        )

target_link_libraries(SortAlgorithm pthread)