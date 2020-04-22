
#include "Word.h"
#include "IdGenerator.h"

Word::Word(std::pair<Locale, Locale> fromToLocale, std::string original, std::string translate) :
        studyRating(0),
        fromToLocale(fromToLocale),
        original(original),
        translate(translate)
{
    id = IdGenerator::getInstance().generateId();
}
