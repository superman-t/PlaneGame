/** @file ProtocolREC.h
 */
#ifndef  __CCX_PROTOCOL_REC_H__
#define  __CCX_PROTOCOL_REC_H__

#include "PluginProtocol.h"
#include <map>
#include <string>

namespace anysdk { namespace framework {

typedef std::map<std::string, std::string> TVideoInfo;

/** @brief RECResultCode enum, with inline docs */
typedef enum 
{
	kRECInitSuccess = 0,/**< enum value is callback of succeeding in initing sdk . */
	kRECInitFail,/**< enum  value is callback of failing to init sdk. */
	kRECStartRecording,/**< enum  value is callback of starting to record. */
	kRECStopRecording,/**< enum  value is callback of stoping to record. */
	kRECPauseRecording,/**< enum  value is callback of pausing to record. */
	kRECResumeRecording,/**< enum  value is callback of resuming to record. */
	kRECEnterSDKPage,/**< enum  value is callback of entering SDK`s page. */
	kRECQuitSDKPage,/**< enum  value is callback of  quiting SDK`s page. */
	kRECShareSuccess,/**< enum  value is callback of succeeding in sharing. */
	kRECShareFail,/**< enum  value is callback of failing to share. */
    kRECExtension = 90000 /**< enum value is  extension code . */
} RECResultCode;
/**   
 *@class  RECResultListener
 *@brief the interface of REC callback  
 */
class RECResultListener
{
public:
	/**   
	 *@brief the interface of REC callback 
	 *@param the id of callback
	 *@param the information of callback
	 */
    virtual void onRECResult(RECResultCode ret, const char* msg) = 0;
};
/**   
 *@class  ProtocolREC
 *@brief the interface of REC  
 */
class ProtocolREC : public PluginProtocol
{
public:

	/**
	* @Description: Start to record video
	*/
	virtual void startRecording() = 0;

	/**
	* @Description: Stop to record video
	*/
	virtual void stopRecording() = 0;

	/**
	* @Description: share video
	* @Param info The info of share
	*/
	virtual void share(TVideoInfo info) = 0;



    /**
    @breif set the result listener
    @param pListener The callback object for REC result
    @wraning Must invoke this interface before REC
    */
    virtual void setResultListener(RECResultListener* pListener) = 0;

    virtual RECResultListener* getRECListener() = 0;


};

}} // namespace anysdk { namespace framework {

#endif   /* ----- #ifndef __CCX_PROTOCOL_SHARE_H__ ----- */
