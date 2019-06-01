/****************************************************************************
Copyright (c) 2012+2013 cocos2d+x.org

http://www.cocos2d+x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#import <Foundation/Foundation.h>

@protocol InterfaceAnalytics<NSObject>

@required
/**
 *  start session analytics
 */
- (void) startSession;

/**
 *  stop session analytics
 */
- (void) stopSession;

/**
 *  Set the timeout for expiring a session.
 *
 *  @param millis In milliseconds as the unit of time.
 *  @note It must be invoked before calling startSession.
 */
- (void) setSessionContinueMillis: (long) millis;

/**
 * Whether to catch uncaught exceptions to server.
 *
 * @warning This interface only worked on android.
 */
- (void) setCaptureUncaughtException: (BOOL) isEnabled;

/**
 *  log an error
 *
 *  @param errorId The identity of event
 *  @param message message for the error
 */
- (void) logError: (NSString*) errorId withMsg:(NSString*) message;

/**
 *  log an event
 *
 *  @param eventId The identity of event
 */
- (void) logEvent: (NSString*) eventId;

/**
 *  log an event
 *
 *  @param eventId  The identity of event
 *  @param paramMap Extern parameters of the event
 */
- (void) logEvent: (NSString*) eventId withParam:(NSMutableDictionary*) paramMap;

/**
 *  Track an event begin
 *
 *  @param eventId The identity of event
 */
- (void) logTimedEventBegin: (NSString*) eventId;

/**
 *  Track an event end.
 *
 *  @param eventId The identity of event
 */
- (void) logTimedEventEnd: (NSString*) eventId;

/**
 *  whether function is supported
 *
 *  @param functionName the name of function
 *
 *  @return return If the function is supported, return true
 or if the function is  not supported, return false
 */
- (BOOL) isFunctionSupported : (NSString*) functionName;

/**
 *  get the version of SDK
 *
 *  @return the version of SDK
 */
- (NSString*) getSDKVersion;

/**
 *  get the version of plugin
 *
 *  @return the version of plugin
 */
- (NSString*) getPluginVersion;

@optional
/**
 *  init SDK
 *
 *  @param cpInfo the parameters of SDK
 */
- (void) configDeveloperInfo : (NSMutableDictionary*) cpInfo;

/**
 *  set debug mode true or false
 *
 *  @param debug the status of debug
 */
- (void) setDebugMode: (BOOL) debug;


@end
