//
//  PluginWrapper.h
//  PluginProtocol
//
#import <UIKit/UIKit.h>

#import <Foundation/Foundation.h>
#import "PluginApplicationDelegate.h"
@interface PluginWrapper : NSObject

@property (nonatomic, strong) NSMutableArray * arrayDelegate;

+ (PluginWrapper*) getInstance;

- (void) setDelegate:(id<PluginApplicationDelegate>)delegate;

//about user system

- (void)applicationDidEnterBackground:(UIApplication *)application ;
- (void)applicationWillEnterForeground:(UIApplication *)application ;

//about iap system
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation ;

- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url;


//about push system
- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken ;

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo ;

- (void)application:(UIApplication *)application handleActionWithIdentifier:(NSString *)identifier forRemoteNotification:(NSDictionary *)userInfo completionHandler:(void(^)())completionHandler ;

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult result))completionHandler;

@end
