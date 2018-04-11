
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
    int count = 0;
    for (auto word : wordVector)
        count += verifyingNeedForStudyWord(word);
    return count;
}

std::vector<std::shared_ptr<Word>> WordModel::getWordPackForStudy() const
{
    std::vector<std::shared_ptr<Word>> wordPack = {};
    for (auto word : wordVector)
    {
        if (verifyingNeedForStudyWord(word))
        {
            wordPack.push_back(word);
        }
    }
    return wordPack;
}

bool WordModel::verifyingNeedForStudyWord(std::shared_ptr<Word> word) const
{
    using namespace std::chrono;
    bool isRatingLow = word->studyRating < config->highLevelRating;
    auto nexStudyTime = word->lastStudyTime + seconds(config->cooldownTime);
    bool isInCooldown = nexStudyTime > time_point_cast<seconds>(system_clock::now());
    return isRatingLow && isInCooldown;
}

void WordModel::studyWord(std::shared_ptr<Word> word)
{
    using namespace std::chrono;
    word->studyRating += config->studyRating;
    word->lastStudyTime = time_point_cast<seconds>(system_clock::now());
}
