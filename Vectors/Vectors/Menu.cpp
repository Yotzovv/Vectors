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

void Menu::pushToCmds(std::string cmd)
{
	this->_Commands.push(cmd);
}

void Menu::setCmds(std::queue<std::string> cmds)
{
	_Commands = cmds;
}

std::vector<std::string> Menu::getOutputs()
{
	return _Outputs;
}

void Menu::pushtToOutputs(std::string output)
{
	_Outputs.push_back(output);
}

void Menu::setOutputs(std::vector<std::string> outputs)
{
	for (auto output : outputs) {
		_Outputs.push_back(output);
	}
}
