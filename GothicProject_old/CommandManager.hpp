#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>

class CommandManager
{
public:
	static CommandManager &GetInstance();

	// reset all active commands
	void ResetCommands();

	// get & set menu-commands
	unsigned int GetMenuCommand();
	void SetMenuCommand(unsigned int command);
	
private:
	unsigned int m_menu_command;

};

