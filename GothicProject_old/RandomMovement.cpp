#include "RandomMovement.hpp"

#include "Settings.hpp"

// load
void RandomMovement::LoadContent()
{
	m_newHorizontalPosition	= sf::Vector2f(0.0f,0.0f);
	m_newVerticalPosition	= sf::Vector2f(0.0f,0.0f);
	m_currentDirection		= DIRECTION::UL;
	m_newDirectionTimer		= 0.0f;
}

// update
void RandomMovement::UpdatePosition(sf::Vector2f enemy_pos, sf::Vector2f player_pos, bool see_player)
{
	// update direction-timer
	m_newDirectionTimer += 1.0f;

	// get current-position
	m_newHorizontalPosition = enemy_pos;
	m_newVerticalPosition   = enemy_pos;

	// check for new direction
	if(m_newDirectionTimer > SET::CREATURE_NEW_DIRECTION_TIMER)
	{
		// reset timer for new direction
		m_newDirectionTimer = 0.0f;

		// get new random direction
		m_currentDirection = std::rand() % 8;  //number between 0 and 7

	}


	// change direction to player is he's in range
	if(see_player == true)
	{
		////////////////////////////////////////////////// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}

	// update position
	switch(m_currentDirection)
	{
	// up-left
	case DIRECTION::UL:
			m_newHorizontalPosition.x -= SET::CREATURE_SPEED_DIAGONAL;
			m_newVerticalPosition.y   -= SET::CREATURE_SPEED_DIAGONAL;
			break;
	// up
	case DIRECTION::U:
			m_newVerticalPosition.y   -= SET::CREATURE_SPEED;
			break;
	// up-right
	case DIRECTION::UR:
			m_newHorizontalPosition.x += SET::CREATURE_SPEED_DIAGONAL;
			m_newVerticalPosition.y   -= SET::CREATURE_SPEED_DIAGONAL;
			break;
	// right
	case DIRECTION::R:
			m_newHorizontalPosition.x += SET::CREATURE_SPEED;
			break;
	// down-right
	case DIRECTION::DR:
			m_newHorizontalPosition.x += SET::CREATURE_SPEED_DIAGONAL;
			m_newVerticalPosition.y   += SET::CREATURE_SPEED_DIAGONAL;
			break;
	// down
	case DIRECTION::D:
			m_newVerticalPosition.y   += SET::CREATURE_SPEED;
			break;
	// down-left
	case DIRECTION::DL:
			m_newHorizontalPosition.x -= SET::CREATURE_SPEED_DIAGONAL;
			m_newVerticalPosition.y   += SET::CREATURE_SPEED_DIAGONAL;
			break;
	// left
	case DIRECTION::L:
			m_newHorizontalPosition.x -= SET::CREATURE_SPEED;
	break;

	default:
			std::cout << "Unknown Direction for creature" << std::endl;	// debug output XXX

	} // 

}


const unsigned int RandomMovement::getSimpleDirection() const
{
	switch( m_currentDirection )
	{
	case DIRECTION::U:	return SET::DIRECTION::UP;

	case DIRECTION::D:	return SET::DIRECTION::DOWN;
	
	case DIRECTION::UL:	return SET::DIRECTION::LEFT;
	case DIRECTION::L:	return SET::DIRECTION::LEFT;
	case DIRECTION::DL: return SET::DIRECTION::LEFT;

	case DIRECTION::UR: return SET::DIRECTION::RIGHT;
	case DIRECTION::R:  return SET::DIRECTION::RIGHT;
	case DIRECTION::DR: return SET::DIRECTION::RIGHT;

	default:	std::cout << "Unknown direction" << std::endl;	// XXX debug output
	}

	return 0;
}