#include "HudEnemyHealth.hpp"

#include "Settings.hpp"
#include "FilePath.hpp"


void HudEnemyHealth::LoadContent()
{
	m_font.loadFromFile(PATH::titel_font);
	m_text.setFont(m_font);
	m_text.setCharacterSize(SET::small_text_size);
	m_text.setColor(SET::red_text_color);
}

void HudEnemyHealth::Update(sf::Vector2f enemy_origin, int enemy_health)
{
	std::ostringstream	integer_to_string;
						integer_to_string.str("");
	std::string			current_string = "";

	integer_to_string << enemy_health;
	current_string = integer_to_string.str();
	
	m_text.setString(current_string);
	m_text.setPosition(enemy_origin.x, enemy_origin.y - m_text.getGlobalBounds().height);
}

void HudEnemyHealth::Render(sf::RenderWindow &window)
{
	window.draw(m_text);
}
