cmake_minimum_required(VERSION 3.14)
project(bald_engine)

#### LIBRARIES

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/vendor/cotire/CMake/)
include(${CMAKE_CURRENT_SOURCE_DIR}/vendor/cotire/CMake/cotire.cmake)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/google/googletest)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/)

set(${PROJECT_NAME}_include_dirs
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/graphics
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/src/input
    ${CMAKE_CURRENT_SOURCE_DIR}/src/math
    ${CMAKE_CURRENT_SOURCE_DIR}/src/events
    ${CMAKE_CURRENT_SOURCE_DIR}/src/events/callback
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm/glm/
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)

include_directories(${bald_engine_include_dirs})

#### END-LIBRARIES

### DEFINITIONS

if(DEFINE_DEBUG)
    add_definitions(-DDEBUG)
elseif(DEFINE_RELEASE)
    add_definitions(-DRELEASE)
endif()

if(TRAVIS_BUILD)
    add_definitions(-DTRAVIS)
endif()

if(LINUX_BUILD)
    add_definitions(-DLINUX)
endif()

#### END DEFINITIONS

#### CONFIG

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(bald_engine
        ${CMAKE_CURRENT_SOURCE_DIR}/src/application.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/file_manager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/split_string.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/input/input_manager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Log.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/graphics/window.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/events/event_manager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/events/callback/handler.cpp)

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

target_include_directories(bald_engine INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)

#### END CONFIG

#### PCH

set_target_properties(bald_engine PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "src/pch.h")
cotire(bald_engine)

#### END-PCH

#### TESTING
enable_testing()
file(GLOB TEST_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp src/Log.cpp)

add_executable(runUnitTests ${TEST_SRC_FILES})
set_target_properties(runUnitTests PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "src/pch.h")
cotire(runUnitTests)

target_link_libraries(runUnitTests gtest gmock_main)
target_link_libraries(runUnitTests bald_engine)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/tests/test_file_manager.txt test_file_manager.txt COPYONLY)

add_test(UnitTests runUnitTests)

#### END-TESTING
