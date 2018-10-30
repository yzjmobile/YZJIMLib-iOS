//
//  NSString+DZCategory.h
//  kdweibo
//
//  Created by Darren on 15/7/26.
//  Copyright © 2015年 www.kingdee.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NSString (DZCategory)

// this method is for calculating the actual size for a given width on a multi-line label
- (CGSize)kd_sizeForMaxWidth:(CGFloat)width
                     font:(UIFont *)font
            numberOfLines:(int)numberOfLines;
- (CGSize)kd_sizeForMaxWidth:(CGFloat)width
                     font:(UIFont *)font;
- (CGSize)kd_sizeWithFont:(UIFont *)font;
- (NSMutableDictionary *)kd_queryComponents;
//NSString *kd_safeString(NSString *str);
- (NSString *)kd_dz_stringByTrimmingWhitespaceAndNewlines;
/**
 *  兼容 yyyy-MM-dd HH:mm:ss 和 yyyy-MM-dd HH:mm:ss.SSS
 *
 *  @return 符合特定规格的时间NSDate
 */
- (NSDate *)kd_dz_dateValue;
- (NSArray *)kd_dz_rangesOfString:(NSString *)searchString;
+ (NSString *)kd_dz_stringFileSizeWithValue:(double)dValue;
- (NSArray *)kd_dz_forEachString;
- (NSUInteger)kd_dz_bytes;
@end
