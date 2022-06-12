cmake_minimum_required(VERSION 3.23)

project(GB LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

add_executable(GB main.cpp myclasses.h myclasses.cpp dz7.pb.h dz7.pb.cc)
