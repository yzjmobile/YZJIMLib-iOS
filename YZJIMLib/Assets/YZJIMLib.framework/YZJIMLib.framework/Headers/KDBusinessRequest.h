//
//  KDBusinessRequest.h
//  kdweibo
//
//  Created by Gil on 2016/12/25.
//  Copyright © 2016年 www.kingdee.com. All rights reserved.
//

#if __has_include("KDRequest.h")
#import "KDRequest.h"
#else
#import <KDNetwork/KDRequest.h>
#endif
@interface KDBusinessRequest : KDRequest

- (NSDictionary *)requestHTTPHeaderField;

@end
