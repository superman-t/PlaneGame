/** @file PluginFactory.h
 */
#ifndef __CCX_PLUGIN_FACTORY_H__
#define __CCX_PLUGIN_FACTORY_H__

namespace anysdk { namespace framework {
    
class PluginProtocol;
class PluginManager;
/**   
 *  @class  PluginFactory  
 */
class PluginFactory
{
public:
	virtual ~PluginFactory();
    /**
     @brief Get singleton of PluginFactory
     */
    static PluginFactory* getInstance();

    /**
     @brief Destory the instance of PluginFactory
     */
    static void purgeFactory();

private:
    friend class PluginManager;
    PluginFactory(void);

    /**
     @brief create the plugin by name and type
     @param the name of plugin
     @param the type of plugin
     */
    PluginProtocol* createPlugin(const char* name, int pluginType);
};

}} //namespace anysdk { namespace framework {

#endif /* __CCX_PLUGIN_FACTORY_H__ */
