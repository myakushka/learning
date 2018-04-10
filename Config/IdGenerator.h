
#ifndef LEARNING_IOS_IDGENERATOR_H
#define LEARNING_IOS_IDGENERATOR_H

class IdGenerator
{
public:
    IdGenerator(IdGenerator const&) = delete;
    void operator=(IdGenerator const&) = delete;

    static IdGenerator& getInstance();
    void initWithoutLastGeneratedId();
    void initWithLastGeneratedId(long long value);
    bool isInitialized() const;
    long long generateId();

private:
    IdGenerator();
    bool initialized;
    long long lastGeneratedId;
};

#endif //LEARNING_IOS_IDGENERATOR_H
