#include <gtest/gtest.h>

#include "../src/Queue.h"
#include "../src/CircularQueue.h"
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
    CircularQueue<int, 5> cq;

    void SetUp()
    {        
        for (auto &&i : { 4, 5, 6, 7 })
        {
            aq.push(i);
            dq.push(i);
            llq.push(i);
            cq.push(i);
        }        
    }
};

TEST_F(QueueTests, back)
{
    EXPECT_EQ(7, dq.back());
    EXPECT_EQ(7, aq.back());
    EXPECT_EQ(7, llq.back());
    EXPECT_EQ(7, cq.back());
}

TEST_F(QueueTests, front)
{
    EXPECT_EQ(4, dq.front());
    EXPECT_EQ(4, aq.front());
    EXPECT_EQ(4, llq.front());
    EXPECT_EQ(4, cq.front());
}

TEST_F(QueueTests, pop)
{    
    dq.pop();
    EXPECT_EQ(3, dq.size());
    EXPECT_EQ(5, dq.front());

    aq.pop();
    EXPECT_EQ(3, aq.size());
    EXPECT_EQ(5, aq.front());
 
    llq.pop();
    EXPECT_EQ(3, llq.size());
    EXPECT_EQ(5, llq.front());

    cq.pop();
    EXPECT_EQ(3, cq.size());
    EXPECT_EQ(5, cq.front());
}

TEST_F(QueueTests, push)
{
    Queue<int, std::deque<int>> ndq;
    ndq.push(11);
    EXPECT_EQ(1, ndq.size());
    EXPECT_EQ(11, ndq.back());

    Queue<int, Array<int>> naq;
    naq.push(11);
    EXPECT_EQ(1, naq.size());
    EXPECT_EQ(11, naq.back());

    Queue<int, LinkedList<int>> nllq;
    nllq.push(11);
    EXPECT_EQ(1, nllq.size());
    EXPECT_EQ(11, nllq.back());

    cq.pop();
    cq.push(11);
    cq.push(12);
    EXPECT_EQ(5, cq.size());
    EXPECT_EQ(12, cq.back());
}

TEST(CircularQueue, copyCtor)
{
    CircularQueue<int,4> q = { 4, 5, 6 };
    q.pop();
    q.pop();

    q.push(11);
    q.push(12);
    q.push(13);
    
    CircularQueue<int, 4> copy = q;

    EXPECT_EQ(q.size(), copy.size());
    while(!copy.empty())
    {
        EXPECT_EQ(q.front(), copy.front());
        q.pop();
        copy.pop();
    }
}