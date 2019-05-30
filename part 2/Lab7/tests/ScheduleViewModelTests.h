#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "MockRepository.h"
#include "MockLog.h"

#include "../srcs/Model/IRepository.h"
#include "../srcs/Model/IDevice.h"
#include "../srcs/Model/ISchedule.h"
#include "../srcs/ViewModel/ScheduleViewModel.h"
#include "../srcs/Log.h"

#include <vector>


class MockSchedule: public ISchedule
{
public:
    MOCK_CONST_METHOD0(GetCount, unsigned long());
    MOCK_CONST_METHOD0(GetAll, std::vector<ScheduleItem>());
    MOCK_CONST_METHOD1(GetByID, ScheduleItem* const(int));
    MOCK_CONST_METHOD1(GetRecordByCondition, std::vector<ScheduleItem>(std::function<bool(ScheduleItem&)>));
    MOCK_METHOD1(AddRecord, bool(ScheduleItem&));
    MOCK_METHOD1(DeleteRecord, bool(ScheduleItem&));
    MOCK_METHOD2(UpdateRecord, bool(ScheduleItem&, ScheduleItem&));
    MOCK_CONST_METHOD1(GetRecordByDevice, std::vector<ScheduleItem>(IDevice*));
    MOCK_CONST_METHOD1(GetRecordByUser, std::vector<ScheduleItem>(User*));
    MOCK_CONST_METHOD1(GetRecordByTime, std::vector<ScheduleItem>(Time));
};

class ScheduleViewModelTests: public ::testing::Test
{
protected:
    void SetUp();
    void TearDown();

    MockRepository<PC>* computers;
    MockSchedule* schedule;
    MockLog* logger;
    ScheduleViewModel* schvm;
};