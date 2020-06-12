#include <iostream>

#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>

#include "config.hpp"

#include "grid.hpp"
#include "listener.hpp"
#include "webSocketSession.hpp"

int main(
    int argc,
    const char * argv[]){

    Config serverConfig("server.conf");

    auto const threads=8;

    // The io_context is required for all I/O
    boost::asio::io_context ioc{threads};

    // Create and launch a listening port
    std::make_shared<Listener>(
        ioc,
        boost::asio::ip::tcp::endpoint{
            boost::asio::ip::make_address(
                serverConfig.exists_value("host","address")?serverConfig.get_value("host","address"):"172.0.0.1"),
            static_cast<unsigned short>(std::atoi((
                serverConfig.exists_value("host","address")?serverConfig.get_value("host","port"):std::string("1302")).c_str()))},//!!Easter egg!!
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
