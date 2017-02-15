#include "TextFileReader.hpp"

const std::vector<char> TextFileReader::ReadTileMap(std::string file_name)
{
	// variables
	std::ifstream		data_input;
	char				map_char;
	std::vector<char>	full_map;
	bool counted_x	   = false;
	m_tile_amount_x = 0;
	m_tile_amount_y = 0;

	// open file
	data_input.open(file_name, std::ios_base::in);

	// XXX debug output
	if(!data_input)	std::cout << "Failed to open text-map" << std::endl;
	
	// read chars
	do
	{
		// read and save new character
		data_input.get(map_char);
		full_map.push_back(map_char);

		// count tile-amount
		if(map_char == '\n' ) 
		{
			m_tile_amount_y++;
			counted_x = true;
		}
		if(counted_x == false)
		{
			m_tile_amount_x++;
		}
	}
	while(map_char != ';');

	// increase once for last line
	m_tile_amount_y++;

	// close file
	data_input.close();


	return full_map;
}
