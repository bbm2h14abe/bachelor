#include <iostream>

#include <SFML\Graphics.hpp>
#include <SFML\Network.hpp>

#define ENTITY_SPEED 200

template<int ID, unsigned short PORT>
void client_code()
{
	sf::TcpSocket socket;
	if (socket.connect("127.0.0.1", PORT) != sf::TcpSocket::Done)
	{
		std::cerr << "Cannot connect to 127.0.0.1 on PORT " << PORT << std::endl;
	}

	sf::Packet p;
	p << ID;

	if (socket.send(p) != sf::TcpSocket::Done)
	{
		std::cerr << "Cannot send ID!" << std::endl;
	}

	sf::RectangleShape entity{ sf::Vector2f{ 128, 128 } };
	entity.setFillColor(sf::Color::Red);
	entity.setPosition(200, 200);

	sf::RenderWindow window{ sf::VideoMode{ 1024, 768, 32 }, "", sf::Style::Close };
	sf::Event event;
	sf::Clock clock;

	while (window.isOpen())
	{
		const float delta = clock.restart().asSeconds();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		bool resend_data = false;
		if (ID == 1)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){ entity.move(0, -ENTITY_SPEED * delta); resend_data = true; }
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){ entity.move(0, ENTITY_SPEED * delta); resend_data = true; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){ entity.move(-ENTITY_SPEED * delta, 0); resend_data = true; }
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){ entity.move(ENTITY_SPEED * delta, 0); resend_data = true; }
		}
		else if (ID == 2)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){ entity.move(0, -ENTITY_SPEED * delta); }
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){ entity.move(0, ENTITY_SPEED * delta); }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){ entity.move(-ENTITY_SPEED * delta, 0); }
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){ entity.move(ENTITY_SPEED * delta, 0); }
		}
		else std::cerr << "Unknown ID" << std::endl;
		
		if (resend_data)
		{
			sf::Packet p;
			p << entity.getPosition().x << entity.getPosition().y;

			if (socket.send(p) != sf::TcpSocket::Done)
			{
				std::cerr << "Cannot send position!" << std::endl;
			}
		}

		window.clear();
		window.draw(entity);
		window.display();
	}
}

int main()
{
	/*
		Server code
	*/
	sf::Thread server{ [](){ 
		// Create listener.
		sf::TcpListener listener;

		// Bind listener to port.
		if (listener.listen(1234) != sf::TcpListener::Done)
		{
			std::cerr << "Cannot listen to 1234!" << std::endl;
		}

		while (true)
		{
			// Accept a new connection.
			sf::TcpSocket client;
			if (listener.accept(client) != sf::TcpListener::Done)
			{
				std::cerr << "Cannot accept client!" << std::endl;
				continue;
			}

			sf::Packet p;
			if (client.receive(p) != sf::TcpSocket::Done)
			{
				std::cerr << "Could not receive data!" << std::endl;
				continue;
			}

			int client_id;
			p >> client_id;
			std::cout << "Message received from " << client.getRemoteAddress().toString() << ", " << client.getRemotePort() << std::endl;
			std::cout << client_id << std::endl;
		}
	} };

	/*
		Client code
	*/
	sf::Thread client_a{ client_code<1, 1234> }, client_b{ client_code<2, 1234> };

	server.launch();
	client_a.launch();
	client_b.launch();

	return 0;
}

