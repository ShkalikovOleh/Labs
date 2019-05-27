#ifndef IREPOSITORY_T_H
#define IREPOSITORY_T_H

#include <functional>
#include <vector>

template<typename T>
class IRepository
{
public:
    virtual unsigned long GetCount() const = 0;
    virtual std::vector<T> GetAll() const = 0;
    virtual T* const GetByID(int) const = 0;
    virtual std::vector<T> GetRecordByCondition(std::function<bool(T&)>) const = 0;
    virtual bool AddRecord(T&) = 0;
    virtual bool DeleteRecord(T&) = 0;
    virtual bool UpdateRecord(T&, T&) = 0;
};

#endif