#include "IDGenerator.h"

IDGenerator* IDGenerator::generator = nullptr;

IDGenerator::IDGenerator()
{
    current = 0;
};

IDGenerator::IDGenerator(const IDGenerator& generator){};

int IDGenerator::GetID()
{
    return ++current;
};

IDGenerator&  IDGenerator::GetInstance()
{
    if(!generator)
    {
        generator = new IDGenerator();
    }
    return *generator;
}