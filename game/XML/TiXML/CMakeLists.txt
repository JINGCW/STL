cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(tinyxml2)

# set lib version
set(GENERIC_LIB_VERSION "8.0.0")
set(GENERIC_LIB_SOVERSION "8")

option(BUILD_SHARED_LIBS "build as shared library" ON)
# to allow using tinyxml in another shared library
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

add_library(tinyxml2 tinyxml2.cpp tinyxml2.h)

set_target_properties(tinyxml2 PROPERTIES
        DEFINE_SYMBOL "TINYXML2_EXPORT"
        VERSION "${GENERIC_LIB_VERSION}"
        SOVERSION "${GENERIC_LIB_SOVERSION}")
