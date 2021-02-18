#ifndef SESSION_HPP
#define SESSION_HPP

#include <asio.hpp>

using namespace asio;
using asio::ip::udp;

const std::string exitstring = "/exit";

class session {
public:
    session();
    static udp::socket sock(io_service& service, udp::endpoint ep);
    static void getData(udp::socket* socket);
    static void sendData(udp::socket* socket, udp::endpoint& ep, std::string& u_name);
};

#endif