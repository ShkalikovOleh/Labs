#include "UserTests.h"

void UserTests::SetUp()
{
    user = new User("Username", 18);
}
void UserTests::TearDown()
{
	delete user;
}

TEST_F(UserTests, GetName)
{
    ASSERT_EQ(user->GetName(), "Username");
}

TEST_F(UserTests, GetAge)
{
    ASSERT_EQ(user->GetAge(), 18);
}

TEST_F(UserTests, SetName)
{
    auto newName = "newName";
    user->SetName(newName);
    ASSERT_EQ(user->GetName(), newName);
}