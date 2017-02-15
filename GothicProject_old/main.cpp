/*
	 _____     ____      ________   __   __   ____	  ______
   //		 //    \\   //  ||  \\  ||	 ||   \||/   //	   \\
  ||  ___   ||	    ||	    ||		||___||	   ||	||	    
  ||    ||  ||	    ||	    ||		||   ||    ||	||	    _
   \\___//   \\____//	    ||		||   ||   /||\	 \\____//

   >>>>>>>>>>>>>>>>>>	2 D - R E M A K E	<<<<<<<<<<<<<<<<<

   @ Paul Bernitz
   @ 15.08.14

   vers: 0.0.1 prototype
   vers: 0.0.2 basic movement	( 18.09. )
   vers: 0.0.3 basic fighting	( 26.09. )
   ___________________________________________________________
	
   written in: C++ using Sfml 2.1

*/




#include <iostream>

#include <SFML\Graphics.hpp>

#include "MainLoop.hpp"


// ==========>> Main
int main()
{

	// init game-loop
	MainLoop GameRoutine;

	// run the game
	GameRoutine.Run();


	return 0;
}



/*

+-------------------------[	TO - DO	]-------------------------+
															  |
   @ 15.08. -> Link sfml-libraries to Visual Studio			[X]
			-> Configurate dll's							[X]
			-> Set up simple "main_cpp"						[X]
			-> Sketch up the programs structure				[X]
			-> Solve the graphics and perspective question	[X]
			-> Search for simple test-sprites				[X] 
															  |
															  |
   @ 16.08.	-> Set up "main-loop_cpp"						[X]
			-> Call "main-loop" in "main"					[X]
			-> Fit window to monitor-size					[X]
			-> Make Render-Window loop						[X]
			-> Set up "settings_hpp" to store constants		[X]
			-> Set up "screen_manager"						[X]
			-> Set up "basic_screen" (base-class)			[X]
			-> Call "basic_screen" in "screen-manager"		[X]
			-> Set up "splash-screen_cpp"					[X]
			-> Set up "start-menu-screen_cpp"				[X]
			-> Test screen-switching						[X]
			-> Set up "file-path_hpp"						[X]
			-> load background-sprites for existing screens [X]
															  |
															  |
   @ 17.08. -> Handle view									[X]
			-> Modify view from screen-classes				[X]
			-> Set up "command-manager"						[X]
			-> write commands for menu						[X]
			-> store command-enums in "settings"			[X]
			-> Set up "time-manager_hpp"					[X]
			-> Frame-time									[X]
															  |
															  |
   @ 20.08. -> concept for loading maps						[X]
			-> Input										[X]
			-> Set up "CreatureManager_hpp"					[X]
															  |
															  |
   @ 21.08.	-> Set up "BasicCreature_hpp"					[X]
			-> find a way to store all creatures			[X]
			-> differences between player and npcs			[X]
			-> Set up "enemyCreature"						[X]
			-> Setup "npcCreature"							[X]
															  |
															  |
   @ 23.08.	-> Maybe inheriting basicCreature protected(?)	[X]
			-> Test loading enemy-creatures and showing		[X]
			-> Test rendering								[X]
			-> Expand Settings_hpp with creature types		[X]
			-> Expand Enemy-class							[X]
			-> Basic animation in creature-class			[X]
															  |
															  |			
   @ 24.08. -> own class for creature-animation				[X]
			-> make enemy sprite-sheet						[X]
			-> animate enemy								[X]
															  |
															  |
   @ 26.08.	-> directions in random-movement				[X]
															  |
															  |
   @ 02.09.	-> set up map-loader-class						[X]
			-> make tiles									[X]
			-> make textfile to load from					[X]
															  |
															  |
   @ 04.09. -> load background								[X]
			-> load tiles									[X]
			-> load enemy-spawn								[X]
															  |
															  |
   @ 07.09. -> enemy-movement								[X]
			-> collision-manager							[X]
			-> collision-check enemy->tiles					[X]
															  |
															  |
   @ 08.09.	-> load player-spawn							[X]
   			-> Try loading player							[X]
			-> player-movement								[X]
			-> player-animation								[X]
															  |
															  |
   @ 09.09. -> player collision-detection					[X]
															  |
															  |
   @ 10.09.	-> view follows the player						[X]
			-> change tile-size to 16bit					[X]
			-> change creature-size to 16bit				[X]
			-> think about dimensions( 320, 240 )			[X]
			-> better placeholder - sprites					[X]
															  |
															  |
   @ 11.09. -> view stops at map-borders					[X]
			-> make gamescreen								[X]
			-> make tiles as struct( sprite, depth, pos )	[X]
			-> test depth for tiles, player & enemy (render)[X]
															  |
															  |
   @ 12.09. -> create own sprite-sheet: player				[X]
			-> more maps for different layers ??	no..	[X]
			-> collision between creatures					[X]
															  |
															  |
   @ 13.09  -> create own tile-set							[X]
			-> create some npc's							[X]
			-> finish player sprite-sheet					[X]
			-> problems with render-by-depth solved			[X]
															  |
															  |
   @ 14.09. -> creature-depth								[X]
			-> make sorting function for enemy-sprites		[X]
			-> draw player within manager with depth		[X]
			-> easy fps-counter								[X]
			-> make some item-sprites						[X]
															  |
															  |
   @ 15.09. -> problem! enemy-collision uses also own rect  [X]
			-> smooth enemy-colliding						[X]
															  |
															  |
   @ 17.09. -> set up spell - manager						[X]
			-> set up spell - animation						[X]
			-> player cast spells							[X]
			-> delete spells from vector					[X]
			-> spell life-time increasing					[X]
			-> spell-collision with enemy					[X]
			-> spell-collision with tiles					[X]
			-> return real-directions from player			[X]
			-> let player shoot in 8-directions				[X]
			-> make own enemy-sprites( goblin )				[X]
															  |
															  |
   @ 18.09. -> use own tile-sprites							[X]
			-> change all tile-chars						[X]
			-> change test-level-map						[X]
			-> set damage in spell-struct					[X]
			-> enemies health gets reduced by spells		[X]
			-> enemies get deleted if health is zero		[X]
			-> enemy health	hud								[X]
			-> make enemy death-animation					[X]
			-> set enemy states								[X]
			-> death-state for enemy with death-animation	[X]
															  |
															  |
   @ 19.09. -> delete creature if death-animation is over	[X]
			-> set walk to false if cast spell				[X]
			-> creature-stats								[X]
			-> make player-animation for spell-casting		[X]												  
															  |
															  |
   @ 20.09. -> spell-animation problem with is_alive var    [X]
			-> is_dead, can_be_deleted-vars in spell-class	[X]
			-> death-animation for fire-ball				[X]
			-> make death-function in fire-ball				[X]
															  |
															  |
   @ 21.09. -> new tile-sprites								[X]
			-> add new tiles in engine						[X]
			-> make wall-tile for column replacement		[X]
															  |
															  |
   @ 22.09. -> add controller support						[X]
			-> finish menus and buttons						[X]
															  |
															  |
   @ 23.09. -> sword-attack sprites for player				[X]
															  |
															  |
   @ 25.09. -> fit collision-bounds	for player				[X]
			-> animation-function for close attacks			[X]
			-> melee-class for close attacks				[X]
															  |
															  |
   @ 26.09. -> finish melee-class							[X]
			-> player-attack animation						[X]
			-> why cant shoot spell up-left					[X]
															  |
															  |
   @ 30.09. -> got-hit-state for enemy						[X]
															  |
															  |
			-> input-manager cant return UL and B same time [ ]	!!!! important
			-> deal_damage status for enemy & player		[ ]
			-> creatures get pushed back by hit				[ ]
			-> enemies follow player if in range			[ ]
			-> enemies attack player						[ ]
			-> make cursor to select buttons				[ ]
			-> enemy cant walk diagonal better performance  [ ]
			-> return switch-screen command from buttons	[ ]
			-> level-switching and different tilesets		[ ]
			-> better random movement for enemies			[ ]
			-> enemies get attached to player if to near	[ ]		
			-> animate tiles								[ ]
			-> make easy splash-screen with logo to start	[ ]

			-> easy menu									[ ]	
			-> easy HUD (hp, mana, exp, inventory( ? ))		[ ]
			-> think about frametime and movement			[ ]
			-> reduce enemy- & player-hp if colliding both	[ ]
			-> push back on hits							[ ]
			-> death-animation for player ?					[ ]
			-> load npc-spawn								[ ]

			-> REDUCE LOADING FUNCTIONS TOO OFTEN, SAVE THEM IN VARS IF USING MORE THAN ONCE !!!!!!!!! 
			-> REFACTORING ...								[ ]
															  |
+-------------------------------------------------------------+

*/