#include "webSocketSession.hpp"

WebSocketSession::WebSocketSession(
    boost::asio::ip::tcp::socket&& socket_)
    :ws(std::move(socket_)){


}

// Get on the correct executor
void WebSocketSession::run(){

    // We need to be executing within a strand to perform async operations
    // on the I/O objects in this session. Although not strictly necessary
    // for single-threaded contexts, this example code is written to be
    // thread-safe by default.
    boost::asio::dispatch(ws.get_executor(),
        boost::beast::bind_front_handler(
            &WebSocketSession::onRun,
            shared_from_this()));
}

// Start the asynchronous operation
void WebSocketSession::onRun(){

    // Set suggested timeout settings for the websocket
    ws.set_option(
        boost::beast::websocket::stream_base::timeout::suggested(
            boost::beast::role_type::server));

    // Set a decorator to change the Server of the handshake
    ws.set_option(boost::beast::websocket::stream_base::decorator(
        [](boost::beast::websocket::response_type& res)
        {
            res.set(boost::beast::http::field::server,
                std::string(BOOST_BEAST_VERSION_STRING) +
                    " websocket-server-async");
        }));
    // Accept the websocket handshake
    ws.async_accept(
        boost::beast::bind_front_handler(
            &WebSocketSession::onAccept,
            shared_from_this()));
}

void WebSocketSession::onAccept(
    boost::beast::error_code ec){

    if(ec)
        return fail(ec, "accept");

    // Read a message
    doRead();
}

void WebSocketSession::doRead(){

    // Read a message into our buffer
    ws.async_read(
        buffer,
        boost::beast::bind_front_handler(
            &WebSocketSession::onRead,
            shared_from_this()));

    std::cerr << boost::beast::make_printable(buffer.data()) << "\n";
}

void WebSocketSession::onRead(
    boost::beast::error_code ec,
    std::size_t bytes_transferred){

    boost::ignore_unused(bytes_transferred);

    // This indicates that the session was closed
    if(ec == boost::beast::websocket::error::closed)
        return;

    if(ec)
        fail(ec, "read");

    // Echo the message
    ws.text(ws.got_text());
    ws.async_write(
        buffer.data(),
        boost::beast::bind_front_handler(
            &WebSocketSession::onWrite,
            shared_from_this()));

    std::cout << boost::beast::make_printable(buffer.data());
}

void WebSocketSession::onWrite(
    boost::beast::error_code ec,
    std::size_t bytes_transferred){

    boost::ignore_unused(bytes_transferred);

    if(ec)
        return fail(ec, "write");

    // Clear the buffer
    buffer.consume(buffer.size());

    // Do another read
    doRead();
}

void WebSocketSession::fail(
    boost::beast::error_code ec,
    char const* what){

    // Don't report these
    if( ec == boost::asio::error::operation_aborted ||
        ec == boost::beast::websocket::error::closed)
        return;

    std::cerr << what << ": " << ec.message() << "\n";
}