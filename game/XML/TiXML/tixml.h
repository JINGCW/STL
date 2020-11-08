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

#endif //STANDARD_TEMPLATE_LIBRARIES_TIXML_H
