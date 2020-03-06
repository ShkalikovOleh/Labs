#include "User.h"
#include "../IDGenerator.h"

User::User(std::string name, unsigned int age)
{
    ID = IDGenerator::GetInstance().GetID();
    this->name = name;
    this->age = age;
}

User::User(const User& user)
{
    ID = IDGenerator::GetInstance().GetID();
    name = user.name;
    age = user.age;
}

int User::GetID() const
{
    return ID;
};

std::string User::GetName() const
{
    return name;
};

unsigned int User::GetAge() const
{
    return age; 
};

void User::SetName(std::string newName)
{
    name = newName;
};

bool operator==(const User& user1, const User& user2)
{
    return user1.name == user2.name && user1.age == user2.age;
};