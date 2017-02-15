#include "TileManager.hpp"

#include "TileChars.hpp"
#include "TextureRectangles.hpp"
#include "ViewManager.hpp"

// return static instance
TileManager &TileManager::GetInstance()
{
	static TileManager instance;
	return instance;
}

// load 
void TileManager::LoadContent(std::string tile_sheet)
{
	m_tile_sheet.loadFromFile(tile_sheet);
}

// add new tile
void TileManager::AddTile(char tile_char, sf::Vector2i position)
{
	// add tile if it isnt empty('.')
	if(tile_char != '.' && tile_char != '\n' && tile_char != ';' && tile_char != ' ')
	{
		// get bounds for new tile
		sf::FloatRect bounds = sf::FloatRect((float)position.x, (float)position.y, (float)TEXT_RECT::TILE_SIZE, (float)TEXT_RECT::TILE_SIZE);

		// tile-stats
		sf::IntRect texture_rect = sf::IntRect(0,0,0,0);
		bool is_solid = false;
		bool is_front = false;

		// check which abilities
		if(tile_char == TILE_CHAR::WALL_LEFT_TOP)
		{
			texture_rect = TEXT_RECT::WALL_LEFT_TOP;
			is_solid	 = true;
			is_front	 = false;
		}
		else if(tile_char == TILE_CHAR::WALL_HORIZONTAL_TOP)
		{	  
			texture_rect = TEXT_RECT::WALL_HORIZONTAL_TOP;
			is_solid	 = true;
			is_front	 = false;
		}
		else if(tile_char == TILE_CHAR::WALL_RIGHT_TOP)	 
		{
			texture_rect = TEXT_RECT::WALL_RIGHT_TOP;
			is_solid	 = true;
			is_front	 = false;
		}
		else if(tile_char == TILE_CHAR::WALL_VERTICAL_LEFT)
		{
			texture_rect = TEXT_RECT::WALL_VERTICAL_LEFT;
			is_solid	 = true;
			is_front	 = false;
		}
		else if(tile_char == TILE_CHAR::FLOOR_SAND_STONE)
		{
			texture_rect = TEXT_RECT::FLOOR_SAND_STONE;
			is_solid	 = false;
			is_front	 = false;
		}
		else if(tile_char == TILE_CHAR::WALL_LEFT_BOTTOM)		  
		{
			texture_rect = TEXT_RECT::WALL_LEFT_BOTTOM;
			is_solid	 = true;
			is_front	 = false;
		}
		else if(tile_char == TILE_CHAR::WALL_HORIZONTAL_BOTTOM)	  
		{
			texture_rect = TEXT_RECT::WALL_HORIZONTAL_BOTTOM;
			is_solid	 = true;
			is_front	 = false;
		}
		else if(tile_char == TILE_CHAR::WALL_RIGHT_BOTTOM)	  
		{
			texture_rect = TEXT_RECT::WALL_RIGHT_BOTTOM;
			is_solid	 = true;
			is_front	 = false;
		}
		else if(tile_char == TILE_CHAR::WALL_VERTICAL_RIGHT)  
		{
			texture_rect = TEXT_RECT::WALL_VERTICAL_RIGHT;
			is_solid	 = true;
			is_front	 = false;
		}
		else if(tile_char == TILE_CHAR::FLOOR_STONE)	  
		{
			texture_rect = TEXT_RECT::FLOOR_STONE;
			is_solid	 = false;
			is_front	 = false;
		}
		else if(tile_char == TILE_CHAR::WALL_CORNER_UL)	  
		{
			texture_rect = TEXT_RECT::WALL_CORNER_UL;
			is_solid	 = true;
			is_front	 = false;
		}
		else if(tile_char == TILE_CHAR::WALL_CORNER_UR)  
		{
			texture_rect = TEXT_RECT::WALL_CORNER_UR;
			is_solid	 = true;
			is_front	 = false;
		}
		else if(tile_char == TILE_CHAR::TREASURE_CHEST)  
		{
			texture_rect = TEXT_RECT::TREASURE_CHEST;
			is_solid	 = true;
			is_front	 = false;
		}
		else if(tile_char == TILE_CHAR::COLUMN_TOP)  
		{
			texture_rect = TEXT_RECT::COLUMN_TOP;
			is_solid	 = false;
			is_front	 = true;
		}
		else if(tile_char == TILE_CHAR::LADDER_VERTICAL)  
		{
			texture_rect = TEXT_RECT::LADDER_VERTICAL;
			is_solid	 = false;
			is_front	 = false;
		}
		else if(tile_char == TILE_CHAR::WALL_CORNER_DL)  
		{
			texture_rect = TEXT_RECT::WALL_CORNER_DL;
			is_solid	 = true;
			is_front	 = false;
		}
		else if(tile_char == TILE_CHAR::WALL_CORNER_DR)  
		{
			texture_rect = TEXT_RECT::WALL_CORNER_DR;
			is_solid	 = true;
			is_front	 = false;
		}
		else if(tile_char == TILE_CHAR::BROKEN_SWORD)  
		{
			texture_rect = TEXT_RECT::BROKEN_SWORD;
			is_solid	 = true;
			is_front	 = false;
		}
		else if(tile_char == TILE_CHAR::COLUMN_BOTTOM)  
		{
			texture_rect = TEXT_RECT::COLUMN_BOTTOM;
			is_solid	 = true;
			is_front	 = false;
		}
		else if(tile_char == TILE_CHAR::LADDER_HORIZONTAL)  
		{
			texture_rect = TEXT_RECT::LADDER_HORIZONTAL;
			is_solid	 = false;
			is_front	 = false;
		}
		else std::cout << std::endl << "Unknown Tile-char in Manager!"<<tile_char;	// XXX debug output

		// new tile
		tile new_tile;

		// set sprite
		new_tile.sprite.setTexture(m_tile_sheet);
		new_tile.sprite.setTextureRect(texture_rect);
		new_tile.sprite.setPosition((sf::Vector2f)position);

		// set stats
		new_tile.bounds = bounds;
		new_tile.is_solid = is_solid;
		new_tile.is_front = is_front;

		// push it back in vector
		m_tiles.push_back(new_tile);

	}
}

// update
void TileManager::Update()
{
}

// draw back
void TileManager::RenderBack(sf::RenderWindow &window)
{
	//sf::FloatRect view_rect = ViewManager::GetInstance().GetBounds();

	for(unsigned int i=0; i<m_tiles.size(); i++)
	{
		if(m_tiles[i].is_front == false /*&& m_tiles[i].bounds.intersects(view_rect)*/)	window.draw(m_tiles[i].sprite);
	}
}

// draw front
void TileManager::RenderFront(sf::RenderWindow &window)
{
	//sf::FloatRect view_rect = ViewManager::GetInstance().GetBounds();

	for(unsigned int i=0; i<m_tiles.size(); i++)
	{
		if(m_tiles[i].is_front == true /*&& m_tiles[i].bounds.intersects(view_rect)*/) window.draw(m_tiles[i].sprite);
	}
}

const std::vector<sf::FloatRect> TileManager::getTileRects()
{
	std::vector<sf::FloatRect> tile_rects;
	
	for(unsigned int i=0; i<m_tiles.size(); i++)
	{
		if(m_tiles[i].is_solid == true)
		{
			sf::FloatRect new_tile_rect;
			new_tile_rect = m_tiles[i].bounds;
			tile_rects.push_back(new_tile_rect);
		}
	}

	return tile_rects;
}