#pragma once
#ifndef LineMenu_H
#define LineMenu_H

#include "Line.h"
#include "Menu.h"

class LineMenu : public Menu
{
public:
	LineMenu(std::queue<std::string> cmds);
	LineMenu();
	void instantiate_line();
	void redirect(int option);
	void print_menu();
private:
	Line _Line;
};

#endif