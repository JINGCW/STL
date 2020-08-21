cmake_minimum_required(VERSION 3.14)
#set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
project(standard_template_libraries LANGUAGES CXX)

set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 2)
#set(BUILD_SHARED_LIBS OFF)
set(PYTHON_INCLUDE_PATH D:/Anaconda3/envs/vconda_summer_charts)
#set(Python3_FIND_VIRTUALENV "vconda_summer_charts")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(conda_sitepackage_dir D:/Anaconda3/envs/vconda_summer_charts/Lib/site-packages)

option(USE_THIS_Boost "Set to switch to build use Boost" OFF)
option(USE_Tetris "build Tetris" OFF)
option(USE_THIS_Torch1 "set to use torch" OFF)
option(USE_THIS_Python "set to use Python" ON)
option(USE_ORIGIN_Torch "set to use origin torch, not python package" ON)
option(USE_PythonPack_Pybind11 "set to use python sitepakcage pybind11" ON)

configure_file(
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_SOURCE_DIR}/config.h"
)

message(STATUS "use this torch: ->${USE_THIS_Torch1}")

if (${USE_THIS_Torch1} STREQUAL "ON")
    set(CUDNN_LIBRARY_PATH D:/cuDNN/cuda/lib)
    set(CUDNN_INCLUDE_PATH D:/cuDNN/cuda/include)
    set(python_torch_sitepackage D:/Anaconda3/envs/vconda_summer_charts/Lib/site-packages/torch)
    set(torch_origin D:/Torch/libtorch)
    if (USE_ORIGIN_Torch)
        set(CMAKE_PREFIX_PATH ${torch_origin}/share/cmake/Torch)
        set(Torch_DIR ${torch_origin})
    else ()
        set(CMAKE_PREFIX_PATH ${python_torch_sitepackage}/share/cmake/Torch)
        set(Torch_DIR ${python_torch_sitepackage})
    endif ()

    #        set(Torch_DIR_PATH D:/Torch/libtorch)
    #    set(Torch_LIBRARY_DIR D:/Torch/libtorch/lib)
    #    set(Torch_INCLUDE_DIR1 D:/Torch/libtorch/include)
    #    set(Torch_INCLUDE_DIR D:/Torch/libtorch/include/torch/csrc/api/include)

    find_package(Torch REQUIRED)
    #    find_package(CUDNN)

    if (NOT Torch_FOUND)
        message(STATUS "Torch not found!!!")
    else ()
        message(STATUS "Torch found!!!")
    endif ()
    message(STATUS "    Torch version: ${Torch_VERSION}")
    #    message(STATUS "    CUDNN version: ${CUDNN_VERSION}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")
    #find_package(OpenCV REQUIRED)

    #include_directories(${Torch_INCLUDE_DIRS})
    #include_directories(${OpenCV_INCLUDE_DIRS})
    message(STATUS "Torch_INCLUDE_DIRS " ${Torch_INCLUDE_DIR})
    #message("OpenCV_INCLUDE_DIRS " ${OpenCV_INCLUDE_DIRS})
else ()
    message("USE_THIS_Torch1 is not ON...")
endif ()

if (USE_THIS_Python)
    if (USE_PythonPack_Pybind11)
        set(PYTHON_EXECUTABLE ${PYTHON_INCLUDE_PATH}/python.exe)
        set(PYTHON_INCLUDE_DIR ${PYTHON_INCLUDE_PATH}/include)
        set(PYTHON_LIBRARY ${PYTHON_INCLUDE_PATH}/libs)
        find_package(Python REQUIRED)
    else ()
        set(PYTHON_INCLUDE_DIR "D:/Python38/include")
        set(PYTHON_LIBRARY_DIR "D:/Python38//libs")
        #    endif ()
    endif ()
    find_package(Python REQUIRED)
    if (NOT Python_FOUND)
        message(Python is not found!!!)
    else ()
        message(STATUS "    Python found!!!->${Python_VERSION}")
    endif ()
    include_directories(${Python_INCLUDE_DIR})
    link_directories(${Python_LIBRARY_DIR})
endif ()

#set(CMAKE_CXX_STANDARD 11)

if (USE_THIS_Boost)
    set(Boost_INCLUDE_DIR D:/boost_1_73_0)
    set(Boost_LIBRARY_DIR D:/boost_1_73_0/lib64-msvc-14.1)
    #set(Boost_LIBRARY_DIR "D:/boost_1_73_0/libs")
    find_package(Boost 1.73.0 COMPONENTS REQUIRED)
endif (USE_THIS_Boost)

if (USE_PythonPack_Pybind11)
    #    if (MSVC)
    #        set(PYBIND11_CPP_STANDARD /std:c++14)
    #        set(PYBIND11_CPP_STANDARD /std:c++latest) # Enables some MSVC C++17 features
    #    elseif (GNU OR Clang)
    #        #gcc/clang
    #        set(PYBIND11_CPP_STANDARD -std=c++11)
    #        set(PYBIND11_CPP_STANDARD -std=c++14)
    #        set(PYBIND11_CPP_STANDARD -std=c++1z)# Experimental C++17 support
    #    endif ()
    #    set(PYTHON_EXECUTABLE ${PYTHON_INCLUDE_PATH}/python.exe)
    set(pybind11_DIR D:/Anaconda3/envs/vconda_summer_charts/Library/share/cmake/pybind11)
    include_directories(${conda_sitepackage_dir}/pybind11/include)
    link_directories(${conda_sitepackage_dir}/pybind11/include)
endif ()
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
    #    include_directories(${Torch_INCLUDE_DIR})
    include_directories(${TORCH_INCLUDE_DIRS})

    #    include_directories(${Torch_INCLUDE_DIR1})
    #    include_directories(${CUDNN_INCLUDE_DIR})
    message(STATUS "Torch_INCLUDE_DIR:->-> ${Torch_INCLUDE_DIR}")
    link_directories(${Torch_LIBRARY_DIR})
    #    link_directories(${CUDNN_LIBRARY_DIR})
    #    link_directories(${Torch_LIBRARY_DIR1})
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
elseif (USE_THIS_Torch1)
    add_executable(torch_example main.cc app.rc)

    #    set_target_properties(torch_example PROPERTIES LINK_FLAGS "-WHOLEARCHIVE:torch_cpu.lib")
    message(STATUS "target link lib ->->${Torch_LIBRARIES}")
    target_link_libraries(torch_example ${Torch_LIBRARIES})
    #    set_property(TARGET torch_example PROPERTY CXX_STANDARD 14)
    # The following code block is suggested to be used on Windows.
    # According to https://github.com/pytorch/pytorch/issues/25457,
    # the DLLs need to be copied to avoid memory errors.
    if (MSVC)
        file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
        add_custom_command(TARGET torch_example
                POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${TORCH_DLLS}
                $<TARGET_FILE_DIR:torch_example>)
    endif (MSVC)
elseif (USE_PythonPack_Pybind11)
    #            add_subdirectory(${conda_sitepackage_dir}/pybind11/include)
    find_package(pybind11 REQUIRED)
    if (NOT pybind11_FOUND)
        message(pybind11 is not found!!!)
    else ()
        message("pybind11_version: ${pybind11_VERSION}")
    endif ()
    pybind11_add_module(pybind11_example
            stl/src/_pybind11/example.h
            stl/src/_pybind11/example.cpp
            )
    #interface library target
#        target_link_libraries(pybind11_example PRIVATE pybind11::module)
#        set_target_properties(pybind11_example PROPERTIES
#                PREFIX "${PYTHON_MODULE_PREFIX}"
#                SUFFIX "${PYTHON_MODULE_SUFFIX}"
#                )
else ()
    #    #add_library(_primer SHARED IMPORTED)
    #    #link_directories("bin")
    add_executable(stl_exx main.cc app.rc)
    #    #add_executable(tetris main.cc app.rc)
    #    add_executable(stl_exx main.cc app.rc)
    #    #add link lib
    #    target_link_libraries(stl_exx _primer)
    target_link_libraries(stl_exx _pybind11_ex)
    #target_link_libraries(stl_exx ${PROJECT_SOURCE_DIR}/cmake-build-debug/stl/lib_primer.dll)
    ##
endif (USE_THIS_Boost)
