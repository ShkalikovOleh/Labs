#ifndef IDGENERATOR_H
#define IDGENERATOR_H

#include <atomic>

class IDGenerator
{
private:
    std::atomic<int> current;
    IDGenerator();
    IDGenerator(const IDGenerator&);
    static IDGenerator* generator;
public:
    int GetID();
    static IDGenerator& GetInstance();
};

#endif