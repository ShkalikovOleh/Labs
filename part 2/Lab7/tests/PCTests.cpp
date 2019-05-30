#include "PCTests.h"

void PCTests::SetUp()
{
    pc = new PC("I7-4770", 8092);
}

void PCTests::TearDown()
{
    delete pc;
}

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