#include "ScreenManager.hpp"


// ==========>> get instance
ScreenManager &ScreenManager::GetInstance()
{
	static ScreenManager Instance;
	return Instance;
}


// ==========>> initializer
void ScreenManager::Initialize(BasicScreen *NewScreen)
{
	// set active screen 
	m_activeScreen = nullptr;
	m_activeScreen = NewScreen;
	m_activeScreen->LoadContent();
}


// ==========>> add new screen
void ScreenManager::AddScreen(BasicScreen *NewScreen)
{
	// delete current-screen
	m_activeScreen->UnloadContent();
	delete m_activeScreen;
	m_activeScreen = nullptr;

	// load new screen
	m_activeScreen = NewScreen;
	m_activeScreen->LoadContent();
}


// ==========>> load content
void ScreenManager::LoadContent()
{
	m_activeScreen->LoadContent();
}


// ==========>> unload content
void ScreenManager::UnloadContent()
{
	m_activeScreen->UnloadContent();
}


// ==========>> updates
void ScreenManager::UpdateGame()
{
	m_activeScreen->Update();
}


// ==========>> draw to window
void ScreenManager::Render(sf::RenderWindow &window)
{
	m_activeScreen->Render(window);
}