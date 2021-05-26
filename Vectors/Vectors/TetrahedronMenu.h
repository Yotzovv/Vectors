#pragma once
#ifndef TetrahedronMenu_H
#define TetrahedronMenu_H

#include "Tetrahedron.h"

class TetrahedronMenu
{
public:
	TetrahedronMenu();
	TetrahedronMenu(std::queue<std::string> cmds);
	void instantiate_tetrahedron();
	void redirect_tetrahedron_menu(int option);
	void print_tetrahedron_menu();
	std::queue<std::string> _Commands;
private:
	Tetrahedron _Tetrahedron;
};

#endif