//
//  AnalyticsWrapper.h
//  PluginProtocol
//
//  Created by cocos2dx on 14-10-9.
//  Copyright (c) 2014年 cocos2dx. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    ACCOUNT_TYPE_ANONYMOUS,/**< enum value is anonymous typek. */
    ACCOUNT_TYPE_REGISTED,/**< enum value is registed type. */
    ACCOUNT_TYPE_SINA_WEIBO,/**< enum value is sineweibo type. */
    ACCOUNT_TYPE_TENCENT_WEIBO,/**< enum value is tecentweibo type */
    ACCOUNT_TYPE_QQ,/**< enum value is qq type */
    ACCOUNT_TYPE_ND91,/**< enum value is nd91 type. */
} ANALYTICS_ACCOUNT_TYPE;

typedef enum {
    ACCOUNT_OPERATE_LOGIN,/**< enum value is the login operate. */
    ACCOUNT_OPERATE_LOGOUT,/**< enum value is the logout operate. */
    ACCOUNT_OPERATE_REGISTER,/**< enum value is the register operate. */
}ANALYTICS_ACCOUNT_OPERATE;

typedef enum {
    ACCOUNT_GENDER_MALE,/**< enum value is male. */
    ACCOUNT_GENDER_FEMALE,/**< enum value is female. */
    ACCOUNT_GENDER_UNKNOWN,/**< enum value is unknow. */
    
} ANALYTICS_ACCOUNT_GENDER;

typedef enum {
    TASK_TYPE_GUIDE_LINE,/**< enum value is the guideline type.. */
    TASK_TYPE_MAIN_LINE,/**< enum value is the mainline type.. */
    TASK_TYPE_BRANCH_LINE,/**<enum value is the branchline type.. */
    TASK_TYPE_DAILY,/**< enum value is the daily type.. */
    TASK_TYPE_ACTIVITY,/**< enum value is the activity type.  */
    TASK_TYPE_OTHER,/**< enum value is other type. */
} ANALYTICS_TASK_TYPE;

