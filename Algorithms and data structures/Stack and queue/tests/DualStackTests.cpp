#include <gtest/gtest.h>

#include "../src/DualStack.h"

TEST(DualStackTests, push)
{
    DualStack<int, 4> ds;
    ds.first().push(4);
    ds.second().push(5);
    ds.first().push(1);

    EXPECT_EQ(2, ds.first().size());
    EXPECT_EQ(1, ds.first().top());
    EXPECT_EQ(1, ds.second().size());
    EXPECT_EQ(5, ds.second().top());
}

TEST(DualStackTests, pushThrowIfFull)
{
    DualStack<int, 4> ds;
    ds.first().push(4);
    ds.first().push(2);
    ds.second().push(5);
    ds.first().push(1);

    EXPECT_ANY_THROW(ds.second().push(11));
    EXPECT_ANY_THROW(ds.first().push(11));
}

TEST(DualStackTests, pop)
{
    DualStack<int, 4> ds;
    ds.first().push(4);
    ds.second().push(5);
    ds.first().push(1);

    ds.first().pop();
    ds.second().pop();

    EXPECT_EQ(1, ds.first().size());
    EXPECT_EQ(4, ds.first().top());
    EXPECT_EQ(true, ds.second().empty());    
}

TEST(DualStackTests, popThrowIfEmpty)
{
    DualStack<int, 4> ds;

    EXPECT_ANY_THROW(ds.first().pop());
    EXPECT_ANY_THROW(ds.second().pop());
}