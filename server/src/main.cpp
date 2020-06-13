#include <iostream>

#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

#include "config.hpp"
#include "util.hpp"

#include <boost/asio.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/random.hpp>

#include "grid.hpp"
#include "listener.hpp"
#include "webSocketSession.hpp"

int main(
    int argc,
    const char * argv[]){

    Config serverConfig(std::string(getpwuid(getuid())->pw_dir)+std::string("/.gridlock/server/server.conf"));

    unsigned int gridSize;
    unsigned int playerCount;

    std::cerr << "Grid size: ";
    std::cin >> gridSize;
    std::cerr << "\n";

    std::cerr << "Player count: ";
    std::cin >> playerCount;
    std::cerr << "\n";

    auto const address=(serverConfig.existsValue("host","address")?serverConfig.getValue("host","address"):
        exec("printf `ifconfig | grep -Eo 'inet (addr:)?([0-9]*\\.){3}[0-9]*' | grep -Eo '([0-9]*\\.){3}[0-9]*' | grep -v '127.0.0.1'`")).c_str();
    auto const port=(serverConfig.existsValue("host","port")?serverConfig.getValue("host","port"):std::string("1302")).c_str();//!!Easter egg!!
    auto const threads=8;

    // The io_context is required for all I/O
    boost::asio::io_context ioc{threads};

    // Create and launch a listening port
    std::make_shared<Listener>(
        ioc,
        boost::asio::ip::tcp::endpoint{
            boost::asio::ip::make_address(address),
            static_cast<unsigned short>(std::atoi(port))},
        boost::make_shared<Grid>(gridSize,4,4))->run();

    std::cerr << "[Enter] to start the server, [commant+c] to end:";
    std::cin.sync();
    std::cin.get();
    std::cin.ignore();
    std::cerr << "\n";

    std::cerr << "Starting server at " << address << ":" << port << "\n\n";

    // Capture SIGINT and SIGTERM to perform a clean shutdown
    boost::asio::signal_set signals(ioc,SIGINT,SIGTERM);
    signals.async_wait(
        [&](boost::beast::error_code const&, int){ioc.stop();});

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

    for(auto& t : v)
        t.join();

    return EXIT_SUCCESS;
}
