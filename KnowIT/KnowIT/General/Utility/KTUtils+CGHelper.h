//
//  KTUtils+CGHelper.h
//  KnowIT
//
//  Created by Littlebox on 23/01/2017.
//  Copyright © 2017 Little Box. All rights reserved.
//

#import "KTUtils.h"

@import ImageIO;

extern CGFloat SCREEN_WIDTH;
extern CGFloat SCREEN_HEIGHT;
extern CGSize SCREEN_SIZE;

extern CGRect SCREEN_FRAME;
extern CGPoint SCREEN_CENTER;

OBJC_EXTERN CGFloat CGPointDistanceBetween(CGPoint point1, CGPoint point2);

@interface KTUtils (CGHelper)

+ (CGFloat)screenScale;

+ (CGRect)screenFrame;

+ (CGFloat)screenWidth;

+ (CGFloat)screenHeight;

+ (CGFloat)pixelAlignForFloat:(CGFloat)position;

+ (CGPoint)pixelAlignForPoint:(CGPoint)point;

+ (CGSize)convertPointSizeToPixelSize:(CGSize)pointSize;

+ (CALayer *)lineWithLength:(CGFloat)length atPoint:(CGPoint)point;

+ (UIColor *)colorAtPoint:(CGPoint)point fromImageView:(UIImageView *)imageView;

+ (CGSize)GIFDimensionalSize:(CGImageSourceRef)imgSourceRef;

@end
