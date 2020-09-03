#include "ExampleObject.h"
#include <stdio.h>
//#include <lua.h>
//#include <lualib.h>
//#include <lauxlib.h>

int lua_average(lua_State *L) {
    int n = lua_gettop(L);
    double out = 0;

    for (int i = 0; i <= n; ++i)
        out += lua_tonumber(L, i);

    lua_pushnumber(L, out / n);
    lua_pushnumber(L, out);

    return 2;//return 2 results
}

int lua_say_hello(lua_State *state) {
    printf("hello world");
    return 0;
}

static const struct luaL_Reg this_lua_lib[] = {
        {"average",   lua_average},
        {"say_hello", lua_say_hello},
        {NULL, NULL}
};

int luaopen_libExample(lua_State *state) {
    luaL_newlib(state, this_lua_lib);
    return 1;
}
