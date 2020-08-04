cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(recipe-02_1 LANGUAGES CXX)

# print custom message depending on the operating system
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "configuring for linux.")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message(STATUS "configuring for darwin.")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "configuring for windows.")
elseif (CMAKE_SYSTEM_NAME STREQUAL "AIX")
    message(STATUS "configuring for IBM AIX.")
else ()
    message(STATUS "configuring for ${CMAKE_SYSTEM_NAME}")
endif ()
