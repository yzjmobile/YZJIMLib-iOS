//
//  KDNetworkPrivate.h
//  Pods
//
//  Created by Gil on 2017/8/3.
//
//

#import <Foundation/Foundation.h>
#import "KDNetworkManager.h"
#import "KDRequest.h"
#import "KDResponse.h"

NS_ASSUME_NONNULL_BEGIN

@interface KDNetworkUtils : NSObject

+ (BOOL)validateResumeData:(NSData *)data;
+ (NSString *)md5StringFromString:(NSString *)string;

@end

@interface KDRequest (Setter)

@property (strong, nonatomic, readwrite) NSURLSessionTask *requestTask;
@property (strong, nonatomic, readwrite, nullable) id resultModel;
@property (strong, nonatomic, readwrite, nullable) NSArray *resultModels;

@end

@interface KDRequest (Interceptor)
- (void)interceptorAtRequestWillStart;
- (void)interceptorAtRequestWillStop;
- (void)interceptorAtRequestDidStop;
- (void)interceptorAtRequestDidFinished;
@end

@interface KDNetworkManager (ServerDate)

- (NSDate *)serverDate;
- (NSTimeInterval)serverDateDelta;

@end

NS_ASSUME_NONNULL_END
