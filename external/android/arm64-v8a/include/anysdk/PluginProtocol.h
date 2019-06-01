/** @file PluginProtocol.h
 */
#ifndef __CCX_IPLUGIN_H__
#define __CCX_IPLUGIN_H__

#include "PluginParam.h"
#include <vector>

#if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
#define CC_DEPRECATED_ATTRIBUTE __attribute__((deprecated))
#elif _MSC_VER >= 1400 //vs 2005 or higher
#define CC_DEPRECATED_ATTRIBUTE __declspec(deprecated)
#else
#define CC_DEPRECATED_ATTRIBUTE
#endif

namespace anysdk { namespace framework {

/**
 * 	@class PluginProtocol
 *	@brief	The super class for all plugins.
 */
class PluginProtocol
{
public:
    virtual ~PluginProtocol() {};
    
    /**
     *@brief set plugin name
     *@param the name of plugin
    */
	virtual void setPluginName(const char* name) = 0 ;
    /**
     *@brief get plugin name
     *@return the name of plugin
    */
	virtual const char* getPluginName() = 0 ;

    /**
     *@brief get the version of plugin
     *@return the version of plugin
    */
	virtual std::string getPluginVersion();
    /**
     *@brief get the version of sdk
     *@return the version of sdk
    */
	virtual std::string getSDKVersion();

    /**
     *@brief switch debug plug-in on/off
     *@param the value of on/off
    */
	CC_DEPRECATED_ATTRIBUTE virtual void setDebugMode(bool bDebug);

    /**
     *@brief methods for reflections
     *@param function name
     *@param PluginParam* param
     *@return void
     */
	virtual void callFuncWithParam(const char* funcName, PluginParam* param, ...);
    /**
     *@brief methods for reflections
     *@param function name
     *@param std::vector<PluginParam*> params
     *@return void
     */
	virtual void callFuncWithParam(const char* funcName, std::vector<PluginParam*> params);

    /**
     *@brief methods for reflections
     *@param function name
     *@param PluginParam* param
     *@return string
     */
	virtual std::string callStringFuncWithParam(const char* funcName, PluginParam* param, ...);
    /**
     *@brief methods for reflections
     *@param function name
     *@param std::vector<PluginParam*> params
     *@return string
     */
	virtual std::string callStringFuncWithParam(const char* funcName, std::vector<PluginParam*> params);

    /**
     *@brief methods for reflections
     *@param function name
     *@param PluginParam* param
     *@return int
     */
	virtual int callIntFuncWithParam(const char* funcName, PluginParam* param, ...);
    /**
     *@brief methods for reflections
     *@param function name
     *@param std::vector<PluginParam*> params
     *@return int
     */
	virtual int callIntFuncWithParam(const char* funcName, std::vector<PluginParam*> params);

    /**
     *@brief methods for reflections
     *@param function name
     *@param PluginParam* param
     *@return bool
     */
	virtual bool callBoolFuncWithParam(const char* funcName, PluginParam* param, ...);
    /**
     *@brief methods for reflections
     *@param function name
     *@param std::vector<PluginParam*> params
     *@return bool
     */
	virtual bool callBoolFuncWithParam(const char* funcName, std::vector<PluginParam*> params);

    /**
     *@brief methods for reflections
     *@param function name
     *@param PluginParam* param
     *@return float
     */
	virtual float callFloatFuncWithParam(const char* funcName, PluginParam* param, ...);
    /**
     *@brief methods for reflections
     *@param function name
     *@param std::vector<PluginParam*> params
     *@return float
     */
	virtual float callFloatFuncWithParam(const char* funcName, std::vector<PluginParam*> params);

    /**
     @brief Check function the plugin support or not
     @param the name of plugin
     @return if the function support ,return true
     	 	 else retur false
     */
    virtual bool isFunctionSupported(std::string functionName);


};

}} //namespace anysdk { namespace framework {

#endif /* __CCX_IPLUGIN_H__ */
