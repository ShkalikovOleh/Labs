#ifndef USER_VIEW_MODEL_H
#define USER_VIEW_MODEL_H

#include "../Model/IRepository.h"
#include "../Model/User.h"
#include "../Log.h"
#include "ViewModel.h"

class UserViewModel: public ViewModel
{
private:
    IRepository<User>* users;
public:
    std::vector<User> GetAll() const;
    User* const GetByID(int) const;
    std::vector<User> FindByAge(unsigned int) const;
    std::vector<User> FindByName(std::string) const;
    void AddUser(std::string, unsigned int);
    void UpdateUser(User*);
    void DeleteUser(User*);
    UserViewModel(ILog*, IRepository<User>*);
};

#endif