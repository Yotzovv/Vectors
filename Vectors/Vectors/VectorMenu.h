#pragma once
#ifndef VectorMenu_H
#define VectorMenu_H

#include "Vector.h"

class VectorMenu
{
public:
	VectorMenu(std::queue<std::string> cmds);
	VectorMenu();
	void instantiate_vector();
	void redirect_vector_menu(int option);
	void print_vector_menu();

private:
	Vector _Vector;
	std::queue<std::string> _Commands;
};

#endif