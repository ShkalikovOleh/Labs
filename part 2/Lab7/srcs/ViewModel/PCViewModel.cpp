#include "PCViewModel.h"

PCViewModel::PCViewModel(ILog* logger, IRepository<PC>* repository):ViewModel(logger)
{
    computers = repository;
}

PC* const PCViewModel::GetAll() const
{
    return computers->GetAll();
};

PC* const PCViewModel::GetByID(int ID) const
{
    return computers->GetByID(ID);
};

PC* const PCViewModel::FindByRAM(unsigned int ram) const
{
    auto condition = [ram](PC& pc){return pc.GetRAM() == ram; };
    return computers->GetRecordByCondition(condition);
};

PC* const PCViewModel::FindByCPU(std::string CPU) const
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
        throw 0;
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
        throw 0;
    if(computers->DeleteRecord(*pc))
    {
        broadcast();
        logger->Log(std::to_string(time(0)) + " - Delete PC with ID: " + std::to_string(pc->GetID()));
    }
};