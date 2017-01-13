
#include "PluginPhunwareAdsLuaHelper.h"
#include "PluginPhunwareAds/PluginPhunwareAds.h"
#include "CCLuaEngine.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"

class PhunwareAdsListenerLua : public sdkbox::PhunwareAdsListener {
public:
    PhunwareAdsListenerLua(): mLuaHandler(0) {
    }

    ~PhunwareAdsListenerLua() {
        resetHandler();
    }

    void setHandler(int luaHandler) {
        if (mLuaHandler == luaHandler) {
            return;
        }
        resetHandler();
        mLuaHandler = luaHandler;
    }

    void resetHandler() {
        if (0 == mLuaHandler) {
            return;
        }

        LUAENGINE->removeScriptHandler(mLuaHandler);
        mLuaHandler = 0;
    }


    void adLoaded(const std::string& name) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue(__FUNCTION__)));
        dict.insert(std::make_pair("name", LuaValue::stringValue(name)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void adFailed(const std::string& name, int errorCode, const std::string& msg) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue(__FUNCTION__)));
        dict.insert(std::make_pair("name", LuaValue::stringValue(name)));
        dict.insert(std::make_pair("errorCode", LuaValue::intValue(errorCode)));
        dict.insert(std::make_pair("msg", LuaValue::stringValue(msg)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void adWillPresent(const std::string& name) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue(__FUNCTION__)));
        dict.insert(std::make_pair("name", LuaValue::stringValue(name)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void adDidPresent(const std::string& name) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue(__FUNCTION__)));
        dict.insert(std::make_pair("name", LuaValue::stringValue(name)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void adWillDissmiss(const std::string& name) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue(__FUNCTION__)));
        dict.insert(std::make_pair("name", LuaValue::stringValue(name)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void adDidDismiss(const std::string& name) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue(__FUNCTION__)));
        dict.insert(std::make_pair("name", LuaValue::stringValue(name)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void willLeaveApp(const std::string& name) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue(__FUNCTION__)));
        dict.insert(std::make_pair("name", LuaValue::stringValue(name)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void reward(const std::string& name, float amount, const std::string& currency) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue(__FUNCTION__)));
        dict.insert(std::make_pair("name", LuaValue::stringValue(name)));
        dict.insert(std::make_pair("amount", LuaValue::floatValue(amount)));
        dict.insert(std::make_pair("currency", LuaValue::stringValue(currency)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

private:
    int mLuaHandler;
};

int lua_PluginPhunwareAdsLua_PluginPhunwareAds_setListener(lua_State* tolua_S) {
    int argc = 0;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginPhunwareAds",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S, 2 , "LUA_FUNCTION",0,&tolua_err))
        {
            goto tolua_lerror;
        }
#endif
        LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
        PhunwareAdsListenerLua* lis = static_cast<PhunwareAdsListenerLua*> (sdkbox::PluginPhunwareAds::getListener());
        if (NULL == lis) {
            lis = new PhunwareAdsListenerLua();
        }
        lis->setHandler(handler);
        sdkbox::PluginPhunwareAds::setListener(lis);

        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginPhunwareAds::setListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginPhunwareAdsLua_PluginPhunwareAds_setListener'.",&tolua_err);
#endif
    return 0;
}

static int lua_createTable(lua_State* L, const std::map<std::string, int>& map) {
    lua_newtable(L);

    std::map<std::string, int>::const_iterator it = map.begin();
    while (it != map.end()) {
        lua_pushstring(L, it->first.c_str());
        lua_pushinteger(L, it->second);
        lua_settable(L, -3);
        it++;
    }

    return 1;
}

static int lua_setTable(lua_State* L, int table, const std::string& name, const std::map<std::string, int>& map) {
    if (table < 0) {
        table = lua_gettop(L) + table + 1;
    }
    lua_pushstring(L, name.c_str());
    lua_createTable(L, map);
    lua_rawset(L, table);

    return 0;
}

int lua_PluginPhunwareAdsLua_constants(lua_State* L) {
    if (NULL == L) {
        return 0;
    }

    lua_pushstring(L, "sdkbox.PluginPhunwareAds");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1)) {

        std::map<std::string, int> enums;
        enums.clear();
        enums.insert(std::make_pair("AdOrientation_AutoDetect", 0));
        enums.insert(std::make_pair("AdOrientation_Landscape", 1));
        enums.insert(std::make_pair("AdOrientation_Portrait", 2));
        lua_setTable(L, -1, "AdOrientation", enums);
    }
    lua_pop(L, 1);

    return 1;
}

int extern_PluginPhunwareAds(lua_State* L) {
    if (NULL == L) {
        return 0;
    }

    lua_pushstring(L, "sdkbox.PluginPhunwareAds");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"setListener", lua_PluginPhunwareAdsLua_PluginPhunwareAds_setListener);
    }
     lua_pop(L, 1);

    lua_PluginPhunwareAdsLua_constants(L);

    return 1;
}

TOLUA_API int register_all_PluginPhunwareAdsLua_helper(lua_State* L) {
    tolua_module(L,"sdkbox",0);
    tolua_beginmodule(L,"sdkbox");

    extern_PluginPhunwareAds(L);

    tolua_endmodule(L);
    return 1;
}


