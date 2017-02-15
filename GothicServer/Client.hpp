#pragma once
#include <iostream>
#include <string>
#include <SFML\Network.hpp>

class Client
{
	sf::TcpSocket _socket;

public:
	Client(const std::string IP, const unsigned short PORT)
	{
		// Establish a connection to the server.
		sf::Socket::Status status = _socket.connect(IP, PORT);
		if (status != sf::Socket::Done) 
			std::cerr << "Cannot connect to " << IP << " on port " << PORT << std::endl;
	}
};

