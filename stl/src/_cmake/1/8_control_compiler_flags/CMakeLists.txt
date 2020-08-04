cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(recipe-08 LANGUAGES CXX)

message("1-8 c++ compiler flags: ${CMAKE_CXX_FLAGS}")

list(APPEND flags "-fPIC" "-Wall")

if (NOT WIN32)
    list(APPEND flags "-Wextra" "-Wpedantic")
endif ()

add_library(message8
        STATIC
        message.cpp
        message.h)

target_compile_options(message8
        PRIVATE
        ${flags})

add_executable(_cmake_main8 main.cpp)

target_compile_options(_cmake_main8
        PRIVATE
        "-fPIC")

target_link_libraries(_cmake_main8 message8)
