//
//  IAPWrapper.h
//  PluginProtocol
//
//  Created by cocos2dx on 14-9-9.
//  Copyright (c) 2014年 cocos2dx. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef enum
{
    PAYRESULT_SUCCESS = 0,/**< enum value is callback of succeeding in paying . */
    PAYRESULT_FAIL,/**< enum value is callback of failing to pay . */
    PAYRESULT_CANCEL,/**< enum value is callback of canceling to pay . */
    PAYRESULT_NETWORK_ERROR,/**< enum value is callback of network error . */
    PAYRESULT_PRODUCTIONINFOR_INCOMPLETE,/**< enum value is callback of incompleting info . */
    PAYRESULT_INIT_SUCCESS,/**< enum value is callback of succeeding in initing sdk . */
    PAYRESULT_INIT_FAIL,/**< enum value is callback of failing to init sdk . */
    PAYRESULT_NOW_PAYING,/**< enum value is callback of paying now . */
    PAYRESULT_PAYEXTENSION = 30000 /**< enum value is  extension code . */
} PAY_RET_CODE;

typedef enum
{
    REQUESTRESULT_SUCCESS = 31000,/**< enum value is callback of succeeding in paying . */
    REQUESTRESULT_FAIL/**< enum value is callback of failing to pay . */
} REQUEST_RET_CODE;

@interface IAPWrapper : NSObject

/**
 *  get the identifier of order
 *
 *  @param orderInfo payment info
 *  @param target    callback object
 *  @param action    callback function
 */
+ (void)getPayOrderId:(NSMutableDictionary*)orderInfo target:(id)target action:(SEL)action;

/**
 *  get order info
 *
 *  @param productInfo product info
 *  @param user        identifier of user
 *
 *  @return order info
 */
+ (NSMutableDictionary*) getOrderInfo:(NSMutableDictionary*)productInfo userID:(NSString*)user;
 /**
 *  The callback interface of pay system
 *
 *  @param pPlugin the pay plugin
 *  @param ret     the code of callback
 *  @param msg     the message of callback
 */
+ (void)onPayResult:(id)pPlugin retCode:(int)ret retMsg:(NSString*)msg;

/**
 *  The callback interface of social system
 *
 *  @param pPlugin the social plugin
 *  @param ret     the code of callback
 *  @param msg     the message of callback
 */
+ (void)onPayResult:(id)pPlugin retCode:(int)ret products:(NSMutableDictionary*)products;

/**
 *  process the notify url
 *
 *  @param class1 plugin
 *  @param url    the source url
 *
 *  @return the destination url
 */
+ (NSString*) replaceNotifyURL:(Class)class1 url:(NSString*)url;

/**
 *  process the  EE Domain
 *
 *  @param domain
 *
 *  @return void
 */
+ (void)replaceEEDomain:(NSString*)domain;

@end
