//
//  PushWrapper.h
//  PluginProtocol
//
//  Created by cocos2dx on 14-10-9.
//  Copyright (c) 2014年 cocos2dx. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum
{
    ACTION_RET_RECEIVEMESSAGE = 0,/**value is callback of Receiving Message . */
    ACTION_RET_PUSHEXTENSION = 60000 /**value is extension code . */
} PUSH_RET_CODE;

@interface PushWrapper : NSObject

/**
 *  the callback interface of push system
 *
 *  @param pPlugin the push plugin
 *  @param ret     the code of callback
 *  @param msg     the message of callback
 */
+ (void) onActionResult:(id)pPlugin retCode:(int)ret retMsg:(NSString*)msg;

@end
