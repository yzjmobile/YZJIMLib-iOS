//
//  KDAudioPlayer.h
//  ContactsLite
//
//  Created by Gil on 12-11-29.
//  Copyright (c) 2012年 kingdee eas. All rights reserved.
//

#import <Foundation/Foundation.h>

@class KDAudioPlayer;
@protocol KDAudioPlayerDelegate <NSObject>

@optional
//播放开始
- (void)audioDidBegin:(KDAudioPlayer *)audioPlayer;
//播放暂停
- (void)audioDidPause:(KDAudioPlayer *)audioPlayer;
//播放停止
- (void)audioDidStop:(KDAudioPlayer *)audioPlayer;
//播放结束
- (void)audioDidFinish:(KDAudioPlayer *)audioPlayer;
//播放错误
- (void)audioDidError:(KDAudioPlayer *)audioPlayer;
//播放被打断
- (void)audioDidInterrupt:(KDAudioPlayer *)audioPlayer;

//播放消息语音结束
- (void)chatAudioDidFinish:(KDAudioPlayer *)audioPlayer;

@end

@interface KDAudioPlayer : NSObject

@property (nonatomic, assign) BOOL isInContinuouslyPlayingMode; // 是否连续播放语音，关系到，凑近黑屏的功能开关时机

@property (nonatomic, weak) id<KDAudioPlayerDelegate> audioPlayerDelegate;

@property (readonly, getter=isPlaying) BOOL playing;

+(KDAudioPlayer *)sharedAudioPlayer;

//开始播放
- (void)startWithData:(NSData *)fileData;
//停止播放
- (void)stop;
//暂停播放
- (void)pause;
//继续播放
- (void)resume;



@end
