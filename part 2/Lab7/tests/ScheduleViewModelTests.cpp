#include "ScheduleViewModelTests.h"
#include <chrono>

void ScheduleViewModelTests::SetUp()
{
    computers = new MockRepository<PC>();
    schedule = new MockSchedule();
    logger = new MockLog();
    schvm = new ScheduleViewModel(logger, schedule, computers);
}

void ScheduleViewModelTests::TearDown()
{
    delete computers;
    delete schedule;
    delete logger;
    delete schvm;
}

Time GetTime()
{
    std::tm tm;
    tm.tm_mon = 2;
    tm.tm_year = 2001;
    tm.tm_yday = 28;
    auto tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    return tp;
}

ScheduleItem GenerateSchItem()
{
    IDevice* pc = new PC("I7-4770", 4096);
    auto user = new User("user1", 18);
    auto item = ScheduleItem(pc, GetTime(), GetTime(), user);   
    return item;
}

TEST_F(ScheduleViewModelTests, GetAll)
{
    auto list = std::vector<ScheduleItem>();
    EXPECT_CALL(*schedule, GetAll()).WillOnce(testing::Return(list));
    ASSERT_EQ(schvm->GetAll(),list);
}

TEST_F(ScheduleViewModelTests, GetByID)
{    
    auto item = GenerateSchItem();
    EXPECT_CALL(*schedule, GetByID(1) ).WillOnce(testing::Return(&item));        
    ASSERT_EQ(schvm->GetByID(1), &item);
}

TEST_F(ScheduleViewModelTests, GetByDevice)
{    
    IDevice* pc = new PC("I7-4770", 4096);    
    auto list = std::vector<ScheduleItem>();
    EXPECT_CALL(*schedule, GetRecordByDevice(testing::_)).WillOnce(::testing::Return(list));
    schvm->FindByDevice(pc);
}

TEST_F(ScheduleViewModelTests, GetByUser)
{    
    auto user = new User("user1", 18);
    auto list = std::vector<ScheduleItem>();
    EXPECT_CALL(*schedule, GetRecordByUser(testing::_)).WillOnce(::testing::Return(list));
    schvm->FindByUser(user);
}

TEST_F(ScheduleViewModelTests, GetByTime)
{
    auto list = std::vector<ScheduleItem>();
    EXPECT_CALL(*schedule, GetRecordByTime(testing::_)).WillOnce(::testing::Return(list));
    schvm->FindByTime(GetTime());
}

TEST_F(ScheduleViewModelTests, FindFreeInPeroid)
{
    auto pcs = std::vector<PC>();
    EXPECT_CALL(*computers, GetAll()).WillOnce(::testing::Return(pcs));
    schvm->FindFreeInPeriod(GetTime(), GetTime(), std::chrono::duration_cast<minutes>(std::chrono::minutes(4)));
}

TEST_F(ScheduleViewModelTests, Add)
{
    auto item = GenerateSchItem();
    IDevice* pc = new PC("I7-4770", 4096);
    auto user = new User("user1", 18);

    EXPECT_CALL(*schedule, AddRecord(::testing::_)).WillOnce(testing::Return(true) );
    EXPECT_CALL(*logger, Log(::testing::_)).Times(1);
    schvm->Add(pc, user, GetTime(), GetTime());
}

TEST_F(ScheduleViewModelTests, Update)
{
    auto item = GenerateSchItem();   
    EXPECT_CALL(*schedule, GetByID(item.GetID())).WillOnce(testing::Return(&item) );
    EXPECT_CALL(*schedule, UpdateRecord(::testing::_,item)).WillOnce(testing::Return(true));
    EXPECT_CALL(*logger, Log(::testing::_)).Times(1);
    schvm->Update(&item);
}

TEST_F(ScheduleViewModelTests, UpdateNull)
{
    ASSERT_THROW(schvm->Update(nullptr), std::invalid_argument);
}

TEST_F(ScheduleViewModelTests, Delete)
{
    auto item = GenerateSchItem();   
    EXPECT_CALL(*schedule, DeleteRecord(item)).WillOnce(testing::Return(true));
    EXPECT_CALL(*logger, Log(::testing::_)).Times(1);
    schvm->Delete(&item);
}

TEST_F(ScheduleViewModelTests, DeleteNull)
{
    ASSERT_THROW(schvm->Delete(nullptr), std::invalid_argument);
}