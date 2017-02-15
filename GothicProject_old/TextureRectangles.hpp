#include <iostream>

#include <SFML\Graphics.hpp>

namespace TEXT_RECT
{
	// instance sizes
	const int TILE_SIZE		= 16;
	const sf::Vector2i PLAYER_SIZE = sf::Vector2i(32, 32);
	const sf::Vector2i ENEMY_SIZE = sf::Vector2i(16, 20);

	// creature-animation rects
	const sf::IntRect CREATURE_DEATH			= sf::IntRect(0, 4, ENEMY_SIZE.x, ENEMY_SIZE.y);

	const sf::IntRect CREATURE_CAST_UP			= sf::IntRect(0,				PLAYER_SIZE.y*4, PLAYER_SIZE.x, PLAYER_SIZE.y); 
	const sf::IntRect CREATURE_CAST_DOWN		= sf::IntRect(PLAYER_SIZE.x,	PLAYER_SIZE.y*4, PLAYER_SIZE.x, PLAYER_SIZE.y); 
	const sf::IntRect CREATURE_CAST_LEFT		= sf::IntRect(PLAYER_SIZE.x*2,	PLAYER_SIZE.y*4, PLAYER_SIZE.x, PLAYER_SIZE.y); 
	const sf::IntRect CREATURE_CAST_RIGHT		= sf::IntRect(PLAYER_SIZE.x*3,	PLAYER_SIZE.y*4, PLAYER_SIZE.x, PLAYER_SIZE.y);

	const sf::IntRect CREATURE_ATTACK_UP		= sf::IntRect(0, 5, PLAYER_SIZE.x, PLAYER_SIZE.y);
	const sf::IntRect CREATURE_ATTACK_DOWN		= sf::IntRect(0, 6, PLAYER_SIZE.x, PLAYER_SIZE.y);
	const sf::IntRect CREATURE_ATTACK_LEFT		= sf::IntRect(0, 7, PLAYER_SIZE.x, PLAYER_SIZE.y);
	const sf::IntRect CREATURE_ATTACK_RIGHT		= sf::IntRect(0, 8, PLAYER_SIZE.x, PLAYER_SIZE.y);

	// "Tile_Sheet_16bit.png"
	const sf::IntRect WALL_LEFT_TOP				= sf::IntRect(0,				 0,	TILE_SIZE, TILE_SIZE);
	const sf::IntRect WALL_HORIZONTAL_TOP		= sf::IntRect(TILE_SIZE,		 0,	TILE_SIZE, TILE_SIZE);
	const sf::IntRect WALL_RIGHT_TOP			= sf::IntRect(TILE_SIZE*2,		 0,	TILE_SIZE, TILE_SIZE);
	const sf::IntRect WALL_VERTICAL_LEFT		= sf::IntRect(TILE_SIZE*3,		 0,	TILE_SIZE, TILE_SIZE);
	const sf::IntRect FLOOR_SAND_STONE			= sf::IntRect(TILE_SIZE*4,		 0,	TILE_SIZE, TILE_SIZE);
	const sf::IntRect WALL_LEFT_BOTTOM			= sf::IntRect(0,		   TILE_SIZE, TILE_SIZE, TILE_SIZE);
	const sf::IntRect WALL_HORIZONTAL_BOTTOM	= sf::IntRect(TILE_SIZE,   TILE_SIZE, TILE_SIZE, TILE_SIZE);
	const sf::IntRect WALL_RIGHT_BOTTOM			= sf::IntRect(TILE_SIZE*2, TILE_SIZE, TILE_SIZE, TILE_SIZE);
	const sf::IntRect WALL_VERTICAL_RIGHT		= sf::IntRect(TILE_SIZE*3, TILE_SIZE, TILE_SIZE, TILE_SIZE);
	const sf::IntRect FLOOR_STONE				= sf::IntRect(TILE_SIZE*4, TILE_SIZE, TILE_SIZE, TILE_SIZE);
	const sf::IntRect WALL_CORNER_UL			= sf::IntRect(0,		   TILE_SIZE*2, TILE_SIZE, TILE_SIZE);
	const sf::IntRect WALL_CORNER_UR			= sf::IntRect(TILE_SIZE,   TILE_SIZE*2, TILE_SIZE, TILE_SIZE);
	const sf::IntRect TREASURE_CHEST			= sf::IntRect(TILE_SIZE*2, TILE_SIZE*2, TILE_SIZE, TILE_SIZE);
	const sf::IntRect COLUMN_TOP				= sf::IntRect(TILE_SIZE*3, TILE_SIZE*2, TILE_SIZE, TILE_SIZE);
	const sf::IntRect LADDER_VERTICAL			= sf::IntRect(TILE_SIZE*4, TILE_SIZE*2, TILE_SIZE, TILE_SIZE);
	const sf::IntRect WALL_CORNER_DL			= sf::IntRect(0,		   TILE_SIZE*3, TILE_SIZE, TILE_SIZE);
	const sf::IntRect WALL_CORNER_DR			= sf::IntRect(TILE_SIZE,   TILE_SIZE*3, TILE_SIZE, TILE_SIZE);
	const sf::IntRect BROKEN_SWORD				= sf::IntRect(TILE_SIZE*2, TILE_SIZE*3, TILE_SIZE, TILE_SIZE);
	const sf::IntRect COLUMN_BOTTOM				= sf::IntRect(TILE_SIZE*3, TILE_SIZE*3, TILE_SIZE, TILE_SIZE);
	const sf::IntRect LADDER_HORIZONTAL			= sf::IntRect(TILE_SIZE*4, TILE_SIZE*3, TILE_SIZE, TILE_SIZE);

	// spells
	const sf::IntRect SPELL_FIRE_BALL	  = sf::IntRect( 0,	0, TILE_SIZE, TILE_SIZE);
	const sf::IntRect SPELL_FIRE_DEATH	  = sf::IntRect( 0,	1, TILE_SIZE, TILE_SIZE);
}