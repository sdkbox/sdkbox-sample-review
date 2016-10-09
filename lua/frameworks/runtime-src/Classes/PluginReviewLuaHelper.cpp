
#include "PluginReviewLuaHelper.h"
#include "PluginReview/PluginReview.h"
#include "SDKBoxLuaHelper.h"

class ReviewListenerLua : public sdkbox::ReviewListener {
public:
	ReviewListenerLua(): mLuaHandler(0) {
	}

	~ReviewListenerLua() {
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

    void onDisplayAlert() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("onDisplayAlert")));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onDeclineToRate() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("onDeclineToRate")));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onRate() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("onRate")));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onRemindLater() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("onRemindLater")));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

private:
	int mLuaHandler;
};

int lua_PluginReviewLua_PluginReview_setListener(lua_State* tolua_S) {
	int argc = 0;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginReview",0,&tolua_err)) goto tolua_lerror;
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
        ReviewListenerLua* lis = static_cast<ReviewListenerLua*> (sdkbox::PluginReview::getListener());
        if (NULL == lis) {
            lis = new ReviewListenerLua();
        }
        lis->setHandler(handler);
        sdkbox::PluginReview::setListener(lis);

        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginReview::setListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginReviewLua_PluginReview_setListener'.",&tolua_err);
#endif
    return 0;
}


int extern_PluginReview(lua_State* L) {
	if (NULL == L) {
		return 0;
	}

	lua_pushstring(L, "sdkbox.PluginReview");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"setListener", lua_PluginReviewLua_PluginReview_setListener);
    }
     lua_pop(L, 1);

    return 1;
}

TOLUA_API int register_all_PluginReviewLua_helper(lua_State* L) {
	tolua_module(L,"sdkbox",0);
	tolua_beginmodule(L,"sdkbox");

	extern_PluginReview(L);

	tolua_endmodule(L);
	return 1;
}


