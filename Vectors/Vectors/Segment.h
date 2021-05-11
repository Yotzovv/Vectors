#ifndef Segment_H
#define Segment_H

#pragma once

#include "Segment.h"
#include "Line.h"
#include "Point.h"

class Segment : public Line
{
private:
	Point Start_pt;
	Point End_pt;

public:
	void set_startPt(Point pt);
	void set_endPt(Point pt);
	Point get_startPt();
	Point get_endPt();
	Segment();
	Segment(Point start_pt, Point end_pt);
	double find_segment_length();
};

#endif