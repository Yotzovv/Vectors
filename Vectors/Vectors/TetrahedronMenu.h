#pragma once
#ifndef TetrahedronMenu_H
#define TetrahedronMenu_H

#include "Tetrahedron.h"
#include "Menu.h"

class TetrahedronMenu : public Menu
{
public:
	TetrahedronMenu();
	TetrahedronMenu(std::queue<std::string> cmds);
	void instantiate_tetrahedron();
	void redirect(int option);
	void print_menu();
private:
	Tetrahedron _Tetrahedron;
};

#endif