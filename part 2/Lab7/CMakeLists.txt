cmake_minimum_required(VERSION 3.0.0)

project(Lab7)

file(GLOB test_srcs tests/*.cpp)
file(GLOB srcs srcs/**.cpp)

add_library(Lab7 SHARED ${srcs})
add_executable(Lab7_Tests ${test_srcs})
target_link_libraries(Lab7_Tests Lab7 gtest gtest_main pthread)

enable_testing()
add_test(Tests Lab7_Tests)