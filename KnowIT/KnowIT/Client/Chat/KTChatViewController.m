//
//  KTChatViewController.m
//  KnowIT
//
//  Created by Littlebox on 15/01/2017.
//  Copyright © 2017 Little Box. All rights reserved.
//

#import "KTChatViewController.h"
#import "KTConfig.h"
#import "KTChatInputView.h"

@interface KTChatViewController () <UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) KTChatInputView *inputView;

@end

@implementation KTChatViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = VC_BACKGROUNDCOLOR;
    self.title = VC_CHAT_TITLE;
    
    UIBarButtonItem *rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:VC_CHAT_NAVIGATIONBAR_BUTTON_RIGHT style:UIBarButtonItemStylePlain target:self action:@selector(notification)];
    self.navigationItem.rightBarButtonItem = rightBarButtonItem;
    UIBarButtonItem *leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:VC_CHAT_NAVIGATIONBAR_BUTTON_LEFT style:UIBarButtonItemStylePlain target:self action:@selector(userInfo)];
    self.navigationItem.leftBarButtonItem = leftBarButtonItem;
    UIBarButtonItem *backItem = [[UIBarButtonItem alloc] initWithTitle:@"返回" style:UIBarButtonItemStylePlain target:nil action:nil];
    self.navigationItem.backBarButtonItem = backItem;
    
    CGRect inputFrame = CGRectMake(0, self.view.frame.size.height - VC_NAVIGATIONBAR_HEIGHT - STATUSBAR_HEIGHT - VC_CHAT_INPUTVIEW_HEIGHT, self.view.frame.size.width, VC_CHAT_INPUTVIEW_HEIGHT);
    self.inputView = [[KTChatInputView alloc] initWithFrame:inputFrame];
    [self.view addSubview:self.inputView];
    
    CGRect tableViewFrame = CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height - VC_NAVIGATIONBAR_HEIGHT - STATUSBAR_HEIGHT - VC_CHAT_INPUTVIEW_HEIGHT);
    self.tableView = [[UITableView alloc] initWithFrame:tableViewFrame style:UITableViewStylePlain];
    self.tableView.backgroundColor = VC_TABLEVIEW_BACKGROUNDCOLOR;
    self.tableView.contentInset = UIEdgeInsetsZero;
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    self.tableView.scrollIndicatorInsets = self.tableView.contentInset;
    
    [self.view addSubview:self.tableView];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}


- (void)notification {
    NSLog(@"notification");
}

- (void)userInfo {
    NSLog(@"userInfo");
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 30;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return VC_TABLEVIEW_CELL_HEIGHT;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"CELL"];
    
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"CELL"];
    }
    
    cell.textLabel.text = [NSString stringWithFormat:@"知识消息%ld", (long)indexPath.row+1];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    
    NSLog(@"%ld", (long)indexPath.row);
    [tableView deselectRowAtIndexPath:indexPath animated:NO];
}

@end
