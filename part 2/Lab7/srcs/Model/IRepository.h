template<typename T>
class IRepository
{
public:
    virtual T* const GetAll() = 0;
    virtual T* const GetRecordByCondition(bool (*condition)(T&)) = 0;
    virtual bool AddRecord(T&) = 0;
    virtual bool DeleteRecord(T&) = 0;
    virtual bool UpdateRecord(T&, T&) = 0;
};