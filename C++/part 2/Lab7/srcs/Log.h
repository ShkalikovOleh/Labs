#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <string>

class ILog
{
public:
    virtual void Log(std::string) = 0;
};

class StreamLog
{
private:
    std::ostream& stream;
public:
    StreamLog(std::ostream&);    
    void Log(std::string);
};

#endif