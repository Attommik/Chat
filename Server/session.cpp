#include <iostream>
#include <vector>
#include <asio.hpp>
#include "session.h"

using namespace asio;
using asio::ip::udp;

void server::addEndpoint(const udp::endpoint& endP) {
    for (auto &endpoint : endpoints)
        if (endP == endpoint)
            return;

    endpoints.push_back(endP);
}

void server::session(asio::io_service& io_service, unsigned short port) {
    udp::socket socket(io_service, udp::endpoint(udp::v4(), port));

    udp::endpoint sender_ep;
    char buff[1024];

    while (true) {
        try {
            int bytes = socket.receive_from(buffer(buff), sender_ep);
            std::string msg(buff, bytes);

            addEndpoint(sender_ep);
            for (auto &endpoint : endpoints) {
                if (endpoint != sender_ep)
                    socket.send_to(buffer(msg), endpoint);
            }
            std::cout << msg;
        }
        catch (std::exception &e) {
            endpoints.erase(remove(endpoints.begin(), endpoints.end(), sender_ep), endpoints.end());

            std::cerr << "Exception in thread: " << e.what() << "\n";
        }
    }
}


