/** @file JSBRelation.h
 */
#ifndef __CCX_JSBRELATION_H__
#define __CCX_JSBRELATION_H__

#include "PluginProtocol.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace anysdk { namespace framework {

/**   
 *  @class  JSBRelation  
 */
class JSBRelation
{
public:
	static string getMethodsOfPlugin(PluginProtocol* plugin);

    


private:
};

}} //namespace anysdk { namespace framework {

#endif /* __CCX_JSBRELATION_H__ */
