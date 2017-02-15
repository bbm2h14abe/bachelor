#include "CommandManager.hpp"

#include "Settings.hpp"

// return static instance
CommandManager &CommandManager::GetInstance()
{
	static CommandManager instance;
	return instance;
}

// reset all commands
void CommandManager::ResetCommands()
{
	m_menu_command = SET::MENU_COMMAND::NONE;
}

// return current menu-command
unsigned int CommandManager::GetMenuCommand()
{
	return m_menu_command;
}

// sets current menu-command
void CommandManager::SetMenuCommand(unsigned int command)
{
	m_menu_command = command;
}
