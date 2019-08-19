cmake_minimum_required(VERSION 3.0)
project(cpp_optimization)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
    ${CMAKE_HOME_DIRECTORY}/lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_HOME_DIRECTORY}/bin)

include_directories(utilities)

add_library(Utilities SHARED
        utilities/timer.cpp
        utilities/timer.h)

add_executable(vectors source/Vectors.cpp)
add_executable(printing source/Printing.cpp)
add_executable(move_semantics source/MoveSemantics.cpp)

target_link_libraries(vectors Utilities)
target_link_libraries(printing Utilities)
target_link_libraries(move_semantics Utilities)
