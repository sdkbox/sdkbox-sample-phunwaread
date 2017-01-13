#ifndef __PluginPhunwareAdsJS_h__
#define __PluginPhunwareAdsJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_PluginPhunwareAds_class;
extern JSObject *jsb_sdkbox_PluginPhunwareAds_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginPhunwareAdsJS_PluginPhunwareAds(JSContext *cx, JS::HandleObject global);
void register_all_PluginPhunwareAdsJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginPhunwareAdsJS_PluginPhunwareAds(JSContext *cx, JSObject* global);
void register_all_PluginPhunwareAdsJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginPhunwareAdsJS_PluginPhunwareAds_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginPhunwareAdsJS_PluginPhunwareAds_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginPhunwareAdsJS_PluginPhunwareAds_getRemainingViews(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginPhunwareAdsJS_PluginPhunwareAds_getRemainingViews(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginPhunwareAdsJS_PluginPhunwareAds_setUserID(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginPhunwareAdsJS_PluginPhunwareAds_setUserID(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginPhunwareAdsJS_PluginPhunwareAds_hide(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginPhunwareAdsJS_PluginPhunwareAds_hide(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginPhunwareAdsJS_PluginPhunwareAds_show(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginPhunwareAdsJS_PluginPhunwareAds_show(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginPhunwareAdsJS_PluginPhunwareAds_cache(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginPhunwareAdsJS_PluginPhunwareAds_cache(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginPhunwareAdsJS_PluginPhunwareAds_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginPhunwareAdsJS_PluginPhunwareAds_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginPhunwareAdsJS_PluginPhunwareAds_isAvailable(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginPhunwareAdsJS_PluginPhunwareAds_isAvailable(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

