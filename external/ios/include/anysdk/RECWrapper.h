//
//  RECWrapper.h
//  PluginProtocol
//


#import <Foundation/Foundation.h>
typedef enum
{
    RECRESULT_RECINITSUCCESSS = 0,/**< enum value is callback of succeeding in initing sdk . */
    RECRESULT_RECINITFAIL,/**< enum  value is callback of failing to init sdk. */
    RECRESULT_RECSTARTRECORDING,/**< enum  value is callback of starting to record. */
    RECRESULT_RECSTOPRECORDING,/**< enum  value is callback of stoping to record. */
    RECRESULT_RECPAUSEECORDING,/**< enum  value is callback of pausing to record. */
    RECRESULT_RECRESUMERECORDING,/**< enum  value is callback of resuming to record. */
    RECRESULT_RECENTERSDKPAGE,/**< enum  value is callback of entering SDK`s page. */
    RECRESULT_RECQUITSDKPAGE,/**< enum  value is callback of  quiting SDK`s page. */
    RECRESULT_RECSHARESUCCESS,/**< enum  value is callback of succeeding in sharing. */
    RECRESULT_RECSHAREFAIL,/**< enum  value is callback of failing to share. */
    RECRESULT_RECEXTENSION = 90000 /**< enum value is  extension code . */
} REC_RET_CODE;

@interface RECWrapper : NSObject

/**
 *  The callback interface of REC system
 *
 *  @param pPlugin the REC plugin
 *  @param ret     the code of callback
 *  @param msg     the message of callback
 */
+ (void) onRECResult:(id)pPlugin retCode:(int)ret retMsg:(NSString*)msg;

@end
