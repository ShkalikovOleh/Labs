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
};

class ISchedule: public IRepository<ScheduleItem>
{    
public:
    virtual std::vector<ScheduleItem> GetRecordByDevice(IDevice*) = 0;
    virtual std::vector<ScheduleItem> GetRecordByUser(User*) = 0;
    virtual std::vector<ScheduleItem> GetRecordByTime(Time) = 0;
};

#endif