cmake_minimum_required(VERSION 3.20)
project(ruleta)

set(CMAKE_CXX_STANDARD 23)

add_executable(ruleta header.h main.cpp operaciones.cpp)
