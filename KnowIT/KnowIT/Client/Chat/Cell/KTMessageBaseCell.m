//
//  KTMessageBaseCell.m
//  KnowIT
//
//  Created by Little Box on 17/01/2017.
//  Copyright © 2017 Little Box. All rights reserved.
//

#import "KTMessageBaseCell.h"
#import "UIKit+KTExt.h"
#import "KTColors.h"
#import "KTConfig.h"

#define MENU_FRAME_HEIGHT 50

#define TOUCH_DELAYED_TIME 0.2

UIImage *receiverTextNodeBkg;
UIImage *receiverTextNodeBkgHL;
UIImage *senderTextNodeBkg;
UIImage *senderTextNodeBkgHL;

UIImage *receiverImageNodeBorder;
UIImage *receiverImageNodeMask;
UIImage *senderImageNodeBorder;
UIImage *senderImageNodeMask;

BOOL KTMessageCellIsEditing = NO;

@interface KTMessageBaseCell () <UIGestureRecognizerDelegate>

@property (nonatomic, strong) NSMutableArray <UIMenuItem *> *menuItems;

@end

@implementation KTMessageBaseCell {
    UIView *_tapView;
    UIView *_longPressedView;
}

@synthesize statusButton = _statusButton;
@synthesize indicatorView = _indicatorView;
@synthesize messageModel = _messageModel;
@synthesize selectControl = _selectControl;

+ (void)initialize {
    
    if (!ReceiverTextNodeBkg) {
        
        ReceiverTextNodeBkg = [[UIImage imageNamed:@"receiver_text_node_bkg"] resizableImage];
        ReceiverTextNodeBkgHL = [[UIImage imageNamed:@"receiver_text_node_bkg_hl"] resizableImage];
        SenderTextNodeBkg = [[UIImage imageNamed:@"sender_text_node_bkg"] resizableImage];
        SenderTextNodeBkgHL = [[UIImage imageNamed:@"sender_text_node_bkg_hl"] resizableImage];
        
        ReceiverImageNodeBorder = [[UIImage imageNamed:@"receiver_image_node_border"] resizableImage];
        ReceiverImageNodeMask = [[UIImage imageNamed:@"receiver_image_node_mask"] resizableImage];
        SenderImageNodeBorder = [[UIImage imageNamed:@"sender_image_node_border"] resizableImage];
        SenderImageNodeMask = [[UIImage imageNamed:@"sender_image_node_mask"] resizableImage];
    }
}

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    
    if (self) {
        
        self.contentView.backgroundColor = VC_TABLEVIEW_BACKGROUNDCOLOR;
        
        self.avatarImage = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, AVATAR_WIDTH, AVATAR_HEIGHT)];
        self.avatarImage.contentMode = UIViewContentModeScaleAspectFill;
        [self.contentView addSubview:self.avatarImage];
        
        self.bubbleImage = [[UIImageView alloc] init];
        self.bubbleImage.contentMode = UIViewContentModeScaleToFill;
        [self.contentView addSubview:self.bubbleImage];
        
        [self setupGestureRecognizer];
    }
    
    return self;
}

- (UIActivityIndicatorView *)indicatorView {
    
    if (!_indicatorView) {
        
        _indicatorView = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
        [self.contentView addSubview:_indicatorView];
        _indicatorView.hidden = YES;
        
        [self layoutMessageStatusViews:self.messageModel.isFromMe];
    }
    
    return _indicatorView;
}

- (UIButton *)statusButton {
    
    if (!_statusButton) {
        
        _statusButton = [UIButton buttonWithType:UIButtonTypeCustom];
        [_statusButton setImage:[UIImage imageNamed:@"message_send_fail"] forState:UIControlStateNormal];
        _statusButton.contentMode = UIViewContentModeScaleAspectFit;
        _statusButton.frame = CGRectMake(0, 0, 24, 24);
        [self.contentView addSubview:_statusButton];
        _statusButton.hidden = YES;
        
        [self layoutMessageStatusViews:self.messageModel.isFromMe];
    }
    
    return _statusButton;
}

- (void)prepareForUse:(BOOL)isFromMe {
    
    NSString *iconName = isFromMe ? @"icon_avatar" : @"user";
    self.avatarImage.image = [UIImage imageNamed:iconName];
    
    self.bubbleImage.image = isFromMe ? senderTextNodeBkg : receiverTextNodeBkg;
    self.bubbleImage.highlightedImage = isFromMe ? senderTextNodeBkgHL : receiverTextNodeBkgHL;
    
    _isCellEditing = KTMessageCellIsEditing;
    if (_isCellEditing) {
        self.selectControl.frame = CGRectMake(3, (AVATAR_HEIGHT - EDIT_CONTROL_SIZE)/2, EDIT_CONTROL_SIZE, EDIT_CONTROL_SIZE);
    }
    
    if (isFromMe) {
        self.avatarImage.frame = CGRectMake(SCREEN_WIDTH - CGRectGetWidth(self.avatarImage.frame) - AVATAR_SUPER_LEFT,
                                            AVATAR_SUPER_TOP,
                                            AVATAR_WIDTH, AVATAR_HEIGHT);
        
    }else {
        CGFloat _x = _isCellEditing ? CGRectGetMaxX(self.selectControl.frame) + 3 : AVATAR_SUPER_LEFT;
        self.avatarImage.frame = CGRectMake(_x, AVATAR_SUPER_TOP, AVATAR_WIDTH, AVATAR_HEIGHT);
    }
}

#pragma mark - 布局 -

- (void)layoutMessageStatusViews:(BOOL)isFromMe {
    
    if (isFromMe) {
        _indicatorView.center = CGPointMake(CGRectGetMinX(self.bubbleImage.frame) - CGRectGetWidth(_indicatorView.frame)/2 - ACTIVITY_VIEW_X_OFFSET + BUBBLE_BLANK_LEFT, CGRectGetMidY(self.bubbleImage.frame) + ACTIVITY_VIEW_Y_OFFSET);
        
        _statusButton.center = CGPointMake(CGRectGetMinX(self.bubbleImage.frame) - CGRectGetWidth(_statusButton.frame)/2 - ACTIVITY_VIEW_X_OFFSET + BUBBLE_BLANK_LEFT, CGRectGetMidY(self.bubbleImage.frame) + ACTIVITY_VIEW_Y_OFFSET);
    }
}

#pragma mark - 手势 -

- (void)setupGestureRecognizer {
    
    _tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(contentTapped:)];
    _tap.delegate = self;
    _tap.numberOfTapsRequired = 1;
    _tap.numberOfTouchesRequired = 1;
    [self.contentView addGestureRecognizer:_tap];
    
    _longPressGR = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(contentLongPressed:)];
    _longPressGR.delegate = self;
    _longPressGR.minimumPressDuration = 0.6;
    _longPressGR.allowableMovement = 1000;
    [self.contentView addGestureRecognizer:_longPressGR];
    
}

#pragma mark - 弹出菜单 -



@end
