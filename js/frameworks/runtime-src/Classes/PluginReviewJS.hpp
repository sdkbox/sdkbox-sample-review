#ifndef __PluginReviewJS_h__
#define __PluginReviewJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginReviewJS_PluginReview(JSContext *cx, JS::HandleObject global);
void register_all_PluginReviewJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginReviewJS_PluginReview(JSContext *cx, JSObject* global);
void register_all_PluginReviewJS(JSContext* cx, JSObject* obj);
#endif
#endif

