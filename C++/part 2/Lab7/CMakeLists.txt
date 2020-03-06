cmake_minimum_required(VERSION 3.0.0)
set (CMAKE_CXX_STANDARD 17)

project(Lab7)

file(GLOB_RECURSE test_srcs tests/*.cpp)
file(GLOB_RECURSE srcs srcs/*.cpp)

message(STATUS ${srcs})

add_library(Lab7 SHARED ${srcs})
add_executable(Lab7_Tests ${test_srcs})
target_link_libraries(Lab7_Tests Lab7 gtest gtest_main gmock_main gmock pthread)

enable_testing()
add_test(Tests Lab7_Tests)