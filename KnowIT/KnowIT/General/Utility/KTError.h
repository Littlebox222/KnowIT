//
//  KTError.h
//  KnowIT
//
//  Created by Littlebox on 16/02/2017.
//  Copyright © 2017 Little Box. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KTErrorCode.h"

@interface KTError : NSObject

@property (nonatomic) KTErrorCode errorCode;
@property (nonatomic, copy) NSString *errorDescription;

- (instancetype)initWithDescription:(NSString *)description code:(KTErrorCode)code;
+ (instancetype)errorWithDescription:(NSString *)description code:(KTErrorCode)code;

@end
