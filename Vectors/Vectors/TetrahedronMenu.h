#pragma once
#ifndef TetrahedronMenu_H
#define TetrahedronMenu_H

#include "Tetrahedron.h"

class TetrahedronMenu
{
public:
	TetrahedronMenu();
	void redirect_tetrahedron_menu(int option);
	void print_tetrahedron_menu();

private:
	Tetrahedron _Tetrahedron;
};

#endif