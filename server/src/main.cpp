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

#include "grid.hpp"
#include "listener.hpp"
#include "webSocketSession.hpp"

int main(
    int argc,
    const char * argv[]){

    Config serverConfig(std::string(getpwuid(getuid())->pw_dir)+std::string("/.gridlock/server/server.conf"));

    auto const threads=8;

    // The io_context is required for all I/O
    boost::asio::io_context ioc{threads};

    // Create and launch a listening port
    std::make_shared<Listener>(
        ioc,
        boost::asio::ip::tcp::endpoint{
            boost::asio::ip::make_address(
                (serverConfig.exists_value("host","address")?serverConfig.get_value("host","address"):
                    exec("printf `ifconfig | grep -Eo 'inet (addr:)?([0-9]*\\.){3}[0-9]*' | grep -Eo '([0-9]*\\.){3}[0-9]*' | grep -v '127.0.0.1'`")).c_str()),
            static_cast<unsigned short>(std::atoi((
                serverConfig.exists_value("host","port")?serverConfig.get_value("host","port"):std::string("1302")).c_str()))},//!!Easter egg!!
        boost::make_shared<Grid>())->run();

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
