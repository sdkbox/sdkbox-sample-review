

#ifndef __js__PluginReviewJSHelper_H_
#define __js__PluginReviewJSHelper_H_

#include "jsapi.h"
#include "jsfriendapi.h"

#if MOZJS_MAJOR_VERSION >= 31
void register_all_PluginReviewJS_helper(JSContext* cx, JS::HandleObject global);
#else
void register_all_PluginReviewJS_helper(JSContext* cx, JSObject* global);
#endif

#endif /* defined(__PluginReviewJSHelper_H_) */
