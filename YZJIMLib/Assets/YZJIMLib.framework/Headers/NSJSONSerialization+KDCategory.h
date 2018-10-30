//
//  NSJSONSerialization+KDCategory.h
//  kdweibo
//
//  Created by Darren on 15/4/20.
//  Copyright (c) 2015年 www.kingdee.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSJSONSerialization (KDCategory)

+ (id)kd_JSONObjectWithData:(NSData *)data;
+ (id)kd_JSONObjectWithString:(NSString *)jsonString;

+ (NSData *)kd_dataWithJSONObject:(id)jsonObject;

+ (NSString *)kd_stringWithJSONObject:(id)jsonObject;

@end
