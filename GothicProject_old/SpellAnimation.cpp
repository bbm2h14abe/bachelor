#include "SpellAnimation.hpp"

#include "Settings.hpp"
#include "TextureRectangles.hpp"

void SpellAnimation::LoadContent()
{
	m_currentFrame			= sf::Vector2i(0,0);
	m_delay					= 0.0f;
	m_can_be_deleted		= false;
}

sf::IntRect SpellAnimation::GetTextureRect(int type, bool is_alive)
{
	m_can_be_deleted = false;

	// check types
	if(type == SET::SPELL::FIRE_BALL)	
	{
		// fire-ball
		if(is_alive == true)
		{
			m_currentFrame.y = TEXT_RECT::SPELL_FIRE_BALL.top;
		}
		else
		{
			m_currentFrame.y = TEXT_RECT::SPELL_FIRE_DEATH.top;	
		}
		
	}

	// set texture-rect
	sf::IntRect texture_rect(0,0,0,0);
	texture_rect.left   = m_currentFrame.x * TEXT_RECT::TILE_SIZE;
	texture_rect.width  = TEXT_RECT::TILE_SIZE;
	texture_rect.top    = m_currentFrame.y * TEXT_RECT::TILE_SIZE;
	texture_rect.height = TEXT_RECT::TILE_SIZE;

	// increase delay
	m_delay += 1.0f;

	// check for showing next frame
	if(m_delay >= SET::ANIMATION_FRAME_DELAY)
	{
		m_currentFrame.x++;
		m_delay = 0.0f;
	}

	// jump to start if frames are over max
	if(m_currentFrame.x >= SET::SPELL_FRAME_AMOUNT)
	{
		m_currentFrame.x = 0;

		if(is_alive == false)
		{
			m_can_be_deleted = true;
		}
	}

	return texture_rect;
}