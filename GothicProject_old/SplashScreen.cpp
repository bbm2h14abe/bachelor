#include "SplashScreen.hpp"

#include "StartMenuScreen.hpp"
#include "ScreenManager.hpp"
#include "FilePath.hpp"
#include "Settings.hpp"

void SplashScreen::LoadContent()
{
	// load background
	m_background_texture.loadFromFile(PATH::splash_screen_background);
	m_background_sprite.setTexture(m_background_texture);

	// set view
	m_view.SetSize(SET::View_Size);
	m_view.SetCenter(sf::Vector2f(m_background_sprite.getPosition().x + m_background_sprite.getGlobalBounds().width / 2.0f,
								  m_background_sprite.getPosition().y + m_background_sprite.getGlobalBounds().height / 2.0f));

	// XXX debug output
	std::cout << "SplashScreen loaded!" << std::endl;
}

void SplashScreen::UnloadContent()
{

}

void SplashScreen::Update()
{
	// XXX debug
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		ScreenManager::GetInstance().AddScreen(new StartMenuScreen); 

}

void SplashScreen::Render(sf::RenderWindow &window)
{
	// set view to window
	m_view.SetToWindow(window);

	// draw background
	window.draw(m_background_sprite);
}
