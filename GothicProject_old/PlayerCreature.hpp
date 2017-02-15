#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>

#include "BasicCreature.hpp"
#include "CreatureAnimation.hpp"
#include "Movement.hpp"
#include "SpellManager.hpp"

// ==========>> Player-class, manages everything with player-sprite, input and stats.
class PlayerCreature : public BasicCreature
{
public:
	void LoadContent(int type, int pos_x, int pos_y);
	void UnloadContent();
	void Update();
	void Render(sf::RenderWindow &window);

	const sf::Sprite	getSprite()			 const{	return m_sprite; }
	const sf::FloatRect getCollisionBounds() const{ return m_collision_bounds; }
	const int			getDepth(){					return m_depth; }

protected:
	sf::Texture m_texture;
	sf::Sprite  m_sprite;

	sf::FloatRect m_collision_bounds;
	int			  m_depth;
	int			  m_state;

private:
	CreatureAnimation	m_animation;
	Movement			m_movement;
	SpellManager		m_spell;

	int m_health;
	int m_mana;
	int m_attack;
	int m_defense;
};

