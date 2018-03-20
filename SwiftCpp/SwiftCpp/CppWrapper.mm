
#import <memory>
#import "CppWrapper.h"
#import "CppInterface.h"

@implementation CppWrapper

- (int)testInt {
    return std::make_shared<CppInterface>()->getInt();
}

@end
