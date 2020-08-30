#ifndef _PYTHON_DLL_TEST_H
#define _PYTHON_DLL_TEST_H

#include <string>

using namespace std;

extern "C" __declspec(dllexport) string nothing();

extern "C" __declspec(dllexport) const char* nothing_c_char();

extern "C" int add(int a,int b)
{
    return a + b;
}

#endif //_PYTHON_DLL_TEST_H
