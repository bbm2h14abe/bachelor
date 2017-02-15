#include "StartMenuScreen.hpp"

#include "GameScreen.hpp"
#include "ScreenManager.hpp"
#include "FilePath.hpp"
#include "Settings.hpp"
#include "InputManager.hpp"


void StartMenuScreen::LoadContent()
{
	// load background
	m_background_texture.loadFromFile(PATH::start_menu_screen_background);
	m_background_sprite.setTexture(m_background_texture);

	// set view
	m_view.SetSize(SET::View_Size);

	// XXX debug output
	std::cout << "StartMenuScreen loaded!" << std::endl;
}

void StartMenuScreen::UnloadContent()
{

}

void StartMenuScreen::Update()
{
	
	// XXX debug
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		ScreenManager::GetInstance().AddScreen(new GameScreen);

	
}

void StartMenuScreen::Render(sf::RenderWindow &window)
{
	// set view
	m_view.SetToWindow(window);

	// draw background
	window.draw(m_background_sprite);

}
