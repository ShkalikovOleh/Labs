#include "IDevice.h"
#include "User.h"
#include "Log.h"
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

class ISchedule
{
protected:
    ILog* logger;    
public:
    ISchedule(ILog* logger):logger(logger){};
    virtual const ScheduleItem* GetRecordByDevice(IDevice*) = 0;
    virtual const ScheduleItem* GetRecordByUser(User*) = 0;
    virtual const ScheduleItem* GetRecordByTime(time_t) = 0;
    virtual const ScheduleItem* GetRecordByCondition(bool (*condition)(ScheduleItem&)) = 0;
    virtual const ScheduleItem* GetAll() = 0;
    virtual bool AddRecord(IDevice*, time_t, User*) = 0;
    virtual bool DeleteRecord(ScheduleItem&) = 0;
    virtual bool UpdateRecord(ScheduleItem&, IDevice*, time_t, User*) = 0;
};