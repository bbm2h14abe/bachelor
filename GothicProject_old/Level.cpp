#include "Level.hpp"

#include "TextFileReader.hpp"
#include "TileChars.hpp"
#include "CreatureManager.hpp"
#include "Settings.hpp"
#include "TextureRectangles.hpp"
#include "TileManager.hpp"
#include "FilePath.hpp"

void Level::Load(std::string file_name, std::string background)
{
	// count current tile-position
	int tile_position_x = 0;
	int tile_position_y = 0;

	// init background
	m_background_texture.loadFromFile(background);
	m_background_sprite.setTexture(m_background_texture);
	
	// init tile-sprites
	TileManager::GetInstance().LoadContent(PATH::tile_sheet_standard);

	// read and save char-map from text-file
	TextFileReader reader;
	std::vector<char> char_map = reader.ReadTileMap(file_name); 

	// XXX test output map======
	std::cout << std::endl << std::endl;
	std::cout << "x: " << reader.getTilesX() << " y: " << reader.getTilesY();
	std::cout << std::endl;
	for(unsigned int i=0; i<char_map.size(); i++)
	{
		std::cout << char_map[i];
	} std::cout << std::endl;
	//===========================

	// loop char-map
	for(unsigned int i=0; i<char_map.size(); i++)
	{
		// position for current object 
		int pos_x = tile_position_x*TEXT_RECT::TILE_SIZE;
		int pos_y = tile_position_y*TEXT_RECT::TILE_SIZE;

		// check current character 
		if(char_map[i] == TILE_CHAR::ENEMY_GOBLIN)	
		{
			CreatureManager::GetInstance().AddEnemy(SET::ENEMY_GOBLIN, pos_x, pos_y);
		}
		else if(char_map[i] == TILE_CHAR::PLAYER)
		{
			CreatureManager::GetInstance().AddPlayer(SET::PLAYER_WARRIOR, pos_x, pos_y);
		}
		else
		{
			TileManager::GetInstance().AddTile(char_map[i],sf::Vector2i(pos_x, pos_y));
		}

		// update position-counter
		tile_position_x++;
		if(tile_position_x > reader.getTilesX())
		{
			tile_position_x = 0;
			tile_position_y++;
		}
	}

}

void Level::RenderBack(sf::RenderWindow &window)
{
	window.draw(m_background_sprite);				// draw background
	TileManager::GetInstance().RenderBack(window);	// draw normal tiles
}

void Level::RenderFront(sf::RenderWindow &window)
{
	TileManager::GetInstance().RenderFront(window);	// draw front-tiles
}