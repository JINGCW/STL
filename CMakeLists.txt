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
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
#set(CMAKE_EXE_LINKER_FLAGS -static)

#set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")

#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

#lookup all source file save name to DIR_SRCS in pwd
aux_source_directory(. DIR_SRCS)
#add subdir
#add_subdirectory(stl)
#specify generate obj
#set(INC_DIR D:/c_repo/cpp_prime/bin)
#set(LINK_DIR D:/c_repo/cpp_prime/include)
#include_directories(${PROJECT_SOURCE_DIR}/lib)
message("+++++++++++++++++++++")
message(${PROJECT_SOURCE_DIR})
message(${CMAKE_SOURCE_DIR})
message("+++++++++++++++++++++")
#add_subdirectory(lib)

#link_directories(${PROJECT_SOURCE_DIR}/lib)
#add_library(_primer SHARED IMPORTED)
#link_directories("bin")
#add_executable(stl_exx main.cc app.rc)
add_executable(tetris main.cc app.rc)
#add link lib
#target_link_libraries(stl_exx _primer)
#target_link_libraries(stl_exx ${PROJECT_SOURCE_DIR}/cmake-build-debug/stl/lib_primer.dll)
##
