//
//  SocialWrapper.h
//  PluginProtocol
//
//  Created by cocos2dx on 14-10-9.
//  Copyright (c) 2014年 cocos2dx. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum
{
    // code for leaderboard feature
    SOCIAL_SUBMITSCORE_SUCCEED = 0,/**< enum value is callback of succeeding in submiting. */
    SOCIAL_SUBMITSCORE_FAIL,/**< enum value is callback of failing to submit . */
    // code for achievement feature
    SOCIAL_UNLOCKACH_SUCCEED,/**< enum value is callback of succeeding in unlocking. */
    SOCIAL_UNLOCKACH_FAIL,/**< enum value is callback of failing to  unlock. */
    SOCIAL_SIGNIN_SUCCEED,/**< enum value is callback of succeeding to login. */
    SOCIAL_SIGNIN_FAIL,/**< enum value is callback of failing to  login. */
    SOCIAL_SIGNOUT_SUCCEED,/**< enum value is callback of succeeding to login. */
    SOCIAL_SIGNOUT_FAIL ,/**< enum value is callback of failing to  login. */
    SOCIAL_GET_GAME_FRIENDS,/**< enum value is callback of getGameFriends. */
    SOCIAL_SOCIALEXTENSION  = 20000/**< enum value is  extension code . */
} SOCIAL_RET_CODE;

@interface SocialWrapper : NSObject

/**
 *  The callback interface of social system
 *
 *  @param pPlugin the social plugin
 *  @param ret     the code of callback
 *  @param msg     the message of callback
 */
+ (void) onSocialResult:(id)pPlugin retCode:(int)ret retMsg:(NSString*)msg;

@end
