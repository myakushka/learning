
#ifndef SWIFTCPP_CPPFACADE_H
#define SWIFTCPP_CPPFACADE_H

#include <string>

class WordModel;
class StudySessionModel;
class LocaleConverter;

class CppFacade
{
public:
    static CppFacade& getCppFacadeInstance();

    CppFacade(CppFacade const&) = delete;
    void operator=(CppFacade const&) = delete;

    void addWord(std::string originalLocale,
                 std::string originalWord,
                 std::string translateLocale,
                 std::string translateWord);
    int getNewWordsCount() const;
    bool isStudySessionActive() const;
    int getStudySessionWordCount() const;
    int getStudySessionBeingWordIndex() const;
    std::string getStudySessionBeingWordOriginalString() const;
    std::string getStudySessionBeingWordTranslateString() const;

    void beingWordStudy();
    void beingWordPass();

private:
    CppFacade();
    std::shared_ptr<WordModel> wordModel;
    std::shared_ptr<StudySessionModel> studySessionModel;
    std::shared_ptr<LocaleConverter> localeConvertor;
};

#endif //SWIFTCPP_CPPFACADE_H
