//
//  NSDateFormatter+KDDefault.h
//  KDFoundation
//
//  Created by tangzeng on 2017/11/22.
//

#import <Foundation/Foundation.h>

@interface NSDateFormatter (KDDefault)
/// kd_defaultFormatter 代替DateFormatter对象的初始化，并进行缓存
///
/// - Returns: DateFormatter对象
+ (NSDateFormatter *)kd_default;
@end
