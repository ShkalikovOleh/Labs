#ifndef ISCHEDULE_H
#define ISCHEDULE_H

#include "IDevice.h"
#include "User.h"
#include "IRepository.h"
#include "../IDGenerator.h"

#include <ctime>
#include <vector>
#include <chrono>
#include <vector>

using Time =  std::chrono::time_point<std::chrono::system_clock>; 

class ScheduleItem
{
protected:
    int ID;
    IDevice* device;
    User* user;
    Time startScheduleDate;
    Time endScheduleDate;    
public:
    ScheduleItem(IDevice* device, Time begin, Time end, User* user):
        device(device), startScheduleDate(begin), endScheduleDate(end), user(user)
    {ID = IDGenerator::GetInstance().GetID();};
    int GetID() const{return ID;}
    IDevice* const GetDevice() const{return device;}
    User* const GetUser() const{return user;}
    Time GetStartScheduledDate() const{return startScheduleDate;}
    Time GetEndScheduledDate() const{return endScheduleDate;}
    friend bool operator==(const ScheduleItem& item1, const ScheduleItem& item2)
    {
        return item1.startScheduleDate == item2.startScheduleDate && 
                item1.endScheduleDate == item2.endScheduleDate &&                
                *item1.user == *item2.user;
    }
};

class ISchedule: public IRepository<ScheduleItem>
{    
public:
    virtual std::vector<ScheduleItem> GetRecordByDevice(IDevice*) const = 0;
    virtual std::vector<ScheduleItem> GetRecordByUser(User*) const = 0;
    virtual std::vector<ScheduleItem> GetRecordByTime(Time) const = 0;
};

#endif