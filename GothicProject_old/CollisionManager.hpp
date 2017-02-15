#pragma once

#include <iostream>
#include <vector>

#include <SFML\Graphics.hpp>

#include "EnemyCreature.hpp"

class CollisionManager
{
public:
	static bool TileCollision(sf::FloatRect creature_rect, std::vector<sf::FloatRect> tile_rects);
	static bool EnemyCollision(sf::FloatRect collision_bounds, std::vector<EnemyCreature*> enemies, int depth);
};

