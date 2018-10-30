//
//  ExtensionShareDataUtils.h
//  kdweibo
//
//  Created by shifking on 15/9/7.
//  Copyright (c) 2015年 www.kingdee.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ExtensionShareDataUtils : NSObject

+ (void)setShareExtensionObject:(NSObject *)obj forKey:(NSString *)key;
+ (id)getShareExtensionObjectByKey:(NSString *)key;

+ (NSString *)getAppToken;
+ (void)setAppToken:(NSString *)token;


+ (void)setUserId:(NSString *)userId;
+ (NSString *)getUserId;

+ (void)setDefaultUserAgent:(NSString *)userAgent;
+ (NSString *)getDefaultUserAgent;

+ (NSString *)getAppGroupName;


#pragma mark - 默认配置 -
//文件组id
+ (void)setFilePersonId:(NSString *)fileId;
+ (NSString *)getFilePersonId;

//发送消息
+ (void)setMessageSendUrl:(NSString *)msgSendUrl;
+ (NSString *)getMessageSendUrl;

//发送文件
+ (void)setFileSendUrl:(NSString *)sendUrl;
+ (NSString *)getFileSendUrl;

+ (void)setBaseUrl:(NSString *)baseUrl;
+ (NSString *)getBaseUrl;

//标记文件url
+ (void)setForwardDocUrl:(NSString *)forwardDocUrl;
+ (NSString *)getForwardDocUrl;

//上传到企业云盘url
+ (void)setSaveToCloudUrl:(NSString *)saveToCloudUrl;
+ (NSString *)getSaveToCloudUrl;
//当前工作圈id
+ (void)setNetworkId:(NSString *)networkId;
+ (NSString *)getNetworkId;

//上传文件url
+ (void)setUploadFileUrl:(NSString *)uploadFileUrl;
+ (NSString *)getUploadFileUrl;

// 会话组更新时间
+ (void)setGroupListUpdateTime:(NSString *)updateTime;
+ (NSString *)getGroupListUpdateTime;

// 新消息缓存
+ (void)setNewMessageDict:(NSDictionary *)messageDict;
+ (NSDictionary *)getNewMessageDict;

@end
