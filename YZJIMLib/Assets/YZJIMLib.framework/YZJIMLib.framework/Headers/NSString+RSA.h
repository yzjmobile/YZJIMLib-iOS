//
//  NSString+RSA.h
//  Pods
//
//  Created by 钟伟杰 on 2016/11/25.
//
//

#import <Foundation/Foundation.h>

@interface NSString (RSA)

/*
 @desc RSA加密算法;
 @param content; -- 需要解密的内容
 @param publicKey; -- 加密公钥
 @param cust3gNo; -- 企业3G号，每个企业使用不同的公钥
 @return 加密后的字符串;
 */
+(NSString *)kd_rsa_encrypt:(NSString *)content publicKey:(NSString *)key cust3gNo:(NSString *)cust3gNo;


@end
