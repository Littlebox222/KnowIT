//
//  KTUtils+Popover.h
//  KnowIT
//
//  Created by Littlebox on 20/02/2017.
//  Copyright © 2017 Little Box. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KTUtils.h"
#import "MBProgressHUD.h"

NS_ASSUME_NONNULL_BEGIN

@interface KTUtils (Popover) <MBProgressHUDDelegate>

+ (void)showMessageAlertWithTitle:(nullable NSString *)title message:(NSString *)message;

+ (void)showMessageAlertWithTitle:(nullable NSString *)title message:(NSString *)message actionTitle:(NSString *)actionTitle;

+ (void)showMessageAlertWithTitle:(nullable NSString *)title message:(NSString *)message actionTitle:(NSString *)actionTitle actionHandler:(void (^ __nullable)())actionHandler;

+ (void)showConfirmAlertWithTitle:(nullable NSString *)title message:(NSString *)message yesTitle:(NSString *)yesTitle yesAction:(void (^ __nullable)())yesAction;

+ (void)showConfirmAlertWithTitle:(nullable NSString *)title message:(NSString *)message yesTitle:(NSString *)yesTitle yesAction:(void (^ __nullable)())yesAction cancelTitle:(NSString *)cancelTitle cancelAction:(void (^ __nullable)())cancelAction;

+ (void)showConfirmAlertWithTitle:(NSString *)title message:(NSString *)message firstActionTitle:(NSString *)firstActionTitle firstAction:(void (^ __nullable)())firstAction secondActionTitle:(NSString *)secondActionTitle secondAction:(void (^ __nullable)())secondAction;


+ (void)showTipView:(nonnull UIView<LLTipDelegate> *)view;

+ (void)hideTipView:(nonnull UIView<LLTipDelegate> *)tipView;

+ (UIViewController *)mostFrontViewController;

#pragma mark - HUD -

+ (MBProgressHUD *)showActionSuccessHUD:(NSString *)title inView:(nullable UIView *)view;

+ (MBProgressHUD *)showActionSuccessHUD:(NSString *)title;

+ (MBProgressHUD *)showTextHUD:(NSString *)text inView:(nullable UIView *)view;

+ (MBProgressHUD *)showTextHUD:(NSString *)text;

+ (MBProgressHUD *)showCircleProgressHUDInView:(UIView *)view;

+ (MBProgressHUD *)showActivityIndicatiorHUDWithTitle:(nullable NSString *)title inView:(nullable UIView *)view;

+ (MBProgressHUD *)showActivityIndicatiorHUDWithTitle:(nullable NSString *)title;

+ (void)hideHUD:(MBProgressHUD *)HUD animated:(BOOL)animated;

//阻止屏幕上某个区域响应用户手势
//+ (void)blockUserInteractionInWindowRect:(CGRect)region;

@end

NS_ASSUME_NONNULL_END
