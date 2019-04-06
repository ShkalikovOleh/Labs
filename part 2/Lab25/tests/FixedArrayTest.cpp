#include <gtest/gtest.h>
#include <iostream>
#include "../src/FixedArray.h"

TEST(FixedArrayTest, AddTest)
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

TEST(FixedArrayTest, CopyCtorTest)
{
    FixedArray<int> farray = FixedArray<int>(10, 20);
    int a = 15, b = 48, c = 12;
    farray.Add(a);
    farray.Add(b);
    farray.Add(c);
    FixedArray<int> cfarray = farray;
    cfarray.Update(++cfarray.begin(), a);
    ASSERT_NE(cfarray[1], farray[1]);
}