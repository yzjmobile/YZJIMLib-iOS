//
//  KDClock.h
//  kdweibo
//
//  Created by hour on 2018/2/6.
//  Copyright © 2018年 www.kingdee.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 参考：https://stackoverflow.com/questions/889380/how-can-i-get-a-precise-time-for-example-in-milliseconds-in-objective-c
 */
@interface KDClock : NSObject

+ (instancetype)sharedClock;

// since device boot or something. Monotonically increasing, unaffected by date and time settings
- (NSTimeInterval)absoluteTime;

@end
