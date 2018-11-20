//
//  KDError.h
//  KDNetwork
//
//  Created by Gil on 2016/12/23.
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSInteger const KDDataParseErrorCode;

@interface KDError : NSObject

@property (assign, nonatomic) NSInteger errorCode;
@property (strong, nonatomic) NSString *errorMessage;

- (instancetype)initWithHTTPStatusCode:(NSInteger)httpStatusCode;

- (instancetype)initWithErrorCode:(NSInteger)errorCode
                     errorMessage:(nullable NSString *)errorMessage;

@end

NS_ASSUME_NONNULL_END
