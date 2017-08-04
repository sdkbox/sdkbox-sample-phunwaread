#ifndef __PluginPhunwareAdsJS_h__
#define __PluginPhunwareAdsJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginPhunwareAdsJS_PluginPhunwareAds(JSContext *cx, JS::HandleObject global);
void register_all_PluginPhunwareAdsJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginPhunwareAdsJS_PluginPhunwareAds(JSContext *cx, JSObject* global);
void register_all_PluginPhunwareAdsJS(JSContext* cx, JSObject* obj);
#endif
#endif

