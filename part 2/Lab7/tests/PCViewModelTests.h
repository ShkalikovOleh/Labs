#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "MockLog.h"
#include "MockRepository.h"

#include "../srcs/Model/IDevice.h"
#include "../srcs/Model/IRepository.h"
#include "../srcs/ViewModel/PCViewModel.h"

#include <vector>

class PCViewModelTests: public ::testing::Test
{
protected:
    void SetUp()
    {        
        rep = new MockRepository<PC>();
        logger = new MockLog();        
        pcvm = new PCViewModel(logger,rep);
    }

    void TearDown()
    {
        delete logger;
        delete rep;
        delete pcvm;
    }

    PCViewModel* pcvm;
    MockRepository<PC>* rep;
    MockLog* logger;
};

TEST_F(PCViewModelTests, GetAll)
{   
    auto list = std::vector<PC>{PC("I7-4770", 4096),PC("I5-3220m", 8092)};
    EXPECT_CALL(*rep, GetAll() ).WillOnce(testing::Return(list) );    
    ASSERT_EQ(pcvm->GetAll(), list);
}

TEST_F(PCViewModelTests, GetByID)
{
    auto pc = new PC("I7-4770", 4096);
    EXPECT_CALL(*rep, GetByID(1) ).WillOnce(testing::Return(pc) );        
    ASSERT_EQ(pcvm->GetByID(1), pc);
}

/*TEST_F(PCViewModelTests, FindByRAM)
{
    auto list = std::vector<PC>{PC("I7-4770", 4096),PC("I5-3220m", 4096)};
    EXPECT_CALL(*rep, FindByCondition() ).WillOnce(testing::Return(list) );
    pcvm->FindByRAM(4096);
}*/

TEST_F(PCViewModelTests, AddPC)
{
    auto pc = new PC("I7-4770", 4096);
    EXPECT_CALL(*rep, AddRecord(*pc) ).WillOnce(testing::Return(true) );
    EXPECT_CALL(*logger, Log(::testing::_)).Times(1);
    pcvm->AddPC("I7-4770", 4096);
}

TEST_F(PCViewModelTests, UpdatePC)
{
    auto pc1 = new PC("I7-4770", 4096);    
    EXPECT_CALL(*rep, UpdateRecord(::testing::_,*pc1)).WillOnce(testing::Return(true));
    EXPECT_CALL(*logger, Log(::testing::_)).Times(1);
    pcvm->UpdatePC(pc1);
}

TEST_F(PCViewModelTests, DeletePC)
{
    auto pc = new PC("I7-4770", 4096);
    EXPECT_CALL(*rep, DeleteRecord(*pc) ).WillOnce(testing::Return(true) );
    EXPECT_CALL(*logger, Log(::testing::_)).Times(1);
    pcvm->DeletePC(pc);
}