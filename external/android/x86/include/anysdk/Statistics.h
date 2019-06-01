#ifndef __STATISTICS_H__
#define __STATISTICS_H__

#include <string>
namespace anysdk { namespace framework {

class Statistics
{
public:
	static void initInfo();
	static void createPlugin(std::string pluginName, int pluginType);
	static void callFunction(std::string pluginName, std::string functionName);

};

}} // namespace anysdk { namespace framework {

#endif //__STATISTICS_H__
