#include "GameScreen.hpp"

#include "ScreenManager.hpp"
#include "FilePath.hpp"
#include "Settings.hpp"

#include "CreatureManager.hpp"

void GameScreen::LoadContent()
{
	// set view
	m_view.SetSize(SET::View_Size);

	// load level
	m_level.Load("TextFiles/test.txt", PATH::game_standard_background);

	// XXX debug output
	std::cout << "GameScreen loaded!" << std::endl;
}

void GameScreen::UnloadContent()
{

}

void GameScreen::Update()
{
	// update player, npc's and enemies
	CreatureManager::GetInstance().Update();

	// update view-position
	m_view.SetCenter(CreatureManager::GetInstance().getPlayerSprite().getPosition());
	m_view.CheckIfInsideMap(m_level.getLevelBounds());
}

void GameScreen::Render(sf::RenderWindow &window)
{
	// set view to window
	m_view.SetToWindow(window);

	// draw tiles & background
	m_level.RenderBack(window);

	// draw player, npc's and enemies
	CreatureManager::GetInstance().Render(window);

	// draw front-tiles 
	m_level.RenderFront(window);
}
