#include <gtest/gtest.h>
#include "../srcs/Model/IDevice.h"

class PCTests: public ::testing::Test
{
protected:
    void SetUp();
    void TearDown();

    PC* pc;
};