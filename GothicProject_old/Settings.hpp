#include <iostream>
#include <string>

#include <SFML\Graphics.hpp>

// ==========>> Namespace for settings
namespace SET
{
	// system
	const std::string  Window_Title  = "G O T H I C       vers: 0.0.3 pre_alpha";	// title for window-bar
	const sf::Vector2f View_Size     = sf::Vector2f( 320.0f , 240.0f );				// size of the view
	const unsigned int Max_Framerate = 70;											// max-frames per second 

	// text
	const unsigned int small_text_size = 5, normal_text_size = 8, big_text_size = 12;
	const sf::Color red_text_color = sf::Color::Red;
	const sf::Color brown_text_color = sf::Color(30,30,30,0);

	// commands
	const enum MENU_COMMAND{ NONE, START_GAME, LOAD_GAME, OPTIONS, QUIT };			// menu-commands

	// types of creatures
	const enum CREATURE_TYPE{ PLAYER_WARRIOR,										// player
							  NPC_NORMAL, NPC_TRADE, NPC_QUEST,						// npc's	
							  ENEMY_GOBLIN };										// enemies

	// creature-states
	const enum CREATURE_STATE{ WALK, ATTACK, CAST_SPELL, GOT_HIT, DEAD };			// states for creatures( attracted?? )

	// attack-range
	const int CREATURE_ATTACK_RANGE = 10.0f;

	// spells
	const enum  SPELL{ FIRE_BALL, ICE_NOVA, LIGHTNING };							// types of spells
	const int	SPELL_LIFE_TIME				 = 50;									// life-span of a spell
	const float SPELL_SPEED					 = 1.8f;								// speed of spell
	const float SPELL_SPEED_DIAGONAL		 = SPELL_SPEED/std::sqrt(2.0f);			// diagonal speed of speel

	// animation
	const float		   ANIMATION_FRAME_DELAY = 10.0f;								// offset between frames
	const sf::Vector2i CREATURE_FRAME_SIZE   = sf::Vector2i(  16 ,  20 );			// size of single frame
	const sf::Vector2i CREATURE_SHEET_SIZE   = sf::Vector2i(  64 ,  80 );			// size of the whole sheet
	const sf::Vector2i CREATURE_FRAME_AMOUNT = sf::Vector2i(   4 ,   4 );			// amount of creature_frames
	const int		   SPELL_FRAME_AMOUNT	 = 3;									// amount of spell_frames

	// direction
	const enum DIRECTION{ UP, DOWN, LEFT, RIGHT, UL, UR, DL, DR };					// directions 

	// creature-movement
	const float CREATURE_NEW_DIRECTION_TIMER = 150.0f;								// delay until new direction
	const float CREATURE_SPEED				 = 0.5f;								// speed of creatures
	const float CREATURE_SPEED_DIAGONAL		 = CREATURE_SPEED/std::sqrt(2.0f);		// diagonal speed of creatures
	const float ENEMY_SEE_RANGE				 = 30.0f;								// range in which enemy follows player

	// player-movement
	const float PLAYER_SPEED				 = 0.9f;								// speed of player
	const float PLAYER_SPEED_DIAGONAL		 = PLAYER_SPEED/std::sqrt(2.0f);		// diagonal speed of player

}