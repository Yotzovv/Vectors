#pragma once
#ifndef VectorMenu_H
#define VectorMenu_H

#include "Vector.h"

class VectorMenu
{
public:
	VectorMenu();
	void redirect_vector_menu(int option);
	void print_vector_menu();

private:
	Vector _Vector;
};

#endif