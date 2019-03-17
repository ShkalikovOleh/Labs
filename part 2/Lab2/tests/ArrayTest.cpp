#include <gtest/gtest.h>
#include "../src/Array.h"

TEST(ArrayTest, addTest){
    Array<int> array = Array<int>(10);
    int a = 5;
    array.Add(a);
    ASSERT_EQ(array.GetSize(), 1);
}
