cmake_minimum_required(VERSION 3.24)
project(cppLox)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS)

add_executable(cppLox src/header/chunk.h src/header/common.h src/chunk.cpp src/main.cpp src/header/debug.h src/header/value.h src/value.cpp)
