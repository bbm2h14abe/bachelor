#pragma once

#include <iostream>
#include <sstream>

#include <SFML\Graphics.hpp>


class HudEnemyHealth
{
public:
	void LoadContent();
	void Update(sf::Vector2f enemy_origin, int enemy_health);
	void Render(sf::RenderWindow &window);

private:
	sf::Font m_font;
	sf::Text m_text;


};

