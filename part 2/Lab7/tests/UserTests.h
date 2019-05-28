#include "gtest/gtest.h"
#include "../srcs/Model/User.h"

class UserTests: public ::testing::Test
{
protected:
    void SetUp();
	void TearDown();

    User* user;
};