cmake_minimum_required(VERSION 3.14)
project(bald_engine)

#### LIBRARIES

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/vendor/cotire/CMake/)

set(GLM_TEST_ENABLE_CXX_17 ON CACHE BOOL "Enable C++ 17" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared library" FORCE)
set(GLM_TEST_ENABLE OFF CACHE BOOL "Build unit tests" FORCE)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/google/googletest/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/stb/)

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
elseif(APPLE_BUILD)
	add_definitions(-DLINUX)
	add_definitions(-DAPPLE)
elseif(WINDOWS_BUILD)
	add_definitions(-DWINDOWS)
endif()

if(LINUX_BUILD)
	set(DEBUG_COMPILE_FLAGS -fPIC -std=c++17 -fsanitize=leak -pedantic -Wall -Wextra -Wnon-virtual-dtor -Werror -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wnull-dereference -Wdouble-promotion -g)
	set(RELEASE_COMPILE_FLAGS -std=c++17 -Ofast -Werror)
elseif(WINDOWS_BUILD)
	#TODO: Add warning and optimization flags
elseif(APPLE_BUILD)
	set(DEBUG_COMPILE_FLAGS -fPIC -std=c++17 -pedantic -Wall -Wextra -Wnon-virtual-dtor -Werror -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wnull-dereference -Wdouble-promotion -g)
	set(RELEASE_COMPILE_FLAGS -std=c++17 -Ofast -Werror)
endif()

#### END DEFINITIONS/FLAGS

#### CONFIG

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(bald_engine STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/app/application.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/app/layer_stack.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/src/core/controllers/camera_2d_controller.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/src/core/debug/logger/logger.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/debug/logger/log_manager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/debug/ui/imgui_layer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/window.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/events/event_manager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/events/callback/event_handler_interface.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/window.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/rendering/camera_2d.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/rendering/sprite.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/rendering/buffers/vertex_buffer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/rendering/buffers/index_buffer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/rendering/buffers/vertex_array.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/rendering/materials/material.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/rendering/rendering_device/batch_2d.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/rendering/rendering_device/renderer_2d.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/rendering/shaders/shader.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/graphics/rendering/textures/texture.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/input/input_manager.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/src/core/models/timer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/platform/opengl/buffers/opengl_vertex_buffer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/platform/opengl/buffers/opengl_index_buffer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/platform/opengl/buffers/opengl_vertex_array.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/platform/opengl/shaders/opengl_shader.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/platform/opengl/textures/opengl_texture.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/utils/file_manager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/utils/image.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/utils/split_string.cpp )

if (APPLE_BUILD)
    target_link_libraries(bald_engine
            glad
            glfw
            glm
            imgui
            stb
            "-framework Cocoa"
            "-framework OpenGL"
            "-framework IOKit"
            "-framework CoreVideo")
elseif (LINUX_BUILD)
    target_link_libraries(bald_engine glad glfw glm imgui stb GL X11 Xi Xrandr Xxf86vm Xinerama Xcursor rt m pthread dl)
else ()
	target_link_libraries(bald_engine glad glfw glm imgui stb)
endif ()

target_include_directories(bald_engine INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)

if(DEFINE_DEBUG)
	target_compile_options(bald_engine PUBLIC ${DEBUG_COMPILE_FLAGS})
elseif(DEFINE_RELEASE)
	target_compile_options(bald_engine PUBLIC ${RELEASE_COMPILE_FLAGS})
endif()

#### END CONFIG

#### PCH
if(LINUX_BUILD)
	if(DEFINE_DEBUG)
		set_target_properties(bald_engine PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "src/core/pch.h")
		set_target_properties(bald_engine PROPERTIES COMPILE_FLAGS "-fsanitize=leak -pedantic -Wall -Wextra -Wnon-virtual-dtor -Werror -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wnull-dereference -Wdouble-promotion -Wduplicated-cond -Wlogical-op -g")
	elseif(DEFINE_RELEASE)
		set_target_properties(bald_engine PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "src/core/pch.h")
		set_target_properties(bald_engine PROPERTIES COMPILE_FLAGS "-Ofast -Werror")
	endif()
elseif(APPLE_BUILD)
	if(DEFINE_DEBUG)
		set_target_properties(bald_engine PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "src/core/pch.h")
		set_target_properties(bald_engine PROPERTIES COMPILE_FLAGS "-pedantic -Wall -Wextra -Wnon-virtual-dtor -Werror -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wnull-dereference -Wdouble-promotion -g")
	elseif(DEFINE_RELEASE)
		set_target_properties(bald_engine PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "src/core/pch.h")
		set_target_properties(bald_engine PROPERTIES COMPILE_FLAGS "-Ofast -Werror")
	endif()
endif()

#### END PCH

#### TESTING
enable_testing()
file(GLOB TEST_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp src/core/debug/logger/logger.cpp)

add_executable(runUnitTests ${TEST_SRC_FILES})

target_link_libraries(runUnitTests gtest gmock_main)
target_link_libraries(runUnitTests bald_engine)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/tests/test_file_manager.txt test_file_manager.txt COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/shaders/basic.vert res/shaders/basic.vert COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/shaders/basic.frag res/shaders/basic.frag COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/shaders/sprite.vert res/shaders/sprite.vert COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/shaders/sprite.frag res/shaders/sprite.frag COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/fabric.jpg res/textures/fabric.jpg COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/lena.jpg res/textures/lena.jpg COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/checkerboard.jpg res/textures/checkerboard.jpg COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Bricks/BIGBRICKS.png res/textures/pixel_textures/Bricks/BIGBRICKS.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Bricks/BIGBRICKS.png res/textures/pixel_textures/Bricks/BIGBRICKS.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Bricks/CASTLEBRICKS.png res/textures/pixel_textures/Bricks/CASTLEBRICKS.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Bricks/CLAYBRICKS.png res/textures/pixel_textures/Bricks/CLAYBRICKS.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Bricks/DUNGEONBRICKS.png res/textures/pixel_textures/Bricks/DUNGEONBRICKS.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Bricks/DUNGEONCELL.png res/textures/pixel_textures/Bricks/DUNGEONCELL.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Bricks/GOOBRICKS.png res/textures/pixel_textures/Bricks/GOOBRICKS.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Bricks/PORCELAINBRICKS.png res/textures/pixel_textures/Bricks/PORCELAINBRICKS.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Bricks/REDBRICKS.png res/textures/pixel_textures/Bricks/REDBRICKS.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Bricks/ROUNDBRICKS.png res/textures/pixel_textures/Bricks/ROUNDBRICKS.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Bricks/SLIMBRICKS.png res/textures/pixel_textures/Bricks/SLIMBRICKS.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Elements/BIGLEAVES.png res/textures/pixel_textures/Elements/BIGLEAVES.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Elements/LAVA.png res/textures/pixel_textures/Elements/LAVA.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Elements/RAPIDS.png res/textures/pixel_textures/Elements/RAPIDS.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Elements/SAND.png res/textures/pixel_textures/Elements/SAND.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Elements/SANDMARKS.png res/textures/pixel_textures/Elements/SANDMARKS.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Elements/SNOW.png res/textures/pixel_textures/Elements/SNOW.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Elements/TALLGRASS.png res/textures/pixel_textures/Elements/TALLGRASS.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Elements/TINYLEAVES.png res/textures/pixel_textures/Elements/TINYLEAVES.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Elements/WATER.png res/textures/pixel_textures/Elements/WATER.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Industrial/CROSSCUBE.png res/textures/pixel_textures/Industrial/CROSSCUBE.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Industrial/CROSSWALL.png res/textures/pixel_textures/Industrial/CROSSWALL.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Industrial/METALTILE.png res/textures/pixel_textures/Industrial/METALTILE.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Industrial/PIPES.png res/textures/pixel_textures/Industrial/PIPES.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Industrial/STORAGE.png res/textures/pixel_textures/Industrial/STORAGE.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Industrial/SUPPORT.png res/textures/pixel_textures/Industrial/SUPPORT.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Rocks/DIRT.png res/textures/pixel_textures/Rocks/DIRT.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Rocks/FLATSTONES.png res/textures/pixel_textures/Rocks/FLATSTONES.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Rocks/GOLDROCKS.png res/textures/pixel_textures/Rocks/GOLDROCKS.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Rocks/ICEYROCKS.png res/textures/pixel_textures/Rocks/ICEYROCKS.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Rocks/LAVAROCKS.png res/textures/pixel_textures/Rocks/LAVAROCKS.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Rocks/PATHROCKS.png res/textures/pixel_textures/Rocks/PATHROCKS.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/textures/pixel_textures/Rocks/SLIMROCKS.png res/textures/pixel_textures/Rocks/SLIMROCKS.png COPYONLY)


add_test(UnitTests runUnitTests)

#### END-TESTING
