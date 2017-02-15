#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>

#include "SpellAnimation.hpp"

// ==========>> Casts spells and stores them in vector. 
//				Also check for collisions and draw them.
class SpellManager
{
public:
	void LoadContent();

	void CastSpell(int type, sf::FloatRect player_bounds, int direction);
	void Update();
	void Render(sf::RenderWindow &window);

private:
	struct	spell
	{
		int		   type;
		int		   damage;
		int		   mana_cost;
		sf::Sprite sprite;
		int		   direction;
		int		   life_time;
		bool	   is_alive;
		bool	   can_be_deleted;
	};

	sf::Texture			m_spell_sheet;
	std::vector<spell*> m_spells;

	SpellAnimation   m_animation;

};

