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

static const int TINYXML2_MAX_ELEMENT_DEPTH = 100;

namespace tinyxml2 {
    /*
     A class that wraps string. Normally stores the start and end
     pointers into the XML file itself, and will apply normalization
     and entity translation if actually read. Can also store (and memory
     manage) a traditional char[]

     Isn't clear why TINYXML2_LIB is needed; but seems to fix #719
     */
    class TINYXML2_LIB StrPair {
    public:
        enum {
            NEEDS_ENTITY_PROCESSING = 0x01,
            NEEDS_NEWLINE_NORMALIZATION = 0x02,
            NEEDS_WHITESPACE_COLLAPSING = 0x04,

            TEXT_ELEMENT = NEEDS_ENTITY_PROCESSING | NEEDS_NEWLINE_NORMALIZATION,
            TEXT_ELEMENT_LEAVE_ENTITIES = NEEDS_NEWLINE_NORMALIZATION,
            ATTRIBUTE_NAME = 0,
            ATTRIBUTE_VALUE = NEEDS_ENTITY_PROCESSING | NEEDS_NEWLINE_NORMALIZATION,
            ATTRIBUTE_VALUE_LEAVE_ENTITIES = NEEDS_NEWLINE_NORMALIZATION,
            COMMENT = NEEDS_NEWLINE_NORMALIZATION
        };

        StrPair():_flags(0),_start(nullptr),_end(nullptr){}

        ~StrPair();

        void Set(char *start,char *end,int flags)
        {
            TIXMLASSERT(start);
            TIXMLASSERT(end);
            Reset();
            _start = start;
            _end = end;
            _flags = flags | NEEDS_FLUSH;
        }

        const char *GetStr();

        bool Empty()const
        {
            return _start == _end;
        }

        void SetInternedStr(const char *str)
        {
            Reset();
            _start = const_cast<char *>(str);
        }

        void SetStr(const char *str, int flags = 0);

        char *ParseText(char *in, const char *endTag,
                        int strFlags, int *curLineNumPtr);

        char *ParseName(char *in);

        void TransferTo(StrPair *other);

        void Reset();
    private:
        void CollapseWhitespace();

        enum {
            NEEDS_FLUSH = 0x100,
            NEEDS_DELETE = 0x200
        };

        int _flags;
        char *_start;
        char *_end;

        StrPair(const StrPair &other);// not support
        void operator=(const StrPair &other);// not support, use TransferTo()
    };
}

#endif //STANDARD_TEMPLATE_LIBRARIES_TIXML_H
