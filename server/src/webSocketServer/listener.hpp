#ifndef GRIDLOCK_LISTENER_HPP
#define GRIDLOCK_LISTENER_HPP

#include <stdexcept>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/dispatch.hpp>
#include <boost/asio/strand.hpp>

#include "grid.hpp"
#include "constants.hpp"
#include "webSocketSession.hpp"

#include "listener.hpp"

class Listener:public std::enable_shared_from_this<Listener>{
private:
    boost::asio::io_context& ioc;
    boost::asio::ip::tcp::acceptor acceptor;
    boost::shared_ptr<Grid> grid;

    void fail(
        boost::beast::error_code ec,
        char const* what);

    void do_accept();

    void on_accept(
        boost::beast::error_code ec,
        boost::asio::ip::tcp::socket socket);

public:
    Listener(
        boost::asio::io_context& ioc_,
        boost::asio::ip::tcp::endpoint endpoint,
        boost::shared_ptr<Grid> const& state);

    // Start accepting incoming connections
    void run();
};

#endif