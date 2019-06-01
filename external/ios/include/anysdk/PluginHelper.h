//
//  PluginHelper.h
//  PluginProtocol
//
//  Created by cocos2dx on 14-8-29.
//  Copyright (c) 2014年 cocos2dx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface PluginHelper : NSObject

/**
 *  get the parameters of SDK
 *
 *  @return the parameters of SDK
 */
+ (NSMutableDictionary*) getParamsInfo;

/**
 *
 * @Title: getDebugModeStatus
 * @Description: get the status of DebugMode
 * @param @return status
 * @return BOOL yes or no
 */
+ (BOOL) getDebugModeStatus;

/**
 *
 * @Title: getLogLevel
 * @Description: get the level of log
 * @param @return level
 * @return "verbose" "debug" "info" "warning" "error"
 */
+ (NSString*) getLogLevel;

/**
 *  get the status of network
 *
 *  @return if the network is reachable ,return true
 or if the network is reachable,return false
 */
+ (BOOL) networkReachable;

/**
 *  get current RootViewController
 *
 *  @return RootViewController
 */
+ (UIViewController *)getCurrentRootViewController;

/**
 *  network transmission in plugin
 *
 *  @param data   content transmitted over the network
 *  @param target callback object
 *  @param sel    callback function
 *  @note the content must contain the value that key is  "server_url"
 *  @note http use post
 */
+ (void) pluginHttp:(NSMutableDictionary*)data target:(id)target sel:(SEL)sel;

/**
 *  log output ，the lever is verbose
 *
 *  @param message the message about this log
 */
+ (void) logVerbose:(NSString*)format,...;

/**
 *   log output ，the lever is error
 *
 *  @param message the message about this log
 */
+ (void) logError:(NSString*)format,...;


/**
 *   log output ，the lever is debug
 *
 *  @param message the message about this log
 */
+ (void) logDebug:(NSString*)format,...;

/**
 *   log output ，the lever is info
 *
 *  @param message the message about this log
 */
+ (void) logInfo:(NSString*)format,...;

/**
 *  get the game identifier
 *
 *  @return name
 */
+ (NSString*) getGameId;

/**
 *  get the application name
 *
 *  @return name
 */
+ (NSString*) getApplicationName;

/**
 *  get the application orientation
 *
 *  @return multiple orientation
 */
+ (NSArray*) getApplicationOrientation;


/**
 *  get the application version
 *
 *  @return version
 */
+ (NSString*) getApplicationVersion;

/**
 *  Parsing XML file
 *  @param the name of XML file
 *  @return NSMutableDictionary the content of XML file
 */
+ (NSMutableDictionary*) getXMLInfoByFileName:(NSString*)fileName;

@end