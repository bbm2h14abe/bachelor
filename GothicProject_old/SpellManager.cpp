#include "SpellManager.hpp"

#include "FilePath.hpp"
#include "Settings.hpp"
#include "TextureRectangles.hpp"
#include "Stats.hpp"

#include "TileManager.hpp"
#include "CreatureManager.hpp"


// ==========>> Load 
void SpellManager::LoadContent()
{
	// load texture-sheet
	m_spell_sheet.loadFromFile(PATH::spell_sheet);

	// load animation_rect
	m_animation.LoadContent();
}


// ==========>> Cast a new spell
void SpellManager::CastSpell(int type, sf::FloatRect player_bounds, int direction)
{
	// set new spell
	spell *new_spell = new spell;

	// init member
	new_spell->sprite.setTexture(m_spell_sheet);
	new_spell->type		 = type;
	new_spell->damage	 = 0;
	new_spell->mana_cost = 0;
	new_spell->direction = direction;
	new_spell->life_time = 0;
	new_spell->is_alive	 = true;
	new_spell->can_be_deleted = false;

	// check which type of spell
	if(new_spell->type == SET::SPELL::FIRE_BALL)
	{
		// set fire-ball
		new_spell->sprite.setTextureRect(TEXT_RECT::SPELL_FIRE_BALL);
		new_spell->damage		= SPELL_STATS::fire_ball_damage;
		new_spell->mana_cost	= SPELL_STATS::fire_ball_mana_cost;
	}
	else
		std::cout << "\nUnknown spell-type\n";	// XXX debug output

	// set position of spell
	new_spell->sprite.setPosition(player_bounds.left + (player_bounds.width/2.0f), player_bounds.top + (player_bounds.height/2.0f));

	// set sprite-direction
	new_spell->sprite.setOrigin(new_spell->sprite.getGlobalBounds().width/2.0f,new_spell->sprite.getGlobalBounds().height/2.0f);
	if(new_spell->direction == SET::DIRECTION::UP)	new_spell->sprite.setRotation(270.0f);
	else if(new_spell->direction == SET::DIRECTION::DOWN) new_spell->sprite.setRotation(90.0f);
	else if(new_spell->direction == SET::DIRECTION::LEFT) new_spell->sprite.setRotation(180.0f);
	else if(new_spell->direction == SET::DIRECTION::UL) new_spell->sprite.setRotation(225.0f);
	else if(new_spell->direction == SET::DIRECTION::UR) new_spell->sprite.setRotation(315.0f);
	else if(new_spell->direction == SET::DIRECTION::DL) new_spell->sprite.setRotation(135.0f);
	else if(new_spell->direction == SET::DIRECTION::DR) new_spell->sprite.setRotation(45.0f);

	// push back new spell
	m_spells.push_back(new_spell);
}


// ==========>> Updates
void SpellManager::Update()
{
	// check if spell-vector isn't empty
	if(m_spells.size() != 0)
	{
		// loop spells
		for(unsigned int i=0; i<m_spells.size(); i++)
		{
			// get current texture-rectangle from animation-object
			sf::IntRect texture_rect = m_animation.GetTextureRect(m_spells[i]->type, m_spells[i]->is_alive);

			// check for deleting 
			if(m_animation.CanBeDeleted()==true)	
			{
				m_spells[i]->can_be_deleted = true;
			}

			// check for wich direction to move
			if(m_spells[i]->is_alive == true)
			{
				if(m_spells[i]->direction == SET::DIRECTION::UP)			m_spells[i]->sprite.move(0.0f, -SET::SPELL_SPEED);
				else if(m_spells[i]->direction == SET::DIRECTION::DOWN)		m_spells[i]->sprite.move(0.0f, SET::SPELL_SPEED);
				else if(m_spells[i]->direction == SET::DIRECTION::LEFT)		m_spells[i]->sprite.move(-SET::SPELL_SPEED, 0.0f);
				else if(m_spells[i]->direction == SET::DIRECTION::RIGHT)	m_spells[i]->sprite.move(SET::SPELL_SPEED, 0.0f);
				else if(m_spells[i]->direction == SET::DIRECTION::UL)		m_spells[i]->sprite.move(-SET::SPELL_SPEED_DIAGONAL, 
																									-SET::SPELL_SPEED_DIAGONAL);
				else if(m_spells[i]->direction == SET::DIRECTION::UR)		m_spells[i]->sprite.move(SET::SPELL_SPEED_DIAGONAL, 
																									-SET::SPELL_SPEED_DIAGONAL);
				else if(m_spells[i]->direction == SET::DIRECTION::DL)		m_spells[i]->sprite.move(-SET::SPELL_SPEED_DIAGONAL, 
																									 SET::SPELL_SPEED_DIAGONAL);
				else if(m_spells[i]->direction == SET::DIRECTION::DR)		m_spells[i]->sprite.move(SET::SPELL_SPEED_DIAGONAL, 
																									 SET::SPELL_SPEED_DIAGONAL);
			}

			// set current texture-rectangle to sprite
			m_spells[i]->sprite.setTextureRect(texture_rect);

			// check if spells life-time is over
			m_spells[i]->life_time++;
			if(m_spells[i]->life_time >= SET::SPELL_LIFE_TIME)
			{
				// destroy spell
				m_spells[i]->is_alive = false;
			}

			// check for collision with tiles
			const std::vector<sf::FloatRect> tile_rects = TileManager::GetInstance().getTileRects();
			for(unsigned int j=0; j<tile_rects.size(); j++)
			{
				if(tile_rects[j].contains(m_spells[i]->sprite.getPosition()))
				{
					// destroy spell
					m_spells[i]->is_alive = false;
				}
			}

			// check for collision with enemies
			const std::vector<sf::FloatRect> enemy_rects = CreatureManager::GetInstance().getEnemyTextureBounds();
			for(unsigned int j=0; j<enemy_rects.size(); j++)
			{
				if(enemy_rects[j].contains(m_spells[i]->sprite.getPosition()))
				{
					// reduce enemy-hp
					if(m_spells[i]->is_alive == true) CreatureManager::GetInstance().getEnemies()[j]->setHealth(m_spells[i]->damage);
					// destroy spell
					m_spells[i]->is_alive = false;
				}
			}

		}

		// check for spells to delete
		for(unsigned int i=0; i<m_spells.size(); i++)
		{
			if(m_spells[i]->can_be_deleted == true)
			{
				m_spells[i] = m_spells.back();
				m_spells.pop_back();
				i--;
			}
		}
	}

}


// ==========>> Draw to screen
void SpellManager::Render(sf::RenderWindow &window)
{
	// check if spell-vector isn't empty
	if(m_spells.size() != 0)
	{
		// loop spells
		for(unsigned int i=0; i<m_spells.size(); i++)
		{
			// draw spells to screen
			window.draw(m_spells[i]->sprite);
		}
	}
}
