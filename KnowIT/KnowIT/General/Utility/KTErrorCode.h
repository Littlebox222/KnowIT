//
//  KTErrorCode.h
//  KnowIT
//
//  Created by Littlebox on 16/02/2017.
//  Copyright © 2017 Little Box. All rights reserved.
//

#ifndef KTErrorCode_h
#define KTErrorCode_h

typedef enum{
    KTErrorGeneral = 1,                      /*! \~chinese 一般错误 \~english General error */
    KTErrorNetworkUnavailable,               /*! \~chinese 网络不可用 \~english Network is unavaliable */
    
    KTErrorInvalidAppkey = 100,              /*! \~chinese Appkey无效 \~english App key is invalid */
    KTErrorInvalidUsername,                  /*! \~chinese 用户名无效 \~english User name is invalid */
    KTErrorInvalidPassword,                  /*! \~chinese 密码无效 \~english Password is invalid */
    KTErrorInvalidURL,                       /*! \~chinese URL无效 \~english URL is invalid */
    
    KTErrorUserAlreadyLogin = 200,           /*! \~chinese 用户已登录 \~english User has already logged in */
    KTErrorUserNotLogin,                     /*! \~chinese 用户未登录 \~english User has not logged in */
    KTErrorUserAuthenticationFailed,         /*! \~chinese 密码验证失败 \~english Password check failed */
    KTErrorUserAlreadyExist,                 /*! \~chinese 用户已存在 \~english User has already exist */
    KTErrorUserNotFound,                     /*! \~chinese 用户不存在 \~english User was not found */
    KTErrorUserIllegalArgument,              /*! \~chinese 参数不合法 \~english Illegal argument */
    KTErrorUserLoginOnAnotherDevice,         /*! \~chinese 当前用户在另一台设备上登录 \~english User has logged in from another device */
    KTErrorUserRemoved,                      /*! \~chinese 当前用户从服务器端被删掉 \~english User was removed from server */
    KTErrorUserRegisterFailed,               /*! \~chinese 用户注册失败 \~english Register user failed */
    KTErrorUpdateApnsConfigsFailed,          /*! \~chinese 更新推送设置失败 \~english Update apns configs failed */
    KTErrorUserPermissionDenied,             /*! \~chinese 用户没有权限做该操作 \~english User has no right for this operation. */
    
    KTErrorServerNotReachable = 300,         /*! \~chinese 服务器未连接 \~english Server is not reachable */
    KTErrorServerTimeout,                    /*! \~chinese 服务器超时 \~english Wait server response timeout */
    KTErrorServerBusy,                       /*! \~chinese 服务器忙碌 \~english Server is busy */
    KTErrorServerUnknownError,               /*! \~chinese 未知服务器错误 \~english Unknown server error */
    
    KTErrorFileNotFound = 400,               /*! \~chinese 文件没有找到 \~english Can't find the file */
    KTErrorFileInvalid,                      /*! \~chinese 文件无效 \~english File is invalid */
    KTErrorFileUploadFailed,                 /*! \~chinese 上传文件失败 \~english Upload file failed */
    KTErrorFileDownloadFailed,               /*! \~chinese 下载文件失败 \~english Download file failed */
    
    KTErrorMessageInvalid = 500,             /*! \~chinese 消息无效 \~english Message is invalid */
    KTErrorMessageIncludeIllegalContent,      /*! \~chinese 消息内容包含不合法信息 \~english Message contains illegal content */
    KTErrorMessageTrafficLimit,              /*! \~chinese 单位时间发送消息超过上限 \~english Unit time to send messages over the upper limit */
    KTErrorMessageEncryption,                /*! \~chinese 加密错误 \~english Encryption error */
    
    KTErrorGroupInvalidId = 600,             /*! \~chinese 群组ID无效 \~english Group Id is invalid */
    KTErrorGroupAlreadyJoined,               /*! \~chinese 已加入群组 \~english User has already joined the group */
    KTErrorGroupNotJoined,                   /*! \~chinese 未加入群组 \~english User has not joined the group */
    KTErrorGroupPermissionDenied,            /*! \~chinese 没有权限进行该操作 \~english User has NO authority for the operation */
    KTErrorGroupMembersFull,                 /*! \~chinese 群成员个数已达到上限 \~english Reach group's max member count */
    KTErrorGroupNotExist,                    /*! \~chinese 群组不存在 \~english Group is not exist */
    
    KTErrorChatroomInvalidId = 700,          /*! \~chinese 聊天室ID无效 \~english Chatroom id is invalid */
    KTErrorChatroomAlreadyJoined,            /*! \~chinese 已加入聊天室 \~english User has already joined the chatroom */
    KTErrorChatroomNotJoined,                /*! \~chinese 未加入聊天室 \~english User has not joined the chatroom */
    KTErrorChatroomPermissionDenied,         /*! \~chinese 没有权限进行该操作 \~english User has NO authority for the operation */
    KTErrorChatroomMembersFull,              /*! \~chinese 聊天室成员个数达到上限 \~english Reach chatroom's max member count */
    KTErrorChatroomNotExist,                 /*! \~chinese 聊天室不存在 \~english Chatroom is not exist */
    
    KTErrorCallInvalidId = 800,              /*! \~chinese 实时通话ID无效 \~english Call id is invalid */
    KTErrorCallBusy,                         /*! \~chinese 已经在进行实时通话了 \~english User is busy */
    KTErrorCallRemoteOffline,                /*! \~chinese 对方不在线 \~english Callee is offline */
    KTErrorCallConnectFailed,                /*! \~chinese 实时通话建立连接失败 \~english Establish connection failed */
    
}KTErrorCode;


#endif /* KTErrorCode_h */
