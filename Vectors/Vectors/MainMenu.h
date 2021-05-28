#pragma once
#ifndef MainMenu_H
#define MainMenu_H

#include "Menu.h"

class MainMenu : public Menu
{
public:
	MainMenu(std::queue<std::string> cmds);
	void redirect(int chose);
	void print_menu();
};

#endif