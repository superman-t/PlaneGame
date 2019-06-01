//
//  SdkHttpListener.h
//  PluginProtocol
//
//  Created by cocos2dx on 14-9-9.
//  Copyright (c) 2014年 cocos2dx. All rights reserved.
//

#import <Foundation/Foundation.h>

//@protocol  <NSObject>
@protocol SdkHttpListener <NSObject>

/**
 *  network response
 *
 *  @param response the response message
 */
- (void) onResponse:(NSString*)response;

/**
 *  network return error
 */
- (void) onError;

@end
