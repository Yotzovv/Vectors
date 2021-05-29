#pragma once
#ifndef VectorMenu_H
#define VectorMenu_H

#include "Vector.h"
#include "Menu.h"

class VectorMenu : public Menu
{
public:
	VectorMenu(std::queue<std::string> cmds);
	VectorMenu();
	void instantiate_vector();
	void redirect(int option);
	void print_menu();

private:
	Vector _Vector;
};

#endif