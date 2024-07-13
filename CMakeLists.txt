cmake_minimum_required(VERSION 3.14)
project(c_algos_structs)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED true)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)
include_directories(libs/Unity/src)

file(GLOB_RECURSE SOURCE_FILES src/*.c)
file(GLOB_RECURSE TESTS_FILES tests/*.c)

add_executable(tests ${TESTS_FILES} ${SOURCE_FILES})
add_library(Unity STATIC libs/Unity/src/unity.c)

include(FetchContent)

FetchContent_Declare(
  Unity
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity
  GIT_TAG v2.6.0
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/libs/Unity)

FetchContent_MakeAvailable(Unity)

target_link_libraries(tests Unity)

enable_testing()
