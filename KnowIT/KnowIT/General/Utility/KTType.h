//
//  KTType.h
//  KnowIT
//
//  Created by Littlebox on 16/02/2017.
//  Copyright © 2017 Little Box. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, KTMessageBodyType) {
    kKTMessageBodyTypeText,
    kKTMessageBodyTypeImage,
    kKTMessageBodyTypeVideo,
    kKTMessageBodyTypeVoice,
    kKTMessageBodyTypeEMLocation,
    kKTMessageBodyTypeFile,
    kKTMessageBodyTypeDateTime,
    kKTMessageBodyTypeGif,
    kKTMessageBodyTypeLocation,
    kKTMessageBodyTypeRecording, //表示正在录音的Cell
};

typedef NS_ENUM(NSInteger, KTMessageStatus) {
    kKTMessageStatusPending,
    kKTMessageStatusDelivering,
    kKTMessageStatusSuccessed,
    kKTMessageStatusFailed,
    kKTMessageStatusWaiting = 10086,
    kKTMessageStatusNone
};

typedef NS_ENUM(NSInteger, KTMessageDownloadStatus) {
    kKTMessageDownloadStatusDownloading,
    kKTMessageDownloadStatusSuccessed,
    kKTMessageDownloadStatusFailed,
    kKTMessageDownloadStatusPending,
    kKTMessageDownloadStatusWaiting = 10086,
    kKTMessageDownloadStatusNone
};

@interface KTType : NSObject

@end
