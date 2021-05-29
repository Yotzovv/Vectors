#pragma once
#ifndef PointMenu_H
#define PointMenu_H

#include "Point.h"
#include "Menu.h"

class PointMenu : public Menu
{
public:
	PointMenu(std::queue<std::string> cmds);
	void instantiate_point();
	void check_if_equal();
	void redirect(int option);
	void print_menu();

private:
	Point _Point;
};

#endif