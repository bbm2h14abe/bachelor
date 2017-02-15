#include <iostream>

#include "Program.hpp"

/*
	Main entry point running the program-routine. 
*/
int main()
{
	// Initializing the program and creating the window.
	const bool init_success = Program::init();
	if (!init_success) return EXIT_FAILURE;

	// Running the main program-loop.
	const bool run_success = Program::run();
	if (!run_success) return EXIT_FAILURE;

	return EXIT_SUCCESS;
}