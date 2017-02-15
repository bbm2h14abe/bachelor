#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <SFML\Graphics.hpp>

class Level
{
public:
	void Load(std::string file_name, std::string background);
	void RenderBack(sf::RenderWindow &window);
	void RenderFront(sf::RenderWindow &window);

	sf::FloatRect getLevelBounds(){ return m_background_sprite.getGlobalBounds(); } 

private:
	sf::Texture m_background_texture;	// background-texture
	sf::Sprite  m_background_sprite;	// background-sprite
	sf::Texture m_tile_sheet;			// tile-sheet texture
	std::vector<sf::Sprite> m_tiles;	// tile-sprites

};

