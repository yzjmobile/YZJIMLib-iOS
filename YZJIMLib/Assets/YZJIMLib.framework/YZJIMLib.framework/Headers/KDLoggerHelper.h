//
//  KDLoggerHelper.h
//  kdweibo
//
//  Created by Gil on 2017/1/17.
//  Copyright © 2017年 www.kingdee.com. All rights reserved.
//

#import <Foundation/Foundation.h>

//extern KDLoggerType const KDLogLevel;//输出的日志级别
extern BOOL const KDConsoleLogEnable;//控制台日志开关

extern NSString * _Nonnull const KDNetworkLogModule;//网络模块名称
//extern BOOL const KDNetworkLogEnable;//网络模块日志开关

@class KDLogMessage;

@interface KDLoggerHelper : NSObject

//+ (void)setupLogger;

+ (void)setupLogger:(nonnull NSString *)kclientId
             userId:(nonnull NSString *)kuserid
                eid:(nonnull NSString *)keid;
+ (void)closeLogger;

+ (NSString *_Nonnull)commonLogContent;

+ (nonnull NSArray<NSString *> *)logFilePath;


/**
 创建一个对象 KDLogMessage

 @param moduleName moduleName
 @return KDLogMessage
 */
+ (nonnull KDLogMessage *)create:(nonnull NSString *)moduleName;


/**
 在app的调试台输出log

 @param log log
 */
+ (void)printAppconsole:(nonnull NSString *)log;

///打印日志
+ (void)log:(NSUInteger)type
   fileName:(const char *)fileName
 lineNumber:(int)lineNumber
   funcName:(const char *)funcName
    message:(NSString *)message;
@end


@interface KDLogMessage : NSObject

@property (nonatomic, readonly) KDLogMessage* _Nonnull (^ _Nonnull appendStr)(NSString * _Nullable str);
@property (nonatomic, readonly) KDLogMessage* _Nonnull (^ _Nonnull appendInt)(int value);
@property (nonatomic, readonly) KDLogMessage* _Nonnull (^ _Nonnull appendLong)(long value);

@property (nonatomic, readonly) void (^ _Nonnull logDebug)(void);
@property (nonatomic, readonly) void (^ _Nonnull logInfo)(void);
@property (nonatomic, readonly) void (^ _Nonnull logWarn)(void);
@property (nonatomic, readonly) void (^ _Nonnull logError)(void);

- (void)setModuleName:(nonnull NSString *)name;
- (void)setCommonLog;

@end

