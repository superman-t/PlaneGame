//
//  Wrapper.h
//  PluginProtocol
//
//  Created by cocos2dx on 14-8-29.
//  Copyright (c) 2014年 cocos2dx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CocosRuntimeDelegate.h"

@interface Wrapper : NSObject

/**
 *  init developer.xml
 */
+ (void) analysisDeveloperInfo;

/**
 *  check application
 *
 *  @param appKey           the value of appkey from AnySDK Client
 *  @param appSeceret       the value of appSeceret from AnySDK Client
 *  @param privateKey       the value of privateKey from AnySDK Client
 *  @param oauthLoginServer the value of appkey from AnySDK Client
 */
+ (void) setAppParam:(const char*)appKey AppSecret:(const char*)appSeceret PrivateKey:(const char*)privateKey OauthLoginServer:(const char*)oauthLoginServer;

/**
 *  get the parameters of SDK
 *
 *  @return the parameters of SDK
 */
+ (NSMutableDictionary*) getDeveloperInfo;

/**
 *  get the information of channel
 *
 *  @return the information of channel
 */
+ (NSMutableDictionary*) getChannelInfo;

/**
 *  get the information of game
 *
 *  @return  the information of game
 */
+ (NSMutableDictionary*) getGameInfo;

/**
 *  get the information of plugin
 *
 *  @return the information of plugin
 */
+ (NSMutableDictionary*) getPluginInfo;

/**
 *  get the information of tool
 *
 *  @return the information of tool
 */
+ (NSMutableDictionary*) getToolInfo;

/**
 *  get support for plug-ins
 *
 *  @return  support for plug-ins 
 */
+ (NSMutableArray*) getSupportForPlugins;

/**
 *  NSMutableDictionary  change to NSString
 *
 *  @param dict NSMutableDictionary value
 *
 *  @return NSString value
 */
+ (NSString*)dictToNSString:(NSMutableDictionary*)dict;

/**
 * get the identifier of value
 *
 *  @return the identifier of value
 */
+ (NSString*)getChannelId;

/**
 *  get custom parameter from AnySDK Client
 *
 *  @return return value description
 */
+ (NSString*) getCustomParam;

+ (BOOL)networkReachable;

+ (NSString*) replaceNotifyURL:(Class)class1 url:(NSString*)url;

+ (void)reset;

//about cocos runtime
+ (id<CocosRuntimeSDKDelegate>)getCocosRuntimeSDKProxy;

+ (void)setCocosRuntimeSDKProxy:(id<CocosRuntimeSDKDelegate>)runtimeProxy;

+ (int)getCocosRuntimeSDKVersionCode;

+ (void)setCocosRuntimeSDKVersionCode:(int)sdkVersionCode;


@end
