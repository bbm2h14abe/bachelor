#include "CreatureAnimation.hpp"

#include "Settings.hpp"
#include "TextureRectangles.hpp"

void CreatureAnimation::LoadContent(sf::Vector2i sheet_size, sf::Vector2i frame_size, sf::Vector2i frames_total)
{
	m_sheetSize		= sheet_size;
	m_frameSize		= frame_size;
	m_framesTotal	= frames_total;

	m_currentFrame	= sf::Vector2i(0,0);
	m_delay			= 0.0f;
}

sf::IntRect CreatureAnimation::GetWalkRect(int direction, bool is_colliding)
{
	// set texture-rect
	sf::IntRect texture_rect(0,0,0,0);
	texture_rect.left   = m_currentFrame.x * m_frameSize.x;
	texture_rect.width  = m_frameSize.x;
	texture_rect.top    = m_currentFrame.y * m_frameSize.y;
	texture_rect.height = m_frameSize.y;

	// increase delay
	m_delay += 1.0f;

	// check for showing next frame
	if(m_delay >= SET::ANIMATION_FRAME_DELAY)
	{
		m_currentFrame.x++;
		m_delay = 0.0f;
	}

	// jump to start if frames are over max
	if(m_currentFrame.x == m_framesTotal.x || is_colliding == true)
	{
		m_currentFrame.x = 0;
	}

	// set vertical position( moving direction )
	m_currentFrame.y = direction;

	return texture_rect;
}


sf::IntRect CreatureAnimation::GetAttackRect(int direction)
{
	// check vertical position( moving direction )
	if(direction == SET::DIRECTION::UP)		m_currentFrame.y = TEXT_RECT::CREATURE_ATTACK_UP.top;
	if(direction == SET::DIRECTION::DOWN)	m_currentFrame.y = TEXT_RECT::CREATURE_ATTACK_DOWN.top;
	if(direction == SET::DIRECTION::LEFT)	m_currentFrame.y = TEXT_RECT::CREATURE_ATTACK_LEFT.top;
	if(direction == SET::DIRECTION::RIGHT)	m_currentFrame.y = TEXT_RECT::CREATURE_ATTACK_RIGHT.top;

	// set texture-rect
	sf::IntRect texture_rect(0,0,0,0);
	texture_rect.left   = m_currentFrame.x * m_frameSize.x;
	texture_rect.width  = m_frameSize.x;
	texture_rect.top    = m_currentFrame.y * m_frameSize.y;
	texture_rect.height = m_frameSize.y;

	// increase delay
	m_delay += 1.0f;

	// check for showing next frame
	if(m_delay >= SET::ANIMATION_FRAME_DELAY/1.5f)
	{
		m_currentFrame.x++;
		m_delay = 0.0f;
	}

	// jump to start if frames are over max
	if(m_currentFrame.x >= m_framesTotal.x)
	{
		m_currentFrame.x = 0;
		texture_rect = sf::IntRect(0,0,0,0);
	}

	return texture_rect;
}


sf::IntRect CreatureAnimation::GetCastRect(int direction)
{
	sf::IntRect texture_rect(0,0,0,0);

	if(direction == SET::DIRECTION::UP) texture_rect = TEXT_RECT::CREATURE_CAST_UP;
	if(direction == SET::DIRECTION::DOWN) texture_rect = TEXT_RECT::CREATURE_CAST_DOWN;
	if(direction == SET::DIRECTION::LEFT) texture_rect = TEXT_RECT::CREATURE_CAST_LEFT;
	if(direction == SET::DIRECTION::RIGHT) texture_rect = TEXT_RECT::CREATURE_CAST_RIGHT;

	// increase delay
	m_delay += 1.0f;

	if(m_delay >= SET::ANIMATION_FRAME_DELAY*2) texture_rect = sf::IntRect(0,0,0,0);

	return texture_rect;
}


sf::IntRect CreatureAnimation::GetDeathRect()
{
	// set vertical position
	m_currentFrame.y = TEXT_RECT::CREATURE_DEATH.top;

	// set texture-rect
	sf::IntRect texture_rect(0,0,0,0);
	texture_rect.left   = m_currentFrame.x * m_frameSize.x;
	texture_rect.width  = m_frameSize.x;
	texture_rect.top    = m_currentFrame.y * m_frameSize.y;
	texture_rect.height = m_frameSize.y;

	// increase delay
	m_delay += 1.0f;

	// check for showing next frame
	if(m_delay >= SET::ANIMATION_FRAME_DELAY)
	{
		m_currentFrame.x++;
		m_delay = 0.0f;
	}

	// jump to start if frames are over max
	if(m_currentFrame.x >= m_framesTotal.x)
	{
		texture_rect = sf::IntRect(0,0,0,0);
	}


	return texture_rect;
}