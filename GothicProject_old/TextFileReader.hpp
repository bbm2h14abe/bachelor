#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class TextFileReader
{
public:
	// read tile-map
	const std::vector<char> ReadTileMap(std::string file_name);
	
	// return tile-amount
	int getTilesX(){ return m_tile_amount_x; }
	int getTilesY(){ return m_tile_amount_y; }

private:
	int m_tile_amount_x;
	int m_tile_amount_y;

};

