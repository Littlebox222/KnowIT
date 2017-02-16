//
//  KTError.m
//  KnowIT
//
//  Created by Littlebox on 16/02/2017.
//  Copyright © 2017 Little Box. All rights reserved.
//

#import "KTError.h"

@implementation KTError

- (instancetype)initWithDescription:(NSString *)description code:(KTErrorCode)code {
    
    self = [super init];
    
    if (self) {
        self.errorDescription = description;
        self.errorCode = code;
    }
    
    return self;
}

+ (instancetype)errorWithDescription:(NSString *)description code:(KTErrorCode)code {
    KTError *error = [[KTError alloc] initWithDescription:description code:code];
    return error;
}

@end
