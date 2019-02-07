cmake_minimum_required(VERSION 3.12)

#### LIBRARIES

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/vendor/cotire/CMake/)
include(${CMAKE_SOURCE_DIR}/vendor/cotire/CMake/cotire.cmake)
add_subdirectory(${CMAKE_SOURCE_DIR}/vendor/google/googletest)
add_subdirectory(${CMAKE_SOURCE_DIR}/vendor/glad/)

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/utils)
include_directories(${CMAKE_SOURCE_DIR}/src/input)
include_directories(${CMAKE_SOURCE_DIR}/src/math)
include_directories(${CMAKE_SOURCE_DIR}/vendor/spdlog/include/)
include_directories(${CMAKE_SOURCE_DIR}/vendor/glfw/include/)
include_directories(${CMAKE_SOURCE_DIR}/vendor/glad/include/)

#### END-LIBRARIES

#### CONFIG/DEFINITIONS

set(CMAKE_CXX_STANDARD 17)

project(bald_engine)

add_compile_options(
        -pedantic -Wall -Wextra
        -Wnon-virtual-dtor -Werror
        -Wold-style-cast -Wcast-align
        -Wunused -Woverloaded-virtual
        -Wpedantic -Wconversion -Wnull-dereference
        -Wdouble-promotion -Wduplicated-cond
        -Wduplicated-branches
        -Wlogical-op -fsanitize=leak)

add_definitions(-D_LINUX)

add_library(bald_engine
        library.cpp library.h
        src/utils/file_manager.cpp
        src/utils/split_string.cpp
        src/input/input_manager.cpp
        src/Log.cpp
        src/math/vec2.cpp
        src/math/vec3.cpp
        src/math/vec4.cpp
        src/math/mat4.cpp)

link_directories(${CMAKE_SOURCE_DIR}/vendor/glad/bin)

if (APPLE)
    target_link_libraries(bald_engine
            glad
            glfw3
            "-framework Cocoa"
            "-framework OpenGL"
            "-framework IOKit"
            "-framework CoreVideo")
else ()
    target_link_libraries(bald_engine glad glfw3 GL X11 Xi Xrandr Xxf86vm Xinerama Xcursor rt m pthread dl)
endif ()

#### END CONFIG/DEFINITIONS

#### EXAMPLES

add_executable(input_example examples/input_example.cpp)
target_link_libraries(input_example bald_engine)

#### END EXAMPLES

#### PCH

set_target_properties(bald_engine PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "src/pch.h")
cotire(bald_engine)

#### END-PCH

#### TESTING
enable_testing()
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/tests/*.cpp src/Log.cpp)

add_executable(runUnitTests ${TEST_SRC_FILES})
set_target_properties(runUnitTests PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "src/pch.h")
cotire(runUnitTests)

target_link_libraries(runUnitTests gtest gmock_main)
target_link_libraries(runUnitTests bald_engine)

configure_file(${PROJECT_SOURCE_DIR}/tests/test_file_manager.txt test_file_manager.txt COPYONLY)

add_test(UnitTests runUnitTests)

#### END-TESTING