
#ifndef LEARNING_IOS_LOCALECONVERTER_H
#define LEARNING_IOS_LOCALECONVERTER_H

#include <unordered_map>

#include "Locale.h"

class LocaleConverter
{
public:
    LocaleConverter();
    Locale convert(std::string localeString) const;

private:
    std::unordered_map<std::string, Locale> localeMap;
};

#endif //LEARNING_IOS_LOCALECONVERTER_H
