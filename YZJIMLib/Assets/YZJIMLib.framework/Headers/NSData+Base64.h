//
//  NSData+Base64.h
//  Pods
//
//  Created by Gil on 2016/11/24.
//
//

#import <Foundation/Foundation.h>

@interface NSData (Base64)

+ (NSData *)kd_dataFromBase64String:(NSString *)string;
- (NSString *)kd_base64EncodedString;

@end
