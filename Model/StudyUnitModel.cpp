
#include <memory>
#include "StudyUnitModel.h"

void StudyUnitModel::addStudyUnit(std::shared_ptr<StudyUnit> studyUnit)
{
    studyUnitVector.push_back(studyUnit);
}

std::vector<std::shared_ptr<StudyUnit>> StudyUnitModel::getStudyUnitVector() const
{
    return studyUnitVector;
}
