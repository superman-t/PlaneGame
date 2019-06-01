//
//  UserWrapper.h
//  PluginProtocol
//
//  Created by cocos2dx on 14-9-4.
//  Copyright (c) 2014年 cocos2dx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "InterfaceUser.h"


typedef enum
{
    ACTION_RET_INIT_SUCCESS = 0,/**< enum value is callback of succeeding in initing sdk. */
    ACTION_RET_INIT_FAIL,/**< enum  value is callback of failing to init sdk. */
    ACTION_RET_LOGIN_SUCCESS,/**< enum value is callback of succeeding in login.*/
    ACTION_RET_LOGIN_TIMEOUT,/**< enum value is callback of network error*/
    ACTION_RET_LOGIN_NO_NEED,/**< enum value is callback of no need login.*/
    ACTION_RET_LOGIN_FAIL,/**< enum value is callback of failing to login. */
    ACTION_RET_LOGIN_CANCEL,/**< enum value is callback of canceling to login. */
    ACTION_RET_LOGOUT_SUCCESS,/**< enum value is callback of succeeding in logout. */
    ACTION_RET_LOGOUT_FAIL,/**< enum value is callback of failing to logout. */
    ACTION_RET_PLATFORM_ENTER,/**< enum value is callback after enter platform. */
    ACTION_RET_PLATFORM_BACK,/**< enum value is callback after exit antiAddiction. */
    ACTION_RET_PAUSE_PAGE,/**< enum value is callback after exit pause page. */
    ACTION_RET_EXIT_PAGE,/**< enum value is callback after exit exit page. */
    ACTION_RET_ANTIADDICTIONQUERY,/**< enum value is callback after querying antiAddiction. */
    ACTION_RET_REALNAMEREGISTER,/**< enum value is callback after registering realname. */
    ACTION_RET_ACCOUNTSWITCH_SUCCESS,/**< enum value is callback of succeeding in switching account. */
    ACTION_RET_ACCOUNTSWITCH_FAIL,/**< enum value is callback of failing to switch account. */
    ACTION_RET_OPENSHOP,/**< enum value is callback of open the shop. */
    ACTION_RET_ACCOUNTSWITCH_CANCEL,/**< enum value is callback of canceling to switch account. */
    ACTION_RET_GAME_EXIT_PAGE,/**< enum value is callback of no channel exit page. */
    ACTION_RET_USEREXTENSION = 50000 /**< enum value is  extension code . */
    
} USER_RET_CODE;

@interface UserWrapper : NSObject
/**
 *  The callback interface of user system
 *
 *  @param pPlugin the user plugin
 *  @param ret     the code of callback
 *  @param msg     the message of callback
 */
+ (void) onActionResult:(id)pPlugin retCode:(int)ret retMsg:(NSString*)msg;

/**
 *  The login authentication
 *
 *  @param data   the parameters
 *  @param target target description
 *  @param sel    sel description
 */
+ (void) getAccessToken:(NSMutableDictionary*)data target:(id)target sel:(SEL)sel;

/**
 *
 * @Title: relaceLoginOauthURL
 * @Description:According to server,it changes login oauth url http://changed_host/
 * @return replace url
 */
+ (NSString*)replaceLoginOauthURL:url;


@end

