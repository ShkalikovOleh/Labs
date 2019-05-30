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
    void SetUp();
    void TearDown();

    PCViewModel* pcvm;
    MockRepository<PC>* rep;
    MockLog* logger;
};