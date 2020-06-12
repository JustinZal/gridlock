#include <iostream>

#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>

#include "grid.hpp"
#include "listener.hpp"
#include "webSocketSession.hpp"

int main(
    int argc,
    const char * argv[]){

    // Check command line arguments.
    if (argc != 3)
    {
        std::cerr <<
            "Usage: websocket-server-async <address> <port> <threads>\n" <<
            "Example:\n" <<
            "    gridlock 8080\n";
        return EXIT_FAILURE;
    }

    auto const address = boost::asio::ip::make_address(argv[1]);
    auto const port = static_cast<unsigned short>(std::atoi(argv[2]));
    auto const threads = 8;

    // The io_context is required for all I/O
    boost::asio::io_context ioc{threads};

    // Create and launch a listening port
    std::make_shared<Listener>(
        ioc,
        boost::asio::ip::tcp::endpoint{address,port},
        boost::make_shared<Grid>())->run();

    // Run the I/O service on the requested number of threads
    std::vector<std::thread> v;
    v.reserve(threads - 1);
    for(auto i = threads - 1; i > 0; --i)
        v.emplace_back(
        [&ioc]
        {
            ioc.run();
        });
    ioc.run();

    return EXIT_SUCCESS;
}
