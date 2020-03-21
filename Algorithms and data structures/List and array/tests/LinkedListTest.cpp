#include <gtest/gtest.h>

#include "../src/LinkedList.h"

class LinkedListTest : public ::testing::Test, public LinkedList<int>
{
protected:
    void SetUp()
    {
        push_back(66);
        push_back(5);
        push_back(66);
    }
};

TEST_F(LinkedListTest, copyCtorTest)
{
    LinkedList<int> list = { 4, 5, 6};
    auto copy = list;
    
    EXPECT_EQ(list.size(), copy.size());
        
    for(auto it = list.cbegin(), jt = copy.cbegin(); it != list.cend(); it++, jt++)
    {
        EXPECT_EQ(*it, *jt);
    }
}

TEST_F(LinkedListTest, frontTest)
{
    ASSERT_EQ(_head->next->data, front());
}

TEST_F(LinkedListTest, frontThrowIfEmptyTest)
{
    LinkedList<int> test;
    ASSERT_THROW(test.front(), std::length_error);
}

TEST_F(LinkedListTest, backTest)
{
    ASSERT_EQ(_tail->previous->data, back());
}

TEST_F(LinkedListTest, backThrowIfEmptyTest)
{
    LinkedList<int> test;
    ASSERT_THROW(test.back(), std::length_error);
}

TEST_F(LinkedListTest, pushBackTest)
{
    int pr_size = _size;
    
    push_back(4);
    
    EXPECT_EQ(4, _tail->previous->data);
    EXPECT_EQ(++pr_size, _size);
}

TEST_F(LinkedListTest, pushFrontTest)
{
    int pr_size = _size;

    push_front(-1);

    EXPECT_EQ(-1, _head->next->data);
    EXPECT_EQ(++pr_size, _size);
}

TEST_F(LinkedListTest, popBackTest)
{
    int pr_size = _size;
    int prelast = _tail->previous->previous->data;

    pop_back();

    EXPECT_EQ(--pr_size, _size);
    EXPECT_EQ(prelast, _tail->previous->data);
}

TEST_F(LinkedListTest, popFrontTest)
{
    int pr_size = _size;
    int pastFirst = _head->next->next->data;

    pop_front();

    EXPECT_EQ(--pr_size, _size);
    EXPECT_EQ(pastFirst, _head->next->data);
}

TEST_F(LinkedListTest, insertEndTest)
{
    int prSize = _size;

    insert(cend() - 1, 11);

    EXPECT_EQ(11, _tail->previous->data);
    EXPECT_EQ(++prSize, _size);
}

TEST_F(LinkedListTest, insertMiddleTest)
{
    int prSize = _size;
    int first = _head->next->data;
    int last = _tail->previous->data;

    insert(cbegin() + 1, 12);

    EXPECT_EQ(12, _head->next->next->next->data);
    EXPECT_EQ(++prSize, _size);
    EXPECT_EQ(first, _head->next->data);
    EXPECT_EQ(last, _tail->previous->data);
}

TEST_F(LinkedListTest, removeByValueTest)
{
    remove(66);

    bool flag = false;
    auto current = _head->next;
    while(current->next)
    {
        if(current->data == 66)
        {
            flag = true;
            break;
        }            
        current = current->next;
    }
    EXPECT_FALSE(flag);
    EXPECT_EQ(1, _size);
}

TEST_F(LinkedListTest, removeByIteratorTest)
{
    int first = _head->next->data;
    int last = _tail->previous->data;
    int removed = _head->next->next->data;
    int prSize = _size;

    remove(cbegin() + 1);

    EXPECT_NE(removed, _head->next->next->data);
    EXPECT_EQ(--prSize, _size);
    EXPECT_EQ(first, _head->next->data);
    EXPECT_EQ(last, _tail->previous->data);
}

TEST_F(LinkedListTest, removeByIteratorRangeTest)
{
    int first = _head->next->data;
    int last = _tail->previous->data;     

    remove(cbegin() + 1, cend() - 2);
    
    EXPECT_EQ(2, _size);
    EXPECT_EQ(first, _head->next->data);
    EXPECT_EQ(last, _tail->previous->data);
}

TEST_F(LinkedListTest, iterationTest)
{    
    auto current = _head->next;
    for(int& value : *this)
    {
        EXPECT_EQ(value, current->data);
        current = current->next;
    }
}