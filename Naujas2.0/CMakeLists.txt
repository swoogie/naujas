cmake_minimum_required(VERSION 3.20)

set(This Naujas2.0)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99) 
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers 
    code/struct.hpp
)

set(Sources
    code/struct.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)