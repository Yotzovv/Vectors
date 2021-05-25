#pragma once
#ifndef LineMenu_H
#define LineMenu_H

#include "Line.h"

class LineMenu
{
public:
	LineMenu();
	void redirect_line_menu(int option);
	void print_line_menu();

private:
	Line _Line;
};

#endif