#include <gtest/gtest.h>

#include "../src/Queue.h"
#include "../../List and array/src/Array.h"
#include "../../List and array/src/LinkedList.h"

#include <vector>
#include <list>
#include <deque>
 

class QueueTests : public ::testing::Test
{
protected:
    Queue<int, std::deque<int>> dq;
    Queue<int, Array<int>> aq;
    Queue<int, LinkedList<int>> llq;

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

TEST_F(QueueTests, back)
{
    EXPECT_EQ(7, dq.back());
    EXPECT_EQ(7, aq.back());
    EXPECT_EQ(7, llq.back());
}

TEST_F(QueueTests, front)
{
    EXPECT_EQ(4, dq.front());
    EXPECT_EQ(4, aq.front());
    EXPECT_EQ(4, llq.front());
}

TEST_F(QueueTests, pop)
{
    std::cout << "DEQ" << std::endl;
    dq.pop();
    EXPECT_EQ(3, dq.size());
    EXPECT_EQ(5, dq.front());

    aq.pop();
    EXPECT_EQ(3, aq.size());
    EXPECT_EQ(5, aq.front());

    std::cout << "LL" << std::endl;
    llq.pop();
    EXPECT_EQ(3, llq.size());
    EXPECT_EQ(5, llq.front());
}

TEST_F(QueueTests, push)
{
    Queue<int, std::deque<int>> dq;
    dq.push(11);
    EXPECT_EQ(1, dq.size());
    EXPECT_EQ(11, dq.back());

    Queue<int, Array<int>> aq;
    aq.push(11);
    EXPECT_EQ(1, aq.size());
    EXPECT_EQ(11, aq.back());

    Queue<int, LinkedList<int>> llq;
    llq.push(11);
    EXPECT_EQ(1, llq.size());
    EXPECT_EQ(11, llq.back());
}
