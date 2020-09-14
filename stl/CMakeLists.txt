cmake_minimum_required(VERSION 3.14)

#project(_primer)
project(_pybind11_ex)

#set(CMAKE_CXX_STANDARD 17)


#set (Torch_DIR D:/Torch/libtorch)
#set(Torch_INCLUDE_DIR ${Torch_DIR}/include)
#set(Torch_LIBRARIES ${Torch_DIR}/lib)
#unset(CMAKE_PREFIX_PATH CACHE)


#aux_source_directory(src/_primer DIR_LIB_SRCS_PRIMER)
add_subdirectory(src/_cmake/1/3)#todo remove this line
add_subdirectory(src/_cmake/1/4_controlling_compilation_with_conditions)#todo remove this line
add_subdirectory(src/_cmake/1/8_control_compiler_flags)
add_subdirectory(src/_cmake/1/9_set_standard_for_lang)
add_subdirectory(src/_cmake/1/10_use_control_flow_constructs)
add_subdirectory(src/_cmake/2_detect_env/4_discover_host_processor_arch)
#add_subdirectory(src/_cmake/2_detect_env/5_discover_host_processor_instruction_set)
add_subdirectory(src/_cmake/2_detect_env/6_enable_vec_for_eigen_lib)
add_subdirectory(src/_cmake/3_deal_compiler-dependent_src)
#add_subdirectory(src/this_torch)


FILE(GLOB SRCS
        "src/_primer/*"
        "src/_templates/*"
#        "src/_torch/*"
#        "src/_pybind11"
        )

FILE(GLOB pybind11_srcs
        "src/_pybind11/*.h"
        "src/_pybind11/*.cpp"
        )

#add_library(_primer SHARED ${SRCS})

#add_library(pybind11_example SHARED ${pybind11_srcs})
#interface library target
#add_library(pybind11_example MODULE ${pybind11_srcs})
#add_library(_primer SHARAED ${DIR_LIB_SRCS_PRIMER})
