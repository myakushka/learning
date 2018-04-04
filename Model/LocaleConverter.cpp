
#include <string>
#include "LocaleConverter.h"

LocaleConverter::LocaleConverter()
{
    localeMap["ru"] = Locale::RU;
    localeMap["eng"] = Locale::ENG;
}

Locale LocaleConverter::convert(std::string localeString) const
{
    if (localeMap.count(localeString))
    {
        return localeMap.at(localeString);
    }
    return ENG;
}
