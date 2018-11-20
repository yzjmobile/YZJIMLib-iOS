//
//  NSFileManager+FileSize.h
//  kdweibo
//
//  Created by tangzeng on 2017/11/2.
//  Copyright © 2017年 www.kingdee.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSFileManager (FileSize)
- (NSNumber *)kd_fileSizeWithFilePath: (NSString *)filePath;
@end
