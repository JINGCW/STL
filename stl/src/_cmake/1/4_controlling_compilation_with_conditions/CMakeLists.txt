cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(recipe-04 LANGUAGES CXX)

set(USE_LIB ON)
message(STATUS "compiling sources into a library?${USE_LIB}")

# BUILD_SHARED_LIBS is a global flag offered by CMake
# to toggle the behavior of add_library
set(BUILD_SHARED_LIBS OFF)

# list sources
list(APPEND _source message.h message.cpp)

if (USE_LIB)
    # add_library will create a static library
    # since BUILD_SHARED_LIBS is OFF
    add_library(message ${_source})
    add_executable(_cmake_main1-4 main.cpp)
    target_link_libraries(_cmake_main1-4 message)
else ()
    add_executable(_cmake_main main.cpp ${_source})
endif ()