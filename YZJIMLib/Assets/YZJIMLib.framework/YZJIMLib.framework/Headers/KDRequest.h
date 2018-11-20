//
//  KDRequest.h
//  KDNetwork
//
//  Created by Gil on 16/7/25.
//  Copyright © 2016年 yunzhijia. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  请求类型
 */
typedef NS_ENUM (NSInteger, KDRequestMethod) {
    KDRequestMethodGET       = 0,
    KDRequestMethodPOST      = 1,
    KDRequestMethodHEAD      = 2,
    KDRequestMethodPUT       = 3,
    KDRequestMethodPATCH     = 4,
    KDRequestMethodDELETE    = 5
};

/**
 *  请求的序列化格式
 */
typedef NS_ENUM (NSInteger, KDRequestSerializer) {
    KDRequestHTTPSerializer  = 0,
    KDRequestJSONSerializer  = 1
};

/**
 *  返回的序列化格式
 */
typedef NS_ENUM (NSInteger, KDResponseSerializer) {
    KDResponseJSONSerializer  = 0,
    KDResponseHTTPSerializer  = 1
};

/**
 *  请求优先级
 */
typedef NS_ENUM(NSInteger, KDRequestPriority) {
    KDRequestPriorityLow = -4L,
    KDRequestPriorityDefault = 0,
    KDRequestPriorityHigh = 4,
};

@class KDRequest, KDResponse;
@protocol KDMultipartFormData;
typedef void (^ KDRequestCompletionBlock)(__kindof KDRequest *request);
typedef void (^ KDRequestConstructingBlock)(id<KDMultipartFormData> formData);
typedef void (^ KDRequestProgressBlock)(__kindof NSProgress *progress);

@protocol KDRequestInterceptor <NSObject>
@optional
/**
 拦截器，用于在请求开始之前、结束或者停止时回调给业务层
 */
- (void)requestWillStart:(KDRequest *)request;
- (void)requestWillStop:(KDRequest *)request;
- (void)requestDidStop:(KDRequest *)request;
- (void)requestDidFinished:(KDRequest *)request;
@end

@interface KDRequest : NSObject

/**
 *  请求优先级，默认为KDRequestPriorityDefault
 */
@property (nonatomic) KDRequestPriority requestPriority;

/**
 *  用来存储自定义的信息
 */
@property (strong, nonatomic, nullable) NSDictionary *userInfo;

#pragma mark - readonly property -
/**
 *  请求唯一ID
 */
@property (strong, nonatomic, readonly, nullable) NSString *requestId;
/**
 *  请求的Task
 */
@property (strong, nonatomic, readonly) NSURLSessionTask *requestTask;
/**
 *  请求的http header
 */
@property (strong, nonatomic, readonly, nullable) NSDictionary <NSString *, NSString *> *requestHTTPHeaderField;
/**
 *  请求成功的回调
 */
@property (copy, nonatomic, readonly, nullable) KDRequestCompletionBlock successCompletionBlock;
/**
 *  请求失败的回调
 */
@property (copy, nonatomic, readonly, nullable) KDRequestCompletionBlock failureCompletionBlock;

/**
 请求的拦截器
 */
@property (copy, nonatomic, readonly, nullable) NSArray<id<KDRequestInterceptor>> *interceptors;


#pragma mark response

@property (strong, nonatomic) KDResponse *response;

//如果传入了resultClass，则解析出resultModel
@property (assign, nonatomic, readonly, nullable) Class resultClass;
@property (strong, nonatomic, readonly, nullable) id resultModel;
@property (strong, nonatomic, readonly, nullable) NSArray *resultModels;

#pragma mark - upload & download -
/**
 *  用于组织POST体的block，多用于上传文件
 */
@property (copy, nonatomic, nullable) KDRequestConstructingBlock constructingBodyBlock;

/**
 *  上传或者下载进度
 */
@property (copy, nonatomic, nullable) KDRequestProgressBlock progressBlock;

/**
 *  下载目录
 */
@property (strong, nonatomic, nullable) NSString *downloadPath;

#pragma mark - method -
//支持自解析返回的Model，resultClass需要是JSONModel的subClass
- (instancetype)initWithResultClass:(nullable Class)resultClass;

#pragma mark http header field
//设置默认的HTTP Header Field
- (void)setValue:(NSString *)value forHTTPHeaderField:(NSString *)field;
//获取某个HTTP Header Field
- (NSString *)valueForHTTPHeaderField:(NSString *)field;
//移除某个HTTP Header Field
- (void)removeHTTPHeaderField:(NSString *)field;

#pragma mark subclass override
/**
 *  请求的baseUrl
 */
- (nullable NSString *)baseUrl;
/**
 *  请求的相对地址，除baseUrl之外的
 */
- (nullable NSString *)requestUrl;
/**
 *  请求参数
 */
- (nullable id)requestParameters;
/**
 *  请求超时时间，默认60秒
 */
- (NSTimeInterval)requestTimeoutInterval;
/**
 *  请求类型，默认KDRequestMethodGET
 */
- (KDRequestMethod)requestMethod;
/**
 *  请求序列化格式，默认KDRequestHTTPSerializer
 */
- (KDRequestSerializer)requestSerializer;
/**
 *  返回的序列化格式，默认KDResponseHTTPSerializer
 */
- (KDResponseSerializer)responseSerializer;

/**
 是否模拟数据，用于接口测试(只有DEBUG模式下才起作用)

 @return 默认为NO
 */
- (BOOL)isSimulated;

/**
 返回模拟数据(只有DEBUG模式下才起作用)

 @return 模拟数据
 */
- (nullable id)simulatedResponse;

#pragma mark action

/**
 *  设置回调Block，批量请求的时候使用
 *
 *  @param success 请求成功回调
 *  @param failure 请求失败回调
 */
- (void)setCompletionBlockWithSuccess:(KDRequestCompletionBlock _Nullable)success
                              failure:(KDRequestCompletionBlock _Nullable)failure;

/**
 *  开始请求
 */
- (void)start;

/**
 *  发起请求
 *
 *  @param success 请求成功回调
 *  @param failure 请求失败回调
 */
- (void)startCompletionBlockWithSuccess:(KDRequestCompletionBlock _Nullable)success
                                failure:(KDRequestCompletionBlock _Nullable)failure;


/**
 *  停止请求
 */
- (void)stop;

/**
 *  清除successCompletionBlock和failureCompletionBlock
 */
- (void)clearCompletionBlock;

/**
 添加拦截器
 */
- (void)addInterceptor:(id<KDRequestInterceptor>)interceptor;

@end

#pragma mark - KDMultipartFormData -
@protocol KDMultipartFormData <NSObject>
- (BOOL)appendPartWithFileURL:(NSURL *)fileURL
                         name:(NSString *)name
                        error:(NSError * _Nullable __autoreleasing *)error;

- (BOOL)appendPartWithFileURL:(NSURL *)fileURL
                         name:(NSString *)name
                     fileName:(NSString *)fileName
                     mimeType:(NSString *)mimeType
                        error:(NSError * _Nullable __autoreleasing *)error;

- (void)appendPartWithInputStream:(nullable NSInputStream *)inputStream
                             name:(NSString *)name
                         fileName:(NSString *)fileName
                           length:(int64_t)length
                         mimeType:(NSString *)mimeType;

- (void)appendPartWithFileData:(NSData *)data
                          name:(NSString *)name
                      fileName:(NSString *)fileName
                      mimeType:(NSString *)mimeType;

- (void)appendPartWithFormData:(NSData *)data
                          name:(NSString *)name;

- (void)appendPartWithHeaders:(nullable NSDictionary <NSString *, NSString *> *)headers
                         body:(NSData *)body;

- (void)throttleBandwidthWithPacketSize:(NSUInteger)numberOfBytes
                                  delay:(NSTimeInterval)delay;
@end

NS_ASSUME_NONNULL_END
