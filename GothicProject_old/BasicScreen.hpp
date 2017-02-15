#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>

class BasicScreen
{
public:
	virtual void LoadContent(){}
	virtual void UnloadContent(){}
	virtual void Update(){}
	virtual void Render(sf::RenderWindow &window){}

};

