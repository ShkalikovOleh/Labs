#include <gtest/gtest.h>

#include "../src/Stack.h"
#include "../../List and array/src/Array.h"
#include "../../List and array/src/LinkedList.h"

#include <vector>
#include <list>
#include <deque>

class StackTests : public ::testing::Test
{
protected:
    Stack<int, std::deque<int>> dq;
    Stack<int, Array<int>> aq;
    Stack<int, LinkedList<int>> llq;

    void SetUp()
    {        
        for (auto &&i : { 4, 5, 6, 7 })
        {
            aq.push(i);
            dq.push(i);
            llq.push(i);
        }        
    }
};

TEST_F(StackTests, back)
{
    EXPECT_EQ(7, dq.top());
    EXPECT_EQ(7, aq.top());
    EXPECT_EQ(7, llq.top());
}

TEST_F(StackTests, pop)
{
    dq.pop();
    EXPECT_EQ(3, dq.size());
    EXPECT_EQ(6, dq.top());

    aq.pop();
    EXPECT_EQ(3, aq.size());
    EXPECT_EQ(6, aq.top());
    
    llq.pop();
    EXPECT_EQ(3, llq.size());
    EXPECT_EQ(6, llq.top());
}

TEST_F(StackTests, push)
{
    Stack<int, std::deque<int>> dq;
    dq.push(11);
    EXPECT_EQ(1, dq.size());
    EXPECT_EQ(11, dq.top());

    Stack<int, Array<int>> aq;
    aq.push(11);
    EXPECT_EQ(1, aq.size());
    EXPECT_EQ(11, aq.top());

    Stack<int, LinkedList<int>> llq;
    llq.push(11);
    EXPECT_EQ(1, llq.size());
    EXPECT_EQ(11, llq.top());
}
