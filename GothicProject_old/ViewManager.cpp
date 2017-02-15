#include "ViewManager.hpp"
#include "Settings.hpp"


// ==========>> Init member
sf::View ViewManager::m_view;
sf::FloatRect ViewManager::m_bounds;


// ==========>> Return static instance( singleton )
ViewManager &ViewManager::GetInstance()
{
	static ViewManager instance;
	return instance;
}


// ==========>> Set view-size
void ViewManager::SetSize(const sf::Vector2f size)
{
	m_view.setSize(size);
}


// ==========>> Set view-center 
void ViewManager::SetCenter(const sf::Vector2f center)
{
	m_view.setCenter(center);
}


// ==========>> Check for background-texture-bounds to stop scrolling there
void ViewManager::CheckIfInsideMap(sf::FloatRect map_background)
{
	// get current view_rect
	m_bounds = sf::FloatRect(m_view.getCenter().x - (SET::View_Size.x/2.0f), 
								m_view.getCenter().y - (SET::View_Size.y/2.0f), 
								SET::View_Size.x, SET::View_Size.y);

	// correct view if its too high
	if(m_bounds.top <= map_background.top) 
		m_view.setCenter(sf::Vector2f(m_view.getCenter().x,map_background.top + (SET::View_Size.y/2.0f)));													              

	// correct view if its too low
	if(m_bounds.top + m_bounds.height >= map_background.top + map_background.height) 
		m_view.setCenter(sf::Vector2f(m_view.getCenter().x, map_background.top + map_background.height - (SET::View_Size.y/2.0f)));					              

	// correct view if its too far on the left
	if(m_bounds.left <= map_background.left) 
		m_view.setCenter(sf::Vector2f(map_background.left + (SET::View_Size.x/2.0f), m_view.getCenter().y));
	
	// correct view if its too far on the right
	if(m_bounds.left + m_bounds.width >= map_background.left + map_background.width) 
		m_view.setCenter(sf::Vector2f(map_background.left + map_background.width - (SET::View_Size.x/2.0f), m_view.getCenter().y));

}


// ==========>> Set view to window
void ViewManager::SetToWindow(sf::RenderWindow &window)
{
	window.setView(m_view);
}

