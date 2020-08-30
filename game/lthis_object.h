//#ifndef _LTHIS_OBJECT_H
#ifndef lthis_object_h
#define lthis_object_h
//#define _LTHIS_OBJECT_H
//#pragma once

#include "ExampleObject.h"
#include <lutok2/lutok2.hpp>
#include <lua.hpp>

//namespace lthis_object
//{
using namespace lutok2;

//class LObject : public Object<this_Object>
class LuaExampleObject : public Object<ExampleObject>
{
public:
    explicit LuaExampleObject(State *state) :
            Object<ExampleObject>(state)
    {
        /* Properties handle access to member variables
         * with getter and setter functions
         */
        LUTOK_PROPERTY("x", &LuaExampleObject::getter, &LuaExampleObject::setter)
        // Methods allow you to call member functions
        LUTOK_METHOD("hello", &LuaExampleObject::hello)
    }

    ExampleObject *constructor(State &state, bool &managed)
    {
        return new ExampleObject();
    }

    void destructor(State &state, ExampleObject *object)
    {
        delete object;
    }

    int getter(State &state, ExampleObject *object)
    {
        state.stack->push<int>(object->x);
        return 1;
    }

    int setter(State &state, ExampleObject *object)
    {
        if (state.stack->is<LUA_TNUMBER>(1))
            object->x = state.stack->to<int>(1);
        return 0;
    }

    int hello(State &state, ExampleObject *object)
    {
        state.stack->push<const string &>(object->hello());
        return 1;
    }
};

//LUA_API
extern "C" __declspec(dllexport) int lobject_interface(lua_State *current_state)
{
    // State object is freed automatically after Lua state closes!
    auto *state = new State(current_state);
    // Prepare main module interface table
    state->stack->newTable();
    /* Object interface registration always returns Lua function
     * with object constructor.
     */
//    state->registerInterface<LuaExampleObject>("LObject");
    state->registerInterface<LuaExampleObject>("LuaExample_ExampleObject");
    /* A new instance of ExampleObject can be obtained by
     * calling Object function from main interface table.
     */
//    state->stack->setField("this_object__Object");
//    state->stack->setField("this_Object");
    state->stack->setField("ExampleObject");
    return 1;
}
//}

#endif //_LTHIS_OBJECT_H
