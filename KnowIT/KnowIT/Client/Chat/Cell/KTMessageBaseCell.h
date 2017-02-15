//
//  KTMessageBaseCell.h
//  KnowIT
//
//  Created by Little Box on 17/01/2017.
//  Copyright © 2017 Little Box. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KTMessageModel.h"
#import "KTMessageCellActionDelegate.h"

//Avatar与SuperView之间的约束
#define AVATAR_SUPER_LEFT       10
#define AVATAR_SUPER_TOP        0
#define AVATAR_WIDTH            45
#define AVATAR_HEIGHT           45

//Bubble上下左右的留白
#define BUBBLE_BLANK_LEFT       7
#define BUBBLE_BLANK_RIGHT      7
#define BUBBLE_BLANK_TOP        2
#define BUBBLE_BLANK_BOTTOM     11

#define BUBBLE_MASK_ARROW       6.5

//Bubble的约束
#define CONTENT_AVATAR_MARGIN   3
#define CONTENT_SUPER_BOTTOM    20
#define CONTENT_SUPER_TOP       AVATAR_SUPER_TOP
#define ACTIVITY_VIEW_Y_OFFSET  ((BUBBLE_BLANK_TOP - BUBBLE_BLANK_BOTTOM) / 2)
#define ACTIVITY_VIEW_X_OFFSET  5

#define EDIT_CONTROL_SIZE       30

extern BOOL KTMessageCellIsEditing;

extern UIImage *ReceiverTextNodeBkg;
extern UIImage *ReceiverTextNodeBkgHL;
extern UIImage *SenderTextNodeBkg;
extern UIImage *SenderTextNodeBkgHL;

extern UIImage *ReceiverImageNodeBorder;
extern UIImage *ReceiverImageNodeMask;
extern UIImage *SenderImageNodeBorder;
extern UIImage *SenderImageNodeMask;

#define HIDE_STATUS_BUTTON _statusButton.hidden = YES
#define SHOW_STATUS_BUTTON _statusButton.hidden = NO

#define HIDE_INDICATOR_VIEW _indicatorView.hidden = YES; [_indicatorView stopAnimating]
#define SHOW_INDICATOR_VIEW _indicatorView.hidden = NO; [_indicatorView startAnimating]

@interface KTMessageBaseCell : UITableViewCell {
    @protected
    UIActivityIndicatorView *_indicatorView;
    UIButton *_statusButton;
    UIImageView *_selectControl;
    
    UITapGestureRecognizer *_tap;
    UILongPressGestureRecognizer *_longPressGR;
    
    KTMessageModel *_messageModel;
}

@property (nonatomic, strong) KTMessageModel *messageModel;

@property (nonatomic, strong) UIImageView *avatarImage;
@property (nonatomic, strong) UIImageView *bubbleImage;

@property (nonatomic, strong) UIActivityIndicatorView *indicatorView;
@property (nonatomic, strong) UIButton *statusButton;
@property (nonatomic, strong) UIImageView *selectControl;

@property (nonatomic, assign) BOOL isCellSelected;
@property (nonatomic, assign) BOOL isCellEditing;

@property (nonatomic, weak) id<KTMessageCellActionDelegate> delegate;

@property (nonatomic, strong) NSArray<NSString *> *menuItemActionNames;
@property (nonatomic, strong) NSArray<NSString *> *menuItemNames;

- (void)prepareForUse:(BOOL)isFromMe;

- (void)setCellEditingAnimated:(BOOL)animated;

- (void)willDisplayCell;

- (void)didEndDisplayingCell;

- (void)willBeginScrolling;

- (void)didEndScrolling;

#pragma mark - 布局

- (void)updateMessageUploadStatus;

- (void)updateMessageDownloadStatus;

- (void)updateMessageThumbnail;

- (void)layoutMessageContentViews:(BOOL)isFromMe;

- (void)layoutMessageStatusViews:(BOOL)isFromMe;

+ (CGFloat)heightForModel:(KTMessageModel *)model;

- (CGRect)contentFrameInWindow;

#pragma mark - 传递给子类的手势事件

- (UIView *)hitTestForTapGestureRecognizer:(CGPoint)aPoint;

- (UIView *)hitTestForlongPressedGestureRecognizer:(CGPoint)aPoint;

- (void)cancelContentTouch;

- (void)contentTouchBeganInView:(UIView *)aView;

- (void)contentTouchCancelled;

- (void)contentLongPressedBeganInView:(UIView *)aView;

- (void)contentLongPressedEndedInView:(UIView *)aView;

- (void)statusButtonDidTapped;

- (void)avatarImageDidTapped;

- (void)selectControlDidTapped;

- (void)contentEventTappedInView:(UIView *)aView;

#pragma mark - 弹出菜单

- (void)showMenuControllerInRect:(CGRect)rect inView:(UIView *)view;

- (void)copyAction:(id)sender;

- (void)transforAction:(id)sender;

- (void)favoriteAction:(id)sender;

- (void)translateAction:(id)sender;

- (void)deleteAction:(id)sender;

- (void)moreAction:(id)sender;

- (void)addToEmojiAction:(id)sender;

- (void)forwardAction:(id)sender;

- (void)showAlbumAction:(id)sender;

- (void)playAction:(id)sender;

- (void)translateToWordsAction:(id)sender;


#pragma mark - 其他

+ (UIImage *)bubbleImageForModel:(KTMessageModel *)model;

+ (void)setCellEditing:(BOOL)isCellEditing;

@end
