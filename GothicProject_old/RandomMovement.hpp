#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

#include <SFML\Graphics.hpp>

class RandomMovement
{
public:
	// load
	void LoadContent();

	// update position
	void UpdatePosition(sf::Vector2f enemy_pos, sf::Vector2f player_pos, bool see_player);

	// get new positions
	const sf::Vector2f getNewHorizontalPosition() const{ return m_newHorizontalPosition; }
	const sf::Vector2f getNewVerticalPosition()   const{ return m_newVerticalPosition; }

	// get direction( without diagonal )
	const unsigned int getSimpleDirection() const;

	
private:
	sf::Vector2f m_newHorizontalPosition, m_newVerticalPosition;
	int	  m_currentDirection;
	float m_newDirectionTimer;

	const enum DIRECTION{ UL, U, UR, R, DR, D, DL, L }; 


};

