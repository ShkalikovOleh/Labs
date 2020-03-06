#include "PCViewModel.h"
#include <exception>

PCViewModel::PCViewModel(ILog* logger, IRepository<PC>* repository):ViewModel(logger)
{
    computers = repository;
}

std::vector<PC> PCViewModel::GetAll() const
{
    return computers->GetAll();
};

PC* const PCViewModel::GetByID(int ID) const
{
    return computers->GetByID(ID);
};

std::vector<PC> PCViewModel::FindByRAM(unsigned int ram) const
{
    auto condition = [ram](PC& pc){return pc.GetRAM() == ram; };
    return computers->GetRecordByCondition(condition);
};

std::vector<PC> PCViewModel::FindByCPU(std::string CPU) const
{
    auto condition = [CPU](PC& pc){return pc.GetCPU() == CPU; };
    return computers->GetRecordByCondition(condition);
};

void PCViewModel::AddPC(std::string cpu, unsigned int ram)
{
    PC pc(cpu, ram);
    if(computers->AddRecord(pc))
    {
        broadcast();
        logger->Log(std::to_string(time(0)) + " - Add PC with ID: " + std::to_string(pc.GetID()));
    }
};

void PCViewModel::UpdatePC(PC* pc)
{
    if(!pc)
        throw std::invalid_argument("pc is null");
    auto lastPc = GetByID(pc->GetID());
    if(computers->UpdateRecord(*lastPc,*pc))
    {
        broadcast();
        logger->Log(std::to_string(time(0)) + " - Update PC with ID: " + std::to_string(pc->GetID()));
    }
};

void PCViewModel::DeletePC(PC* pc)
{
    if(!pc)
        throw std::invalid_argument("pc is null");
    if(computers->DeleteRecord(*pc))
    {
        broadcast();
        logger->Log(std::to_string(time(0)) + " - Delete PC with ID: " + std::to_string(pc->GetID()));
    }
};