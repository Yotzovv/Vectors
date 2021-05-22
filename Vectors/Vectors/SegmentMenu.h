#pragma once
#ifndef SegmentMenu_H
#define SegmentMenu_H

#include "Segment.h"
#include "SegmentMenu.h"

class SegmentMenu
{
public:
	SegmentMenu();
	void redirect_segment_menu(int option);
	void print_segment_menu();

private:
	Segment _Segment;
};

#endif