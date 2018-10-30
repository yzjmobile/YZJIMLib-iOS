//
//  KDMercChannel+CMD.h
//  kdweibo
//
//  Created by hour on 2018/1/4.
//  Copyright © 2018年 www.kingdee.com. All rights reserved.
//

#import "KDMercChannel.h"

/**
 文档：http://192.168.0.22/cms/pages/viewpage.action?pageId=19401143
 */
@interface KDMercChannel (Log)

@property (assign, nonatomic) NSTimeInterval startTimeInterval;

- (void)logMercDidConnected;
- (void)logMercDidFailWithError:(NSError *)error;

- (void)logOnLongLinkStatusChange:(int32_t)status longConnStatus:(int32_t)longConnStatus;

- (void)logOnPushWithMsg:(NSString *)msg;

- (void)logSendMsgWithTask:(KDMercTask *)task;

- (void)logNetworkChanged:(KDReachabilityStatus)status;


@end
