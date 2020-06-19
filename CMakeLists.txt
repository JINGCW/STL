cmake_minimum_required(VERSION 3.14)
#set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
project(standard_template_libraries LANGUAGES CXX)


#set(CMAKE_CXX_STANDARD 14)

#file(GLOB PRIMER_SRC
#        "stl/src/_primer/*.cpp"
#        "stl/src/_primer/*.cc"
#        "stl/src/_primer/*.h"
#)
#file(GLOB INCL
#        "stl/inc/*.h"
#    )

#add_executable(
#        STL
#        ${PRIMER_SRC}
#        ${INCL}
#)
#lookup all source file save name to DIR_SRCS in pwd
aux_source_directory(. DIR_SRCS)
#add subdir
add_subdirectory(stl)
#specify generate obj
add_executable(stl_exx main.cc)
#add link lib
target_link_libraries(stl_exx _primer)
##
