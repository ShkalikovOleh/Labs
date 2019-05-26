#ifndef USER_VIEW_MODEL_H
#define USER_VIEW_MODEL_H

#include "../Model/IRepository.h"
#include "../Model/User.h"
#include "../Log.h"
#include "ViewModel.h"

class UserViewModel: ViewModel
{
private:
    IRepository<User>* users;
public:
    User* const GetAll() const;
    User* const GetByID(int) const;
    User* const FindByAge(unsigned int) const;
    User* const FindByName(std::string) const;
    void AddUser(std::string, unsigned int);
    void UpdateUser(User*);
    void DeleteUser(User*);
    UserViewModel(ILog*, IRepository<User>*);
};

#endif