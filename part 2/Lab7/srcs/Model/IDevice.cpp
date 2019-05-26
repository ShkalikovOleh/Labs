#include "IDevice.h"
#include "IDGenerator.h"

IDevice::IDevice()
{
    ID = IDGenerator::GetInstance().GetID();
}

IDevice::IDevice(const IDevice& device)
{
    ID = IDGenerator::GetInstance().GetID();
}

int IDevice::GetID() const
{
    return ID;
}

std::string PC::GetInfo() const
{
    return "PC ID: " + std::to_string(ID) + " CPU: " + CPU + " RAM: " + std::to_string(RAM) + "Mb";
};