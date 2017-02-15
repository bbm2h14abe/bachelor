#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <memory>

#include <SFML\Graphics.hpp>

#include "IScreen.hpp"

/*
	Program-routine that handles the basic functionality of the engine and also creates and updates the window.
*/
class Program
{
	static sf::RenderWindow _window;
	static std::unique_ptr<IScreen> _screen;

public:
	static const bool init();
	static const bool run();

private:
	static std::map<std::string, std::string> readSettings(const std::string fileName);

};

