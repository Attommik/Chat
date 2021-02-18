cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(Chat VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_library(asio INTERFACE)
target_include_directories(asio INTERFACE C:/msys64/mingw64/include)

add_subdirectory(Server)
add_subdirectory(Client)
