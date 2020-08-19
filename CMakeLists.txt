cmake_minimum_required(VERSION 3.14)
#set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
project(standard_template_libraries LANGUAGES CXX)

set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 2)

option(USE_THIS_Boost "Set to switch to build use Boost" ON)
option(USE_Tetris "build Tetris" OFF)
option(USE_THIS_Torch1 "set to use torch" ON)
option(USE_THIS_Python "set to use Python" OFF)

configure_file(
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_SOURCE_DIR}/config.h"
)

message(STATUS "use this torch: ->${USE_THIS_Torch1}")

if (${USE_THIS_Torch1} STREQUAL "ON")
    set(CUDNN_LIBRARY_PATH D:/cuDNN/cuda/lib)
    set(CUDNN_INCLUDE_PATH D:/cuDNN/cuda/include)
    set(CMAKE_PREFIX_PATH "D:/Torch/libtorch")
    #    set(Torch_DIR_PATH D:/Torch/libtorch)
    set(Torch_LIBRARY_DIR D:/Torch/libtorch/lib)
    set(Torch_INCLUDE_DIR1 D:/Torch/libtorch/include)
    set(Torch_INCLUDE_DIR D:/Torch/libtorch/include/torch/csrc/api/include)

    find_package(Torch REQUIRED)
#    find_package(CUDNN)

    if (NOT Torch_FOUND)
        message(STATUS "Torch not found!!!")
    else ()
        message(STATUS "Torch found!!!")
    endif ()
    message(STATUS "    Torch version: ${Torch_VERSION}")
#    message(STATUS "    CUDNN version: ${CUDNN_VERSION}")
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")
    #find_package(OpenCV REQUIRED)

    #include_directories(${Torch_INCLUDE_DIRS})
    #include_directories(${OpenCV_INCLUDE_DIRS})
    message(STATUS "Torch_INCLUDE_DIRS " ${Torch_INCLUDE_DIR})
    #message("OpenCV_INCLUDE_DIRS " ${OpenCV_INCLUDE_DIRS})
else ()
    message("USE_THIS_Torch1 is not ON...")
endif ()

if (USE_THIS_Python)
    set(Python_INCLUDE_DIR D:/Python38/include)
    set(Python_LIBRARY_DIR D:/Python38/libs)
    find_package(Python REQUIRED)
    if (NOT Python_FOUND)
        message(Python is not found!!!)
    else ()
        message(STATUS "    Python found!!!->${Python_VERSION}")
        include_directories(${Python_INCLUDE_DIR})
        link_directories(${Python_LIBRARY_DIR})
    endif ()
endif ()


#set(CMAKE_CXX_STANDARD 14)

if (USE_THIS_Boost)
    set(Boost_INCLUDE_DIR D:/boost_1_73_0)
    set(Boost_LIBRARY_DIR D:/boost_1_73_0/lib64-msvc-14.1)
    #set(Boost_LIBRARY_DIR "D:/boost_1_73_0/libs")
    find_package(Boost 1.73.0 COMPONENTS REQUIRED)
endif (USE_THIS_Boost)
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
add_subdirectory(stl)#todo remove this line or retain
#specify generate obj
#set(INC_DIR D:/c_repo/cpp_prime/bin)
#set(LINK_DIR D:/c_repo/cpp_prime/include)
#include_directories(${PROJECT_SOURCE_DIR}/lib)
if (USE_THIS_Boost)
    include_directories(${Boost_INCLUDE_DIR})
    message(STATUS "Boost_INCLUDE_DIR:->-> ${Boost_INCLUDE_DIR}")
endif (USE_THIS_Boost)

if (USE_THIS_Torch1)
    include_directories(${Torch_INCLUDE_DIR})
    include_directories(${Torch_INCLUDE_DIR1})
#    include_directories(${CUDNN_INCLUDE_DIR})
    message(STATUS "Torch_INCLUDE_DIR:->-> ${Torch_INCLUDE_DIR}")
    link_directories(${Torch_LIBRARY_DIR})
#    link_directories(${CUDNN_LIBRARY_DIR})
    link_directories(${Torch_LIBRARY_DIR1})
    message(STATUS "Torch libs: ->${Torch_LIBRARIES}")
endif ()

message("+++++++++++++++++++++")
message(${PROJECT_SOURCE_DIR})
message(${PROJECT_BINARY_DIR})
message(${CMAKE_SOURCE_DIR})
message("+++++++++++++++++++++")
#add_subdirectory(lib)

#link_directories(${PROJECT_SOURCE_DIR}/lib)

if (USE_THIS_Boost)
    link_directories(${Boost_LIBRARY_DIR})

    add_executable(boost_options main.cc app.rc)

    target_link_libraries(boost_options ${Boost_LIBRARIES})
    message(STATUS "Boost libs: ->${Boost_LIBRARIES}")

    if (USE_THIS_Torch1)
        message(STATUS "target link lib ->->${Torch_LIBRARIES}")
        target_link_libraries(boost_options ${Torch_LIBRARIES})
    endif ()

#    install(TARGETS boost_options DESTINATION bin)
#    install(FILES "${PROJECT_SOURCE_DIR}/config.h" DESTINATION include)
#
#    set(CPACK_GENERATOR "TGZ")
#    set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}-${VERSION_MAJOR}-${VERSION_MINOR}")
#    include(CPACK)
elseif (USE_Tetris)
    add_executable(tetris tetris.cc app.rc)
else ()
    #    #add_library(_primer SHARED IMPORTED)
    #    #link_directories("bin")
    add_executable(stl_exx main.cc app.rc)
    #    #add_executable(tetris main.cc app.rc)
    #    add_executable(stl_exx main.cc app.rc)
    #    #add link lib
    #target_link_libraries(stl_exx _primer)
    #target_link_libraries(stl_exx ${PROJECT_SOURCE_DIR}/cmake-build-debug/stl/lib_primer.dll)
    ##
endif (USE_THIS_Boost)
