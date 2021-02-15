#ifndef SESSION_HPP
#define SESSION_HPP

#include <asio.hpp>

using namespace asio;
using asio::ip::udp;

class manip {
public:
    static void getData(udp::socket* socket);

    static void sendData(udp::socket* socket, udp::endpoint& ep, std::string& u_name);
};

#endif