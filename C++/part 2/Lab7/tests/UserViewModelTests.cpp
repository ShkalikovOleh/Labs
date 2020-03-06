#include "UserViewModelTests.h"

void UserViewModelTests::SetUp()
{
    users = new MockRepository<User>();
    logger = new MockLog();
    usvm = new UserViewModel(logger, users);
}

void UserViewModelTests::TearDown()
{
    delete users;
    delete logger;
    delete usvm;
}

TEST_F(UserViewModelTests, GetAll)
{
    auto list = std::vector<User>{User("user1", 18),User("user2", 16)};
    EXPECT_CALL(*users, GetAll() ).WillOnce(testing::Return(list));
    ASSERT_EQ(usvm->GetAll(),list);
}

TEST_F(UserViewModelTests, GetByID)
{
    auto user = new User("I7-4770", 4096);
    EXPECT_CALL(*users, GetByID(1) ).WillOnce(testing::Return(user) );
    ASSERT_EQ(usvm->GetByID(1), user);
}

TEST_F(UserViewModelTests, FindByName)
{
    auto list = std::vector<User>{User("user", 18)};
    EXPECT_CALL(*users, GetRecordByCondition(::testing::_) ).WillOnce(testing::Return(list) );
    usvm->FindByName("user");
}

TEST_F(UserViewModelTests, FindByAge)
{
    auto list = std::vector<User>{User("user", 18)};
    EXPECT_CALL(*users, GetRecordByCondition(::testing::_) ).WillOnce(testing::Return(list) );
    usvm->FindByAge(18);
}

TEST_F(UserViewModelTests, AddUser)
{
    auto user = new User("user1", 18);
    EXPECT_CALL(*users, AddRecord(*user) ).WillOnce(testing::Return(true) );
    EXPECT_CALL(*logger, Log(::testing::_)).Times(1);
    usvm->AddUser("user1", 18);
}

TEST_F(UserViewModelTests, UpdateUser)
{
    auto user = new User("user1", 18);
    EXPECT_CALL(*users, GetByID(user->GetID())).WillOnce(testing::Return(user) );    
    EXPECT_CALL(*users, UpdateRecord(::testing::_,*user)).WillOnce(testing::Return(true));
    EXPECT_CALL(*logger, Log(::testing::_)).Times(1);
    usvm->UpdateUser(user);
}

TEST_F(UserViewModelTests, UpdateNullUser)
{
    ASSERT_THROW(usvm->UpdateUser(nullptr), std::invalid_argument);
}

TEST_F(UserViewModelTests, DeleteUser)
{
    auto user = new User("user1", 18);    
    EXPECT_CALL(*users, DeleteRecord(*user) ).WillOnce(testing::Return(true) );
    EXPECT_CALL(*logger, Log(::testing::_)).Times(1);
    usvm->DeleteUser(user);
}

TEST_F(UserViewModelTests, DeleteNullUser)
{
    ASSERT_THROW(usvm->DeleteUser(nullptr), std::invalid_argument);
}