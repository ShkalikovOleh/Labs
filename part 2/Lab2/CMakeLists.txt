cmake_minimum_required(VERSION 3.0.0)

project(Lab2)

file(GLOB test_srcs tests/*.cpp)

add_executable(Lab2_Tests ${test_srcs})
target_link_libraries(Lab2_Tests gtest gtest_main pthread)

enable_testing()
add_test(Tests Lab2_Tests)