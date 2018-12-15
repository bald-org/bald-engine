cmake_minimum_required(VERSION 3.12)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/vendor/cotire/CMake/)
include(${CMAKE_SOURCE_DIR}/vendor/cotire/CMake/cotire.cmake)

project(bald_engine)

add_compile_options(
        -pedantic -Wall -Wextra
        -Wnon-virtual-dtor
        -Wold-style-cast -Wcast-align
        -Wunused -Woverloaded-virtual
        -Wpedantic -Wconversion
        -Wsign-conversion -Wnull-dereference
        -Wdouble-promotion -Wduplicated-cond
        -Wduplicated-branches
        -Wlogical-op -Wuseless-cast
)
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/vendor)

set(CMAKE_CXX_STANDARD 17)

add_library(bald_engine library.cpp library.h)

set_target_properties(bald_engine PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "src/pch.h")
cotire(bald_engine)