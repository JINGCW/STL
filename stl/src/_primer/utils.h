#ifndef STANDARD_TEMPLATE_LIBRARIES_UTILS_H
#define STANDARD_TEMPLATE_LIBRARIES_UTILS_H

//#pragma once
//#pragma comment(lib, "_primer.dll")
#define USE_EXPORT_API

#ifdef USE_EXPORT_API
 #define EXPORT_API __declspec(dllexport)
#else
 #define EXPORT_API __declspec(dllimport)
#endif

#include <fstream>

//#include "_7_class.h"
//#include "_6_function.h"
//#include "_8_IO.h"
//#include "_9_sequential_container.h"
//#include "_12_dy_mem.h"
//#include "_17_stdlib.h"

using namespace std;

#define DYNAMIC_EXPORT __declspec(dllexport)
#define DYNAMIC_IMPORT __declspec(dllimport)

class EXPORT_API Math
{
public:
    static double add(double a, double b);

    static double mul(double a, double b);
};

EXPORT_API void mini_text_query();

#endif //STANDARD_TEMPLATE_LIBRARIES_UTILS_H
