#pragma once
#ifndef TriangleMenu_H
#define TriangleMenu_H

#include "Triangle.h"

class TriangleMenu
{
public:
	TriangleMenu();
	TriangleMenu(std::queue<std::string> cmds);
	void instantiate_triangle();
	void redirect_triangle_menu(int option);
	void print_triangle_menu();
	std::queue<std::string> _Commands;
private:
	Triangle _Triangle;
};

#endif