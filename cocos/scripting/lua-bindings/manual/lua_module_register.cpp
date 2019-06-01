#include "lua-bindings/manual/lua_module_register.h"

#include "lua-bindings/manual/ui/lua_cocos2dx_ui_manual.hpp"


int lua_module_register(lua_State* L)
{
    // Don't change the module register order unless you know what your are doing
  
    register_ui_module(L);

    return 1;
}

