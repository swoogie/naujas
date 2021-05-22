cmake_minimum_required(VERSION 3.20)

set(This Tests)

project(${This} C CXX)

set(Sources
    Tests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main #google test main program
    Naujas2.0  #program that will be tested
)

add_test(
    NAME ${This}
    COMMAND ${This}
)