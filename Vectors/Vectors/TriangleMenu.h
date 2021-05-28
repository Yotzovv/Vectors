#pragma once
#ifndef TriangleMenu_H
#define TriangleMenu_H

#include "Triangle.h"
#include "Menu.h"

class TriangleMenu : public Menu
{
public:
	TriangleMenu();
	TriangleMenu(std::queue<std::string> cmds);
	void instantiate_triangle();
	void redirect(int option);
	void print_menu();
private:
	Triangle _Triangle;
};

#endif