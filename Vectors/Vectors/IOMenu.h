#pragma once
#ifndef IOMenu_H
#define IOMenu_H

#include <iostream>
#include <string>
#include <vector>
#include "MainMenu.h"

class IOMenu : public Menu
{
public:
	IOMenu();
	std::vector<std::string> read_directory();
	void read_file();
	void redirect(int chose);
	void print_io_menu();
};

#endif