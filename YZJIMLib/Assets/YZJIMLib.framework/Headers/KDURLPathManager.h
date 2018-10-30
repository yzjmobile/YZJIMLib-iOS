//
//  KDURLPathManager.h
//  kdweibo
//
//  Created by Gil on 15/1/21.
//  Copyright (c) 2015年 www.kingdee.com. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * _Nullable const KDURLChangeNotification;

//这个数字不能修改，否则会导致现有用户出问题。
typedef NS_ENUM(NSUInteger, KDURLType) {
    KDURLTypeProduction = 1,
    KDURLTypeKDTest = 2,
    KDURLTypeDev = 3,
    KDURLTypeDevTest = 4,
//    KDURLTypeRedPacket = 6,//临时红包调试环境
    
    KDURLTypeCustom = 100,//自定义环境
};

#define KD_URLPathManager [KDURLPathManager sharedURLPathManager]
@interface KDURLPathManager : NSObject

+ (nonnull instancetype)sharedURLPathManager;

// 启动时初始化
- (void)setupBaseUrl:(NSString * _Nonnull)baseUrl imgBaseUrl:(NSString * _Nonnull)imgBaseUrl;

- (nonnull NSString *)baseUrl;
- (nonnull NSString *)baseUrlWithoutTLS;
- (nonnull NSString *)imageBaseUrl;

//======环境切换  不支持专有云==========
@property (assign, nonatomic) KDURLType urlType;

- (NSString *_Nullable)urlTypeText;//Test、Dev
- (NSString *_Nullable)urlTypeDesc;

- (nonnull NSArray *)urlTypeDescList;
- (KDURLType)urlTypeWithDesc:(NSString *_Nullable)desc;

- (void)setCustomHttpUrl:(NSString *_Nullable)httpUrl wsUrl:(NSString *_Nullable)wsUrl;
- (void)clearCustomUrl;

@end
