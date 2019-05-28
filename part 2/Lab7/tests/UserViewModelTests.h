#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "MockLog.h"
#include "MockRepository.h"

#include "../srcs/Model/User.h"
#include "../srcs/Model/IRepository.h"
#include "../srcs/ViewModel/UserViewModel.h"

#include <vector>

class UserViewModelTests: public ::testing::Test
{
protected:    
    void SetUp()
    {
        users = new MockRepository<User>();
        logger = new MockLog();
        usvm = new UserViewModel(logger, users);
    }

    void TearDown()
    {
        delete users;
        delete logger;
        delete usvm;
    }

    MockRepository<User>* users;
    MockLog* logger;
    UserViewModel* usvm;
};

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
    ON_CALL(*users, GetByID(testing::_)).WillByDefault(testing::Return(user));
    EXPECT_CALL(*users, UpdateRecord(::testing::_,*user)).WillOnce(testing::Return(true));
    EXPECT_CALL(*logger, Log(::testing::_)).Times(1);
    usvm->UpdateUser(user);
}

TEST_F(UserViewModelTests, DeleteUser)
{
    auto user = new User("user1", 18);
    EXPECT_CALL(*users, DeleteRecord(*user) ).WillOnce(testing::Return(true) );
    EXPECT_CALL(*logger, Log(::testing::_)).Times(1);
    usvm->DeleteUser(user);
}