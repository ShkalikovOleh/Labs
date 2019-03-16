cmake_minimum_required(VERSION 3.0.0)

project(Lab2.2)

file(GLOB test_srcs test/*.cpp)

add_executable(Lab2.2Tests ${test_srcs})
target_link_libraries(Lab2.2Tests gtest gtest_main pthread)

enable_testing()
add_test(Tests Lab2.2Tests)