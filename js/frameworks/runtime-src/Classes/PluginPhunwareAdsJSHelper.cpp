#include "PluginPhunwareAdsJSHelper.h"
#include "cocos2d_specifics.hpp"
#include "PluginPhunwareAds/PluginPhunwareAds.h"
#include "SDKBoxJSHelper.h"

#include "js_manual_conversions.h"

extern JSObject* jsb_sdkbox_PluginPhunwareAds_prototype;
static JSContext* s_cx = nullptr;

class PhunwareAds_CallbackJS: public cocos2d::CCObject {
public:
    PhunwareAds_CallbackJS();
    void schedule();
    void notityJs(float dt);

    std::string _name;

    jsval _paramVal[3];
    int _paramLen;
};

class PhunwareAdsListenerJS : public sdkbox::PhunwareAdsListener {
private:
    JSObject* _JSDelegate;
public:
    void setJSDelegate(JSObject* delegate) {
        _JSDelegate = delegate;
    }

    JSObject* getJSDelegate() {
        return _JSDelegate;
    }

    void adLoaded(const std::string& name) {
        PhunwareAds_CallbackJS* cb = new PhunwareAds_CallbackJS();
        cb->_name = __FUNCTION__;
        cb->_paramVal[0] = std_string_to_jsval(s_cx, name);
        cb->_paramLen = 1;
        cb->schedule();
    }
    void adFailed(const std::string& name, int errorCode, const std::string& msg) {
        PhunwareAds_CallbackJS* cb = new PhunwareAds_CallbackJS();
        cb->_name = __FUNCTION__;
        cb->_paramVal[0] = std_string_to_jsval(s_cx, name);
        cb->_paramVal[1] = INT_TO_JSVAL(errorCode);
        cb->_paramVal[2] = std_string_to_jsval(s_cx, msg);
        cb->_paramLen = 3;
        cb->schedule();
    }
    void adWillPresent(const std::string& name) {
        PhunwareAds_CallbackJS* cb = new PhunwareAds_CallbackJS();
        cb->_name = __FUNCTION__;
        cb->_paramVal[0] = std_string_to_jsval(s_cx, name);
        cb->_paramLen = 1;
        cb->schedule();
    }
    void adDidPresent(const std::string& name) {
        PhunwareAds_CallbackJS* cb = new PhunwareAds_CallbackJS();
        cb->_name = __FUNCTION__;
        cb->_paramVal[0] = std_string_to_jsval(s_cx, name);
        cb->_paramLen = 1;
        cb->schedule();
    }
    void adWillDissmiss(const std::string& name) {
        PhunwareAds_CallbackJS* cb = new PhunwareAds_CallbackJS();
        cb->_name = __FUNCTION__;
        cb->_paramVal[0] = std_string_to_jsval(s_cx, name);
        cb->_paramLen = 1;
        cb->schedule();
    }
    void adDidDismiss(const std::string& name) {
        PhunwareAds_CallbackJS* cb = new PhunwareAds_CallbackJS();
        cb->_name = __FUNCTION__;
        cb->_paramVal[0] = std_string_to_jsval(s_cx, name);
        cb->_paramLen = 1;
        cb->schedule();
    }
    void willLeaveApp(const std::string& name) {
        PhunwareAds_CallbackJS* cb = new PhunwareAds_CallbackJS();
        cb->_name = __FUNCTION__;
        cb->_paramVal[0] = std_string_to_jsval(s_cx, name);
        cb->_paramLen = 1;
        cb->schedule();
    }
    void reward(const std::string& name, float amount, const std::string& currency) {
        PhunwareAds_CallbackJS* cb = new PhunwareAds_CallbackJS();
        cb->_name = __FUNCTION__;
        cb->_paramVal[0] = std_string_to_jsval(s_cx, name);
        cb->_paramVal[1] = DOUBLE_TO_JSVAL(amount);
        cb->_paramVal[2] = std_string_to_jsval(s_cx, currency);
        cb->_paramLen = 3;
        cb->schedule();
    }

    void invokeJS(const char* func, jsval* pVals, int valueSize) {
        if (!s_cx) {
            return;
        }
        JSContext* cx = s_cx;
        const char* func_name = func;
        JS::RootedObject obj(cx, _JSDelegate);
        JSAutoCompartment ac(cx, obj);

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
        bool hasAction;
        JS::RootedValue retval(cx);
        JS::RootedValue func_handle(cx);
#else
        bool hasAction;
        jsval retval;
        JS::RootedValue func_handle(cx);
#endif
#elif defined(JS_VERSION)
        JSBool hasAction;
        jsval retval;
        jsval func_handle;
#endif

        if (JS_HasProperty(cx, obj, func_name, &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, func_name, &func_handle)) {
                return;
            }
            if(func_handle == JSVAL_VOID) {
                return;
            }

#if MOZJS_MAJOR_VERSION >= 31
            if (0 == valueSize) {
                JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::empty(), &retval);
            } else {
                JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::fromMarkedLocation(valueSize, pVals), &retval);
            }
#else
            if (0 == valueSize) {
                JS_CallFunctionName(cx, obj, func_name, 0, nullptr, &retval);
            } else {
                JS_CallFunctionName(cx, obj, func_name, valueSize, pVals, &retval);
            }
#endif
        }
    }

};


PhunwareAds_CallbackJS::PhunwareAds_CallbackJS():
_paramLen(0) {
}

void PhunwareAds_CallbackJS::schedule() {
    retain();
    cocos2d::CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(PhunwareAds_CallbackJS::notityJs), this, 0.1, false);
    autorelease();
}

void PhunwareAds_CallbackJS::notityJs(float dt) {
    sdkbox::PhunwareAdsListener* lis = sdkbox::PluginPhunwareAds::getListener();
    PhunwareAdsListenerJS* l = dynamic_cast<PhunwareAdsListenerJS*>(lis);
    if (l) {
        l->invokeJS(_name.c_str(), _paramVal, _paramLen);
    }
    cocos2d::CCDirector::sharedDirector()->getScheduler()->unscheduleAllForTarget(this);
    release();
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
bool js_PluginPhunwareAdsJS_PluginPhunwareAds_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#else
bool js_PluginPhunwareAdsJS_PluginPhunwareAds_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#endif
#elif defined(JS_VERSION)
JSBool js_PluginPhunwareAdsJS_PluginPhunwareAds_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#endif
{
    s_cx = cx;
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;

    if (argc == 1) {

        if (!args.get(0).isObject())
        {
            ok = false;
        }
        JSObject *tmpObj = args.get(0).toObjectOrNull();

        JSB_PRECONDITION2(ok, cx, false, "js_PluginPhunwareAdsJS_PluginPhunwareAds_setIAPListener : Error processing arguments");
        PhunwareAdsListenerJS* wrapper = new PhunwareAdsListenerJS();
        wrapper->setJSDelegate(tmpObj);
        sdkbox::PluginPhunwareAds::setListener(wrapper);

        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginPhunwareAdsJS_PluginPhunwareAds_setListener : wrong number of arguments");
    return false;
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginPhunwareAdsJS_helper(JSContext* cx, JS::HandleObject global) {
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginPhunwareAds", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginPhunwareAdsJS_PluginPhunwareAds_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
}
#else
void register_all_PluginPhunwareAdsJS_helper(JSContext* cx, JSObject* global) {
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, JS::RootedObject(cx, global), "sdkbox.PluginPhunwareAds", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginPhunwareAdsJS_PluginPhunwareAds_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginPhunwareAdsJS_helper(JSContext* cx, JSObject* global) {
    jsval pluginVal;
    JSObject* pluginObj;
    pluginVal = sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginPhunwareAds", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginPhunwareAdsJS_PluginPhunwareAds_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
}
#endif
