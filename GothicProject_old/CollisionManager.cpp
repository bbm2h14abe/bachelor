#include "CollisionManager.hpp"

bool CollisionManager::TileCollision(sf::FloatRect creature_rect, std::vector<sf::FloatRect> tile_rects)
{
	for(unsigned int i=0; i<tile_rects.size(); i++)
	{
		if(creature_rect.intersects(tile_rects[i]))
		{
			return true;
		}
	}
	return false;
}


bool CollisionManager::EnemyCollision(sf::FloatRect collision_bounds, std::vector<EnemyCreature*> enemies, int depth)
{
	unsigned int index = 0;

	for(unsigned int i=0; i<enemies.size(); i++)
	{
		if(depth == enemies[i]->getDepth()) 
		{
			index = i;
		}
	}

	for(unsigned int i=0; i<enemies.size(); i++)
	{
		if(i != index && collision_bounds.intersects(enemies[i]->getCollisionBounds()))
		{
			return true;
		}
	}

	return false;
}