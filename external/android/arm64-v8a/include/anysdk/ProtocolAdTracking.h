/** @file ProtocolAdTracking.h
 */
#ifndef  __CCX_PROTOCOL_ADTRACKING_H__
#define  __CCX_PROTOCOL_ADTRACKING_H__

#include "PluginProtocol.h"
#include <map>
namespace anysdk { namespace framework {
/**   
 *@class  ProtocolAdTracking
 *@brief the interface of AdTracking  
 */
class ProtocolAdTracking : public PluginProtocol
{
public:

	/**
	 *
	* @Title: onRegister
	* @Description: Call this method if you want to track register events as happening during a section.
	* @param userId    user identifier
	* @return void
	 */
    virtual void onRegister(const char* userId) = 0;
    
	/**
	 *
	* @Title: onLogin
	* @Description:Call this method if you want to track login events as happening during a section.
	* @param userInfo  The details of this parameters are already covered by document.
	* @return void
	 */
    virtual void onLogin(std::map<std::string, std::string> userInfo) = 0;
    
    /**
     *
    * @Title: onPay
    * @Description: Call this method if you want to track pay events as happening during a section.
    * @param  productInfo  The details of this parameters are already covered by document.
    * @return void
     */
    virtual void onPay(std::map<std::string, std::string> productInfo) = 0;

	/**
	 *
	* @Title: trackEvent
	* @Description: Call this method if you want to track custom events with parameters as happening during a section.
	* @param eventId The custom event name.
	* @param  paramMap The details of this parameters are already covered by document.
	 */
    virtual void trackEvent(const char* eventId, std::map<std::string, std::string>* paramMap = NULL) = 0;


};

}} // namespace anysdk { namespace framework {

#endif   /* ----- #ifndef __CCX_PROTOCOL_ADTRACKING_H__ ----- */
