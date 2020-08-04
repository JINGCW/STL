cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(recipe-02_2 LANGUAGES CXX)

add_executable(_cmake_main_2_2 main.cpp)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_definitions(_cmake_main_2_2 PUBLIC "IS_LINUX")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_compile_definitions(_cmake_main_2_2 PUBLIC "IS_MACOS")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_definitions(_cmake_main_2_2 PUBLIC "IS_WINDOWS")
endif ()