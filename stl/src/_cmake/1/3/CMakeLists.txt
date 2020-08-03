cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

option(USE_Static_LIB "use static lib" OFF)
option(USE_OBJ_LIB "use object lib" ON)

project(recipe-03 LANGUAGES CXX)

if (USE_Static_LIB)
    add_library(message
            STATIC
            message.cpp
            message.h
            )
endif ()

if (USE_OBJ_LIB)
    add_library(message_objs
            OBJECT
            message.cpp
            message.h)
    #static lib
    add_library(message_static
            STATIC
            $<TARGET_OBJECTS:message_objs>)
    set_target_properties(message_static
            PROPERTIES
            OUTPUT_NAME "message")
    #shared lib
    add_library(message_shared
            SHARED
            $<TARGET_OBJECTS:message_objs>)
    set_target_properties(message_shared
            PROPERTIES
            OUTPUT_NAME "message")

endif ()

add_executable(_cmake_main main.cpp)

if (USE_Static_LIB)
    target_link_libraries(_cmake_main message)
endif ()

if (USE_OBJ_LIB)
    target_link_libraries(_cmake_main message_shared)
endif ()
