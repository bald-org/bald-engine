cmake_minimum_required(VERSION 3.14)
project(sandbox)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(LINUX_BUILD)
    add_definitions(-DLINUX)
endif()

include_directories(${bald_engine_include_dirs})

add_executable(sandbox sandbox.cpp)

target_link_libraries(sandbox PUBLIC bald_engine)
