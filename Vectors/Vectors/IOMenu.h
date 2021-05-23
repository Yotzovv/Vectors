#pragma once
#ifndef FiguresMenu_H
#define FiguresMenu_H

#include <iostream>
#include <string>
#include <vector>

class IOMenu
{
public:
	void input_from_file(std::string line);
	std::vector<std::string> read_directory();
	void read_file();
	void redirect(int chose);
	void print_io_menu();
};

#endif