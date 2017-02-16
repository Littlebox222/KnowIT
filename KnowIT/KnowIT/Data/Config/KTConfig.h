//
//  KTConfig.h
//  KnowIT
//
//  Created by Littlebox on 15/01/2017.
//  Copyright © 2017 Little Box. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UIColor+KTExt.h"

#pragma mark - 通用字符配置 -
#define VC_CHAT_TITLE @"知然"
#define VC_CHAT_NAVIGATIONBAR_BUTTON_LEFT @"用户"
#define VC_CHAT_NAVIGATIONBAR_BUTTON_RIGHT @"通知"

#pragma mark - 通用颜色配置 -
#define VC_BACKGROUNDCOLOR UIColorRGB(235,235,235)
#define VC_TABLEVIEW_BACKGROUNDCOLOR UIColorRGB(235,235,235)

#pragma mark - 通用UI配置 -

#pragma mark 全局
#define VC_NAVIGATIONBAR_HEIGHT self.navigationController.navigationBar.frame.size.height
#define STATUSBAR_HEIGHT [[UIApplication sharedApplication] statusBarFrame].size.height

#pragma mark 聊天页
#define VC_TABLEVIEW_CELL_HEIGHT 45
#define VC_CHAT_INPUTVIEW_HEIGHT 55

#pragma mark - 时间配置 -
#define DEFAULT_DURATION 0.25       //默认动画时间，单位秒

#pragma mark -
@interface KTConfig : NSObject

@end
