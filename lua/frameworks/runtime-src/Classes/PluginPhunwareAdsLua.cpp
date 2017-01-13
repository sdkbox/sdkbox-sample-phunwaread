#include "PluginPhunwareAdsLua.hpp"
#include "PluginPhunwareAds/PluginPhunwareAds.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/Sdkbox.h"



int lua_PluginPhunwareAdsLua_PluginPhunwareAds_getRemainingViews(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginPhunwareAds",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginPhunwareAds:getRemainingViews");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginPhunwareAdsLua_PluginPhunwareAds_getRemainingViews'", nullptr);
            return 0;
        }
        int ret = sdkbox::PluginPhunwareAds::getRemainingViews(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginPhunwareAds:getRemainingViews",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginPhunwareAdsLua_PluginPhunwareAds_getRemainingViews'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginPhunwareAdsLua_PluginPhunwareAds_setUserID(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginPhunwareAds",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginPhunwareAds:setUserID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginPhunwareAdsLua_PluginPhunwareAds_setUserID'", nullptr);
            return 0;
        }
        sdkbox::PluginPhunwareAds::setUserID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginPhunwareAds:setUserID",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginPhunwareAdsLua_PluginPhunwareAds_setUserID'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginPhunwareAdsLua_PluginPhunwareAds_hide(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginPhunwareAds",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginPhunwareAds:hide");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginPhunwareAdsLua_PluginPhunwareAds_hide'", nullptr);
            return 0;
        }
        sdkbox::PluginPhunwareAds::hide(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginPhunwareAds:hide",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginPhunwareAdsLua_PluginPhunwareAds_hide'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginPhunwareAdsLua_PluginPhunwareAds_show(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginPhunwareAds",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginPhunwareAds:show");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginPhunwareAdsLua_PluginPhunwareAds_show'", nullptr);
            return 0;
        }
        sdkbox::PluginPhunwareAds::show(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginPhunwareAds:show",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginPhunwareAdsLua_PluginPhunwareAds_show'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginPhunwareAdsLua_PluginPhunwareAds_cache(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginPhunwareAds",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginPhunwareAds:cache");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginPhunwareAdsLua_PluginPhunwareAds_cache'", nullptr);
            return 0;
        }
        sdkbox::PluginPhunwareAds::cache(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginPhunwareAds:cache",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginPhunwareAdsLua_PluginPhunwareAds_cache'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginPhunwareAdsLua_PluginPhunwareAds_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginPhunwareAds",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginPhunwareAdsLua_PluginPhunwareAds_init'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginPhunwareAds::init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginPhunwareAds:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginPhunwareAdsLua_PluginPhunwareAds_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginPhunwareAdsLua_PluginPhunwareAds_isAvailable(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginPhunwareAds",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginPhunwareAds:isAvailable");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginPhunwareAdsLua_PluginPhunwareAds_isAvailable'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginPhunwareAds::isAvailable(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginPhunwareAds:isAvailable",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginPhunwareAdsLua_PluginPhunwareAds_isAvailable'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginPhunwareAdsLua_PluginPhunwareAds_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginPhunwareAds)");
    return 0;
}

int lua_register_PluginPhunwareAdsLua_PluginPhunwareAds(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginPhunwareAds");
    tolua_cclass(tolua_S,"PluginPhunwareAds","sdkbox.PluginPhunwareAds","",nullptr);

    tolua_beginmodule(tolua_S,"PluginPhunwareAds");
        tolua_function(tolua_S,"getRemainingViews", lua_PluginPhunwareAdsLua_PluginPhunwareAds_getRemainingViews);
        tolua_function(tolua_S,"setUserID", lua_PluginPhunwareAdsLua_PluginPhunwareAds_setUserID);
        tolua_function(tolua_S,"hide", lua_PluginPhunwareAdsLua_PluginPhunwareAds_hide);
        tolua_function(tolua_S,"show", lua_PluginPhunwareAdsLua_PluginPhunwareAds_show);
        tolua_function(tolua_S,"cache", lua_PluginPhunwareAdsLua_PluginPhunwareAds_cache);
        tolua_function(tolua_S,"init", lua_PluginPhunwareAdsLua_PluginPhunwareAds_init);
        tolua_function(tolua_S,"isAvailable", lua_PluginPhunwareAdsLua_PluginPhunwareAds_isAvailable);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginPhunwareAds).name();
    g_luaType[typeName] = "sdkbox.PluginPhunwareAds";
    g_typeCast["PluginPhunwareAds"] = "sdkbox.PluginPhunwareAds";
    return 1;
}
TOLUA_API int register_all_PluginPhunwareAdsLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginPhunwareAdsLua_PluginPhunwareAds(tolua_S);

	tolua_endmodule(tolua_S);

	sdkbox::setProjectType("lua");
	return 1;
}

