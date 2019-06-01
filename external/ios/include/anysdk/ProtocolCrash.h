/** @file ProtocolCrash.h
 */
#ifndef __CCX_PROTOCOL_CRASH_H__
#define __CCX_PROTOCOL_CRASH_H__

#include "PluginProtocol.h"
#include <map>
#include <string>

namespace anysdk { namespace framework {

class ProtocolCrash : public PluginProtocol
{
public:
	/**
	 *  set user identifier
	 *
	 *  @param userInfo
	 */
	virtual void setUserIdentifier(const char* identifier) = 0;

	/**
	 *  The uploader captured in exception information
	 *
	 *	@param message   Set the custom information
	 *  @param exception  The exception
	 */
	virtual void reportException(const char* message, const char* exception) = 0;

	/**
	 *  customize logging
	 *
	 *  @param string Custom log
	 */
	virtual void leaveBreadcrumb(const char* breadcrumb) = 0;




};

}} // namespace anysdk { namespace framework {

#endif /* __CCX_PROTOCOL_CRASH_H__ */
