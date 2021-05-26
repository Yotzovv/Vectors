#pragma once
#ifndef SegmentMenu_H
#define SegmentMenu_H

#include "Segment.h"
#include "SegmentMenu.h"

class SegmentMenu
{
public:
	SegmentMenu(std::queue<std::string> cmds);
	SegmentMenu();
	void instantiate_segment();
	void redirect_segment_menu(int option);
	void print_segment_menu();
	std::queue<std::string> _Commands;
private:
	Segment _Segment;
};

#endif