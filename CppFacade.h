
#ifndef SWIFTCPP_CPPFACADE_H
#define SWIFTCPP_CPPFACADE_H

#include <string>

class StudyUnitModel;
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

private:
    CppFacade();
    std::shared_ptr<StudyUnitModel> studyUnitModel;
    std::shared_ptr<LocaleConverter> localeConvertor;
};

#endif //SWIFTCPP_CPPFACADE_H
