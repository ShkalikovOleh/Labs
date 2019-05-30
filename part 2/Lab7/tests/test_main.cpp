#include "gtest/gtest.h"

#include "UserTests.h"
#include "PCTests.h"
#include "PCViewModelTests.h"
#include "UserViewModelTests.h"
#include "ScheduleViewModelTests.h"

GTEST_API_ main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}