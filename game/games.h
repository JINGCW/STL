#ifndef _GAMES_H
#define _GAMES_H

#include <lua.hpp>
#include <lutok2/lutok2.hpp>

namespace with_lutok2
{
    using namespace lutok2;

    /* A function to be exposed should always use following form:
     * Input argument : A reference to Lutok2 State object
     * Output variable: An integral number of return values
     */
    int lutok2_games(State &state)
    {
        return 0;
    }

    extern "C" LUA_API int lua_lutok2_games(lua_State *current_state)
    {
        auto *state = new State(current_state);
        Module self_module;
        /* Expose lutok2_games function in
         * Lua language environment.
         * Key value represents a function name in Lua.
         * Value should always be a function pointer.
         */
        self_module["lutok2_games"] = lutok2_games;
        /* This module will return a Lua table
         * that exposes all functions listed in self_module.
         */
        state->stack->newTable();
        state->registerLib(self_module);
        return 1;
    }
}

namespace with_lua_c_api
{
    static int lua_games(lua_State*L)
    {
        return 0;
    }

    static const struct luaL_Reg self_module[]={
            {"lua_games",lua_games},
            {NULL,NULL}
    };

    extern "C" LUA_API int lua_lua_games(lua_State*L)
    {
        lua_newtable(L);
//        lua_register()
        luaL_register(L, NULL, self_module);
        return 1;
    }
}


#endif //_GAMES_H
