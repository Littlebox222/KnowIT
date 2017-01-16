//
//  KTTextActionDelegate.h
//  KnowIT
//
//  Created by Little Box on 17/01/2017.
//  Copyright © 2017 Little Box. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol KTTextActionDelegate <NSObject>

- (void)textLinkDidTapped:(nonnull NSURL *)url userInfo:(nonnull id)userInfo;
- (void)textLinkDidLongPressed:(nonnull NSURL *)url userInfo:(nonnull id)userInfo;
- (void)textPhoneNumberDidTapped:(nonnull NSString *)url userInfo:(nonnull id)userInfo;

@end
