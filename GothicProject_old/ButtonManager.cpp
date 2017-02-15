#include "ButtonManager.hpp"

#include "FilePath.hpp"
#include "Settings.hpp"

void ButtonManager::LoadContent()
{
	m_font.loadFromFile(PATH::titel_font);
}

void ButtonManager::AddButton(std::string string, sf::Vector2f position)
{
	sf::Text new_button;
	new_button.setString(string);
	new_button.setFont(m_font);
	new_button.setCharacterSize(SET::big_text_size);
	new_button.setColor(SET::brown_text_color);
	new_button.setPosition(position);

	m_buttons.push_back(new_button);
}

void ButtonManager::Update()
{

}

void ButtonManager::Render(sf::RenderWindow &window)
{
	if(m_buttons.size() != 0)
	{
		for(unsigned int i=0; i<m_buttons.size(); i++)
		{
			window.draw(m_buttons[i]);
		}
	}
}