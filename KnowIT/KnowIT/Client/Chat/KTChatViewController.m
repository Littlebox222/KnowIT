//
//  KTChatViewController.m
//  KnowIT
//
//  Created by Littlebox on 15/01/2017.
//  Copyright © 2017 Little Box. All rights reserved.
//

#import "KTChatViewController.h"
#import "KTConfig.h"
#import "UIColor+KTExt.h"

@interface KTChatViewController ()

@end

@implementation KTChatViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor randomColor];
    self.title = VC_TITLE_CHAT;
}

- (void)viewWillAppear:(BOOL)animated {
    
    [super viewWillAppear:animated];
    self.navigationController.navigationBar.translucent = NO;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
