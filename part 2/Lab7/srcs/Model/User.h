#ifndef USER_H
#define USER_H

#include <string>

class User
{
protected:
    int ID;
    std::string name;
    unsigned int age;
    friend bool operator==(const User&, const User&);
public:
    User(std::string, unsigned int);
    User(const User&);
    int GetID() const;
    std::string GetName() const;
    unsigned int GetAge() const;
    void SetName(std::string);
};

#endif