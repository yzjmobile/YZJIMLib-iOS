//
//  KDNetworkManager.h
//  KDNetwork
//
//  Created by Gil on 16/7/25.
//  Copyright © 2016年 yunzhijia. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class KDRequest, KDBatchRequest;
@interface KDNetworkManager : NSObject

+ (instancetype)sharedManager;

- (void)addRequest:(KDRequest *)request;

- (void)cancelRequest:(KDRequest *)request;
- (void)cancelAllRequests;

- (NSURL *)urlWithRequest:(KDRequest *)request;

/// 设置 只对 AFJSONResponseSerializer有效
- (void)setJsonResponseSerializerSupportHtml:(BOOL)jsonResponseSerializerSupportHtml;

@end

NS_ASSUME_NONNULL_END
