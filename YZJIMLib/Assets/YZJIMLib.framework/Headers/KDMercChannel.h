//
//  KDMercChannel.h
//  kdweibo
//
//  Created by hour on 2018/1/4.
//  Copyright © 2018年 www.kingdee.com. All rights reserved.
//

#import <Foundation/Foundation.h>


#if __has_include("KDReachabilityManager.h")
#import "KDReachabilityManager.h"
#import "KDMerc.h"
#else
@import KDNetwork;
#import <KDMerc/KDMerc.h>
#endif

//@class KDReachabilityStatus;


#define kMercCGISendMsg @"/yzj/send_msg" // 发消息

FOUNDATION_EXPORT NSErrorDomain const KDMercMsgErrDomain;

typedef void (^KDMercConnectSuccessBlock) (void);
typedef void (^KDMercConnectFailedBlock) (void);

@protocol KDMercChannelDelegate <NSObject>

- (void)handlePush:(nonnull id)msg;

//- (NSString * _Nonnull)dataPubAcctUpdateTime;

- (void)mercChannelLogout:(nullable NSString *)errMsg;
- (void)mercCheckQueryAll;  // 底层会有逻辑触发query

@required


@end

@interface KDMercChannel : NSObject <KDMercServiceDelegate>

@property (strong, nonatomic) KDMercConnectSuccessBlock successBlock;
@property (strong, nonatomic) KDMercConnectFailedBlock failedBlock;

@property (strong, nonatomic, readonly) dispatch_queue_t handleQueue;
@property (strong, nonatomic, readonly) NSMutableDictionary *cmdMap;

@property (assign, nonatomic, readonly) KDMercConnectStatus connStatus;

@property (weak, nonatomic) id<KDMercChannelDelegate> delegate;

- (void)openChannelWithPubKey:(nonnull NSString *)pubKey
                    openToken:(nonnull NSString *)openToken
                    userAgent:(nonnull NSString *)userAgent
                     clientId:(nonnull NSString *)clientId
              longLinkAddress:(nonnull NSString *)longLinkAddress
                 longLinkPort:(unsigned short)longLinkPort
              shortLinkAddress:(nonnull NSString *)shortLinkAddress
                shortLinkPort:(unsigned short)shortLinkPort;
- (void)closeChannel;

/// private method 外部不要调用
- (void)_openChannel;

- (void)report_onForeground:(BOOL)isForeground;
- (void)report_onNetworkChanged:(KDReachabilityStatus)status;
- (void)handleCrash;

- (NSString *)sessionId;

/**
 用于query，不需要返回数据

 @param msg query_msg
 */
- (void)queryMessage:(NSString * _Nonnull)msg;

- (void)sendMsg:(NSString * _Nonnull)msg
        withCGI:(NSString * _Nonnull)cgi
        success:(void (^_Nullable)(NSString * _Nullable) )succBlock
        failure:(void (^_Nullable)(NSError * _Nullable))failBlock;

@end
