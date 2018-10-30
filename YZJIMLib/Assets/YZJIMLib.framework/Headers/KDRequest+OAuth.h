//
//  KDRequest+OAuth.h
//  KDNetwork
//
//  Created by Gil on 16/8/17.
//
//

#import "KDRequest.h"

@interface KDRequest (OAuth)


/**
 OAuth 1.0签名，使用"HMAC-SHA1"算法签名

 @param clientIdentifier 客户端Key
 @param clientSecret     客户端Secret
 @param tokenIdentifier  用户Token
 @param tokenSecret      用户TokenSecret
 */
- (void)signRequestWithClientIdentifier:(NSString *)clientIdentifier
                           clientSecret:(NSString *)clientSecret
                        tokenIdentifier:(NSString *)tokenIdentifier
                            tokenSecret:(NSString *)tokenSecret;

@end
