#ifndef __CRT_SDK_DELEGATE_H
#define __CRT_SDK_DELEGATE_H

#import <Foundation/Foundation.h>

@protocol CocosRuntimeSDKDelegate <NSObject>

- (NSMutableArray*)getSupportForPlugins;
- (NSMutableDictionary*)getPluginParams;
- (NSString*)getDevelopInfo;

@end

#endif /* __CRT_SDK_DELEGATE_H */
