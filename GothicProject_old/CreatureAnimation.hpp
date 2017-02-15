#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>

class CreatureAnimation
{
public:
	void LoadContent(sf::Vector2i sheet_size, sf::Vector2i frame_size, sf::Vector2i frames_total);

	sf::IntRect GetWalkRect(int direction, bool is_colliding);
	sf::IntRect GetAttackRect(int direction);
	sf::IntRect GetCastRect(int direction);
	sf::IntRect GetDeathRect();

	void SetCurrentHorizontalFrame(int frame_x){ m_currentFrame.x = frame_x; }

private:
	sf::Vector2i m_sheetSize, m_frameSize, m_framesTotal;

	sf::Vector2i m_currentFrame;
	float		 m_delay;

};

