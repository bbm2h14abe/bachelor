#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>

class BasicCreature
{
public:
	virtual void LoadContent(int type, int pos_x, int pos_y);
	virtual void UnloadContent();
	virtual void Update();
	virtual void Render(sf::RenderWindow &window);


protected:
	sf::Texture		m_texture;
	sf::Sprite		m_sprite;

	sf::FloatRect	m_collision_bounds;
	int				m_depth;
	int				m_state;
};

