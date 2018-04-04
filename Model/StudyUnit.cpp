
#include "StudyUnit.h"

static const unsigned needStudyPercentage = 80;
static const unsigned studyStepPercentage = 20;

StudyUnit::StudyUnit(std::pair<Locale, Locale> fromToLocale, std::string original, std::string translate) :
        studyPercentage(0),
        fromToLocale(fromToLocale),
        original(original),
        translate(translate)
{
}

bool StudyUnit::isNeedStudy() const
{
    return studyPercentage > needStudyPercentage;
}

void StudyUnit::study()
{
    studyPercentage += studyStepPercentage;
}
