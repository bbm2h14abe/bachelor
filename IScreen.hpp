#pragma once
#include <SFML\Graphics.hpp>

class IScreen : public sf::Drawable, public sf::Transformable
{
public:
	virtual void update() = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

