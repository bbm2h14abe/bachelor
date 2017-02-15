#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>

class NpcCreature
{
public:
	void LoadContent(int type, int pos_x, int pos_y);
	void UnloadContent();
	void Update();
	void Render(sf::RenderWindow &window);

};

