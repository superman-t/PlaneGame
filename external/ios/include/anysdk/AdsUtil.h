//
//  AdsUtil.h
//  PluginProtocol
//
//  Created by cocos2dx on 14-9-23.
//  Copyright (c) 2014年 cocos2dx. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AdsUtil : NSObject

/**
 *  get the parameters of ads system in special case
 *
 *  @return return the parameters
 */
+ (NSMutableDictionary*)getAdsParams;

@end
