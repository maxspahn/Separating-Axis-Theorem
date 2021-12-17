# Only some requirements for the version of cmake
cmake_minimum_required(VERSION 2.8)
# project name, not really important at this point
project(sepAxisTheorem)

# This sets some requirements for the c++ version.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(sepAxisTheorem_INCLUDE_DIR "${sepAxisTheorem_SOURCE_DIR}/include")
include_directories(${sepAxisTheorem_INCLUDE_DIR})
add_executable(main
  "${sepAxisTheorem_SOURCE_DIR}/src/main.cpp"
  "${sepAxisTheorem_INCLUDE_DIR}/Intersect.h"
)
