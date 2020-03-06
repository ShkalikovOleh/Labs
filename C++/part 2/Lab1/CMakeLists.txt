cmake_minimum_required(VERSION 3.0.0)

project(Lab1)

include(GoogleTest)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB srcs src/*.cpp)
file(GLOB test_srcs test/*.cpp)

add_library(Lab1 SHARED ${srcs})

add_executable(Lab1Tests ${test_srcs})
target_link_libraries(Lab1Tests gtest gtest_main pthread Lab1)

enable_testing()
add_test(NAME Tests COMMAND Lab1Tests)
add_dependencies(Lab1Tests Lab1)