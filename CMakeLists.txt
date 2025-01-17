cmake_minimum_required(VERSION 3.14)
project(c_algos_structs C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED true)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLGAS}  --coverage -lm")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage -lm ")
set(CMAKE_BUILD_TYPE Debug)

include_directories(include)
include_directories(libs/Unity/src)

file(GLOB_RECURSE SOURCE_FILES src/*.c)
file(GLOB_RECURSE TESTS_FILES tests/*.c)

add_executable(main cmd/main.c ${SOURCE_FILES})
add_executable(bench cmd/bench.c ${SOURCE_FILES})
add_executable(tests ${TESTS_FILES} ${SOURCE_FILES})
add_library(Unity STATIC libs/Unity/src/unity.c)
add_library(CMock STATIC libs/CMock/src/cmock.c)

target_link_libraries(tests m)
target_link_libraries(main m)
target_link_libraries(bench m)
target_link_libraries(tests Unity)
target_link_libraries(tests CMock)

enable_testing()
add_test(NAME tests COMMAND tests)
add_test(NAME mem_check_tests
         COMMAND valgrind --leak-check=full --error-exitcode=1
                 --track-origins=yes ./tests)
