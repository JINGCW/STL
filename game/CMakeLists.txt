cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(games)

file(GLOB GAMES_SRCS
        "./*.cpp"
        "./*.h"
        )

add_library(games ${GAMES_SRCS})
