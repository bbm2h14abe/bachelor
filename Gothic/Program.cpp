#include "Program.hpp"
#include "SplashScreen.hpp"

sf::RenderWindow Program::_window;

// Load settings from file and create window.
const bool Program::init()
{
	auto settings = readSettings("Config.cfg");

	const unsigned WINDOW_WIDTH = std::atoi(settings["WINDOW_WIDTH"].c_str());
	const unsigned WINDOW_HEIGHT = std::atoi(settings["WINDOW_HEIGHT"].c_str());
	const unsigned WINDOW_BPP = std::atoi(settings["WINDOW_BPP"].c_str());
	const unsigned MAX_FPS = std::atoi(settings["MAX_FPS"].c_str());

	_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BPP), "", sf::Style::Close);
	_window.setFramerateLimit(MAX_FPS);

	_screen = std::make_unique<IScreen>(new SplashScreen);

	return true;
}

// Open the window and updating.
const bool Program::run()
{
	sf::Event event; 

	while (_window.isOpen())
	{
		while (_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) _window.close();
		}

		_screen->update();

		_window.clear();
		_window.draw(*_screen);
		_window.display();
	}

	return true;
}

/*
	Reading the settings from a file.

	Structure:
		WINDOW_WIDTH 800
		WINDOW_HEIGHT 600
*/
std::map<std::string, std::string> Program::readSettings(const std::string fileName)
{
	std::ifstream dat{ fileName };
	std::map<std::string, std::string> settings;

	std::string key = "", val = "";
	while (dat >> key >> val) settings[key] = val;

	return settings;
}