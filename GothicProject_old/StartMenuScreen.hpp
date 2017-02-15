#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>

#include "BasicScreen.hpp"
#include "Level.hpp"
#include "ViewManager.hpp"

class StartMenuScreen : public BasicScreen
{
public:
	void LoadContent();
	void UnloadContent();
	void Update();
	void Render(sf::RenderWindow &window);

private:
	sf::Texture m_background_texture;
	sf::Sprite  m_background_sprite;

	ViewManager m_view;
};

