//
//  ShareWrapper.h
//  PluginProtocol
//
//  Created by cocos2dx on 14-11-12.
//  Copyright (c) 2014年 zhangbin. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum
{
    SHARERESULT_SUCCESS = 0,/**< enum value is callback of failing to sharing . */
    SHARERESULT_FAIL,/**< enum value is callback of failing to share . */
    SHARERESULT_CANCEL,/**< enum value is callback of canceling to share . */
    SHARERESULT_NETWORK_ERROR, /**< enum value is callback of network error . */
    SHARERESULT_SHAREEXTENSION = 10000 /**< enum value is  extension code . */
} SHARE_RET_CODE;

@interface ShareWrapper : NSObject

/**
 *  The callback interface of share system
 *
 *  @param pPlugin the share plugin
 *  @param ret     the code of callback
 *  @param msg     the message of callback
 */
+ (void) onShareResult:(id)pPlugin retCode:(int)ret retMsg:(NSString*)msg;

@end
