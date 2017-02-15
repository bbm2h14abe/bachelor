#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>

class MeleeAttack
{
public:
	static MeleeAttack &GetInstance();

	void Attack(int direction);

};

