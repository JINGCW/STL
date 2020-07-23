cmake_minimum_required(VERSION 3.14)

project(_primer)

set(CMAKE_CXX_STANDARD 17)


#aux_source_directory(src/_primer DIR_LIB_SRCS_PRIMER)
FILE(GLOB SRCS
        "src/_primer/*"
        "src/_templates/*"
        )
add_library(_primer SHARED ${SRCS})
#add_library(_primer SHARAED ${DIR_LIB_SRCS_PRIMER})
