#ifndef SESSION_H
#define SESSION_H

#include <vector>
#include <asio.hpp>

using namespace asio;
using asio::ip::udp;

typedef std::vector<udp::endpoint> array;

class server {
private:
    array endpoints;

public:
    server();
    void addEndpoint( asio::ip::udp::endpoint& endP);

    void session(asio::io_service& io_service, unsigned short port);
};

#endif