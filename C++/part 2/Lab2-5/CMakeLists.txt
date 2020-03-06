cmake_minimum_required(VERSION 3.0.0)

project(Lab25)

file(GLOB test_srcs tests/*.cpp)

add_executable(Lab25_Tests ${test_srcs})
target_link_libraries(Lab25_Tests gtest gtest_main pthread)

enable_testing()
add_test(Tests Lab25_Tests)