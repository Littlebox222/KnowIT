//
//  KTChatInputView.m
//  KnowIT
//
//  Created by Little Box on 17/01/2017.
//  Copyright © 2017 Little Box. All rights reserved.
//

#import "KTChatInputView.h"
#import "UIColor+KTExt.h"

@interface KTChatInputView ()

@property (nonatomic, strong) UILabel *label;

@end

@implementation KTChatInputView

- (id)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    
    if (self) {
        
        self.label = [[UILabel alloc] initWithFrame:CGRectZero];
        [self addSubview:self.label];
    }
    
    return self;
}

- (void)layoutSubviews {
    self.backgroundColor = [UIColor randomColor];
    self.label.frame = CGRectMake(0, 0, self.frame.size.width, self.frame.size.height);
    self.label.text = @"输入面板";
    self.label.font = [UIFont systemFontOfSize:16];
    self.label.textAlignment = NSTextAlignmentCenter;
    self.label.textColor = [UIColor whiteColor];
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

@end
