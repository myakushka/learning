
#ifndef LEARNING_IOS_STUDYUNIT_H
#define LEARNING_IOS_STUDYUNIT_H

#include <memory>
#include <string>
#include "Locale.h"

class StudyUnit
{
public:
    StudyUnit(std::pair<Locale, Locale> fromToLocale, std::string original, std::string translate);

    bool isNeedStudy() const;
    void study();

private:
    std::pair<Locale, Locale> fromToLocale;
    std::string original;
    std::string translate;
    unsigned studyPercentage;
};

#endif //LEARNING_IOS_STUDYUNIT_H
