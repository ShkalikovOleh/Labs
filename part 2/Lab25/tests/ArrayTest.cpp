#include <gtest/gtest.h>
#include <iostream>
#include "../src/Array.h"

TEST(ArrayTests, addTest){
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

TEST(FixedArrayTest, Add)
{
    FixedArray<int> farray = FixedArray<int>(10, 20);
    int a = 15, b = 48;
    farray.Add(a);
    farray.Add(b);
    ASSERT_EQ(farray.GetSize(), 1);
}

TEST(FixedArrayTest, OutputTest)
{
    FixedArray<int> farray = FixedArray<int>(10, 20);
    int a = 15, b = 48;
    farray.Add(a);
    farray.Add(b);
    std::ostringstream stream;
    stream << farray;
    std::string output = stream.rdbuf()->str();
    ASSERT_EQ(output, "15\n");
}