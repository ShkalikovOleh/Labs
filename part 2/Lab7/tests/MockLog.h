#ifndef MOCK_LOG
#define MOCK_LOG

#include <gmock/gmock.h>
#include "../srcs/Log.h"

#include <string>

class MockLog: public ILog
{
public:
    MOCK_METHOD1(Log, void(std::string));
};

#endif