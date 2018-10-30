//
//  NSString+URLEncode.h
//  Pods
//
//  Created by 钟伟杰 on 2016/11/28.
//
//

#import <Foundation/Foundation.h>

@interface NSString (URLEncode)

- (NSString *)kd_URLEncode;
- (NSString *)kd_URLEncodeUsingEncoding:(NSStringEncoding)encoding;

- (NSString *)kd_URLDecode;
- (NSString *)kd_URLDecodeUsingEncoding:(NSStringEncoding)encoding;

@end
