#pragma once
#ifndef TriangleMenu_H
#define TriangleMenu_H

#include "Triangle.h"

class TriangleMenu
{
public:
	TriangleMenu();
	void redirect_triangle_menu(int option);
	void print_triangle_menu();

private:
	Triangle _Triangle;
};

#endif