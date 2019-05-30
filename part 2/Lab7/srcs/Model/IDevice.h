#ifndef IDEVICE_H
#define IDEVICE_H

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
    friend bool operator==(const PC&, const PC&);
public:
    PC(std::string, unsigned int);
    PC(const PC&);
    std::string GetInfo() const;
    std::string GetCPU() const;
    unsigned int GetRAM() const;
    void SetRAM(unsigned int);
    void SetCPU(std::string);
};

#endif