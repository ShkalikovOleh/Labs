cmake_minimum_required(VERSION 3.0.0)
set (CMAKE_CXX_STANDARD 17)

project(StackQueue)

file(GLOB_RECURSE srcs tests/*.cpp)

add_executable(SQ_Tests ${srcs})
target_link_libraries(SQ_Tests gtest_main gmock_main gmock pthread)

enable_testing()
add_test(Tests SQ_Tests)