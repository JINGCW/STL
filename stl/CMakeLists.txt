cmake_minimum_required(VERSION 3.14)

project(_primer)

set(CMAKE_CXX_STANDARD 17)


#aux_source_directory(src/_primer DIR_LIB_SRCS_PRIMER)
add_subdirectory(src/_cmake/1/3)#todo remove this line
add_subdirectory(src/_cmake/1/4_controlling_compilation_with_conditions)#todo remove this line

FILE(GLOB SRCS
        "src/_primer/*"
        "src/_templates/*"
        )
add_library(_primer SHARED ${SRCS})
#add_library(_primer SHARAED ${DIR_LIB_SRCS_PRIMER})
