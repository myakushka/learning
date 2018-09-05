
#import <memory>
#import "CppWrapper.h"
#import "CppFacade.h"

@implementation CppWrapper

- (int)getInt {
    return CppFacade::getCppFacadeInstance().getNewWordsCount();
}

- (NSString*)getString {
    const std::string& string = CppFacade::getCppFacadeInstance().getStudySessionBeingWordOriginalString();
    NSString* nsString = [NSString stringWithUTF8String:string.c_str()];
    return nsString;
}


@end
