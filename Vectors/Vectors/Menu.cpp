#include "Menu.h"

Menu::Menu()
{
}

Menu::Menu(std::queue<std::string> cmds)
{
	_Commands = cmds;
}

void Menu::redirect(int chose)
{
}

void Menu::print_menu()
{
}

std::queue<std::string> Menu::getCmds()
{
	return this->_Commands;
}

void Menu::setCmds(std::queue<std::string> cmds)
{
	_Commands = cmds;
}
