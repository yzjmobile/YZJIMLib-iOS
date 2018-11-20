//
//  KDVideoCompressUtil.h
//  kdweibo
//
//  Created by Darren Zheng on 2017/4/25.
//  Copyright © 2017年 www.kingdee.com. All rights reserved.
//

@interface KDVideoCompressUtil : NSObject
+ (void)convertVideoToLowQuailtyWithInputURL:(NSURL*)inputURL
                                   outputURL:(NSURL*)outputURL
                                   comletion:(void (^)(void))completion;
@end
