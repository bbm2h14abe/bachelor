#include "MeleeAttack.hpp"

#include "CreatureManager.hpp"
#include "Settings.hpp"
#include "Stats.hpp"

MeleeAttack &MeleeAttack::GetInstance()
{
	static MeleeAttack instance;
	return instance;
}

void MeleeAttack::Attack(int direction)
{
	// player collision-bounds
	sf::IntRect player_rect = (sf::IntRect)CreatureManager::GetInstance().getPlayerBounds();
	
	// rectangle that represents the swords hitbox
	sf::IntRect attack_rect(0,0,0,0);

	// check for direction and set hitbox
	switch(direction)
	{
	case SET::DIRECTION::UP:
		attack_rect = sf::IntRect(player_rect.left - SET::CREATURE_ATTACK_RANGE,	// left
		player_rect.top - SET::CREATURE_ATTACK_RANGE,								// top
		SET::CREATURE_ATTACK_RANGE*3,												// width
		SET::CREATURE_ATTACK_RANGE);												// height
		break;
	case SET::DIRECTION::DOWN:
		attack_rect = sf::IntRect(player_rect.left - SET::CREATURE_ATTACK_RANGE,	// left
		player_rect.top + player_rect.height,										// top
		SET::CREATURE_ATTACK_RANGE*3,												// width
		SET::CREATURE_ATTACK_RANGE);												// height
		break;
	case SET::DIRECTION::LEFT:
		attack_rect = sf::IntRect(player_rect.left - SET::CREATURE_ATTACK_RANGE,	// left
		player_rect.top - SET::CREATURE_ATTACK_RANGE,								// top
		SET::CREATURE_ATTACK_RANGE,													// width
		SET::CREATURE_ATTACK_RANGE*3);												// height
		break;
	case SET::DIRECTION::RIGHT:
		attack_rect = sf::IntRect(player_rect.left + player_rect.width,				// left
		player_rect.top - SET::CREATURE_ATTACK_RANGE,								// top
		SET::CREATURE_ATTACK_RANGE,													// width
		SET::CREATURE_ATTACK_RANGE*3);												// height
		break;
	default:
		std::cout << "Unknown direction for melee-attack" << std::endl;				// XXX debug output
	}
	
	// check for collision with enemies
	const std::vector<sf::FloatRect> enemy_rects = CreatureManager::GetInstance().getEnemyTextureBounds();
	for(unsigned int i=0; i<enemy_rects.size(); i++)
	{
		if(enemy_rects[i].intersects((sf::FloatRect)attack_rect))
		{
			// reduce enemy-hp
			CreatureManager::GetInstance().getEnemies()[i]->setHealth(WEAPON_STATS::sword_damage);
		}
	}

}