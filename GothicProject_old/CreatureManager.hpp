#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>

#include "BasicCreature.hpp"
#include "PlayerCreature.hpp"
#include "EnemyCreature.hpp"
#include "NpcCreature.hpp"


class CreatureManager
{
public:
	static CreatureManager &GetInstance();

	// add creatures
	void AddPlayer(int type, int pos_x, int pos_y);
	void AddNpc();
	void AddEnemy(int type, int pos_x, int pos_y);

	// unload
	void Unload();
	
	// updates
	void Update();

	// draw
	void Render(sf::RenderWindow &window);


	// return instances
	const sf::Sprite getPlayerSprite()				  const{ return m_player->getSprite(); }
	const sf::FloatRect getPlayerBounds()			  const{ return m_player->getCollisionBounds(); }
	const std::vector<EnemyCreature*> getEnemies()	  const{ return m_enemies; }
	const std::vector<sf::FloatRect> getEnemyBounds() const;
	const std::vector<sf::FloatRect> getEnemyTextureBounds() const;

private:
	PlayerCreature*				m_player;
	std::vector<BasicCreature*> m_npcs;
	std::vector<EnemyCreature*> m_enemies;
	
};

