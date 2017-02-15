#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>

#include "BasicScreen.hpp"
#include "ViewManager.hpp"

class SplashScreen : public BasicScreen
{
public:
	void LoadContent();
	void UnloadContent();
	void Update();
	void Render(sf::RenderWindow &window);

private:
	// background
	sf::Texture m_background_texture;
	sf::Sprite  m_background_sprite;
	
	// view
	ViewManager m_view;

};

