
#include <memory>
#include "CppFacade.h"
#include "StudyUnitModel.h"
#include "StudyUnit.h"
#include "LocaleConverter.h"

CppFacade& CppFacade::getCppFacadeInstance()
{
    static CppFacade instance;
    return instance;
}

CppFacade::CppFacade() :
        studyUnitModel(std::make_shared<StudyUnitModel>()),
        localeConvertor(std::make_shared<LocaleConverter>())
{
}

void CppFacade::addWord(std::string originalLocale,
                        std::string originalWord,
                        std::string translateLocale,
                        std::string translateWord)
{

    std::pair<Locale, Locale> fromToLocale = {
            localeConvertor->convert(originalLocale),
            localeConvertor->convert(translateLocale)
    };
    auto studyUnit = std::make_shared<StudyUnit>(fromToLocale, originalWord, translateWord);
}

int CppFacade::getNewWordsCount() const
{
    return 0;
}
