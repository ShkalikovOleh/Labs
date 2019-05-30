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
    void SetUp();
    void TearDown();

    MockRepository<User>* users;
    MockLog* logger;
    UserViewModel* usvm;
};