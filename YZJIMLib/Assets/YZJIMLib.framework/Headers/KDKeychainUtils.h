//
//  KDKeychainUtils.h
//  kdweibo_common
//
//  Created by Gil on 16/3/19.
//  Copyright © 2016年 kingdee. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSInteger {
    KDKeychainAccessibleAlways = 0,
    KDKeychainAccessibleAfterFirstUnlockThisDeviceOnly,
    KDKeychainAccessibleAlwaysThisDeviceOnly,
} KDKeychainAccessible;

@interface KDKeychainUtils : NSObject

/**
 *  从钥匙串中获取字符串
 *
 *  @param account      kSecAttrAccount
 *  @param service      kSecAttrService
 *  @param accessible   访问权限设置
 *  @param error        NSError
 *
 *  @return NSString
 */
+ (NSString *)getItemWithAccount:(NSString *)account
                         service:(NSString *)service
                      accessible:(KDKeychainAccessible)accessible
                           error:(NSError **)error;

/**
 *  将字符串存入钥匙串中
 *
 *  @param item             需要存入钥匙串的字符串
 *  @param account          kSecAttrAccount
 *  @param service          kSecAttrService
 *  @param accessible       访问权限设置
 *  @param updateExisting   是否强制更新
 *  @param error            NSError
 *
 *  @return true or false
 */
+ (BOOL)storeItem:(NSString *)item
      withAccount:(NSString *)account
          service:(NSString *)service
       accessible:(KDKeychainAccessible)accessible
   updateExisting:(BOOL)updateExisting
            error:(NSError **)error;


+ (BOOL)deleteItemForAccount:(NSString *)account
                     service:(NSString *)service
                  accessible:(KDKeychainAccessible)accessible
                       error:(NSError **)error;

@end
