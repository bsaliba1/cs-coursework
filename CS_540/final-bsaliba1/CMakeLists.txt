cmake_minimum_required(VERSION 3.14)
project(440_final)

set(CMAKE_CXX_STANDARD 14)

add_executable(emitter emitter/emitter.cpp)
add_executable(type_handler type_handler/type_handler.cpp)