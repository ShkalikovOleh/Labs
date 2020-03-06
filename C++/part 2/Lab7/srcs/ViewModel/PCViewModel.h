#ifndef PC_VIEW_MODEL_H
#define PC_VIEW_MODEL_H

#include <string>

#include "ViewModel.h"
#include "../Model/IRepository.h"
#include "../Model/IDevice.h"
#include "../Log.h"

class PCViewModel: public ViewModel
{
private:
    IRepository<PC>* computers;
public:
    std::vector<PC> GetAll() const;
    PC* const GetByID(int) const;
    std::vector<PC> FindByRAM(unsigned int) const;
    std::vector<PC> FindByCPU(std::string) const;
    void AddPC(std::string, unsigned int);
    void UpdatePC(PC*);
    void DeletePC(PC*);
    PCViewModel(ILog*, IRepository<PC>*);
};

#endif