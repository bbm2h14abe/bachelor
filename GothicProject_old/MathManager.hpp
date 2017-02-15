#include <iostream>
#include <cstdio>
#include <math.h>

#include <SFML\Graphics.hpp>

namespace MATH
{
	bool ObjectInRange(sf::Vector2f obj_a, sf::Vector2f obj_b, float range)
	{
		// calculate distance on x and y
		float distance_x = obj_a.x - obj_b.x;	
		float distance_y = obj_a.y - obj_b.y;	

		// calculate real distance
		float distance = std::sqrt( (distance_x * distance_x) + (distance_y * distance_y) );	

		// check if objects distance is smaller than range 
		if(distance < range) return true;
	
		return false;
	}
}