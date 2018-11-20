//
//  KDMercTask.h
//  KDMerc
//
//  Created by hour on 2018/1/4.
//

#import <Foundation/Foundation.h>

typedef enum : int32_t {
    ChannelType_ShortConn = 1,
    ChannelType_LongConn = 2,
    ChannelType_All = 3
} ChannelType;

typedef enum : int32_t{
    ChannelNormalStrategy = 0,
    ChannelFastStrategy = 1,
    ChannelDisasterRecoveryStategy = 2
} ChannelStrategy;

//@class KDMercTask;
//typedef void (^KDMercTaskSuccess) (NSString * _Nullable resp, KDMercTask * _Nonnull task);
//typedef void (^KDMercTaskFail) (NSError * _Nullable error, KDMercTask * _Nonnull task);

typedef void (^KDMercTaskSuccess) (NSString * _Nullable resp);
typedef void (^KDMercTaskFail) (NSError * _Nullable error);

@interface KDMercTask : NSObject

//@property(nonatomic) uint32_t taskid;
//@property(nonatomic) KDMercCmdidType cmdid;

@property(nonatomic, copy, nonnull) NSString *cgi;

@property (nonatomic, assign) BOOL sendOnly;

// short link
@property(nonatomic, copy, nonnull) NSString *host;

@property (nonatomic, copy, nullable) NSString *reqMsg;
@property (nonatomic, copy, nullable) NSString *respMsg;

@property (nonatomic, copy, nonnull) KDMercTaskSuccess succBlock;
@property (nonatomic, copy, nonnull) KDMercTaskFail failBlock;

@property(nonatomic) ChannelType channel_select;
@property (nonatomic, assign) BOOL networkStatusSensitive;
@property (nonatomic, assign) ChannelStrategy channelStragery;

@property (nonatomic, assign) int32_t priority;

@property (nonatomic, assign) int32_t retryCount;
@property (nonatomic, assign) int32_t totalTimeout;

//=== 用于log统计 ===
// 用于统计task的执行时间
@property (nonatomic, assign) NSTimeInterval startTime, endTime;
// 从OnTaskEnd中取
@property (nonatomic, assign) uint32_t errCode, errType;


@end
