#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>


// ==========>> Manages all views.
class ViewManager
{
public:
	static ViewManager &GetInstance();

	void SetSize(const sf::Vector2f size);
	void SetCenter(const sf::Vector2f center);
	void CheckIfInsideMap(sf::FloatRect map_background);
	void SetToWindow(sf::RenderWindow &window);

	sf::FloatRect GetBounds(){ return m_bounds; }

private:
	static sf::View m_view;
	static sf::FloatRect m_bounds;

};

