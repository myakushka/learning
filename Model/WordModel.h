
#ifndef LEARNING_IOS_WORDMODEL_H
#define LEARNING_IOS_WORDMODEL_H

#include <vector>

class Config;
class Word;

class WordModel
{
public:
    void initializeWithConfig(std::shared_ptr<Config> config);
    void addWord(std::shared_ptr<Word> word);
    void studyWord(std::shared_ptr<Word> word);
    int getNeededToStudyWordCount() const;
    std::vector<std::shared_ptr<Word>> getWordPackForStudy() const;

private:
    std::vector<std::shared_ptr<Word>> wordVector;
    std::shared_ptr<Config> config;
    bool verifyingNeedForStudyWord(std::shared_ptr<Word> word) const;

};

#endif //LEARNING_IOS_WORDMODEL_H
