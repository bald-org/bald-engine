cmake_minimum_required(VERSION 3.12)
project(bald_engine)

set(CMAKE_CXX_STANDARD 17)

#add_library(bald_engine library.cpp library.h src/utils/file_manager.h src/utils/file_manager.cpp)
add_executable(bald_engine main.cpp library.cpp library.h src/utils/file_manager.h src/utils/file_manager.cpp main.cpp)
add_library(bald_engine library.cpp library.h)


set_target_properties(bald_engine PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "src/pch.h")
cotire(bald_engine)