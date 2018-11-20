//
//  KDJSONModel.h
//  KDNetwork
//
//  Created by Gil on 2016/12/29.
//  Copyright © 2016年 Gil. All rights reserved.
//

#import <JSONModel/JSONModelLib.h>

@interface KDJSONModel : JSONModel
+ (BOOL)propertyIsOptional:(NSString*)propertyName;
+ (NSString *)kd_jsonStringFromModels:(NSArray *)array;

@end
