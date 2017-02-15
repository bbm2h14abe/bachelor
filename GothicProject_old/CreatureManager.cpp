#include "CreatureManager.hpp"

#include <algorithm>	// for sorting


CreatureManager &CreatureManager::GetInstance()
{
	static CreatureManager instance;
	return instance;
}

void CreatureManager::AddPlayer(int type, int pos_x, int pos_y)
{
	// load player
	m_player = new PlayerCreature;
	m_player->LoadContent(type, pos_x, pos_y);
	
}

void CreatureManager::AddNpc()
{

	BasicCreature *NewNpc = new BasicCreature;

	m_npcs.push_back(NewNpc);
}

void CreatureManager::AddEnemy(int type, int pos_x, int pos_y)
{
	EnemyCreature *NewEnemy = new EnemyCreature;
	NewEnemy->LoadContent(type, pos_x, pos_y);

	m_enemies.push_back(NewEnemy);
}

void CreatureManager::Unload()
{
	delete m_player;
	m_player = nullptr;	// maybe use "m_player = 0"
	
	m_npcs.clear();
	m_enemies.clear();
}

void CreatureManager::Update()
{
	// update player
	m_player->Update();

	// update enemies
	if(m_enemies.size() != 0)
	{
		for(unsigned int i=0; i<m_enemies.size(); i++)
		{
			m_enemies[i]->Update();

			// check if alive
			if(m_enemies[i]->isAlive() == false) 
			{
				m_enemies[i] = m_enemies.back();
				m_enemies.pop_back();
				i--;
			}
		}

	}
}

void CreatureManager::Render(sf::RenderWindow &window)
{
	// sort enemy-creatures by depth
	EnemyCreature::SortSpritesByDepth(m_enemies);

	bool player_drawn = false;

	if(m_enemies.size() != 0)
	{
		for(unsigned int i=0; i<m_enemies.size(); i++)
		{
			if(m_enemies[i]->getDepth() >= m_player->getDepth() && player_drawn == false) 
			{
				m_player->Render(window);
				player_drawn = true;
			}
			m_enemies[i]->Render(window);
		}
	}

	if(player_drawn == false) m_player->Render(window);


}


const std::vector<sf::FloatRect> CreatureManager::getEnemyBounds() const
{
	std::vector<sf::FloatRect> enemy_bounds;

	for(unsigned int i=0; i<m_enemies.size(); i++)
	{
		sf::FloatRect new_bounds = m_enemies[i]->getCollisionBounds();
		enemy_bounds.push_back(new_bounds);
	}

	return enemy_bounds;
}

const std::vector<sf::FloatRect> CreatureManager::getEnemyTextureBounds() const
{
	std::vector<sf::FloatRect> enemy_texture_bounds;

	for(unsigned int i=0; i<m_enemies.size(); i++)
	{
		sf::FloatRect new_bounds = m_enemies[i]->getTextureBounds();
		enemy_texture_bounds.push_back(new_bounds);
	}

	return enemy_texture_bounds;
}