#include <iostream>

namespace TILE_CHAR
{
	// empty-tile
	const char EMPTY					= '.';
	
	// map-tiles
	const char WALL_LEFT_TOP			= '{';
	const char WALL_HORIZONTAL_TOP		= '-';
	const char WALL_RIGHT_TOP			= '}';
	const char WALL_VERTICAL_LEFT		= '>';
	const char FLOOR_SAND_STONE			= '*';
	const char WALL_LEFT_BOTTOM			= '[';
	const char WALL_HORIZONTAL_BOTTOM	= '_';
	const char WALL_RIGHT_BOTTOM		= ']';
	const char WALL_VERTICAL_RIGHT		= '<';
	const char FLOOR_STONE				= '+';
	const char WALL_CORNER_UL			= '1';
	const char WALL_CORNER_UR			= '2';
	const char TREASURE_CHEST			= '3';
	const char COLUMN_TOP				= '4';
	const char LADDER_VERTICAL			= '5';
	const char WALL_CORNER_DL			= '6';
	const char WALL_CORNER_DR			= '7';
	const char BROKEN_SWORD				= '8';
	const char COLUMN_BOTTOM			= '9';
	const char LADDER_HORIZONTAL		= '0';
	

	// player-spawn
	const char PLAYER		= '@';

	// enemy-spawns	
	const char ENEMY_GOBLIN = 'G';

	// npc-spawns
	const char NPC_NORMAL	= 'N';



}