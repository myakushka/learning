
#ifndef LEARNING_IOS_WORD_H
#define LEARNING_IOS_WORD_H

#include <memory>
#include <string>
#include <chrono>
#include "Locale.h"

class Word
{
public:
    Word(std::pair<Locale, Locale> fromToLocale, std::string original, std::string translate);

    long long id;
    std::pair<Locale, Locale> fromToLocale;
    std::string original;
    std::string translate;
    double studyRating;
    std::chrono::time_point<double> lastStudyTime;
};

#endif //LEARNING_IOS_WORD_H
