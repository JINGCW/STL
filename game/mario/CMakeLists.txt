cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(uMario)

#set(CMAKE_PREFIX_PATH D:/lua/SDL2-2.0.12)
#set(SDL2_DIR D:/lua/SDL2-2.0.12)
#set(CMAKE_PREFIX_PATH ${SDL2_DIR})
#find_package(SDL2 REQUIRED)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${uMario_SOURCE_DIR}/cmake")


message(STATUS "@@@SDL2_INCLUDE_DIR->${SDL2_INCLUDE_DIR}")
message(STATUS "@@@SDL2_LIBRARY_DIR->${SDL2_LIBRARY_DIR}")
include_directories(
        ${SDL2_INCLUDE_DIR}
)
if (MSVC_VERSION GREATER_EQUAL "1900")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
    if (_cpp_latest_flag_supported)
        add_compile_options("/std:c++latest")
    endif ()
elseif (GNU OR Clang)
    add_compile_definitions("-std=c++1z")
endif ()

link_directories(${SDL_LIBRARY_DIR})
FILE(GLOB uMarioSRCS
        "./*.cpp"
        "./*.h"
        )

if (MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "/SUBSYSTEM:CONSOLE")
endif ()

add_executable(uMario main.cpp uMario.rc ${uMarioSRCS})
#set_target_properties(sdl2_c++ PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
target_link_libraries(uMario
        ${SDL2_LIBRARIES}
        ${SDL2_mixer_LIBRARIES}
        ${SDL2_image_LIBRARIES}
        )
