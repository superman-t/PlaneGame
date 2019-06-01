//
//  AdsWrapper.h
//  PluginProtocol
//
//  Created by cocos2dx on 14-8-29.
//  Copyright (c) 2014年 cocos2dx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum
{
    RESULT_CODE_AdsReceived = 0,    // The ad is received
    RESULT_CODE_AdsShown, // The advertisement shown
    RESULT_CODE_AdsDismissed, // The advertisement
    // dismissed
    RESULT_CODE_PointsSpendSucceed, // The points
    // spend succeed
    RESULT_CODE_PointsSpendFailed, // The points
    // spend failed
    RESULT_CODE_NetworkError, // Network error
    RESULT_CODE_UnknownError, // Unknown error
    RESULT_CODE_OfferWallOnPointsChanged, // Change the point of offerwall
    RESULT_CODE_RewardedVideoWithReward,//the callback of receiving the reward of rewardedvideo
    RESULT_CODE_InAppPurchaseFinished,////the callback of finishing IAP ad
    RESULT_CODE_AdsClicked, //the callback of the advertisement clicked
    RESULT_CODE_ADSEXTENSION = 40000  //ads extension code
    
}AD_RET_CODE;

typedef enum
{
    AD_TYPE_BANNER = 0,/**< enum value is banner ads . */
    AD_TYPE_FULLSCREEN,/**< enum value is fullscreen ads . */
    AD_TYPE_MOREAPP,/**< enum value is moreapp ads . */
    AD_TYPE_OFFERWALL, /**< enum value is offerwall ads . */
    AD_TYPE_REWARDEDVIDEO,/**< enum value is rewarded video ads . */
    AD_TYPE_NATIVEEXPRESS,/**< enum value is Native express  ads . */
    AD_TYPE_NATIVEADVANCED/**< enum value is Native advanced  ads . */
} ADS_TYPE;
typedef enum
{
    POS_CENTER = 0,/**< enum the toolbar is at center. */
    POS_TOP,/**< enum the toolbar is at top. */
    POS_TOP_LEFT,/**< enum the toolbar is at topleft. */
    POS_TOP_RIGHT,/**< enum the toolbar is at topright. */
    POS_BOTTOM,/**< enum the toolbar is at bottom. */
    POS_BOTTOM_LEFT,/**< enum the toolbar is at bottomleft. */
    POS_BOTTOM_RIGHT/**< enum the toolbar is at bottomright. */
    
}AD_POS;

@interface AdsWrapper : NSObject

/**
 *  get current RootViewController
 *
 *  @return RootViewController
 */
+ (UIViewController *)getCurrentRootViewController;

/**
 * get top window
 *
 *  @return return top window
 */
+ (UIWindow*) getTopWindow;

/**
 *  The callback interface of pay system
 *
 *  @param pPlugin the pay plugin
 *  @param ret     the code of callback
 *  @param msg     the message of callback
 */
+ (void)onAdsResult:(id)target retCode:(int)code msg:(NSString*)msg;

/**
 *  add ad view
 *
 *  @param view view
 *  @param pos  position
 */
+ (void) addAdView:(UIView*) view atPos:(AD_POS) pos;

/**
 *  get the name of the advertising types
 *
 *  @param adType the type of the advertising
 *
 *  @return the name of the advertising types
 */
+ (NSString*)getAdNameWithType:(int)adType;

@end
