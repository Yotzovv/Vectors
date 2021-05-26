#pragma once
#ifndef LineMenu_H
#define LineMenu_H

#include "Line.h"

class LineMenu
{
public:
	LineMenu(std::queue<std::string> cmds);
	LineMenu();
	void instantiate_line();
	void redirect_line_menu(int option);
	void print_line_menu();
	std::queue<std::string> _Commands;
private:
	Line _Line;
};

#endif