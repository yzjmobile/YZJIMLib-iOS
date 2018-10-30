//
//  KDLogUtil.h
//  KDMerc
//
//  Created by Gil on 2017/12/9.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, KDLoggerType) {
    KDLoggerTypeAll = 0,
    KDLoggerTypeDebug,
    KDLoggerTypeInfo,
    KDLoggerTypeWarn,
    KDLoggerTypeError,
    KDLoggerTypeFatal,
    KDLoggerTypeNone,
};

#define __FILENAME__ (strrchr(__FILE__,'/')+1)
#define KDLogDebug(format, ...) LogInternal(KDLoggerTypeDebug, __FILENAME__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__)
#define KDLogInfo(format, ...) LogInternal(KDLoggerTypeInfo, "", 0, "", format, ##__VA_ARGS__)
#define KDLogWarn(format, ...) LogInternal(KDLoggerTypeWarn, "", 0, "", format, ##__VA_ARGS__)
#define KDLogError(format, ...) LogInternal(KDLoggerTypeError, "", 0, "", format, ##__VA_ARGS__)

NS_ASSUME_NONNULL_BEGIN
@interface KDLogUtil : NSObject

///设置打印的日志级别，建议Debug设置为KDLoggerTypeDebug，release设置为KDLoggerTypeInfo
+ (void)setLoggerType:(KDLoggerType)type;

///设置是否输出到Xcode控制台，建议Debug设置为true，release设置为false
+ (void)setConsoleLog:(BOOL)enable;

/**
 异步执行，内存中的缓存写入文件
 */
+ (void)flush;

/**
 只在debug下调用
 */
+ (void)flushSync;

/**
 获取某一天的log文件的路径（可能有多个log文件）

 @param timeSpan 0为当天的log，1为昨天的log，2为前天的log, 以此类推
 @return logpath array
 */
+ (nullable NSArray<NSString *> *)logFilePathFromTimeSpan:(int)timeSpan
                                                   prefix:(nonnull NSString *)prefix;

/**
 设置单个log文件的最大字节数

 @param byteSize 字节数
 */
+ (void)setMaxFileSize:(uint64_t)byteSize;

/** 开启日志功能
 * path：日志文件路径
 * prefix：文件名前缀
 * publicKey：加密公钥
 */
+ (void)openLogWithPath:(NSString *)path
                 prefix:(NSString *)prefix
              publicKey:(NSString *)key;

///关闭日志，在- (void)applicationWillTerminate:(UIApplication *)application 方法中调用
+ (void)closeLog;

///打印日志
+ (void)log:(KDLoggerType)type
   fileName:(const char *)fileName
 lineNumber:(int)lineNumber
   funcName:(const char *)funcName
    message:(NSString *)message;

@end

@interface KDLogUtil (Log)
+ (void)writelog:(KDLoggerType)logType fileName:(const char *)fileName lineNumber:(int)lineNumber funcName:(const char *)funcName message:(NSString *)message;
+ (void)writelog:(KDLoggerType)logType fileName:(const char *)fileName lineNumber:(int)lineNumber funcName:(const char *)funcName format:(NSString *)format, ...;

+ (BOOL)shouldLog:(int)type;
@end
NS_ASSUME_NONNULL_END

#define LogInternal(type, file, line, func, format, ...) \
do { \
    if ([KDLogUtil shouldLog:type]) { \
        NSString *aMessage = [NSString stringWithFormat:@"%@", [NSString stringWithFormat:format, ##__VA_ARGS__, nil]]; \
        [KDLogUtil writelog:type fileName:file lineNumber:line funcName:func message:aMessage]; \
    } \
} while(0)
