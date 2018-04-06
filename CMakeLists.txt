cmake_minimum_required(VERSION 2.8)

project(scratch CXX)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

set(CMAKE_CXX_FLAGS_DEBUG
    "${CMAKE_CXX_FLAGS} -O0 -g3 -pg -ftest-coverage -fprofile-arcs")

add_executable(scratch main.cpp)
add_executable(templates templates.cpp)
add_executable(hexscratch hexscratch.cpp)
