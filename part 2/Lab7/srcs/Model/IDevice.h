#include <string>

class IDevice
{
protected:
    int ID;
public:
    IDevice();
    IDevice(const IDevice&);
    int GetID() const;
    virtual std::string GetInfo() const = 0;
};

class PC: public IDevice
{
private:
    std::string CPU;
    unsigned int RAM;
public:
    PC(std::string, unsigned int);
    PC(const PC&);
    std::string GetInfo() const;
};