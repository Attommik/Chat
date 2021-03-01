cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(Server VERSION 0.0.1 LANGUAGES CXX)

add_executable(Server main.cpp session.cpp session.h)

target_link_libraries(Server PRIVATE ASIO::ASIO)

