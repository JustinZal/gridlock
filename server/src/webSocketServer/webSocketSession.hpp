#ifndef GRIDLOCK_WEBSOCKETSESSION_HPP
#define GRIDLOCK_WEBSOCKETSESSION_HPP

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

class WebSocketSession:public std::enable_shared_from_this<WebSocketSession>{
private:
    boost::beast::flat_buffer buffer_;
    boost::beast::websocket::stream<boost::beast::tcp_stream> ws_;
    boost::shared_ptr<Grid> state_;
    std::vector<boost::shared_ptr<std::string const>> queue_;

public:
    // Take ownership of the socket
    explicit WebSocketSession(
        boost::asio::ip::tcp::socket&& socket_);

    // Get on the correct executor
    void run();

    // Start the asynchronous operation
    void on_run();

    void on_accept(
        boost::beast::error_code ec);

    void do_read();

    void on_read(
        boost::beast::error_code ec,
        std::size_t bytes_transferred);

    void on_write(
        boost::beast::error_code ec,
        std::size_t bytes_transferred);

    void fail(
        boost::beast::error_code ec,
        char const* what);
};

#endif