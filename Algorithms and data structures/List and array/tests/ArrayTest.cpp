#include <gtest/gtest.h>

#include "../src/Array.h"

class ArrayTest: public ::testing::Test, public Array<int>
{
protected:
    void SetUp()
    {
        push_back(4);
        push_back(5);
        push_back(6);
    };
    void TearDown(){    };
};

TEST_F(ArrayTest, pushBackTest)
{
    push_back(4);
    ASSERT_EQ(4, _data[_size - 1]);
}

TEST_F(ArrayTest, insertEndTest)
{
    insert(cend() - 1, 11);
    ASSERT_EQ(11, _data[_size - 1]);
}

TEST_F(ArrayTest, insertMiddleTest)
{
    insert(cbegin() + 1, 12);
    ASSERT_EQ(12, _data[2]);
}

TEST_F(ArrayTest, indexingTest)
{
    ASSERT_EQ(_data[2], operator[](2));
}

TEST_F(ArrayTest, iterationsTest)
{
    int i = 0;
    for(int& value : *this)
    {
        EXPECT_EQ(value, _data[i]);
        i++;
    }
}