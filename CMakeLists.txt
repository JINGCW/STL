cmake_minimum_required(VERSION 3.14)
#set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
project(standard_template_libraries LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 14)

file(GLOB PRIMER_SRC
        "stl/src/_primer/*.cpp"
        "stl/src/_primer/*.cc"
        "stl/src/_primer/*.h"
)
file(GLOB INCL
        "stl/inc/*.h"
    )

add_executable(
        cpp_prime
        ${PRIMER_SRC}
        ${INCL}
)
##