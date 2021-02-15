#include <iostream>
#include <asio.hpp>
#include "session.h"

using namespace asio;
using asio::ip::udp;

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        asio::io_service io_service;
        server s;
        s.session(io_service, 500);
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}