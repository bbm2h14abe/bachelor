#include "MainLoop.hpp"

#include <ctime>
#include <cstdlib>

#include "ScreenManager.hpp"
#include "SplashScreen.hpp"
#include "Settings.hpp"
#include "TimeManager.hpp"
#include "InputManager.hpp"


// ==========>> Run the main-loop
void MainLoop::Run()
{
	// get monitor-settings
	unsigned int monitor_width  = sf::VideoMode::getDesktopMode().width;
	unsigned int monitor_height = sf::VideoMode::getDesktopMode().height;
	unsigned int colors			= sf::VideoMode::getDesktopMode().bitsPerPixel;

	// init new render-window
	sf::RenderWindow render_window(sf::VideoMode(monitor_width, monitor_height, colors), SET::Window_Title);
	
	// set framerate-limit
	render_window.setFramerateLimit(SET::Max_Framerate);

	// init new event-manager
	sf::Event main_event;

	// init screen-manager
	ScreenManager::GetInstance().Initialize(new SplashScreen);


	/////////////////////////////////////////////////////////////////////
	// XXX debug output( delete me )
	std::cout << "X: " << monitor_width << "	Y: " << monitor_height << "		BITS: " << colors << std::endl;
	// XXX TEST FRAMES PER SEC
	float frametime = 0.0f;
	sf::Clock clock;
	int tickcounter = 0;
	/////////////////////////////////////////////////////////////////////


	// render-window loop
	while(render_window.isOpen())
	{
		// check for close-event
		while(render_window.pollEvent(main_event))
			if(main_event.type == sf::Event::Closed)
				render_window.close();
		
		// reset timer for random-numbers
		std::srand(std::time(NULL));

		// updates
		TimeManager::GetInstance().UpdateFrameTime();	// time
		InputManager::GetInstance().UpdateInput();		// input
		ScreenManager::GetInstance().UpdateGame();		// game-objects

		// clear screen 
		render_window.clear();

		// draw to screen
		ScreenManager::GetInstance().Render(render_window);

		// show drawn things on screen
		render_window.display();



		/////////////////////////////////////////////////////////////////////
		// XXX TEST FRAMES PER SEC
		frametime += clock.getElapsedTime().asSeconds();
		clock.restart();
		tickcounter++;
		if(frametime >= 1.0f)
		{
			std::cout << "FPS: " << tickcounter << std::endl;
			frametime = 0.0f;
			tickcounter = 0;
		}
		/////////////////////////////////////////////////////////////////////

	}
}

