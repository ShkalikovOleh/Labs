#include "ScheduleViewModel.h"
#include <vector>

ScheduleViewModel::ScheduleViewModel(ILog* logger, ISchedule* schedule, IRepository<PC>* compRep): ViewModel(logger)
{
    this->schedule = schedule; 
    computers = compRep;
};

std::vector<ScheduleItem> ScheduleViewModel::GetAll() const
{
    return schedule->GetAll();
};

ScheduleItem* const ScheduleViewModel::GetByID(int ID) const
{
    return schedule->GetByID(ID);
};

std::vector<ScheduleItem> ScheduleViewModel::FindByDevice(IDevice* device) const
{
    return schedule->GetRecordByDevice(device);
};

std::vector<ScheduleItem> ScheduleViewModel::FindByTime(Time time) const
{
    return schedule->GetRecordByTime(time);
};

std::vector<ScheduleItem> ScheduleViewModel::FindByUser(User* user) const
{
    return schedule->GetRecordByUser(user);
};

std::vector<std::tuple<IDevice*, Time, Time> > ScheduleViewModel::FindFreeInPeriod(Time start, Time end, minutes duration)
{
    std::vector<std::tuple<IDevice*, Time, Time> > result;
    auto pcs = computers->GetAll();
    for (int i = 0; i < pcs.size(); i++)
    {
        bool isReserve = false;
        auto scheduledItems = FindByDevice(&pcs[i]);
        std::sort(scheduledItems.begin(), scheduledItems.end(), 
            [](ScheduleItem item1, ScheduleItem item2){return item1.GetStartScheduledDate() >= item2.GetEndScheduledDate();});
        for(int j = 1; j < scheduledItems.size(); j++)
        {
            auto endPrev = scheduledItems[i-1].GetEndScheduledDate();
            auto startNext = scheduledItems[i].GetStartScheduledDate();
            auto delta = scheduledItems[i].GetStartScheduledDate() - scheduledItems[i-1].GetEndScheduledDate();
            if(delta > duration)
            {
                result.push_back(std::make_tuple(&pcs[i], endPrev, startNext));
            }
        }
    }
    return result;
};

void ScheduleViewModel::Add(IDevice* device, User* user, Time beginTime, Time endTime)
{
    ScheduleItem item(device, beginTime, endTime, user);
    if(schedule->AddRecord(item))
    {
        broadcast();
        logger->Log(std::to_string(time(0)) + " - Add ScheduledItem with ID: " + std::to_string(item.GetID()));
    }
};

void ScheduleViewModel::Update(ScheduleItem* item)
{
    if(!item)
        throw std::invalid_argument("Item is null");
    auto lastItem = GetByID(item->GetID());
    if(schedule->UpdateRecord(*lastItem, *item))
    {
        broadcast();
        logger->Log(std::to_string(time(0)) + " - Update ScheduledItem with ID: " + std::to_string(item->GetID()));
    }
};

void ScheduleViewModel::Delete(ScheduleItem* item)
{
    if(!item)
        throw std::invalid_argument("Item is null");
    if(schedule->DeleteRecord(*item))
    {
        broadcast();
        logger->Log(std::to_string(time(0)) + " - Delete ScheduledItem with ID: " + std::to_string(item->GetID()));
    }
};