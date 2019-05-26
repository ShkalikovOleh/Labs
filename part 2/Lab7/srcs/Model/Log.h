#include <iostream>
#include <string>

class ILog
{
public:
    virtual void Log(std::string) noexcept = 0;
};

class StreamLog
{
private:
    std::ostream& stream;
public:
    StreamLog(std::ostream&);    
    void Log(std::string) noexcept;
};