#ifndef this_object_h
#define this_object_h
//#pragma once

#include <string>
#include <vector>
#include <lua.hpp>

using namespace std;

//namespace this_object
//{

//class this_Object
class ExampleObject
{
public:
    int x;

    string hello()
    {
        return "hello";
    }
};

//}
class LStudent
{
public:
    LStudent() :
            name(""), age(0)
    {}

    ~LStudent() = default;

    string get_name()
    {
        return name;
    }

    void set_name(const string &name_)
    {
        name = name_;
    }

    unsigned get_age()
    {
        return age;
    }

    void set_age(unsigned age_)
    {
        age = age_;
    }

private:
    string name;
    unsigned age;
};

int lcreate_student(lua_State *L)
{
    //create a pointer store in stack，return back to lua call.
    auto **s = static_cast<LStudent**>(lua_newuserdata(L, sizeof(LStudent*)));
    *s = new LStudent();
    return 1;
}

int lget_name(lua_State *L);

int lset_name(lua_State *L);

static const luaL_Reg l_reg_student_functions[] = {
        {"create",   lcreate_student},
        {"get_name", lget_name},
        {"set_name", lset_name},
        {nullptr, NULL}
};

int lstudent_lib(lua_State *L);

#endif //this_object_h
