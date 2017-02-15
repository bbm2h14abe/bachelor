#pragma once
#include "IScreen.hpp"

class SplashScreen : public IScreen
{
public:
	SplashScreen();
	~SplashScreen();

	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};