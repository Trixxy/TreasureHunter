/***********************************************************
export LD_LIBRARY_PATH=/opt/gcc/4.8.1/lib64/
export LD_PRELOAD=/opt/gcc/4.8.1/lib64/libstdc++.so.6
***********************************************************/

#include <boost/asio.hpp>
#include <iostream>
#include <thread>
#include "game.hpp"
#include <cstdio>

using boost::asio::ip::tcp;

void server(){
	try{
    	boost::asio::io_service io_service;
	    tcp::endpoint endpoint(tcp::v4(), 4242);
    	tcp::acceptor acceptor(io_service, endpoint);

    	tcp::iostream stream;
    	stream.rdbuf()->pubsetbuf(0, 0);
    	boost::system::error_code ec;
    	acceptor.accept(*stream.rdbuf(), ec);
    	if (!ec){
    		stream << "Poke\n";
    		std::string line;
	   	 	stream >> line;
	    	std::cout << line << std::endl;
    	}
  	}
  	catch (std::exception& e)
  	{
  		std::cerr << e.what() << std::endl;
  	}
}

void client(){

	try{
	    tcp::iostream s("127.0.0.1", "4242");
	    s.rdbuf()->pubsetbuf(0, 0);
	    if (!s)
	    {
	      //std::cout << "Unable to connect: " << s.error().message() << std::endl;
	      return;
	    }

	    std::string line;
	    std::getline(s, line);
	    std::cout << line << std::endl;
	    s << "Poked\n";
  	}
  	catch (std::exception& e)
  	{
    	std::cout << "Exception: " << e.what() << std::endl;
  	}
}

int main(){

//  printf("\033[6;3HHello\n");

  using namespace cprogame;

//  std::cout << "Hello, world!\n";
  Game g;
//  std::cout << "Game initialized!\n";
  g.run();
//  std::cout << "Game terminated!\n";


	// std::cout << BOOST_VERSION << std::endl;
	// std::thread s(server);
 //    std::thread c(client);
 //    s.join();
 //    c.join();

	return 0;
}

