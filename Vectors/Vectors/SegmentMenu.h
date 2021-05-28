#pragma once
#ifndef SegmentMenu_H
#define SegmentMenu_H

#include "Segment.h"
#include "SegmentMenu.h"
#include "Menu.h"

class SegmentMenu : public Menu
{
public:
	SegmentMenu(std::queue<std::string> cmds);
	SegmentMenu();
	void instantiate_segment();
	void redirect(int option);
	void print_menu();
private:
	Segment _Segment;
};

#endif