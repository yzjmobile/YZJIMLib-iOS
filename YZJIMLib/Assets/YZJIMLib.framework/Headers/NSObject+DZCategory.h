//
//  NSObject+DZCategory.h
//  Meidaojia
//
//  Created by Darren on 15/5/24.
//  Copyright (c) 2015年 Darren Zheng. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSObject (DZCategory)

// kvc
- (BOOL)kd_dz_hasKey:(NSString *)strKey; // 注意不是dict
- (void)kd_dz_setValue:(id)value forKey:(NSString *)key;
- (id)kd_dz_modelWithDictionary:(NSDictionary *)dict except:(NSArray *)array;
@end
