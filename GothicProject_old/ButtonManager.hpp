#pragma once

#include <iostream>
#include <vector>

#include <SFML\Graphics.hpp>

// ==========>> Shows button-text and manages cursor-position, also can switch screens
class ButtonManager
{
private:
	sf::Font m_font;
	std::vector<sf::Text> m_buttons;

public:
	void LoadContent();

	void AddButton(std::string string, sf::Vector2f position);
	void Update();
	void Render(sf::RenderWindow &window);


};

