//
//  KTMainVeiwController.m
//  KnowIT
//
//  Created by Littlebox on 15/01/2017.
//  Copyright © 2017 Little Box. All rights reserved.
//

#import "KTMainVeiwController.h"

@interface KTMainVeiwController ()

@property (nonatomic, strong) KTViewController *currentViewController;

@end

@implementation KTMainVeiwController

- (void)viewDidLoad {
    
    KTChatViewController *chatViewController = [[KTChatViewController alloc] init];
    [self setCurrentViewController:chatViewController];
    [self setViewControllers:@[chatViewController] animated:NO];
}

@end
