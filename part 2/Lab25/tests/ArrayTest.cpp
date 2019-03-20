#include <gtest/gtest.h>
#include <iostream>
#include "../src/Array.h"

TEST(ArrayTests, addTest)
{
    Array<int> array = Array<int>(10);
    int a = 5;
    array.Add(a);    
    ASSERT_EQ(array.GetSize(), 1);
}

TEST(ArrayTests, outputTest)
{
    Array<int> array = Array<int>();
    int a = 48, b = 60;
    array.Add(a);
    array.Add(b);
    std::ostringstream stream;
    stream << array;
    std::string output = stream.rdbuf()->str();
    ASSERT_EQ(output, "48\n60\n");
}

TEST(ArrayTests, indexingCorrect)
{
    Array<int> array = Array<int>();
    int a = 48, b = 60;
    array.Add(a);
    array.Add(b);
    ASSERT_EQ(a, array[0]);
    ASSERT_EQ(b, array[1]);
}