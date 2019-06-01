//
//  CustomWrapper.h
//  PluginProtocol
//
//

#import <Foundation/Foundation.h>

typedef enum
{
    CUSTOMRESULT_CUSTOMEXTENSION = 80000 /**< enum value is  extension code . */
} CUSTOM_RET_CODE;

@interface CustomWrapper : NSObject

/**
 *  The callback interface of Custom system
 *
 *  @param pPlugin the Custom plugin
 *  @param ret     the code of callback
 *  @param msg     the message of callback
 */
+ (void) onCustomResult:(id)pPlugin retCode:(int)ret retMsg:(NSString*)msg;

@end
