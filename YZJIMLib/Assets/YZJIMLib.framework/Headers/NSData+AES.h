//
//  NSData+AES.h
//  kdweibo
//
//  Created by Gil on 16/1/27.
//  Copyright © 2016年 www.kingdee.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (AES)

- (NSData *)kd_AES256EncryptWithKey:(NSString *)key;   //加密
- (NSData *)kd_AES256DecryptWithKey:(NSString *)key;   //解密

- (NSData *)kd_AES128EncryptWithKey:(NSString *)key;   //加密
- (NSData *)kd_AES128DecryptWithKey:(NSString *)key;   //解密

@end
