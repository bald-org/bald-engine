cmake_minimum_required(VERSION 3.14)
project(bald_engine)

#### LIBRARIES

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/vendor/cotire/CMake/)

set(GLM_TEST_ENABLE_CXX_17 ON CACHE BOOL "Enable C++ 17" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared library" FORCE)
set(GLM_TEST_ENABLE OFF CACHE BOOL "Build unit tests" FORCE)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/google/googletest/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/)

set(${PROJECT_NAME}_include_dirs
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/app
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/debug
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/debug/ui
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/events
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/events/callback
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/input
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/platform
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/src/math
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm/
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)

include_directories(${bald_engine_include_dirs})

#### END-LIBRARIES

### DEFINITIONS/FLAGS

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

set(DEBUG_COMPILE_FLAGS -fPIC -std=c++17 -fsanitize=leak -pedantic -Wall -Wextra -Wnon-virtual-dtor -Werror -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wnull-dereference -Wdouble-promotion -Wduplicated-cond -Wlogical-op -g)
set(RELEASE_COMPILE_FLAGS -std=c++17 -Ofast -Werror)

#### END DEFINITIONS/FLAGS

#### CONFIG

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(bald_engine
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/app/application.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/app/layer_stack.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/debug/logger.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/debug/ui/imgui_layer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/events/event_manager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/events/callback/event_handler_interface.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/window.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/rendering/buffers/vertex_buffer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/rendering/buffers/index_buffer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/rendering/buffers/vertex_array.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/rendering/shaders/shader.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/input/input_manager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/platform/opengl/buffers/opengl_vertex_buffer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/platform/opengl/buffers/opengl_index_buffer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/platform/opengl/buffers/opengl_vertex_array.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/platform/opengl/shaders/opengl_shader.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/utils/file_manager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/utils/split_string.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/utils/timer.cpp)

if (APPLE)
    target_link_libraries(bald_engine
            glad
            glfw
            glm
            spdlog
            imgui
            "-framework Cocoa"
            "-framework OpenGL"
            "-framework IOKit"
            "-framework CoreVideo")
else ()
    target_link_libraries(bald_engine glad glfw glm spdlog imgui GL X11 Xi Xrandr Xxf86vm Xinerama Xcursor rt m pthread dl)
endif ()

target_include_directories(bald_engine INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)

if(DEFINE_DEBUG)
    target_compile_options(bald_engine PUBLIC ${DEBUG_COMPILE_FLAGS})
elseif(DEFINE_RELEASE)
    target_compile_options(bald_engine PUBLIC ${RELEASE_COMPILE_FLAGS})
endif()

#### END CONFIG

#### PCH

if(DEFINE_DEBUG)
    set_target_properties(bald_engine PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "src/core/pch.h")
    set_target_properties(bald_engine PROPERTIES COMPILE_FLAGS "-fsanitize=leak -pedantic -Wall -Wextra -Wnon-virtual-dtor -Werror -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wnull-dereference -Wdouble-promotion -Wduplicated-cond -Wlogical-op -g")
elseif(DEFINE_RELEASE)
    set_target_properties(bald_engine PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "src/core/pch.h")
    set_target_properties(bald_engine PROPERTIES COMPILE_FLAGS "-Ofast -Werror")
endif()

#### END PCH

#### TESTING
enable_testing()
file(GLOB TEST_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp src/core/debug/logger.cpp)

add_executable(runUnitTests ${TEST_SRC_FILES})

target_link_libraries(runUnitTests gtest gmock_main)
target_link_libraries(runUnitTests bald_engine)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/tests/test_file_manager.txt test_file_manager.txt COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/shaders/basic.vert res/shaders/basic.vert COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/shaders/basic.frag res/shaders/basic.frag COPYONLY)

add_test(UnitTests runUnitTests)

#### END-TESTING