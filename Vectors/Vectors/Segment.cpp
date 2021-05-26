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

Point Segment::find_segment_middle()
{
	Point middle((Start_pt.X + End_pt.X) / 2, (Start_pt.Y + End_pt.Y) / 2);

	return middle;
}

//Check if point lies on segment
bool Segment::operator==(Point point)
{
	//(x - x1) / (x2 - x1) = (y - y1) / (y2 - y1)
	return (point.X - Start_pt.X) / (get_endPt().X - get_startPt().X) == (point.Y - get_startPt().Y) / (get_endPt().Y - get_startPt().Y);
}

std::ostream& Segment::ins(std::ostream& print) const
{
	print << Start_pt, End_pt;

	return print;
}

std::istream& Segment::ext(std::istream& in)
{
	cout << endl << "--- Create Segment Menu ---" << endl;

	Point pt_x;
	Point pt_y;

	in >> pt_x >> pt_y;

	Start_pt = pt_x;
	End_pt = pt_y;

	return in;
}

