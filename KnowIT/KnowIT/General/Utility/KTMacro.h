//
//  KTMacro.h
//  KnowIT
//
//  Created by Littlebox on 23/01/2017.
//  Copyright © 2017 Little Box. All rights reserved.
//

#ifndef KTMacro_h
#define KTMacro_h

#define WEAK_SELF __weak typeof(self) weakSelf = self
#define STRONG_SELF if (!weakSelf) return; \
                    __strong typeof(weakSelf) strongSelf = weakSelf

#ifndef    weakify
#define weakify( x ) \\
_Pragma("clang diagnostic push") \\
_Pragma("clang diagnostic ignored \\"-Wshadow\\"") \\
autoreleasepool{} __weak __typeof__(x) __weak_##x##__ = x; \\
_Pragma("clang diagnostic pop")
#endif

#ifndef    strongify
#define strongify( x ) \\
_Pragma("clang diagnostic push") \\
_Pragma("clang diagnostic ignored \\"-Wshadow\\"") \\
try{} @finally{} __typeof__(x) x = __weak_##x##__; \\
_Pragma("clang diagnostic pop")
#endif

#define SAFE_SEND_MESSAGE(obj, msg) if ((obj) && [(obj) respondsToSelector:@selector(msg)])

#define RADIANS_TO_DEGREES(radian) ((radian)/M_PI*180.0)
#define DEGREES_TO_RADIANS(degree) ((degree)/180.0*M_PI)

#define TABLE_SECTION_HEIGHT_ZERO 0.000001f

#define NOT_SUPPORT_ALERT [LLUtils showTextHUD:@"暂不支持该功能"];

#define THE_GOLDEN_RATIO  0.618

#define CREATE_SHARED_MANAGER(CLASS_NAME) \
+ (instancetype)sharedManager { \
static CLASS_NAME *_instance; \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
_instance = [[CLASS_NAME alloc] init]; \
}); \
\
return _instance; \
}

#define CREATE_SHARED_INSTANCE(CLASS_NAME) \
+ (instancetype)sharedInstance { \
static CLASS_NAME *_instance; \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
_instance = [[CLASS_NAME alloc] init]; \
}); \
\
return _instance; \
}

#define FONT_OF_SIZE(size) \
+ (UIFont *)fontOfSize##size { \
static UIFont *font; \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
font = [UIFont systemFontOfSize:size]; \
}); \
\
return font; \
}

#endif /* KTMacro_h */
