#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>

#include "BasicScreen.hpp"
#include "ViewManager.hpp"
#include "Level.hpp"

class GameScreen : public BasicScreen
{
public:
	void LoadContent();
	void UnloadContent();
	void Update();
	void Render(sf::RenderWindow &window);

private:	
	// view
	ViewManager m_view;

	// level
	Level m_level;
};

