#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>

class SpellAnimation
{
public:
	void LoadContent();

	sf::IntRect GetTextureRect(int type, bool is_alive);
	bool		CanBeDeleted(){ return m_can_be_deleted; }

private:
	sf::Vector2i m_currentFrame;
	float		 m_delay;
	bool		 m_can_be_deleted;

};

