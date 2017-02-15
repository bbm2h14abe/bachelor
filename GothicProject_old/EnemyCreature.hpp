#pragma once

#include <iostream>
#include <algorithm>

#include <SFML\Graphics.hpp>

#include "BasicCreature.hpp"
#include "CreatureAnimation.hpp"
#include "RandomMovement.hpp"
#include "HudEnemyHealth.hpp"

class EnemyCreature : public BasicCreature
{
public:
	void LoadContent(int type, int pos_x, int pos_y);
	void UnloadContent();
	void Update();
	void Render(sf::RenderWindow &window);

	void setHealth(int damage);

	// sorting
	static bool MyCreatureSortPredicate(const EnemyCreature *lhs, const EnemyCreature *rhs){ return lhs->m_depth < rhs->m_depth; }
	static void SortSpritesByDepth(std::vector<EnemyCreature*> &enemies);

	// return
	const sf::Sprite	getSprite()			 const{ return m_sprite; }
	const sf::FloatRect getCollisionBounds() const{ return m_collision_bounds; }
	const sf::FloatRect getTextureBounds()	 const{ return m_texture_bounds; }
	const int			getDepth(){					return m_depth; }
	const bool			isAlive()			 const{ return m_is_alive; }

protected:
	sf::Texture m_texture;
	sf::Sprite  m_sprite;

	sf::FloatRect	m_collision_bounds;
	sf::FloatRect   m_texture_bounds;
	int				m_depth;
	int				m_state;
	int				m_health;
	bool			m_is_alive;

private:
	CreatureAnimation	m_animation;
	RandomMovement		m_movement;
	HudEnemyHealth		m_health_hud;
	
	int					m_last_health;

};
