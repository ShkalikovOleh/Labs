#include "gtest/gtest.h"

#include "UserTests.h"
#include "PCTest.h"
#include "IDGeneratorTests.h"
#include "PCViewModelTests.h"
#include "UserViewModelTests.h"

GTEST_API_ main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}