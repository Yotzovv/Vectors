#pragma once
#ifndef PointMenu_H
#define PointMenu_H

#include "Point.h"
#include <queue>
#include <string>

class PointMenu
{
public:
	PointMenu(std::queue<std::string> cmds);
	void instantiate_point();
	void check_if_equal();
	void redirect_point_menu(int option);
	void print_point_menu();

private:
	Point _Point;
	std::queue<std::string> _Commands;
};

#endif