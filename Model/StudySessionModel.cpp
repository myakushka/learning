
#include "StudySessionModel.h"
#include "WordModel.h"
#include "Config.h"

StudySessionModel::StudySessionModel(std::shared_ptr<WordModel> wordModel) :
        wordModel(wordModel),
        isSessionActive(false),
        beingStudiedWordIndex(undefinedIndex)
{
}

void StudySessionModel::startSession()
{
    auto wordVector = wordModel->getWordPackForStudy();
    std::copy(wordVector.begin(), wordVector.end(), std::back_inserter(wordList));
    beingStudiedWordIndex = 0;
    isSessionActive = true;
}

void StudySessionModel::completeSession()
{
    beingStudiedWordIndex = undefinedIndex;
    wordList.clear();
    isSessionActive = false;
}

void StudySessionModel::studyWord()
{
    auto beingStudiedWordIt = std::next(wordList.begin(), beingStudiedWordIndex);
    wordModel->studyWord(*beingStudiedWordIt);
    beingStudiedWordIndex++;
}

void StudySessionModel::passWord()
{
    auto beingStudiedWordIt = std::next(wordList.begin(), beingStudiedWordIndex);
    wordList.splice(wordList.end(), wordList, beingStudiedWordIt);
}

std::shared_ptr<Word> StudySessionModel::getBeingStudiedWord() const
{
    auto beingStudiedWordIt = std::next(wordList.begin(), beingStudiedWordIndex);
    return *beingStudiedWordIt;
}
