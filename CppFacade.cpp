
#include <memory>
#include "CppFacade.h"
#include "Word.h"
#include "WordModel.h"
#include "StudySessionModel.h"
#include "LocaleConverter.h"
#include "Config.h"

CppFacade& CppFacade::getCppFacadeInstance()
{
    static CppFacade instance;
    return instance;
}

CppFacade::CppFacade() :
        wordModel(std::make_shared<WordModel>()),
        studySessionModel(std::make_shared<StudySessionModel>(wordModel)),
        localeConvertor(std::make_shared<LocaleConverter>())
{
    auto config = std::make_shared<Config>();
    wordModel->initializeWithConfig(config);
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
    auto studyUnit = std::make_shared<Word>(fromToLocale, originalWord, translateWord);
    wordModel->addWord(studyUnit);
}

int CppFacade::getNewWordsCount() const
{
    return wordModel->getNeededToStudyWordCount();
}
