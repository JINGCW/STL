cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(ConanCaveman LANGUAGES CXX)

set(TARGET_NAME ConanCaveman)

aux_source_directory(. MCC_SRCS)


add_executable(${TARGET_NAME} ${MCC_SRCS})

target_link_libraries(${TARGET_NAME}
        ${SDL2_LIBRARIES}
        #        ${SDL2_image_LIBRARIES}
        ${SDL2_mixer_LIBRARIES}
        )
