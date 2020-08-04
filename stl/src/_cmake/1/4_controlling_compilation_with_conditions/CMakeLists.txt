cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(recipe-04 LANGUAGES CXX)

set(USE_LIB ON)
message(STATUS "compiling sources into a library?${USE_LIB}")

#specify the compiler
message(STATUS "Is the c++ compiler loaded?${CMAKE_CXX_COMPILER_LOADED}")
if (CMAKE_CXX_COMPILER_LOADED)
    message(STATUS "The c++ compiler ID is: ${CMAKE_CXX_COMPILER_ID}")
    message(STATUS "Is the c++ from GNU?${CMAKE_COMPILER_IS_GNUCXX}")
    message(STATUS "The c++ compiler version: ${CMAKE_CXX_COMPILER_VERSION}")
endif ()
message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")

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
