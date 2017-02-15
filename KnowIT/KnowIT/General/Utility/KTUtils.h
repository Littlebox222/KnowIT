//
//  KTUtils.h
//  KnowIT
//
//  Created by Littlebox on 23/01/2017.
//  Copyright © 2017 Little Box. All rights reserved.
//

@import UIKit;

#import "KTColors.h"
#import "KTConfig.h"
#import "KTMacro.h"

NS_ASSUME_NONNULL_BEGIN

inline static long long adjustTimestampFromServer(long long timestamp) {
    if (timestamp > 140000000000) {
        timestamp /= 1000;
    }
    return timestamp;
}

@interface KTUtils : NSObject

+ (instancetype)sharedUtils;

+ (NSTimeInterval)adjustTimestampFromServer:(long long)timestamp;

+ (UIButton *)navigationBackButton;

@end

static inline UIViewAnimationOptions animationOptionsWithCurve(UIViewAnimationCurve curve) {
    switch (curve) {
        case UIViewAnimationCurveEaseInOut:
            return UIViewAnimationOptionCurveEaseInOut;
        case UIViewAnimationCurveEaseIn:
            return UIViewAnimationOptionCurveEaseIn;
        case UIViewAnimationCurveEaseOut:
            return UIViewAnimationOptionCurveEaseOut;
        case UIViewAnimationCurveLinear:
            return UIViewAnimationOptionCurveLinear;
    }
    
    return curve << 16;
}

NS_ASSUME_NONNULL_END

#import "KTUtils+CGHelper.h"
//#import "KTUtils+IPhone.h"
//#import "KTUtils+File.h"
//#import "KTUtils+Video.h"
//#import "KTUtils+Text.h"
//#import "KTUtils+Application.h"
//#import "KTUtils+Popover.h"
//#import "KTUtils+Audio.h"
//#import "KTUtils+Notification.h"
