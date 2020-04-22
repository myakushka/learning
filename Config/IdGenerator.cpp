
#include "IdGenerator.h"

IdGenerator& IdGenerator::getInstance()
{
    static IdGenerator instance;
    return instance;
}

IdGenerator::IdGenerator() :
        initialized(false),
        lastGeneratedId(0)
{
}

void IdGenerator::initWithoutLastGeneratedId()
{
    initialized = true;
}

void IdGenerator::initWithLastGeneratedId(long long value)
{
    lastGeneratedId = value;
    initWithoutLastGeneratedId();
}

long long IdGenerator::generateId()
{
    if (!initialized) {
        throw "IdGenerator must be initialized before id generation";
    }
    return ++lastGeneratedId;
}

bool IdGenerator::isInitialized() const
{
    return initialized;
}
