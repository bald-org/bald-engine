cmake_minimum_required(VERSION 3.14)
project(sandbox)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

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

include_directories(${bald_engine_include_dirs})

add_executable(sandbox src/sandbox.cpp)
target_link_libraries(sandbox PUBLIC bald_engine)

#### EXAMPLES

add_executable(application_example examples/application_example.cpp)
add_executable(input_example examples/input_example.cpp)
add_executable(events_example examples/events_example.cpp)

target_link_libraries(application_example PUBLIC bald_engine)
target_link_libraries(input_example PUBLIC bald_engine)
target_link_libraries(events_example PUBLIC bald_engine)

#### END EXAMPLES


