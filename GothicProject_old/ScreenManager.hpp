#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>

#include "BasicScreen.hpp"

// ==========>> Manages screens
class ScreenManager
{
public:
	// return instance as singleton
	static ScreenManager &GetInstance();

	// add screen or initializer
	void AddScreen(BasicScreen *newScreen);
	void Initialize(BasicScreen *newScreen);

	// functions from active-screen
	void LoadContent();
	void UnloadContent();
	void UpdateGame();
	void Render(sf::RenderWindow &window);
	
private:
	// pointer to the active basic screen
	BasicScreen *m_activeScreen;	

};

