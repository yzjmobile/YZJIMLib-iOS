//
//  NSCalendar+KDCalendar.h
//  KDFoundation
//
//  Created by tangzeng on 2017/11/22.
//

#import <Foundation/Foundation.h>

@interface NSCalendar (KDCalendar)
/// kd_current 代替current方法
///
/// - Returns: 当前日历
+ (NSCalendar *)kd_current;

/// kd_default 代替普通的NSCalendar初始化
///
/// - Returns: 一个默认的NSCalendar对象
+ (NSCalendar *)kd_default;
@end
