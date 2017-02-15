//
//  KTUtils.m
//  KnowIT
//
//  Created by Littlebox on 23/01/2017.
//  Copyright © 2017 Little Box. All rights reserved.
//

#import "KTUtils.h"

@implementation KTUtils

+ (instancetype)sharedUtils {
    
    static KTUtils *_instance;
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [[KTUtils alloc] init];
    });
    
    return _instance;
}

- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

+ (NSTimeInterval)adjustTimestampFromServer:(long long)timestamp {
    if (timestamp > 140000000000) {
        timestamp /= 1000;
    }
    return timestamp;
}

+ (UIButton *)navigationBackButton {
    
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    [btn setImage:[UIImage imageNamed:@"bar_button_icon_back"] forState:UIControlStateNormal];
    
    [btn setTitle:@"返回" forState:UIControlStateNormal];
    [btn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [btn setTitleColor:[UIColor grayColor] forState:UIControlStateHighlighted];
    
    btn.titleLabel.font = [UIFont systemFontOfSize:15.8];
    btn.backgroundColor = [UIColor clearColor];
    btn.frame = CGRectMake(0, 0, 47, 50);
    
    return btn;
}

@end
