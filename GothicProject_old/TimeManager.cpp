#include "TimeManager.hpp"

float	  TimeManager::m_frametime = 0.0f;
sf::Clock TimeManager::m_clock;

TimeManager &TimeManager::GetInstance()
{
	static TimeManager instance;
	return instance;
}

void TimeManager::UpdateFrameTime()
{
	m_frametime = m_clock.getElapsedTime().asSeconds();
	m_clock.restart();
}

float TimeManager::GetFrameTime()
{
	return m_frametime;
}
