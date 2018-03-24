
#ifndef SWIFTCPP_CPPINTERFACE_H
#define SWIFTCPP_CPPINTERFACE_H

#import <string>

class CppInterface {
public:
    int getInt() const;
    const std::string& getString() const;
};

#endif //SWIFTCPP_CPPINTERFACE_H
