#include <gtest/gtest.h>
#include "../srcs/Model/IDevice.h"

class PCTests: public ::testing::Test
{
protected:
    void SetUp()
    {
        pc = new PC("I7-4770", 8092);
    }
    
    void TearDown()
    {
        delete pc;
    }

    PC* pc;
};

TEST_F(PCTests, GetName)
{
    ASSERT_EQ(pc->GetCPU(), "I7-4770");
}

TEST_F(PCTests, GetAge)
{
    ASSERT_EQ(pc->GetRAM(), 8092);
}

TEST_F(PCTests, SetCPU)
{
    auto newCPU = "I5-3230m";
    pc->SetCPU(newCPU);
    ASSERT_EQ(pc->GetCPU(), newCPU);
}