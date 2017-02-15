#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <SFML\Graphics.hpp>

class TileManager
{
public:
	static TileManager &GetInstance();

	void LoadContent(std::string tile_sheet);

	void AddTile(char tile_char, sf::Vector2i position);
	void Update();
	void RenderBack(sf::RenderWindow &window);
	void RenderFront(sf::RenderWindow &window);

	const std::vector<sf::FloatRect> getTileRects();

private:
	struct tile
	{
		sf::Sprite		sprite;		// sprite
		sf::FloatRect	bounds;		// it's global bounds
		bool			is_solid;	// if its collidable
		bool			is_front;	// if it's rendered in front of creatures
	};

	sf::Texture m_tile_sheet;
	std::vector<tile> m_tiles;

};

