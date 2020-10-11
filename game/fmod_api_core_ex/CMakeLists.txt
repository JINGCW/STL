cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(Play_Sound)

#set(CMAKE_PREFIX_PATH D:/lua/SDL2-2.0.12)
#set(SDL2_DIR D:/lua/SDL2-2.0.12)
#set(CMAKE_PREFIX_PATH ${SDL2_DIR})
#find_package(SDL2 REQUIRED)
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${uMario_SOURCE_DIR}/cmake")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
#set(fmod_target Play_Sound)
set(fmod_target Play_Stream)

if (MSVC_VERSION GREATER_EQUAL "1900")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
    if (_cpp_latest_flag_supported)
        add_compile_options("/std:c++latest")
    endif ()
elseif (GNU OR Clang)
    add_compile_definitions("-std=c++1z")
endif ()

FILE(GLOB Play_Sound_SRCS
        "common.cpp"
        "common.h"
        "common_platform.cpp"
        "common_platform.h"
#        "play_sound.cpp"
        "play_stream.cpp"
        )

if (MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "/SUBSYSTEM:CONSOLE")
endif ()

add_executable(${fmod_target} ${Play_Sound_SRCS})
message(STATUS "FMOD_LIBRARIES->: ${FMOD_LIBRARIES}")

target_link_libraries(${fmod_target}
        ${FMOD_LIBRARIES}
        )
