cmake_minimum_required(VERSION 3.12)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/vendor/cotire/CMake/)
include(${CMAKE_SOURCE_DIR}/vendor/cotire/CMake/cotire.cmake)
add_subdirectory(${CMAKE_SOURCE_DIR}/vendor/google/googletest)

project(bald_engine)

add_compile_options(
        -pedantic -Wall -Wextra
        -Wnon-virtual-dtor
        -Wold-style-cast -Wcast-align
        -Wunused -Woverloaded-virtual
        -Wpedantic -Wconversion -Wnull-dereference
        -Wdouble-promotion -Wduplicated-cond
        -Wduplicated-branches
        -Wlogical-op
)
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/utils)
include_directories(${CMAKE_SOURCE_DIR}/vendor/spdlog/include/)

set(CMAKE_CXX_STANDARD 17)

add_library(bald_engine library.cpp library.h)

set_target_properties(bald_engine PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "src/pch.h")
cotire(bald_engine)

enable_testing()
#file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/tests/*.cpp)

message("-- TEST EXECUTALES: " ${TEST_SRC_FILES})
#add_executable(runUnitTests ${TEST_SRC_FILES})

add_executable(runUnitTests
        ${PROJECT_SOURCE_DIR}/tests/test_file_manager.cpp
        ${PROJECT_SOURCE_DIR}/src/Log.cpp
        ${PROJECT_SOURCE_DIR}/src/utils/file_manager.cpp
        )

target_link_libraries(runUnitTests gtest gtest_main)
target_link_libraries(runUnitTests bald_engine)
add_test(UnitTests runUnitTests)

configure_file(${PROJECT_SOURCE_DIR}/tests/test_file_manager.txt test_file_manager.txt COPYONLY)
