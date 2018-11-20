//
//  KDResponse.h
//  KDNetwork
//
//  Created by Gil on 16/7/26.
//  Copyright © 2016年 yunzhijia. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class KDError;
@interface KDResponse : NSObject

/**
 *  是否为有效的Response
 */
@property (assign, nonatomic, readonly, getter=isValidResponse) BOOL validResponse;
/**
 *  返回值(Object)
 */
@property (strong, nonatomic, readonly, nullable) id responseObject;
/**
 *  返回值(String)
 */
@property (strong, nonatomic, readonly, nullable) NSString *responseString;
/**
 *  原始返回值
 */
@property (strong, nonatomic, readonly, nullable) id originalResponseObject;

/**
 *  Response HeaderFields
 */
@property (strong, nonatomic, readonly, nullable) NSDictionary *allHeaderFields;
/**
 *  Response Status Code
 */
@property (assign, nonatomic, readonly) NSInteger statusCode;

/**
 *  错误
 */
@property (strong, nonatomic, readonly, nullable) KDError *error;

@property (strong, nonatomic, readonly, nullable) NSURLSessionTask *sessionTask;

- (void)setTask:(NSURLSessionTask *)task
       response:(nullable id)responseObject
          error:(nullable NSError *)error;

- (void)setSpecialError:(KDError *)error;
- (void)setSimulatedResponse:(nullable id)responseObject;

@end

NS_ASSUME_NONNULL_END
