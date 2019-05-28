#include <gtest/gtest.h>
#include "../srcs/IDGenerator.h"

TEST(IDGeneratorTests, GetID)
{
    auto id1 = IDGenerator::GetInstance().GetID();
    auto id2 = IDGenerator::GetInstance().GetID();
    ASSERT_NE(id1, id2);
}