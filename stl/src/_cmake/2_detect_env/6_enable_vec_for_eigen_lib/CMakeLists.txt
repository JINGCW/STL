cmake_minimum_required(VERSION 3.14)

project(recipe2_6 LANGUAGES CXX)

option(USE_Optimization "use optimization compile options" OFF)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EIGEN3_INCLUDE_DIR D:/eigen/eigen-3.3.7)
#find_package(Eigen3 3.3.7 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-march=native" _march_native_works)
check_cxx_compiler_flag("-xHost" _xhost_works)

set(_cxx_flags)
if (_march_native_works)
    message(STATUS "Using processor's vector instructions (-march=native compiler flag set)")
    set(_cxx_flags "-march=native")
elseif (_xhost_works)
    message(STATUS "Using processor's vector instructions (-xHost compiler flag set)")
    set(_cxx_flags "-xHost")
else ()
    message(STATUS "No suitable compiler flag found for vectorization")
endif ()


if (USE_Optimization)
    add_executable(_cmake_main2_6_optimize main.cpp)
    target_compile_options(_cmake_main2_6_optimize
            PRIVATE
            ${_cxx_flags})
    #target_link_libraries(_cmake_main2_6_optimize
    #        PRIVATE
    #        Eigen)
else ()
    add_executable(_cmake_main2_6_unoptimize main.cpp)
    #target_link_libraries(_cmake_main2_6_unoptimize
    #        PRIVATE
    #        Eigen)
endif ()
