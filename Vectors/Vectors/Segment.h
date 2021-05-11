#ifndef Segment_H
#define Segment_H

#pragma once

#include "Segment.h"
#include "Line.h"
#include "Point.h"

class Segment : public Line
{
public:
	Point Start_pt;
	Point End_pt;
	Segment();
	Segment(Point start_pt, Point end_pt);
};

#endif