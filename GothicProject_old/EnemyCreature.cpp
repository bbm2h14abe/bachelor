#include "EnemyCreature.hpp"

#include "Settings.hpp"
#include "FilePath.hpp"
#include "CollisionManager.hpp"
#include "TileManager.hpp"
#include "TextureRectangles.hpp"
#include "CreatureManager.hpp"
#include "Stats.hpp"
#include "MathManager.hpp"

/* load */
void EnemyCreature::LoadContent(int type, int pos_x, int pos_y)
{
	// init depth & state
	m_depth = 0;
	m_state = SET::CREATURE_STATE::WALK;
	m_health = 0;
	m_is_alive = true;

	// load texture
	switch(type)
	{
	case SET::ENEMY_GOBLIN:
		m_texture.loadFromFile(PATH::enemy_goblin_sheet);
		m_health = ENEMY_GOBLIN::health;
		m_last_health = m_health;
		break;
	default:
		std::cout << "Unknown Enemy-Type" << std::endl;	// XXX debug output
	}

	// set texture to sprite
	m_sprite.setTexture(m_texture);

	// set sprite-position
	m_sprite.setPosition((float)pos_x, (float)pos_y);

	// load animation
	m_animation.LoadContent(SET::CREATURE_SHEET_SIZE, TEXT_RECT::ENEMY_SIZE, SET::CREATURE_FRAME_AMOUNT);

	// load random-movement
	m_movement.LoadContent();

	// load health-hud
	m_health_hud.LoadContent();
}

/* unload */
void EnemyCreature::UnloadContent()
{

}

/* updates */
void EnemyCreature::Update()
{
	// variables
	bool is_colliding = false;
	bool see_player	  = false;

	// set state to dead if health is zero
	if(m_health <= 0)
	{
		if(m_state != SET::CREATURE_STATE::DEAD)	m_animation.SetCurrentHorizontalFrame(0);

		m_state = SET::CREATURE_STATE::DEAD;
	}

	if(m_last_health != m_health)
	{
		m_last_health = m_health;
		m_state = SET::CREATURE_STATE::GOT_HIT;
	}

	// check if player is in range
	see_player = MATH::ObjectInRange(CreatureManager::GetInstance().getPlayerSprite().getPosition(),
									 m_sprite.getPosition(), SET::ENEMY_SEE_RANGE);


	// walk - state
	if(m_state == SET::CREATURE_STATE::WALK)
	{
		// update movement
		m_movement.UpdatePosition(m_sprite.getPosition(), CreatureManager::GetInstance().getPlayerSprite().getPosition(), see_player);

		// get new bounding-boxes
		sf::FloatRect new_horizontal_bounds = sf::FloatRect(m_movement.getNewHorizontalPosition().x, m_movement.getNewHorizontalPosition().y,
															(float)TEXT_RECT::ENEMY_SIZE.x, (float)TEXT_RECT::ENEMY_SIZE.y);
		sf::FloatRect new_vertical_bounds = sf::FloatRect(m_movement.getNewVerticalPosition().x, m_movement.getNewVerticalPosition().y,
															(float)TEXT_RECT::ENEMY_SIZE.x, (float)TEXT_RECT::ENEMY_SIZE.y);

		// smaller collision-rectangle
		sf::FloatRect horizontal_collision_bounds	= new_horizontal_bounds;
		horizontal_collision_bounds.top				+= horizontal_collision_bounds.height/2.0f;
		horizontal_collision_bounds.height			-= horizontal_collision_bounds.height/2.0f;
		sf::FloatRect vertical_collision_bounds		= new_vertical_bounds;
		vertical_collision_bounds.top				+= vertical_collision_bounds.height/2.0f;
		vertical_collision_bounds.height			-= vertical_collision_bounds.height/2.0f;

		// collision-bounds for return
		m_collision_bounds = horizontal_collision_bounds;
		m_texture_bounds   = new_horizontal_bounds;

		// check collision with new position on x and y
		// tile-collision
		bool collide_horizontal = CollisionManager::TileCollision(horizontal_collision_bounds,	TileManager::GetInstance().getTileRects());
		bool collide_vertical   = CollisionManager::TileCollision(vertical_collision_bounds,	TileManager::GetInstance().getTileRects());

		// collision with player
		if(collide_horizontal == false) 
		{
			sf::FloatRect player_rect = CreatureManager::GetInstance().getPlayerBounds();
			collide_horizontal = horizontal_collision_bounds.intersects(player_rect);
		}
		if(collide_vertical == false) 
		{
			sf::FloatRect player_rect = CreatureManager::GetInstance().getPlayerBounds();
			collide_vertical = vertical_collision_bounds.intersects(player_rect);
		}
		// collision with other enemies
		if(collide_horizontal == false) 
		{
			collide_horizontal = CollisionManager::EnemyCollision(horizontal_collision_bounds,CreatureManager::GetInstance().getEnemies(),m_depth);
		
		}
		if(collide_vertical == false)
		{
			collide_vertical = CollisionManager::EnemyCollision(vertical_collision_bounds,CreatureManager::GetInstance().getEnemies(),m_depth);
		}

		// set new position on x or y if no collision happens on this axis
		if(collide_horizontal == false)
			m_sprite.setPosition(m_movement.getNewHorizontalPosition().x, m_sprite.getPosition().y);
		if(collide_vertical == false)
			m_sprite.setPosition(m_sprite.getPosition().x, m_movement.getNewVerticalPosition().y);

		// XXXX THINK ABOUT...
		if(collide_horizontal == true && collide_vertical == true) is_colliding = true;


		// update walk-animation
		sf::IntRect texture_rectangle = m_animation.GetWalkRect((int)m_movement.getSimpleDirection(), is_colliding);

		m_sprite.setTextureRect(texture_rectangle);
	}

	// got-hit state
	if(m_state == SET::CREATURE_STATE::GOT_HIT)
	{
		// handle push-back function
		// check for collision with tiles & player
		// dont handle damage if got-hit state
		// change state if enough recoil
		m_state = SET::CREATURE_STATE::WALK;
	}

	// death - state
	if(m_state == SET::CREATURE_STATE::DEAD)
	{
		// update death animation once
		sf::IntRect texture_rectangle = m_animation.GetDeathRect();
		m_sprite.setTextureRect(texture_rectangle);

		if(texture_rectangle == sf::IntRect(0,0,0,0))	m_is_alive = false;
	}

	// set depth
	m_depth = (int)m_sprite.getGlobalBounds().top;

	// set health-hud
	m_health_hud.Update(m_sprite.getPosition(), m_health);
}

/* render */
void EnemyCreature::Render(sf::RenderWindow &window)
{
	// draw sprite
	window.draw(m_sprite);
	
	// draw health
	m_health_hud.Render(window);
}

void EnemyCreature::setHealth(int damage)
{
	m_health -= damage;
	if(m_health < 0)	m_health = 0;
}


void EnemyCreature::SortSpritesByDepth(std::vector<EnemyCreature*> &enemies)
{
	// sort the vector using predicate and std::sort
	std::sort(enemies.begin(), enemies.end(), MyCreatureSortPredicate);
}