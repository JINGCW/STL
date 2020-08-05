cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(recipe3 LANGUAGES CXX)

add_executable(_cmake_main3 "")
target_sources(_cmake_main3
        PRIVATE
        main.cpp)

target_compile_definitions(_cmake_main3 PUBLIC "COMPILER_NAME=\"${CMAKE_CXX_COMPILER_ID}\"")
# let the preprocessor know about the compiler vendor
if (CMAKE_CXX_COMPILER_ID MATCHES Intel)
    target_compile_definitions(_cmake_main3 PUBLIC "IS_INTEL_CXX_COMPILER")
elseif (CMAKE_CXX_COMPILER_ID MATCHES GNU)
    target_compile_definitions(_cmake_main3 PUBLIC "IS_GNU_CXX_COMPILER")
elseif (CMAKE_CXX_COMPILER_ID MATCHES PGI)
    target_compile_definitions(_cmake_main3 PUBLIC "IS_PGI_CXX_COMPILER")
elseif (CMAKE_CXX_COMPILER_ID MATCHES MSVC)
    target_compile_definitions(_cmake_main3 PUBLIC "IS_MSVC_CXX_COMPILER")
endif ()
