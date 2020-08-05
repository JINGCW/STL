cmake_minimum_required(VERSION 3.14)

project(recipe-02-4 LANGUAGES CXX)

add_executable(_cmake_main2_4 main.cpp)

# let the preprocessor know about the size of void *
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    target_compile_definitions(_cmake_main2_4 PUBLIC "IS_64_BIT_ARCH")
    message(STATUS "target is 64bit.")
else ()
    target_compile_definitions(_cmake_main2_4 PUBLIC "IS_32_BIT_ARCH")
    message(STATUS "target is 32bit.")
endif ()

# let the preprocessor know about the host processor architecture
if (CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "i386")
    message(STATUS "i386 arch detected.")
elseif (CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "i686")
    message(STATUS "i684 arch detected.")
elseif (CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")
    message(STATUS "x86_64 arch detected.")
else ()
    message(STATUS "unknown arch detected.")
endif ()

target_compile_definitions(_cmake_main2_4
        PUBLIC
        "ARCHITECTURE=${CMAKE_HOST_SYSTEM_PROCESSOR}")
