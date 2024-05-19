cmake_minimum_required(VERSION 3.16)
project(decorator)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(decorator ${CMAKE_CURRENT_SOURCE_DIR}/decorator.cpp)

include(../CPack.cmake)
