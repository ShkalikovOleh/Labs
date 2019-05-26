#ifndef IREPOSITORY_T_H
#define IREPOSITORY_T_H

#include <functional>
#include <vector>

template<typename T>
class IRepository
{
public:
    virtual unsigned long GetCount() const;
    virtual std::vector<T> GetAll() = 0;
    virtual T* const GetByID(int) = 0;
    virtual std::vector<T> GetRecordByCondition(std::function<bool(T&)>) = 0;
    virtual bool AddRecord(T&) = 0;
    virtual bool DeleteRecord(T&) = 0;
    virtual bool UpdateRecord(T&, T&) = 0;
};

#endif