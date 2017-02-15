//
//  KTUtils+CGHelper.m
//  KnowIT
//
//  Created by Littlebox on 23/01/2017.
//  Copyright © 2017 Little Box. All rights reserved.
//

#import "KTUtils+CGHelper.h"
#import "UIKit+KTExt.h"

@import ImageIO;

CGFloat SCREEN_WIDTH;
CGFloat SCREEN_HEIGHT;
CGSize SCREEN_SIZE;

CGRect SCREEN_FRAME;
CGPoint SCREEN_CENTER;


CGFloat CGPointDistanceBetween(CGPoint point1, CGPoint point2) {
    
    CGFloat dtx = point1.x - point2.x;
    CGFloat dty = point1.y - point2.y;
    CGFloat distance = sqrt(dtx * dtx + dty * dty);
    return distance;
}

@implementation KTUtils (CGHelper)

+ (void)load {
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        SCREEN_FRAME = [UIScreen mainScreen].bounds;
        SCREEN_SIZE = SCREEN_FRAME.size;
        SCREEN_WIDTH = SCREEN_SIZE.width;
        SCREEN_HEIGHT = SCREEN_SIZE.height;
        SCREEN_CENTER = CGPointMake(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    });
}

+ (CGFloat)screenScale {
    
    static CGFloat _scale = 0;
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _scale = [UIScreen mainScreen].scale;
    });
    
    return _scale;
}

+ (CGRect)screenFrame {
    return [UIScreen mainScreen].bounds;
}

+ (CGFloat)screenWidth {
    return [UIScreen mainScreen].bounds.size.width;
}

+ (CGFloat)screenHeight {
    return [UIScreen mainScreen].bounds.size.height;
}

+ (CGFloat)pixelAlignForFloat:(CGFloat)position {
    CGFloat scale = [KTUtils screenScale];
    return round(position * scale) / scale;
}

+ (CGPoint)pixelAlignForPoint:(CGPoint)point {
    
    CGFloat scale = [KTUtils screenScale];
    CGFloat x = round(point.x * scale) / scale;
    CGFloat y = round(point.x * scale) / scale;
    
    return CGPointMake(x, y);
}

+ (CGSize)convertPointSizeToPixelSize:(CGSize)pointSize {
    CGFloat scale = [self screenScale];
    return CGSizeMake(pointSize.width * scale, pointSize.height * scale);
}

+ (CALayer *)lineWithLength:(CGFloat)length atPoint:(CGPoint)point {
    
    CALayer *line = [CALayer layer];
    UIColor *color = UIColorRGB(221, 221, 221);
    line.backgroundColor = color.CGColor;
    
    line.frame = CGRectMake(point.x, point.y, length, 1/[self screenScale]);
    
    return line;
}

@end
