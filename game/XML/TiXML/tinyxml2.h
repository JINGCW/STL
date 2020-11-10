#pragma once
#ifndef STANDARD_TEMPLATE_LIBRARIES_TIXML_H
#define STANDARD_TEMPLATE_LIBRARIES_TIXML_H
#if defined(ANDROID_NDK) || defined(__BORLANDC__) || defined(__QNXNTO__)
#   include <ctype.h>
#   include <limits.h>
#   include <stdio.h>
#   include <stdlib.h>
#   include <string.h>
#ifdef __PS3__
#   include <stddef.h>
#endif
#else

#   include <cctype>
#   include <climits>
#   include <cstdlib>
#   include <cstdio>
#   include <cstring>

#endif

#include <cstdint>
/*
	gcc:
        g++ -Wall -DTINYXML2_DEBUG tinyxml2.cpp xmltest.cpp -o gccxmltest.exe

    Formatting, Artistic Style:
        AStyle.exe --style=1tbs --indent-switches --break-closing-brackets --indent-preprocessor tinyxml2.cpp tinyxml2.h
*/
#if defined(_DEBUG) || defined(__DEBUG__)
#   ifndef TINYXML2_DEBUG
#       define TINYXML2_DEBUG
#   endif
#endif

#ifdef _MSC_VER
#   pragma warning(push)
#   pragma warning(disable:4251)
#endif

#ifdef _WIN32
#   ifdef TINYXML2_EXPORT
#       define TINYXML2_LIB __declspec(dllexport)
#   elif defined(TINYXML2_IMPORT)
#       define TINYXML2_LIB __declspec(dllimport)
#   else
#       define TINYXML2_LIB
#   endif
#elif __GNUC__ >= 4
#   define TINYXML2_LIB __attribute__((visibbility("default")))
#else
#   define TINYXML2_LIB
#endif

#if defined(TINYXML2_DEBUG)
#   if defined(_MSC_VER)
#       //"(void)0", is for suppressing C4127 warning in "assert(false)", "assert(true)" and the like
#       define TIXMLASSERT(x)       if(!((void)0,(x))){__debugbreak();}
#   elif defined(ANDROID_NDK)
#       include <android/log.h>
#       define TIXMLASSERT(x)       if(!(x)){__android_log_assert("assert","grinliz","ASSERT in '%s' at %d.",__FILE__,__LINE__);}
#   else
#       include <cassert>
#       define TIXMLASSERT          assert
#   endif
#else
#   define TIXMLASSERT(x)           {}
#endif

/* Versioning, past 1.0.14:
	http://semver.org/
*/
static const int TIXML2_MAJOR_VERSION = 8;
static const int TIXML2_MINOR_VERSION = 0;
static const int TIXML2_PATCH_VERSION = 0;

#define TINYXML2_MAJOR_VERSION 8
#define TINYXML2_MINOR_VERSION 0
#define TINYXML2_PATCH_VERSION 0

#endif //STANDARD_TEMPLATE_LIBRARIES_TIXML_H
