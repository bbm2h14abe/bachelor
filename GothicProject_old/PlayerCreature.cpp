#include "PlayerCreature.hpp"

#include "Settings.hpp"
#include "FilePath.hpp"
#include "CollisionManager.hpp"
#include "TileManager.hpp"
#include "TextureRectangles.hpp"
#include "InputManager.hpp"
#include "CreatureManager.hpp"
#include "Stats.hpp"
#include "MeleeAttack.hpp"

/* load */
void PlayerCreature::LoadContent(int type, int pos_x, int pos_y)
{
	// init depth & state
	m_depth = 0;
	m_state = SET::CREATURE_STATE::WALK;

	// load texture
	switch(type)
	{
	case SET::PLAYER_WARRIOR:
		m_texture.loadFromFile(PATH::player_warrior_sheet);
		// stats
		m_health	= WARRIOR_STATS::health;
		m_mana		= WARRIOR_STATS::mana;
		m_attack	= WARRIOR_STATS::attack;
		m_defense	= WARRIOR_STATS::defense;
		break;
	default:
		std::cout << "Unknown Player-Type" << std::endl;	// XXX debug output
	}

	// set texture to sprite
	m_sprite.setTexture(m_texture);

	// set sprite-position
	m_sprite.setPosition((float)pos_x, (float)pos_y);

	// load animation
	m_animation.LoadContent(SET::CREATURE_SHEET_SIZE, TEXT_RECT::PLAYER_SIZE, SET::CREATURE_FRAME_AMOUNT);

	// load movement
	m_movement.LoadContent();

	// load spells
	m_spell.LoadContent();

}

/* unload */
void PlayerCreature::UnloadContent()
{

}

/* updates */
void PlayerCreature::Update()
{
	// variables
	bool is_colliding = false;
	int  pressed_button = InputManager::GetInstance().GetPressed_Button();

	// check for attack
	bool is_attacking = false;
	if(pressed_button == InputManager::BUTTON::A && m_state == SET::CREATURE_STATE::WALK)
	{
		m_state = SET::CREATURE_STATE::ATTACK;
		is_attacking = true;
	}

	// check for spell
	bool cast_spell = false;
	if(pressed_button == InputManager::BUTTON::B && m_state == SET::CREATURE_STATE::WALK)
	{
		m_state = SET::CREATURE_STATE::CAST_SPELL;
		cast_spell = true;
	}

	// walk - state
	if(m_state == SET::CREATURE_STATE::WALK)
	{
		// update movement
		m_movement.UpdatePosition(m_sprite.getPosition());

		// get new bounding-boxes
		sf::FloatRect new_horizontal_bounds = sf::FloatRect(m_movement.getNewHorizontalPosition().x, m_movement.getNewHorizontalPosition().y,
															(float)TEXT_RECT::PLAYER_SIZE.x, (float)TEXT_RECT::PLAYER_SIZE.y);
		sf::FloatRect new_vertical_bounds = sf::FloatRect(m_movement.getNewVerticalPosition().x, m_movement.getNewVerticalPosition().y,
															(float)TEXT_RECT::PLAYER_SIZE.x, (float)TEXT_RECT::PLAYER_SIZE.y);

		// smaller collision-rectangle
		sf::FloatRect horizontal_collision_bounds	= new_horizontal_bounds;
		horizontal_collision_bounds.top				+= 19.0f;
		horizontal_collision_bounds.height			-= 19.0f + 6.0f;
		horizontal_collision_bounds.left			+= 10.0f;
		horizontal_collision_bounds.width			-= 10.0f + 10.0f;
		sf::FloatRect vertical_collision_bounds		= new_vertical_bounds;
		vertical_collision_bounds.top				+= 19.0f;
		vertical_collision_bounds.height			-= 19.0f + 6.0f;
		vertical_collision_bounds.left				+= 10.0f;
		vertical_collision_bounds.width				-= 10.0f + 10.0f;

		// collision-bounds for return
		m_collision_bounds = horizontal_collision_bounds;

		// check collision with new position on x and y with tiles
		bool collide_horizontal = CollisionManager::TileCollision(horizontal_collision_bounds, TileManager::GetInstance().getTileRects());
		bool collide_vertical   = CollisionManager::TileCollision(vertical_collision_bounds, TileManager::GetInstance().getTileRects());
		// collision with enemies
		if(collide_horizontal == false) 
		{
			collide_horizontal = CollisionManager::TileCollision(horizontal_collision_bounds, CreatureManager::GetInstance().getEnemyBounds());
		}
		if(collide_vertical == false) 
		{
			collide_vertical = CollisionManager::TileCollision(vertical_collision_bounds, CreatureManager::GetInstance().getEnemyBounds());
		}


		if(m_sprite.getPosition() != m_movement.getNewHorizontalPosition() || m_sprite.getPosition() != m_movement.getNewVerticalPosition())
			is_colliding = false;
		else 
			is_colliding = true;

		// set new position on x or y if no collision happens on this axis
		if(collide_horizontal == false)
			m_sprite.setPosition(m_movement.getNewHorizontalPosition().x, m_sprite.getPosition().y);
		if(collide_vertical == false)
			m_sprite.setPosition(m_sprite.getPosition().x, m_movement.getNewVerticalPosition().y);

		// update animation
		sf::IntRect texture_rectangle = m_animation.GetWalkRect(m_movement.getSimpleDirection(), is_colliding);	
		m_sprite.setTextureRect(texture_rectangle);
	}

	// attack - state
	if(m_state == SET::CREATURE_STATE::ATTACK)
	{
		// attack - once
		if(is_attacking == true)
		{
			// set x-frame to start
			m_animation.SetCurrentHorizontalFrame(0);

			// check for sword <-> enemy-collision
			MeleeAttack::GetInstance().Attack(m_movement.getSimpleDirection());
		}

		
		// update attack-animation
		sf::IntRect texture_rectangle = m_animation.GetAttackRect(m_movement.getSimpleDirection());
		if(texture_rectangle != sf::IntRect(0,0,0,0))
			m_sprite.setTextureRect(texture_rectangle);

		// change state to walk if returns empty texture_rect
		if(texture_rectangle == sf::IntRect(0,0,0,0))	m_state = SET::CREATURE_STATE::WALK;
	}

	// cast-spell - state
	if(m_state == SET::CREATURE_STATE::CAST_SPELL)
	{
		// cast spell once
		if(cast_spell == true)
			m_spell.CastSpell(SET::SPELL::FIRE_BALL, m_sprite.getGlobalBounds(), m_movement.getDirection());

		// update spell-casting animation 
		sf::IntRect texture_rectangle = m_animation.GetCastRect(m_movement.getSimpleDirection());
		if(texture_rectangle != sf::IntRect(0,0,0,0))
			m_sprite.setTextureRect(texture_rectangle);

		// change state to walk if returns empty texture_rect
		if(texture_rectangle == sf::IntRect(0,0,0,0))	m_state = SET::CREATURE_STATE::WALK;
	}


	// update - spell
	m_spell.Update();

	// set depth
	m_depth = m_sprite.getGlobalBounds().top;
}

/* render */
void PlayerCreature::Render(sf::RenderWindow &window)
{
	// draw player-sprite
	window.draw(m_sprite);

	// draw spell
	m_spell.Render(window);
}