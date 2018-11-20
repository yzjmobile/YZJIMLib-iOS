//
//  KDBatchRequest.h
//  KDNetwork
//
//  Created by Gil on 16/7/26.
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class KDRequest, KDBatchRequest;
typedef void (^ KDBatchRequestCompletionBlock)(KDBatchRequest *batchRequest);

@interface KDBatchRequest : NSObject

/**
 *  批量执行的request集合
 */
@property (strong, nonatomic, readonly, nullable) NSArray *requests;

/**
 *  请求完成的block
 */
@property (copy, nonatomic, readonly, nullable) KDBatchRequestCompletionBlock completionBlock;

/**
 *  初始化请求集合
 */
- (instancetype)initWithRequests:(NSArray<KDRequest *> *)requests;


/**
 *  发起请求
 */
- (void)startWithCompletionBlock:(KDBatchRequestCompletionBlock _Nullable)completionBlock;

/**
 *  停止请求
 */
- (void)stop;

/**
 *  清除completionBlock
 */
- (void)clearCompletionBlock;

@end

NS_ASSUME_NONNULL_END
