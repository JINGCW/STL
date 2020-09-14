#ifndef this_object_h
#define this_object_h
//#pragma once

//#include <string>
//#include <vector>

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

LUALIB_API int luaopen_libExample(lua_State *L);

}

//using namespace std;

//namespace this_object
//{
//#ifdef LUA_EXPORTS
//#define LUA_API __declspec(dllexport)
//#else
//#define LUA_API __declspec(dllimport)
//#endif

//extern "C" LUA_API int luaopen_this_lualib(lua_State *L);


//class this_Object
//class ExampleObject {
//public:
//    int x;
//
//    string hello() {
//        return "hello";
//    }
//};

//}
//class LStudent {
//public:
//    LStudent() :
//            name(""), age(0) {}
//
//    ~LStudent() = default;
//
//    string get_name() {
//        return name;
//    }
//
//    void set_name(const string &name_) {
//        name = name_;
//    }
//
//    unsigned get_age() {
//        return age;
//    }
//
//    void set_age(unsigned age_) {
//        age = age_;
//    }
//
//private:
//    string name;
//    unsigned age;
//};

//int lcreate_student(lua_State *L) {
//    //create a pointer store in stack，return back to lua call.
//    auto **s = static_cast<LStudent **>(lua_newuserdata(L, sizeof(LStudent *)));
//    *s = new LStudent();
//    return 1;
//}

//int lget_name(lua_State *L) {
//    LStudent **s = static_cast<LStudent **>(lua_touserdata(L, 1));
//    luaL_argcheck(L, s != nullptr, 1, "invalid user data");
//    //clear stack
//    lua_settop(L, 0);
//    lua_pushstring(L, (*s)->get_name().c_str());
//    return 1;
//}

//int lset_name(lua_State *L) {
//    LStudent **s = static_cast<LStudent **>(lua_touserdata(L, 1));
//    luaL_argcheck(L, s != nullptr, 1, "invalid user data");
//    luaL_checktype(L, -1, LUA_TSTRING);
//    string new_name = lua_tostring(L, -1);
//    (*s)->set_name(new_name);
//    return 0;
//}

//static const luaL_Reg l_reg_student_functions[] = {
//        {"create",   lcreate_student},
//        {"get_name", lget_name},
//        {"set_name", lset_name},
//        {NULL, NULL}
//};

//__declspec(dllexport) int  luaopen_student(lua_State* L)
//{
//    luaL_register(L, "lstudent", l_reg_student_functions);
//    return 1;
//}


//int lopen_student_lib(lua_State *L) {
//    luaL_newlib(L, l_reg_student_functions);
//    return 1;
//}

//
//static const luaL_Reg lua_reg_libs[] = {
//        {"base",         luaopen_base},
//        {"open_student", lopen_student_lib},
//        {NULL, NULL},
//};

//int __declspec(dllexport) lua_open_reg_libs(lua_State * L)
//{
//    const luaL_Reg *_lua_reg_libs = lua_reg_libs;
//    for(;)
//}

#endif //this_object_h
