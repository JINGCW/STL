cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(recipe-08 LANGUAGES CXX)

message("1-9 c++ compiler flags: ${CMAKE_CXX_FLAGS}")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(message1_9
        SHARED
        message.h
        message.cpp)

set_target_properties(message1_9
        PROPERTIES
        CXX_STANDARD 14
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
        POSITION_INDEPENDENT_CODE 1)

add_executable(_cmake_main1_9 main.cpp)

set_target_properties(_cmake_main1_9
        PROPERTIES
        CXX_STANDARD 14
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
        )

target_link_libraries(_cmake_main1_9 message1_9)
