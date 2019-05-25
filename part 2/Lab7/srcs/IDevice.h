#include <string>

class IDevice
{
protected:
    int ID;
public:
    IDevice();
    IDevice(const IDevice&);
    int GetID() const;
    virtual std::string GetInfo() const;
    virtual bool IsReady() const = 0;  
};

class PC: public IDevice
{

};