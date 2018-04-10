
#ifndef LEARNING_IOS_STUDYSESSIONMODEL_H
#define LEARNING_IOS_STUDYSESSIONMODEL_H

#include <list>

class Word;
class WordModel;

class StudySessionModel
{
public:
    StudySessionModel(std::shared_ptr<WordModel> wordModel);
    void startSession();
    void completeSession();
    void studyWord();
    void passWord();
    std::shared_ptr<Word> getBeingStudiedWord() const;

private:
    std::shared_ptr<WordModel> wordModel;
    bool isSessionActive;
    std::list<std::shared_ptr<Word>> wordList;
    int beingStudiedWordIndex;
};

#endif //LEARNING_IOS_STUDYSESSIONMODEL_H
