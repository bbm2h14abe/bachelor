#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

#include <SFML\Graphics.hpp>

class Movement
{
public:
	// load
	void LoadContent();

	// update position
	void UpdatePosition(sf::Vector2f position);

	// get new positions
	const sf::Vector2f getNewHorizontalPosition() const{ return m_newHorizontalPosition; }
	const sf::Vector2f getNewVerticalPosition()   const{ return m_newVerticalPosition; }

	// get direction( without diagonal, for animation )
	const unsigned int getSimpleDirection() const;
	// get real direction
	const unsigned int getDirection() const{ return m_currentDirection; }

	
private:
	sf::Vector2f m_newHorizontalPosition, m_newVerticalPosition;
	int	  m_currentDirection;


};

