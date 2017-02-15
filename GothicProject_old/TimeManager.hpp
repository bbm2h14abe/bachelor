#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>

class TimeManager
{
public:
	static TimeManager &GetInstance();

	void  UpdateFrameTime();
	float GetFrameTime();

private:
	static float	 m_frametime;
	static sf::Clock m_clock;

};

