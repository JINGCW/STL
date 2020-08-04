cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(recipe-10 LANGUAGES CXX)

#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

message("1-10 c++ compiler flags: ${CMAKE_CXX_FLAGS}")

add_library(message1_10
        SHARED
        message.cpp
        message.h)

# we wish to compile the library with the optimization flag: -O3
target_compile_options(message1_10
        PRIVATE
        -O3)

add_library(geometry1_10
        SHARED
        geometry_circle.h
        geometry_circle.cpp)


list(APPEND sources_with_lower_optimization
        geometry_circle.cpp
        geometry_circle.h)

# we use the IN LISTS foreach syntax to set source properties
message(STATUS "Setting source properties using IN LISTS syntax:")
foreach (_source IN LISTS sources_with_lower_optimization)
    set_source_files_properties(${_source} PROPERTIES COMPILE_FLAGS -O3)
    message(STATUS "Appending -O3 flags for ${_source}")
endforeach ()
# we demonstrate the plain foreach syntax to query source properties
# which requires to expand the contents of the variable
message(STATUS "Querying sources properties using plain syntax:")
foreach (_source IN LISTS sources_with_lower_optimization)
    get_source_file_property(_flags ${_source} COMPILE_FLAGS)
    message(STATUS "source ${_source} has the following extra COMPILE_FLAGS: ${_flags}")
endforeach ()

add_executable(_cmake_main1_10 main.cpp)

target_link_libraries(_cmake_main1_10 message1_10 geometry1_10)
