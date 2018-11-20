//
//  NSURL+Util.h
//  KDFoundation
//
//  Created by hour on 2018/10/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSURL (Util)

+ (NSDictionary *)decodingURL:(NSURL *)url;
+ (NSDictionary *)decodingURLWithString:(NSString *)urlString;

- (BOOL)isYZJDomain;

@end

NS_ASSUME_NONNULL_END
