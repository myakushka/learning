
#include <memory>
#include <set>
#include <chrono>
#include "WordModel.h"
#include "Word.h"
#include "Config.h"

void WordModel::initializeWithConfig(std::shared_ptr<Config> config)
{
    this->config = config;
}

void WordModel::addWord(std::shared_ptr<Word> word)
{
    wordVector.push_back(word);
}

int WordModel::getNeededToStudyWordCount() const
{
    auto count = std::count_if(wordVector.begin(),
                               wordVector.end(),
                               &WordModel::verifyingNeedForStudyWord);
    return static_cast<int>(count);
}

std::vector<std::shared_ptr<Word>> WordModel::getWordPackForStudy() const
{
    std::vector<std::shared_ptr<Word>> wordPack = {};
    std::copy_if(wordVector.begin(),
                 wordVector.end(),
                 wordPack.begin(),
                 &WordModel::verifyingNeedForStudyWord);
    return wordPack;
}

bool WordModel::verifyingNeedForStudyWord(std::shared_ptr<Word> word) const
{
    bool isRatingLow = word->studyRating < config->highLevelRating;
    bool isInCooldown = word->lastStudyTime < std::chrono::system_clock::now() + config->cooldownTime;
    return isRatingLow && isInCooldown;
}

void WordModel::studyWord(std::shared_ptr<Word> word)
{
    word->studyRating += config->studyRating;
    word->lastStudyTime = std::chrono::system_clock::now();
}
