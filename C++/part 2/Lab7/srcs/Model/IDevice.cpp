#include "IDevice.h"
#include "../IDGenerator.h"

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

PC::PC(std::string cpu, unsigned int ram):IDevice()
{
    CPU = cpu;
    RAM = ram;
}

PC::PC(const PC& pc)
{
    ID = IDGenerator::GetInstance().GetID();
    CPU = pc.CPU;
    RAM = pc.RAM;
}

std::string PC::GetInfo() const
{
    return "PC ID: " + std::to_string(ID) + " CPU: " + CPU + " RAM: " + std::to_string(RAM) + "Mb";
};

std::string PC::GetCPU() const
{
    return CPU;
}

unsigned int PC::GetRAM() const
{
    return RAM;
}

void PC::SetCPU(std::string newCPU)
{
    CPU = newCPU;
}

void PC::SetRAM(unsigned int newRAM)
{
    RAM = newRAM;
}

bool operator==(const PC& pc1, const PC& pc2)
{
    return pc1.CPU == pc2.CPU && pc1.RAM == pc2.RAM;
}