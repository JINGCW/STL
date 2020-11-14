cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(games)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
#set(CMAKE_C++_CREATE_SHARED_LIBRARY ON)
#set(LUA_DIR D:/lua/5.1)
#
#set(CMAKE_PREFIX_PATH ${LUA_DIR})
#set(Lua_INCLUDE_DIR ${LUA_DIR}/include)
#set(Lua_LIBRARY_DIR ${LUA_DIR}/lib)
#find_package(Lua REQUIRED)
#if (NOT Lua_FOUND)
#    message(Lua is not found!!!)
#else ()
#    message(STATUS "    Lua found!!!->${Lua_VERSION}")
#endif ()
#include_directories(${Lua_INCLUDE_DIR})
#link_directories(${Lua_LIBRARY_DIR})
##lutok2
#include_directories(tools/lutok2-master/include)
#link_directories(tools/lutok2-master/include)

add_subdirectory(sdl2game)
add_subdirectory(mario)
add_subdirectory(fmod_api_core_ex)
add_subdirectory(XML/TiXML)

file(GLOB GAMES_SRCS
#        "./*.cpp"
#        "./*.h"
#        "lthis_object.h"
        "ExampleObject.h"
#        "python_dll_test.h"
#        "python_dll_test.cpp"
        "ExampleObject.cpp"
#        "games.cpp"
#        "my_math.c"
        )

#aux_source_directory(${PROJECT_SOURCE_DIR}/tools/lutok2-master/include lutok2_SRCS)

#set(LTARGET_NAME this_object__Object)
set(LTARGET_NAME Example)
#set(LTARGET_NAME my_math)
add_library(${LTARGET_NAME} SHARED ${GAMES_SRCS} ExampleObject.cpp my_math.c)
message(STATUS "games ${PROJECT_SOURCE_DIR}")

#set_target_properties(games PROPERTIES LINKER_LANGUAGE C++)
target_link_libraries(${LTARGET_NAME} ${LUA_LIBRARIES})
