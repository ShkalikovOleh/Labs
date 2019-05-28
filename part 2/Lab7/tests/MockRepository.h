#ifndef MOCK_REPOSITORY
#define MOCK_REPOSITORY

#include <gmock/gmock.h>

#include "../srcs/Model/IRepository.h"
#include <vector>

template<class T>
class MockRepository: public IRepository<T>
{
public:
    MOCK_CONST_METHOD0_T(GetCount, unsigned long());
    MOCK_CONST_METHOD0_T(GetAll, std::vector<T>());
    MOCK_CONST_METHOD1_T(GetByID, T* const(int));
    MOCK_CONST_METHOD1_T(GetRecordByCondition, std::vector<T>(std::function<bool(T&)>));
    MOCK_METHOD1_T(AddRecord, bool(T&));
    MOCK_METHOD1_T(DeleteRecord, bool(T&));
    MOCK_METHOD2_T(UpdateRecord, bool(T&, T&));
};

#endif