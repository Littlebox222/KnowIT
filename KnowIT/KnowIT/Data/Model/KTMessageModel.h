//
//  KTMessageModel.h
//  KnowIT
//
//  Created by Little Box on 17/01/2017.
//  Copyright © 2017 Little Box. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "KTType.h"
#import "KTError.h"

typedef NS_ENUM(NSInteger, KTMessageModelUpdateReason) {
    kKTMessageModelUpdateReasonUploadComplete, //消息上传成功
    kKTMessageModelUpdateReasonAttachmentDownloadComplete, //消息附件下载成功
    kKTMessageModelUpdateReasonThumbnailDownloadComplete,  //消息缩略图下载成功
    kKTMessageModelUpdateReasonReGeocodeComplete,          //地理名称解析完毕
};

@interface KTMessageModel : NSObject

//标识
@property (nonatomic, copy, readonly) NSString *messageId;
@property (nonatomic, copy, readonly) NSString *conversationId;

//来源
@property (nonatomic, copy) NSString *from;
@property (nonatomic, copy) NSString *to;
@property (nonatomic, getter=isFromMe) BOOL fromMe;

//内容
@property (nonatomic, readonly) KTMessageBodyType messageBodyType;
@property (nonatomic) NSTimeInterval timestamp;
@property (nonatomic) NSString *text;
@property (nonatomic) NSMutableAttributedString *attributedText;
@property (nonatomic) NSDictionary *ext;

@property (nonatomic) NSInteger gifShowIndex;
@property (nonatomic, weak) UIImage *thumbnailImage;
@property (nonatomic) CGSize thumbnailImageSize;

@property (nonatomic) BOOL isMediaPlaying;
@property (nonatomic) BOOL isMediaPlayed;
@property (nonatomic) BOOL needAnimateVoiceCell;

@property (nonatomic) CGFloat mediaDuration;

@property (nonatomic, copy) NSString *fileRemotePath;
@property (nonatomic, copy) NSString *fileLocalPath;
@property (nonatomic) long long fileSize;
@property (nonatomic) CGFloat fileUploadProgress;
@property (nonatomic) CGFloat fileDownloadProgress;
@property (nonatomic, readonly) BOOL isFetchingThumbnail;
@property (nonatomic, readonly) BOOL isFetchingAttachment;

@property (nonatomic) KTError *error;

- (BOOL)isVideoPlayable;
- (BOOL)isFullImageAvailable;
- (BOOL)isVoicePlayable;

- (UIImage *)fullImage;

- (instancetype)initWithType:(KTMessageBodyType)type;
- (void)updateMessage:(KTMessageModel *)message updateReason:(KTMessageModelUpdateReason)updateReason;
- (long long)fileAttachmentSize;
- (void)cleanWhenConversationSessionEnded;

//状态
@property (nonatomic, readonly) KTMessageStatus messageStatus;
@property (nonatomic, readonly) KTMessageDownloadStatus messageDownloadStatus;
@property (nonatomic, readonly) KTMessageDownloadStatus thumbnailDownloadStatus;

//UI
@property (nonatomic) CGFloat cellHeight;

//交互
@property (nonatomic) BOOL isSelected;
@property (nonatomic) BOOL isDeleting;

#pragma mark - MessageCell 更新 -
//因为APP有消息缓存(默认1300条)，所以减少重复计算是有必要的 -

- (void)setNeedsUpdateThumbnail;
- (void)setNeedsUpdateUploadStatus;
- (void)setNeedsUpdateDownloadStatus;
- (void)setNeedsUpdateForReuse;
- (BOOL)checkNeedsUpdateThumbnail;
- (BOOL)checkNeedsUpdateUploadStatus;
- (BOOL)checkNeedsUpdateDownloadStatus;
- (BOOL)checkNeedsUpdateForReuse;
- (BOOL)checkNeedsUpdate;
- (void)clearNeedsUpdateThumbnail;
- (void)clearNeedsUpdateUploadStatus;
- (void)clearNeedsUpdateDownloadStatus;
- (void)clearNeedsUpdateForReuse;

#pragma mark - 以下方法 Client代码不直接访问 -

@property (nonatomic) BOOL isDownloadingAttachment;

- (void)internal_setMessageStatus:(KTMessageStatus)messageStatus;
- (void)internal_setMessageDownloadStatus:(KTMessageDownloadStatus)messageDownloadStatus;
- (void)internal_setThumbnailDownloadStatus:(KTMessageDownloadStatus)thumbnailDownloadStatus;
- (void)internal_setIsFetchingAttachment:(BOOL)isFetchingAttachment;
- (void)internal_setIsFetchingThumbnail:(BOOL)isFetchingThumbnail;

#pragma mark - 以下方法仅供测试使用 -
- (instancetype)initWithImageModel:(KTMessageModel *)messageModel;

@end
