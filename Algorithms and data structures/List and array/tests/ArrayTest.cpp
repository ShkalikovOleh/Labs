#include <gtest/gtest.h>

#include "../src/Array.h"

class ArrayTest: public ::testing::Test, public Array<int>
{
protected:
    void SetUp()
    {
        push_back(66);
        push_back(5);
        push_back(66);
    };    
};

TEST_F(ArrayTest, copyCtorTest)
{
    Array<int> array = { 4, 5, 6 };
    auto copy = array;
    
    EXPECT_EQ(array.size(), copy.size());
    for(int i = 0; i < array.size(); i++)
    {        
        EXPECT_EQ(array[i], copy[i]);
    }
}

TEST_F(ArrayTest, shrinkTest)
{
    int first = _data[0];
    int last = _data[_size - 1];

    shrinkToFit();

    EXPECT_EQ(_size, capacity());    
    EXPECT_EQ(first, _data[0]);
    EXPECT_EQ(last, _data[_size - 1]);
}

TEST_F(ArrayTest, frontTest)
{
    ASSERT_EQ(_data[0], front());
}

TEST_F(ArrayTest, frontThrowIfEmptyTest)
{
    Array<int> test;
    ASSERT_THROW(test.front(), std::length_error);
}

TEST_F(ArrayTest, backTest)
{
    ASSERT_EQ(_data[_size - 1], back());
}

TEST_F(ArrayTest, backThrowIfEmptyTest)
{
    Array<int> test;
    ASSERT_THROW(test.back(), std::length_error);
}

TEST_F(ArrayTest, pushBackTest)
{
    int pr_size = _size;
    
    push_back(4);
    
    EXPECT_EQ(4, _data[_size - 1]);
    EXPECT_EQ(++pr_size, _size);
}

TEST_F(ArrayTest, pushFrontTest)
{
    int pr_size = _size;

    push_front(-1);

    EXPECT_EQ(-1, _data[0]);
    EXPECT_EQ(++pr_size, _size);
}

TEST_F(ArrayTest, popBackTest)
{
    int pr_size = _size;
    int prelast = _data[_size - 2];

    pop_back();

    EXPECT_EQ(--pr_size, _size);
    EXPECT_EQ(prelast, _data[_size - 1]);
}

TEST_F(ArrayTest, popFrontTest)
{
    int pr_size = _size;
    int pastFirst = _data[1];

    pop_front();

    EXPECT_EQ(--pr_size, _size);
    EXPECT_EQ(pastFirst, _data[0]);
}

TEST_F(ArrayTest, insertEndTest)
{
    int prSize = _size;

    insert(cend() - 1, 11);
    EXPECT_EQ(11, _data[_size - 1]);
    EXPECT_EQ(++prSize, _size);
}

TEST_F(ArrayTest, insertMiddleTest)
{
    int prSize = _size;
    int first = _data[0];
    int last = _data[_size - 1];

    insert(cbegin() + 1, 12);

    EXPECT_EQ(12, _data[2]);
    EXPECT_EQ(++prSize, _size);
    EXPECT_EQ(first, _data[0]);
    EXPECT_EQ(last, _data[_size - 1]);
}

TEST_F(ArrayTest, removeByValueTest)
{
    remove(66);

    bool flag = false;
    for(int i = 0; i < _size; i++)
    {
        if(_data[i] == 66)
        {
            flag = true;
            break;
        }            
    }        
    ASSERT_FALSE(flag);
}

TEST_F(ArrayTest, removeByIteratorTest)
{
    int first = _data[0];
    int last = _data[_size - 1];
    int removed = _data[1];
    int prSize = _size;

    remove(cbegin() + 1);

    EXPECT_NE(removed, _data[1]);
    EXPECT_EQ(--prSize, _size);
    EXPECT_EQ(first, _data[0]);
    EXPECT_EQ(last, _data[_size - 1]);
}

TEST_F(ArrayTest, removeByIteratorRangeTest)
{
    int first = _data[0];
    int last = _data[_size - 1];        

    remove(cbegin() + 1, cend() - 2);
    
    EXPECT_EQ(2, _size);
    EXPECT_EQ(first, _data[0]);
    EXPECT_EQ(last, _data[_size - 1]);
}

TEST_F(ArrayTest, indexingTest)
{
    ASSERT_EQ(_data[2], operator[](2));
}

TEST_F(ArrayTest, iterationTest)
{
    int i = 0;
    for(int& value : *this)
    {
        EXPECT_EQ(value, _data[i]);
        i++;
    }
}