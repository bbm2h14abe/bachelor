#include "InputManager.hpp"

// init member
int  InputManager::m_arrow			= ARROW::NO_ARROW;
int  InputManager::m_button			= BUTTON::NO_BUTTON;
bool InputManager::m_pressed_arrow  = false;
bool InputManager::m_pressed_button = false;


// return instance static
InputManager &InputManager::GetInstance()
{
	static InputManager instance;
	return instance;
}


// update current pressed button and arrow
void InputManager::UpdateInput()
{
	// reset arrow & button
	m_arrow  = ARROW::NO_ARROW;
	m_button = BUTTON::NO_BUTTON;

	// check for current arrow-press
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Joystick::getAxisPosition(0,sf::Joystick::Y) < -90.0f )	// up
	{
		if(m_pressed_arrow == false)
		{
			m_pressed_arrow = true;
			m_arrow = ARROW::UP;
		}
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Joystick::getAxisPosition(0,sf::Joystick::Y) > 90.0f)	// down
	{
		if(m_pressed_arrow == false)
		{
			m_pressed_arrow = true;
			m_arrow = ARROW::DOWN;
		}
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Joystick::getAxisPosition(0,sf::Joystick::X) < -90.0f)	// left
	{
		if(m_pressed_arrow == false)
		{
			m_pressed_arrow = true;
			m_arrow = ARROW::LEFT;
		}
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Joystick::getAxisPosition(0,sf::Joystick::X) > 90.0f)	// right
	{
		if(m_pressed_arrow == false)
		{
			m_pressed_arrow = true;
			m_arrow = ARROW::RIGHT;
		}
	}


	// check if an arrow was pressed
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)   || sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
	   sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)||
	   sf::Joystick::getAxisPosition(0,sf::Joystick::Y) < -90.0f || sf::Joystick::getAxisPosition(0,sf::Joystick::Y) > 90.0f ||
	   sf::Joystick::getAxisPosition(0,sf::Joystick::X) < -90.0f || sf::Joystick::getAxisPosition(0,sf::Joystick::X) > 90.0f)
	{
		m_pressed_arrow = true;
	}
	else
	{
		m_pressed_arrow = false;
	}


// ____________________________________________________________________________________________________//



	// check for current button-press
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)	|| sf::Joystick::isButtonPressed(0,1))	// A
	{
		if(m_pressed_button == false)
		{
			m_pressed_button = true;
			m_button = BUTTON::A;
		}
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)	|| sf::Joystick::isButtonPressed(0,2))	// B
	{
		if(m_pressed_button == false)
		{
			m_pressed_button = true;
			m_button = BUTTON::B;
		}
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)	|| sf::Joystick::isButtonPressed(0,5))	// start
	{
		if(m_pressed_button == false)
		{
			m_pressed_button = true;
			m_button = BUTTON::START;
		}
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)	|| sf::Joystick::isButtonPressed(0,6))	// select
	{
		if(m_pressed_button == false)
		{
			m_pressed_button = true;
			m_button = BUTTON::SELECT;
		}
	}

	// check if a button was pressed
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::B) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Return) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
		sf::Joystick::isButtonPressed(0,1) || sf::Joystick::isButtonPressed(0,2) || 
		sf::Joystick::isButtonPressed(0,5) || sf::Joystick::isButtonPressed(0,6))
	{
		m_pressed_button = true;
	}
	else
	{
		m_pressed_button = false;
	}
	
}


// ____________________________________________________________________________________________________//


// check if Up-arrow is hold-down
bool InputManager::GetHold_Up()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Joystick::getAxisPosition(0,sf::Joystick::Y) < -90.0f)
	{
		return true;
	}

	return false;
}

// check if Down-arrow is hold-down
bool InputManager::GetHold_Down()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Joystick::getAxisPosition(0,sf::Joystick::Y) > 90.0f)
	{
		return true;
	}

	return false;
}

// check if Left-arrow is hold-down
bool InputManager::GetHold_Left()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Joystick::getAxisPosition(0,sf::Joystick::X) < -90.0f)
	{
		return true;
	}

	return false;
}

// check if Right-arrow is hold-down
bool InputManager::GetHold_Right()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Joystick::getAxisPosition(0,sf::Joystick::X) > 90.0f)
	{
		return true;
	}

	return false;
}

