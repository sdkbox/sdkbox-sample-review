#include "PluginReviewLua.hpp"
#include "PluginReview/PluginReview.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/sdkbox.h"



int lua_PluginReviewLua_PluginReview_userDidSignificantEvent(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginReview",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginReview:userDidSignificantEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginReviewLua_PluginReview_userDidSignificantEvent'", nullptr);
            return 0;
        }
        sdkbox::PluginReview::userDidSignificantEvent(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginReview:userDidSignificantEvent",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginReviewLua_PluginReview_userDidSignificantEvent'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginReviewLua_PluginReview_setRateButtonTitle(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginReview",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginReview:setRateButtonTitle");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginReviewLua_PluginReview_setRateButtonTitle'", nullptr);
            return 0;
        }
        sdkbox::PluginReview::setRateButtonTitle(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginReview:setRateButtonTitle",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginReviewLua_PluginReview_setRateButtonTitle'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginReviewLua_PluginReview_show(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginReview",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginReviewLua_PluginReview_show'", nullptr);
            return 0;
        }
        sdkbox::PluginReview::show();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginReview:show");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginReviewLua_PluginReview_show'", nullptr);
            return 0;
        }
        sdkbox::PluginReview::show(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginReview:show",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginReviewLua_PluginReview_show'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginReviewLua_PluginReview_setTitle(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginReview",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginReview:setTitle");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginReviewLua_PluginReview_setTitle'", nullptr);
            return 0;
        }
        sdkbox::PluginReview::setTitle(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginReview:setTitle",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginReviewLua_PluginReview_setTitle'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginReviewLua_PluginReview_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginReview",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginReviewLua_PluginReview_init'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginReview::init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginReview:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginReviewLua_PluginReview_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginReviewLua_PluginReview_setRateLaterButtonTitle(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginReview",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginReview:setRateLaterButtonTitle");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginReviewLua_PluginReview_setRateLaterButtonTitle'", nullptr);
            return 0;
        }
        sdkbox::PluginReview::setRateLaterButtonTitle(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginReview:setRateLaterButtonTitle",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginReviewLua_PluginReview_setRateLaterButtonTitle'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginReviewLua_PluginReview_setMessage(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginReview",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginReview:setMessage");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginReviewLua_PluginReview_setMessage'", nullptr);
            return 0;
        }
        sdkbox::PluginReview::setMessage(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginReview:setMessage",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginReviewLua_PluginReview_setMessage'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginReviewLua_PluginReview_setCancelButtonTitle(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginReview",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginReview:setCancelButtonTitle");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginReviewLua_PluginReview_setCancelButtonTitle'", nullptr);
            return 0;
        }
        sdkbox::PluginReview::setCancelButtonTitle(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginReview:setCancelButtonTitle",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginReviewLua_PluginReview_setCancelButtonTitle'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginReviewLua_PluginReview_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginReview)");
    return 0;
}

int lua_register_PluginReviewLua_PluginReview(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginReview");
    tolua_cclass(tolua_S,"PluginReview","sdkbox.PluginReview","",nullptr);

    tolua_beginmodule(tolua_S,"PluginReview");
        tolua_function(tolua_S,"userDidSignificantEvent", lua_PluginReviewLua_PluginReview_userDidSignificantEvent);
        tolua_function(tolua_S,"setRateButtonTitle", lua_PluginReviewLua_PluginReview_setRateButtonTitle);
        tolua_function(tolua_S,"show", lua_PluginReviewLua_PluginReview_show);
        tolua_function(tolua_S,"setTitle", lua_PluginReviewLua_PluginReview_setTitle);
        tolua_function(tolua_S,"init", lua_PluginReviewLua_PluginReview_init);
        tolua_function(tolua_S,"setRateLaterButtonTitle", lua_PluginReviewLua_PluginReview_setRateLaterButtonTitle);
        tolua_function(tolua_S,"setMessage", lua_PluginReviewLua_PluginReview_setMessage);
        tolua_function(tolua_S,"setCancelButtonTitle", lua_PluginReviewLua_PluginReview_setCancelButtonTitle);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginReview).name();
    g_luaType[typeName] = "sdkbox.PluginReview";
    g_typeCast["PluginReview"] = "sdkbox.PluginReview";
    return 1;
}
TOLUA_API int register_all_PluginReviewLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginReviewLua_PluginReview(tolua_S);

	tolua_endmodule(tolua_S);

	sdkbox::setProjectType("lua");
	return 1;
}

