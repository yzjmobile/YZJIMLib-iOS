//
//  NSDate+Server.h
//  Pods
//
//  Created by Gil on 2017/8/1.
//
//

#import <Foundation/Foundation.h>

@interface NSDate (Server)
+ (NSDate *)serverDate;
+ (NSTimeInterval)serverDateDelta;
@end
