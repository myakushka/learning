
#ifndef LEARNING_IOS_WORDMODEL_H
#define LEARNING_IOS_WORDMODEL_H

#include <vector>

class StudyUnit;

class StudyUnitModel
{
public:
    void addStudyUnit(std::shared_ptr<StudyUnit> studyUnit);
    std::vector<std::shared_ptr<StudyUnit>> getStudyUnitVector() const;

private:
    std::vector<std::shared_ptr<StudyUnit>> studyUnitVector;
};

#endif //LEARNING_IOS_WORDMODEL_H
