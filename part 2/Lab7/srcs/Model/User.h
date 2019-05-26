#include <string>

class User
{
protected:
    int ID;
    std::string name;
    unsigned int age;
public:
    User(std::string, unsigned int);
    User(const User&);
    int GetID() const;
    std::string GetName() const;
    unsigned int GetAge() const;
};