#include <iostream>
#include <asio.hpp>
#include "session.h"

using namespace asio;
using asio::ip::udp;

void manip::getData(udp::socket* socket) {
    char buff[1024];
    udp::endpoint sender_ep;

    int bytes = socket->receive_from(buffer(buff), sender_ep);
    std::string data(buff, bytes);
    std::cout << data;
}

void manip::sendData(udp::socket* socket, udp::endpoint& ep, std::string& u_name) {
    while (true) {
        std::string data;
        getline(std::cin, data);
        socket->send_to(buffer(u_name + data + "\n"), ep);
    }
}
