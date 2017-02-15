#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <SFML\Network.hpp>

template<const unsigned short PORT>
class Server
{
	sf::TcpListener _listener;
	std::vector<sf::TcpSocket> _clients;

public:
	void update()
	{
		// Bind the listener that listens to incoming connections to port.
		if (_listener.listen(PORT) != sf::Socket::Done)
			std::cerr << "Server can't listen on port " << PORT << std::endl;

		// Accept a new connection.

	}
};

