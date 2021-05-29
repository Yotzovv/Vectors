#pragma once
#ifndef Menu_H
#define Menu_H

#include <iostream>
#include <queue>
#include <string>

class Menu
{
public:
	Menu();
	Menu(std::queue<std::string> cmds);
	virtual void redirect(int chose);
	virtual void print_menu();
	std::queue<std::string> _Commands;
};

#endif