//
//  KTViewController.m
//  KnowIT
//
//  Created by Littlebox on 15/01/2017.
//  Copyright © 2017 Little Box. All rights reserved.
//

#import "KTViewController.h"

@interface KTViewController ()

@end

@implementation KTViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)viewWillAppear:(BOOL)animated {
    
    [super viewWillAppear:animated];
    self.navigationController.navigationBar.translucent = NO;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
