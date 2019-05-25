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