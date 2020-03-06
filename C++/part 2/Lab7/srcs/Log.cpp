#include "Log.h"

StreamLog::StreamLog(std::ostream& stream):stream(stream){};  

void StreamLog::Log(std::string info)
{
    stream << info << std::endl;
};