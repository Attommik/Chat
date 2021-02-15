#include <iostream>
#include <functional>
#include <asio.hpp>
#include "session.h"

using namespace asio;
using asio::ip::udp;

int main()
{
    io_service service;

    udp::socket socket(service, udp::endpoint(udp::v4(), 0) );
    udp::endpoint ep(ip::address::from_string("127.0.0.1"), 500);

    std::string u_name;
    std::cout << "Enter your name: ";
    getline(std::cin, u_name);
    u_name += ": ";

    manip mp;
    while(true)
    {
        asio::thread g(std::bind(mp.sendData, &socket, ep, u_name));
        mp.getData(&socket);
    }

    return 0;
}