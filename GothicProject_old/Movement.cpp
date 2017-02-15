#include "Movement.hpp"

#include "Settings.hpp"
#include "InputManager.hpp"

// load
void Movement::LoadContent()
{
	m_newHorizontalPosition	= sf::Vector2f(0.0f,0.0f);
	m_newVerticalPosition	= sf::Vector2f(0.0f,0.0f);
	m_currentDirection		= SET::DIRECTION::UL;
}

// update
void Movement::UpdatePosition(sf::Vector2f position)
{
	// get current-position
	m_newHorizontalPosition = position;
	m_newVerticalPosition   = position;

	// input
	bool hold_up	= InputManager::GetInstance().GetHold_Up();
	bool hold_down	= InputManager::GetInstance().GetHold_Down();
	bool hold_left	= InputManager::GetInstance().GetHold_Left();
	bool hold_right = InputManager::GetInstance().GetHold_Right();
	bool is_moving  = false;
	if(hold_up == true || hold_down == true || hold_left == true || hold_right == true) is_moving = true;

	//check for new direction
	if(hold_up == true)							m_currentDirection = SET::DIRECTION::UP;
	if(hold_down == true)						m_currentDirection = SET::DIRECTION::DOWN;
	if(hold_left == true)						m_currentDirection = SET::DIRECTION::LEFT;
	if(hold_right == true)						m_currentDirection = SET::DIRECTION::RIGHT;
	if(hold_up == true && hold_left == true)	m_currentDirection = SET::DIRECTION::UL;
	if(hold_up == true && hold_right == true)	m_currentDirection = SET::DIRECTION::UR;
	if(hold_down == true && hold_right == true) m_currentDirection = SET::DIRECTION::DR;
	if(hold_down == true && hold_left == true)	m_currentDirection = SET::DIRECTION::DL;


	if(is_moving == true)
	{
		// update position
		switch(m_currentDirection)
		{
		// up-left
		case SET::DIRECTION::UL:
				m_newHorizontalPosition.x -= SET::PLAYER_SPEED_DIAGONAL;
				m_newVerticalPosition.y   -= SET::PLAYER_SPEED_DIAGONAL;
				break;
		// up
		case SET::DIRECTION::UP:
				m_newVerticalPosition.y   -= SET::PLAYER_SPEED;
				break;
		// up-right
		case SET::DIRECTION::UR:
				m_newHorizontalPosition.x += SET::PLAYER_SPEED_DIAGONAL;
				m_newVerticalPosition.y   -= SET::PLAYER_SPEED_DIAGONAL;
				break;
		// right
		case SET::DIRECTION::RIGHT:
				m_newHorizontalPosition.x += SET::PLAYER_SPEED;
				break;
		// down-right
		case SET::DIRECTION::DR:
				m_newHorizontalPosition.x += SET::PLAYER_SPEED_DIAGONAL;
				m_newVerticalPosition.y   += SET::PLAYER_SPEED_DIAGONAL;
				break;
		// down
		case SET::DIRECTION::DOWN:
				m_newVerticalPosition.y   += SET::PLAYER_SPEED;
				break;
		// down-left
		case SET::DIRECTION::DL:
				m_newHorizontalPosition.x -= SET::PLAYER_SPEED_DIAGONAL;
				m_newVerticalPosition.y   += SET::PLAYER_SPEED_DIAGONAL;
				break;
		// left
		case SET::DIRECTION::LEFT:
				m_newHorizontalPosition.x -= SET::PLAYER_SPEED;
				break;

		default:
				std::cout << "Unknown Direction for player" << std::endl;	// debug output XXX

		} // 

	}
}


const unsigned int Movement::getSimpleDirection() const
{
	switch( m_currentDirection )
	{
	case SET::DIRECTION::UP:	return SET::DIRECTION::UP;

	case SET::DIRECTION::DOWN:	return SET::DIRECTION::DOWN;
	
	case SET::DIRECTION::UL:	return SET::DIRECTION::UP;
	case SET::DIRECTION::LEFT:	return SET::DIRECTION::LEFT;
	case SET::DIRECTION::DL:	return SET::DIRECTION::DOWN;

	case SET::DIRECTION::UR:	return SET::DIRECTION::UP;
	case SET::DIRECTION::RIGHT: return SET::DIRECTION::RIGHT;
	case SET::DIRECTION::DR:	return SET::DIRECTION::DOWN;

	default:	std::cout << "Unknown direction" << std::endl;	// XXX debug output
	}

	return 0;
}
