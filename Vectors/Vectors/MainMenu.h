#pragma once
#ifndef MainMenu_H
#define MainMenu_H

#include <queue>
#include <string>

class MainMenu
{
public:
	std::queue<std::string> _Commands;
	void redirectMain(int chose);
	void print_main_menu();
};

#endif