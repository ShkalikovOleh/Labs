#include "IDevice.h"
#include "User.h"
#include "Log.h"
#include "IRepository.h"
#include <ctime>
#include <vector>

class ScheduleItem
{
protected:
    IDevice* device;
    User* user;
    time_t scheduleDate;
    ScheduleItem(IDevice* device, time_t scheduleDate, User* user):
        device(device), scheduleDate(scheduleDate), user(user){};
};

class ISchedule: IRepository<ScheduleItem>
{    
public:
    virtual ScheduleItem* const GetRecordByDevice(IDevice*) = 0;
    virtual ScheduleItem* const GetRecordByUser(User*) = 0;
    virtual ScheduleItem* const GetRecordByTime(time_t) = 0;
};