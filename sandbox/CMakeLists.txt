cmake_minimum_required(VERSION 3.14)
project(sandbox)

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

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
if(LINUX_BUILD)
	set(DEBUG_COMPILE_FLAGS -fsanitize=leak -pedantic -Wall -Wextra -Wnon-virtual-dtor -Werror -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wnull-dereference -Wdouble-promotion -Wduplicated-cond -Wlogical-op -g)
	set(RELEASE_COMPILE_FLAGS -Ofast -Werror)
elseif(WINDOWS_BUILD)
#TODO: opt and warning flags
elseif(APPLE_BUILD)
	set(DEBUG_COMPILE_FLAGS -fPIC -std=c++17 -pedantic -Wall -Wextra -Wnon-virtual-dtor -Werror -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wnull-dereference -Wdouble-promotion -g)
	set(RELEASE_COMPILE_FLAGS -std=c++17 -Ofast -Werror)
endif()

#### END DEFINITIONS/FLAGS

#### CONFIG

include_directories(${bald_engine_include_dirs})

add_executable(sandbox src/sandbox.cpp)
target_link_libraries(sandbox PUBLIC bald_engine)

#### END CONFIG

#### EXAMPLES

add_executable(application_example examples/application_example.cpp)
add_executable(input_example examples/input_example.cpp)
add_executable(events_example examples/events_example.cpp)
add_executable(event_time_test examples/event_time_test.cpp)

target_link_libraries(application_example PUBLIC bald_engine)
target_link_libraries(input_example PUBLIC bald_engine)
target_link_libraries(events_example PUBLIC bald_engine)
target_link_libraries(event_time_test PUBLIC bald_engine)

if(DEFINE_DEBUG)
	target_compile_options(application_example PUBLIC ${DEBUG_COMPILE_FLAGS})
	target_compile_options(input_example PUBLIC ${DEBUG_COMPILE_FLAGS})
	target_compile_options(events_example PUBLIC ${DEBUG_COMPILE_FLAGS})
	target_compile_options(event_time_test PUBLIC ${DEBUG_COMPILE_FLAGS})
elseif(DEFINE_RELEASE)
	target_compile_options(application_example PUBLIC ${RELEASE_COMPILE_FLAGS})
	target_compile_options(input_example PUBLIC ${RELEASE_COMPILE_FLAGS})
	target_compile_options(events_example PUBLIC ${RELEASE_COMPILE_FLAGS})
	target_compile_options(event_time_test PUBLIC ${RELEASE_COMPILE_FLAGS})
endif()

#### END EXAMPLES


