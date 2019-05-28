cmake_minimum_required(VERSION 3.14)

project(glad)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(DEBUG_COMPILE_FLAGS -fsanitize=leak -pedantic -Wall -Wextra -Wnon-virtual-dtor -Werror -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wnull-dereference -Wdouble-promotion -Wduplicated-cond -Wlogical-op -g)
set(RELEASE_COMPILE_FLAGS -Ofast -Werror)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(glad src/glad.c)

if(DEFINE_DEBUG)
    target_compile_options(glad INTERFACE ${DEBUG_COMPILE_FLAGS})
elseif(DEFINE_RELEASE)
    target_compile_options(glad INTERFACE ${RELEASE_COMPILE_FLAGS})
endif()