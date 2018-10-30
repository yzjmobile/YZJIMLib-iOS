//
//  KDAudioStreamRecorder.h
//  kdweibo
//
//  Created by 钟伟杰 on 2017/8/24.
//  Copyright © 2017年 www.kingdee.com. All rights reserved.
//

//#pragma clang diagnostic ignored "-Wdocumentation"
#import <UIKit/UIKit.h>

static const NSInteger KDAudioSampleRate = 16000;    // 采样率
static const NSInteger KDAudioBits       = 16;       // 比特率
static const NSInteger KDAudioChannel    = 1;        // 声道数

@class KDAudioStreamRecorder;

// 录放音类型
typedef NS_ENUM (NSInteger,RecordCode)
{
    Record_No_Error = 0,                // 正常
    Record_NO_Hardware_Error,            // 无录音设备
    Record_Safari_Error,                // 不支持Safari
    Record_Using_Error                  // 正在录音
};

//录音器委托
@protocol KDAudioStreamRecorderDelegate<NSObject>

@optional
/**
 *	@function	onReturnBuffer
 *	@abstract	录音数据回调
 *	@discussion
 *	@param
 */
- (void)onReturnBuffer:(KDAudioStreamRecorder *)recorder buffer:(Byte *)buffer bufferSize:(int)size;


/**
 *	@function	onError
 *	@abstract	录音中出错回调
 *	@discussion
 *	@param
 */
- (void)onError:(KDAudioStreamRecorder *)recorder theRecordCode:(RecordCode)error;

//该回调方法用于获取音量
- (void)getPeakPower:(KDAudioStreamRecorder *)recorder peakPower:(float)peakPower;

//该回调方法用于录音完成的回调
- (void)onFinishRecord:(KDAudioStreamRecorder *)recorder;

@end

//录音器
@interface KDAudioStreamRecorder : NSObject

@property (nonatomic, weak) id<KDAudioStreamRecorderDelegate> recorderDelegate;    //录音器委托属性
@property (nonatomic, strong) NSString *recordPath;                                 //录音路径

/**
 *	@function	start
 *	@abstract	开始录音
 *	@discussion
 *	@param
 */
- (RecordCode)start;

/**
 *	@function	stop
 *	@abstract	停止录音
 *	@discussion
 *	@param
 */
- (void)stop;

/**
 *	@function	isRecording
 *	@abstract	是否正在录音
 *	@discussion
 *	@param
 */
- (BOOL)isRecording;

@end

