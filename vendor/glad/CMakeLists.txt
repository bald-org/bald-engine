cmake_minimum_required(VERSION 3.12)

project(glad)

include_directories(include)

add_library(glad src/glad.c)

install(
        TARGETS glad
        LIBRARY DESTINATION bin
        ARCHIVE DESTINATION bin
)