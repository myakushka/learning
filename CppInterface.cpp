
#include "CppInterface.h"

std::string string = "stringggg";

int CppInterface::getInt() const {
    return 19;
}

const std::string& CppInterface::getString() const {
    return string;
}
