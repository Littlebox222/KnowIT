//
//  UIColor+KTExt.h
//  KnowIT
//
//  Created by Little Box on 16/01/2017.
//  Copyright © 2017 Little Box. All rights reserved.
//

@import UIKit;

@interface UIColor (KTExt)

#define UIColorRGBA(_red, _green, _blue, _alpha) [UIColor colorWithRed:(_red/255.0) green:(_green/255.0) blue:(_blue/255.0) alpha:(_alpha)]
#define UIColorRGB(red, green, blue) UIColorRGBA(red, green, blue, 1);
#define UIColorHexRGBA(rgbaString) [UIColor colorWithHexRGBA:(rgbaString)]
#define UIColorHexRGB(rgbString) [UIColor colorWithHexRGB:(rgbString)]

+ (instancetype)colorWithHexRGBA:(NSString *)rgba;

+ (instancetype)colorWithHexRGB:(NSString *)rgb;

+ (instancetype)colorWithHexARGB:(NSString *)argb;

+ (UIColor *)randomColor;

+ (UIColor *)randomColorWithAlpha:(CGFloat)alpha;

@end
