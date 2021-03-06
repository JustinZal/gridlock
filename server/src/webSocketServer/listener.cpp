#include "listener.hpp"

Listener::Listener(
    boost::asio::io_context& _ioc,
    boost::asio::ip::tcp::endpoint _endpoint,
    boost::shared_ptr<Grid> const& _grid):
    ioc(_ioc),
    acceptor(_ioc),
    grid(_grid){

    boost::beast::error_code ec;

    // Open the acceptor
    acceptor.open(_endpoint.protocol(), ec);
    if(ec)
    {
        fail(ec, "open");
        return;
    }

    // Allow address reuse
    acceptor.set_option(boost::asio::socket_base::reuse_address(true), ec);
    if(ec)
    {
        fail(ec, "set_option");
        return;
    }

    // Bind to the server address
    acceptor.bind(_endpoint, ec);
    if(ec)
    {
        fail(ec, "bind");
        return;
    }

    // Start listening for connections
    acceptor.listen(boost::asio::socket_base::max_listen_connections, ec);
    if(ec)
    {
        fail(ec, "listen");
        return;
    }
}

void Listener::doAccept(){

    // The new connection gets its own strand
    acceptor.async_accept(
        boost::asio::make_strand(ioc),
        boost::beast::bind_front_handler(
            &Listener::onAccept,
            shared_from_this()));
}

// Start accepting incoming connections
void Listener::run(){

    doAccept();
}

void Listener::onAccept(
    boost::beast::error_code ec,
    boost::asio::ip::tcp::socket socket){

    std::cerr << socket.remote_endpoint().address().to_string() << std::endl;

    if(ec)
    {
        fail(ec, "accept");
    }
    else
    {
        // Create the session and run it
        std::make_shared<WebSocketSession>(std::move(socket),grid)->run();
    }

    // Accept another connection
    doAccept();
}

void Listener::fail(
    boost::beast::error_code ec,
    char const* what){

    // Don't report on canceled operations
    if(ec==boost::asio::error::operation_aborted)
        return;
    std::cerr << what << ": " << ec.message() << "\n";
}