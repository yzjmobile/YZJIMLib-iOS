//
//  KDNetworkConfig.h
//  KDNetwork
//
//  Created by Gil on 16/7/25.
//  Copyright © 2016年 yunzhijia. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class KDSecurityPolicy;

@interface KDNetworkConfig : NSObject

+ (instancetype)sharedConfig;

/**
 *  统一配置baseUrl
 */
@property (strong, nonatomic, nullable) NSString *baseUrl;

/**
 *  默认的HTTP Header Field
 */
@property (strong, nonatomic, readonly, nullable) NSDictionary <NSString *, NSString *> *requestHTTPHeaderField;

/**
 *  安全控制
 */
@property (strong, nonatomic, readonly) KDSecurityPolicy *scurityPolicy;

//设置默认的HTTP Header Field
- (void)setValue:(NSString *)value forHTTPHeaderField:(NSString *)field;
//获取某个HTTP Header Field
- (NSString *)valueForHTTPHeaderField:(NSString *)field;
//移除某个HTTP Header Field
- (void)removeHTTPHeaderField:(NSString *)field;

@end

#pragma mark - 安全策略 -
@interface KDSecurityPolicy : NSObject
/**
 *  是否允许不信任的证书，默认为NO
 */
@property (assign, nonatomic) BOOL allowInvalidCertificates;
/**
 *  是否验证域名证书的CN(common name)字段，默认为YES
 */
@property (assign, nonatomic) BOOL validatesDomainName;

+ (instancetype)defaultPolicy;

@end

NS_ASSUME_NONNULL_END
