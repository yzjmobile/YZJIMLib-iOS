//
//  NSString+WYAddtion.h
//  kdweibo
//
//  Created by kyle on 16/10/19.
//  Copyright © 2016年 www.kingdee.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (WYAddtion)

+(NSString *) kd_jsonStringWithString:(NSString *) string;
+(NSString *) kd_jsonStringWithArray:(NSArray *)array;
+(NSString *) kd_jsonStringWithDictionary:(NSDictionary *)dictionary;
+(NSString *) kd_jsonStringWithObject:(id) object;

@end
