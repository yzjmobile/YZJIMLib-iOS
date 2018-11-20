//
//  NSObject+StopQueue.h
//  Pods
//
//  Created by Gil on 2017/8/4.
//
//

#import <Foundation/Foundation.h>

@class KDRequest;
@interface NSObject (StopQueue)

///将请求加入到
- (void)addRequestToStopQueue:(KDRequest *)request;

- (void)stopRequestsAtStopQueue;

@end
