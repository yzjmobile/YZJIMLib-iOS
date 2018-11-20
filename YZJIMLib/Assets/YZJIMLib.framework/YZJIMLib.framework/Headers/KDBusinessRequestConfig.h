//
//  KDBusinessRequestConfig.h
//  AFNetworking
//
//  Created by hour on 2018/9/3.
//

#import <Foundation/Foundation.h>

@interface KDBusinessRequestConfig : NSObject

+ (instancetype)sharedConfig;

// 是否打印Log
@property (assign, nonatomic) BOOL networkLogEnable;
    
//  [BOSConfig sharedConfig].user.token
@property (copy, nonatomic) NSString *userOpenToken;
// [BOSConfig sharedConfig].user.oauthToken
@property (copy, nonatomic) NSString *userOauthToken;

// [BOSConfig sharedConfig].user.oauthTokenSecret]
@property (copy, nonatomic) NSString *userOauthTokenSecret;

//
//#define KD_APP_OAUTH_KEY (([UIDevice isiPadDevice]) ? KD_DEFAULT_OAUTH_CONSUMER_KEY_IPAD : KD_DEFAULT_OAUTH_CONSUMER_KEY)
//#define KD_APP_OAUTH_SECRET (([UIDevice isiPadDevice]) ? KD_DEFAULT_OAUTH_CONSUMER_SECRET_IPAD : KD_DEFAULT_OAUTH_CONSUMER_SECRET)
@property (copy, nonatomic) NSString *kdAppOauthKey;
@property (copy, nonatomic) NSString *kdAppOauthSecret;

    


@end
