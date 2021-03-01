cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(Chat VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

find_package(ASIO REQUIRED)
message(STATUS "ASIO found: ${ASIO_FOUND}")

add_subdirectory(Server)
add_subdirectory(Client)

