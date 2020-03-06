#include "PCViewModelTests.h"

void PCViewModelTests::SetUp()
{        
    rep = new MockRepository<PC>();
    logger = new MockLog();        
    pcvm = new PCViewModel(logger,rep);
}

void PCViewModelTests::TearDown()
{
    delete logger;
    delete rep;
    delete pcvm;
}

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

TEST_F(PCViewModelTests, FindByRAM)
{
    auto list = std::vector<PC>{PC("I7-4770", 4096),PC("I5-3220m", 4096)};
    EXPECT_CALL(*rep, GetRecordByCondition(::testing::_) ).WillOnce(testing::Return(list) );
    pcvm->FindByRAM(4096);
}

TEST_F(PCViewModelTests, FindByCPU)
{
    auto list = std::vector<PC>{PC("I7-4770", 4096)};
    EXPECT_CALL(*rep, GetRecordByCondition(::testing::_) ).WillOnce(testing::Return(list) );
    pcvm->FindByCPU("I7-4770");
}

TEST_F(PCViewModelTests, AddPC)
{
    auto pc = new PC("I7-4770", 4096);
    EXPECT_CALL(*rep, AddRecord(*pc) ).WillOnce(testing::Return(true) );
    EXPECT_CALL(*logger, Log(::testing::_)).Times(1);
    pcvm->AddPC("I7-4770", 4096);
}

TEST_F(PCViewModelTests, UpdatePC)
{
    auto pc = new PC("I7-4770", 4096);   
    EXPECT_CALL(*rep, GetByID(pc->GetID())).WillOnce(testing::Return(pc) ); 
    EXPECT_CALL(*rep, UpdateRecord(::testing::_,*pc)).WillOnce(testing::Return(true));
    EXPECT_CALL(*logger, Log(::testing::_)).Times(1);
    pcvm->UpdatePC(pc);
}

TEST_F(PCViewModelTests, UpdateNullPC)
{
    ASSERT_THROW(pcvm->UpdatePC(nullptr), std::invalid_argument);
}

TEST_F(PCViewModelTests, DeletePC)
{
    auto pc = new PC("I7-4770", 4096);
    EXPECT_CALL(*rep, DeleteRecord(*pc) ).WillOnce(testing::Return(true) );
    EXPECT_CALL(*logger, Log(::testing::_)).Times(1);
    pcvm->DeletePC(pc);
}

TEST_F(PCViewModelTests, DeleteNullPC)
{
    ASSERT_THROW(pcvm->DeletePC(nullptr), std::invalid_argument);
}