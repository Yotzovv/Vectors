#pragma once
#include "Point.h"
#ifndef PointMenu_H
#define PointMenu_H

class PointMenu
{
public:
	void instantiate_point();
	void check_if_equal();
	void redirect_point_menu(int option);
	void print_point_menu();

private:
	Point _Point;
};

#endif