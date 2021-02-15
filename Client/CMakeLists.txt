cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(Client VERSION 0.0.1 LANGUAGES CXX)

add_executable(Client main.cpp session.cpp session.h)

target_link_libraries(Client PRIVATE asio)

