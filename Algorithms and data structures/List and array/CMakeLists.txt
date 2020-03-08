cmake_minimum_required(VERSION 3.0.0)
set (CMAKE_CXX_STANDARD 17)

project(LinkedList)

file(GLOB_RECURSE srcs tests/*.cpp)

add_executable(LinkedList_Tests ${srcs} ${PROJECT_SOURCE_DIR}/src/Tasks.cpp)
target_link_libraries(LinkedList_Tests gtest gtest_main gmock_main gmock pthread)

enable_testing()
add_test(Tests LinkedList_Tests)