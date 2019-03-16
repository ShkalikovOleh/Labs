#include <gtest/gtest.h>
#include "../src/List.h"

TEST(ListTests, ctorWithoutArgs){
    List<double> doubleList = List<double>();
    ASSERT_TRUE(doubleList.begin() == doubleList.end());
    ASSERT_EQ(doubleList.GetSize(), 0);
}