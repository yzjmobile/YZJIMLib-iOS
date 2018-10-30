//
//  KDMarsService.h
//  KDMerc
//
//  Created by hour on 2018/1/4.
//

#import <Foundation/Foundation.h>

@class KDMercTask;

FOUNDATION_EXPORT NSErrorDomain const KDMercErrorDomain;

typedef NS_ENUM(int32_t, KDMercConnectStatus) {
    KDMercConnUnknow = 0,
    KDMercConnecting,
    KDMercConnected,
    //    KDMercFailedLongLink,   // 长连接失败 // biz 忽略这个状态
    //    KDMercFailedPubKey, // pubkey上传失败
    //    KDMercFailedLogin,  // @"login"协议调用失败
    KDMercConnFailed,
};

@protocol KDMercServiceDelegate <NSObject>

@optional - (NSArray<NSString *> *)OnNewDns:(NSString *)address;

/*
  发的消息封装成CGITask对象，req 和 resp 的数据(目前都是string) 都封装在task对象中
  startTask -> req2buf -> buf2resp -> onTaskEnd
 */
@required - (NSData*)Request2BufferWithTaskID:(uint32_t)tid task:(KDMercTask *)task;
@required - (NSInteger)Buffer2ResponseWithTaskID:(uint32_t)tid responseData:(NSData *)data task:(KDMercTask *)task;
@required - (NSInteger)OnTaskEndWithTaskID:(uint32_t)tid task:(KDMercTask *)task errType:(uint32_t)errtype errCode:(uint32_t)errcode;

@required - (void)OnPushWithData:(NSString *)respMsg;

/**
 Error errcode 0 成功；1 获取session_id失败； 2 登录失败； 3 登录，返回数据有问题
 errMsg 成功也会返回msg，登录的结果
 */
@required - (void)onConnectStatusChange:(KDMercConnectStatus)status error:(NSError *)err;

@required - (void)OnLongLinkStatusChange:(int32_t)status longConnStatus:(int32_t)longConnStatus;

@required - (void)addCGITask:(KDMercTask*)cgiTask forKey:(NSString *)key;
@required - (void)removeCGITaskForKey:(NSString *)key;

@end


@interface KDMercService : NSObject

@property (nonatomic, weak) id<KDMercServiceDelegate> delegate;

@property (assign, nonatomic, readonly) KDMercConnectStatus connStatus;

+ (KDMercService *)sharedInstance;
- (void)createMerc;
- (void)destoryMerc;

/* 管理session，session位于mars之上 */
- (void)openSessionWithPubKey:(NSString *)pubKey openToken:(NSString *)token userAgent:(NSString *)ua clientId:(NSString *)clientId;
- (void)closeSession;

- (void)report_onNetworkChange;

/**
 程序前后台改变时调用，必须调用，否则可能会出现网络连接频率没那么快的问题。
 @param isForeground : true 为前台， false 为后台。

 @param isForeground
 */
- (void)report_onForeground:(BOOL)isForeground;

/**
 crash后需要调用, 无需再调用onDestroy
 */
- (void)OnExceptionCrash;

- (void)setClientVersion:(UInt32)clientVersion;
- (void)setShortLinkDebugIP:(NSString *)IP port:(const unsigned short)port;
- (void)setShortLinkPort:(const unsigned short)port;
- (void)setLongLinkAddress:(NSString *)string port:(const unsigned short)port debugIP:(NSString *)IP;
- (void)setLongLinkAddress:(NSString *)string port:(const unsigned short)port;

/**
 检测长链接状态。如果没有连接上，则会尝试重连
 */
- (void)makesureLongLinkConnect;

- (NSString *)longLinkIp;
- (int64_t)getSessionId;

/**
 发送task

 @param task
 @return
 */
- (uint32_t)startTask:(KDMercTask *)task;
- (void)stopTask:(uint32_t)taskID;

// callbacks
- (NSArray *)OnNewDns:(NSString *)address;
- (void)OnPushWithCmd:(NSInteger)cid data:(NSData *)data;
- (NSData*)Request2BufferWithTaskID:(uint32_t)tid userContext:(const void *)context;
- (NSInteger)Buffer2ResponseWithTaskID:(uint32_t)tid ResponseData:(NSData *)data userContext:(const void *)context;
- (NSInteger)OnTaskEndWithTaskID:(uint32_t)tid userContext:(const void *)context errType:(uint32_t)errtype errCode:(uint32_t)errcode;

- (void)OnOpenSessionErrorCode:(int)errcode errorMsg:(NSString *)errMsg;

- (void)OnConnectionStatusChange:(int32_t)status longConnStatus:(int32_t)longConnStatus;

@end

