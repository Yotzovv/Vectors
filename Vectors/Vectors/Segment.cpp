#include "Segment.h"
#include <math.h>
#include <cmath>

void Segment::set_startPt(Point pt)
{
	Start_pt = pt;
}

void Segment::set_endPt(Point pt)
{
	End_pt = pt;
}

Point Segment::get_startPt()
{
	return Start_pt;
}

Point Segment::get_endPt()
{
	return End_pt;
}

Segment::Segment()
{
}

Segment::Segment(Point start_pt, Point end_pt)
{
	set_startPt(start_pt);
	set_endPt(end_pt);
}

double Segment::find_segment_length()
{
	return (double)sqrt(pow(get_endPt().X - get_startPt().X, 2) + pow(get_endPt().Y - get_startPt().Y, 2));
}
