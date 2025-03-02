#pragma once

#include <boost/asio.hpp>

#include <iostream>
#include <array>
#include <memory>

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
private:
    tcp::socket socket_;
    std::array<char, 1024> data_;

    void do_read();
    void send();
public:
    Session(tcp::socket socket);

    void start();
};