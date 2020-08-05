cmake_minimum_required(VERSION 3.14)

project(recipe2-5 LANGUAGES CXX)

#define executable
add_executable(_cmake_main2_5 "")
#and it's source file
target_sources(_cmake_main2_5
        PRIVATE
        main.cpp)

#and it's include directories
message("2-5 target_include_directories: ${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(_cmake_main2_5
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR})

foreach (key IN ITEMS
        NUMBER_OF_LOGICAL_CORES
        NUMBER_OF_PHYSICAL_CORES
        TOTAL_VIRTUAL_MEMORY
        AVAILABLE_VIRTUAL_MEMORY
        TOTAL_PHYSICAL_MEMORY
        AVAILABLE_PHYSICAL_MEMORY
        IS_64BIT
        HAS_FPU
        HAS_MMX
        HAS_MMX_PLUS
        HAS_SSE
        HAS_SSE2
        HAS_SSE_FP
        HAS_SSE_MMX
        HAS_AMD_3DNOW
        HAS_AMD_3DNOW_PLUS
        HAS_IA64
        OS_NAME
        OS_RELEASE
        OS_VERSION
        OS_PLATFORM)
    cmake_host_system_information(RESULT _${key} QUERY ${key})
endforeach ()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
        ${CMAKE_CURRENT_SOURCE_DIR}/config.h
        @ONLY)
