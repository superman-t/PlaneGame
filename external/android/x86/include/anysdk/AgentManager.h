/** @file AgentManager.h
 */


#ifndef __CCX_AGENTMANAGER_H__
#define __CCX_AGENTMANAGER_H__

#include "PluginManager.h"
#include "ProtocolIAP.h"
#include "ProtocolAnalytics.h"
#include "ProtocolShare.h"
#include "ProtocolAds.h"
#include "ProtocolSocial.h"
#include "ProtocolUser.h"
#include "ProtocolPush.h"
#include "ProtocolCrash.h"
#include "ProtocolREC.h"
#include "ProtocolCustom.h"
#include "ProtocolAdTracking.h"
#include <map>
#include <string>
namespace anysdk { namespace framework {
/** @brief Plugin_type enum, with inline docs */
typedef enum {
    kPluginAds = 16,/**< enum value is  the type of Ads. */
    kPluginAnalytics = 1,/**< enum value is  the type of Analytics. */
    kPluginIAP = 8,/**< enum value is  the type of IAP. */
    kPluginShare = 2,/**< enum value is  the type of Share. */
    kPluginUser = 32,/**< enum value is  the type of User. */
    kPluginSocial = 4,/**< enum value is  the type of Social. */
    kPluginPush = 64,/**< enum value is  the type of Push. */
    kPluginCrash = 128,/**< enum value is  the type of Crash. */
    kPluginCustom = 256,/**< enum value is  the type of Custom. */
    kPluginREC = 512,/**< enum value is  the type of REC. */
    kPluginAdTracking = 1024,/**< enum value is  the type of AdTracking. */
}Plugin_type;
/**   
 *  @class  AgentManager  
 */
class AgentManager
{
public:
	virtual ~AgentManager();
    /**
     @brief Get singleton of AgentManager
     */

    static AgentManager* getInstance();
    /**
     @brief Destory the instance of AgentManager
     */
    static void end();
    
    /**
    @breif the init of AgentManager
    @param the appKey of anysdk
    @param the appSecret of anysdk
    @param the privateKey of anysdk
    @param the url of oauthLoginServer
    @warning Must invoke this interface before loadAllPlugins
    */
    void init(std::string appKey,std::string appSecret,std::string privateKey,std::string oauthLoginServer);

    /**
     @brief load the plugins
     */
    CC_DEPRECATED_ATTRIBUTE void loadALLPlugin();
    /**
     @brief unload the plugins
     */
    CC_DEPRECATED_ATTRIBUTE void unloadALLPlugin();
    
    /**
     @brief load the plugins
    */
    void loadAllPlugins();

    /**
     @brief unload the plugins
    */
    void unloadAllPlugins();

    /**
     @brief Get Analytics plugin
     @return  if Analytics plugin exist ,return value is Analytics plugin.
     	 	  else return value is null pointer.
     */
    ProtocolAnalytics* getAnalyticsPlugin(){return _pAnalytics;};

    /**
     @brief Get User plugin
     @return  if User plugin exist ,return value is User plugin.
     	 	  else return value is null pointer.
     */
    ProtocolUser* getUserPlugin(){return _pUser;};

    /**
     @brief Get IAP plugin
     @return  if IAP plugin exist ,return value is IAP plugin.
     	 	  else return value is null pointer.
     */
    std::map<std::string , ProtocolIAP*>* getIAPPlugin(){return &_pluginsIAPMap;};

    /**
     @brief Get Share plugin
     @return  if Share plugin exist ,return value is Share plugin.
     	 	  else return value is null pointer.
     */
    ProtocolShare* getSharePlugin(){return _pShare;};

    /**
     @brief Get Social plugin
     @return  if Social plugin exist ,return value is Social plugin.
     	 	  else return value is null pointer.
     */
    ProtocolSocial* getSocialPlugin(){return _pSocial;};

    /**
     @brief Get Ads plugin
     @return  if Ads plugin exist ,return value is Ads plugin.
     	 	  else return value is null pointer.
     */
    ProtocolAds* getAdsPlugin(){return _pAds;};
    
    /**
     @brief Get Push plugin
     @return  if Push plugin exist ,return value is Push plugin.
     	 	  else return value is null pointer.
     */
    ProtocolPush* getPushPlugin(){return _pPush;};

    /**
     @brief Get Crash plugin
     @return  if Crash plugin exist ,return value is Crash plugin.
         	 else return value is null pointer.
     */
    ProtocolCrash* getCrashPlugin(){return _pCrash;};

    /**
     @brief Get Custom plugin
     @return  if Crash plugin exist ,return value is Custom plugin.
            else return value is null pointer.
     */
    ProtocolCustom* getCustomPlugin(){return _pCustom;};


    /**
     @brief Get REC plugin
     @return  if REC plugin exist ,return value is REC plugin.
             else return value is null pointer.
    */
    ProtocolREC* getRECPlugin(){return _pREC;};
    
    /**
     @brief Get AdTracking plugin
     @return  if AdTracking plugin exist ,return value is AdTracking plugin.
     else return value is null pointer.
     */
    ProtocolAdTracking* getAdTrackingPlugin(){return _pAdTracking;};

    /**
     @brief Get channel ID
     @return  return value is channel ID.
     */
    std::string getChannelId();

    /**
     @brief Get custom param
     @return  return value is custom param for channel.
     */
    std::string getCustomParam();

    /**
     @brief Get framework version
     @return  return value is the version of AnySDKFramework.
     */
    std::string getFrameworkVersion();

    /**
    @Title: setIsAnaylticsEnabled
    @Description: choose to open or close
    @param @param enabled    true or false
    @return void
    */
    void setIsAnaylticsEnabled(bool value){bIsAnaylticsEnabled = value;};
    /**
    @Title: isAnaylticsEnabled
    @Description: the status of Anayltics
    @param @return    true or false
    @return boolean
    */
    bool isAnaylticsEnabled(){return bIsAnaylticsEnabled;};
    
    
    void loadPlugin(const char* nodeName,int type);
protected:
    void setDebugMode(bool flag);
    std::string getSupportPlugin();
    void release();
    

private:
    AgentManager(void);
    
    // Analytics plugin
    ProtocolAnalytics* _pAnalytics;

    // user plugin
    ProtocolUser* _pUser;

    // IAP plugins
    //    ProtocolIAP* _pIAP;
    std::map<std::string , ProtocolIAP*> _pluginsIAPMap;

    // Share plugin
    ProtocolShare* _pShare;

    // Social plugin
    ProtocolSocial* _pSocial;

    // Ads plugin
    ProtocolAds* _pAds;
    
    // Push plugin
    ProtocolPush* _pPush;

    // Crash plugin
    ProtocolCrash* _pCrash;

    // Custom plugin
    ProtocolCustom* _pCustom;

    // REC plugin
    ProtocolREC* _pREC;
    
    // AdTracking plugin
    ProtocolAdTracking* _pAdTracking;

    bool bIsAnaylticsEnabled;

};

}} //namespace anysdk { namespace framework {

#endif /* __CCX_AGENTMANAGER_H__ */
