#ifndef SCHEDULE_VIEW_MODEL_H
#define SCHEDULE_VIEW_MODEL_H

#include <ctime>
#include <chrono>
#include <tuple>
#include <vector>

#include "ViewModel.h"
#include "../Model/IRepository.h"
#include "../Model/ISchedule.h"
#include "../Model/User.h"
#include "../Model/IDevice.h"
#include "../Log.h"

using minutes = std::chrono::duration<int, std::ratio<60> >;

class ScheduleViewModel: public ViewModel
{
private:
    ISchedule* schedule;
    IRepository<PC>* computers;
public:
    ScheduleViewModel(ILog*, ISchedule*, IRepository<PC>*);
    std::vector<ScheduleItem> GetAll() const;
    ScheduleItem* const GetByID(int) const;
    std::vector<ScheduleItem> FindByDevice(IDevice*) const;
    std::vector<ScheduleItem> FindByTime(Time) const;
    std::vector<ScheduleItem> FindByUser(User*) const;
    std::vector<std::tuple<IDevice*, Time, Time> > FindFreeInPeriod(Time start, Time end, minutes);
    void Add(IDevice*, User*, Time, Time);
    void Update(ScheduleItem*);
    void Delete(ScheduleItem*);
};

#endif