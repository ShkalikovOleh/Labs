#include "UserViewModel.h"
#include <exception>

UserViewModel::UserViewModel(ILog* logger, IRepository<User>* repository):ViewModel(logger)
{
    users = repository;
}

std::vector<User> UserViewModel::GetAll() const
{
    return users->GetAll();    
}

User* const UserViewModel::GetByID(int ID) const
{
    return users->GetByID(ID);
}

std::vector<User> UserViewModel::FindByAge(unsigned int age) const
{
    auto condition = [age](User& user){return user.GetAge() == age; };
    return users->GetRecordByCondition(condition);
}

std::vector<User> UserViewModel::FindByName(std::string name) const
{
    auto condition = [name](User& user){return user.GetName() == name; };
    return users->GetRecordByCondition(condition);
}

void UserViewModel::AddUser(std::string name, unsigned int age)
{
    User user(name, age);
    if(users->AddRecord(user))
    {
        broadcast();
        logger->Log(std::to_string(time(0)) + " - Add User with ID: " + std::to_string(user.GetID()));
    }
};

void UserViewModel::UpdateUser(User* user)
{
    if(!user)
        throw std::invalid_argument("user is null");
    auto lastUser = GetByID(user->GetID());
    if(users->UpdateRecord(*lastUser, *user))
    {
        broadcast();
        logger->Log(std::to_string(time(0)) + " - Update User with ID: " + std::to_string(user->GetID()));
    }
};

void UserViewModel::DeleteUser(User* user)
{
    if(!user)
        throw std::invalid_argument("user is null");
    if(users->DeleteRecord(*user))
    {
        broadcast();
        logger->Log(std::to_string(time(0)) + " - Delete User with ID: " + std::to_string(user->GetID()));
    }
};