cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(sdl2_c++)

#set(CMAKE_PREFIX_PATH D:/lua/SDL2-2.0.12)
#set(SDL2_DIR D:/lua/SDL2-2.0.12)
#set(CMAKE_PREFIX_PATH ${SDL2_DIR})
#find_package(SDL2 REQUIRED)

message(STATUS "@@@SDL2_INCLUDE_DIR->${SDL2_INCLUDE_DIR}")
message(STATUS "@@@SDL2_LIBRARY_DIR->${SDL2_LIBRARY_DIR}")
include_directories(
        ${SDL2_INCLUDE_DIR}
)

link_directories(${SDL_LIBRARY_DIR})
FILE(GLOB sdl2c++SRCS
        "./*.cpp"
        "./*.h"
        )

add_executable(sdl2_c++ main.cpp sdl2c++.rc ${sdl2c++SRCS})
target_link_libraries(sdl2_c++
        ${SDL2_LIBRARIES}
#        ${SDL2_image_LIBRARIES}
        )
