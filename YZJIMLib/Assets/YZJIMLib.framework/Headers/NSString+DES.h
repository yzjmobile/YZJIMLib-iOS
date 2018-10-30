//
//  NSString+DES.h
//  Pods
//
//  Created by 钟伟杰 on 2016/11/25.
//
//

#import <Foundation/Foundation.h>

@interface NSString (DES)

/*
 @desc DES加密算法,加密编码格式为NSUTF8StringEncoding;
 @param text; -- 需要加密的字符串
 @param key; -- 加密密钥
 @return 加密后的base64字符串;
 */
+(NSString *)kd_des_Encrypt:(NSString *)text key:(NSString *)key;
+(NSData *)kd_des_Encrypt2Data:(NSString *)text key:(NSString *)key;

/*
 @desc DES解密算法,解密编码格式为NSUTF8StringEncoding;
 @param text; -- 需要解密的base64字符串
 @param key; -- 解密密钥
 @return 解密后的字符串;
 */
+(NSString *)kd_des_Decrypt:(NSString *)text key:(NSString *)key;
+(NSString *)kd_des_DecryptWithData:(NSData *)text key:(NSString *)key;
+(NSData *)kd_des_Decrypt2DataWithData:(NSData *)text key:(NSString *)key;

@end
