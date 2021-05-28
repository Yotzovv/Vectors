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

Segment::Segment(std::queue<std::string> cmds)
{
	_Commands = cmds;
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
	return (double)sqrt(pow(get_endPt().X - get_startPt().X, 2) + pow(get_endPt().Y - get_startPt().Y, 2) + pow(get_endPt().Z - get_startPt().Z, 2));
}

Point Segment::find_segment_middle()
{
	Point middle((Start_pt.X + End_pt.X) / 2, (Start_pt.Y + End_pt.Y) / 2);

	return middle;
}

//Check if point lies on segment
bool Segment::operator==(Point point)
{
	//formula used:
	//(x - x1) / (x2 - x1) = (y - y1) / (y2 - y1)

	//in case the X coordinate of all three points is equal only the Y coordinate should be checked
	if ((point.X == get_startPt().X) &&
		(point.X == get_endPt().X) &&
		(get_startPt().X == get_endPt().X))
	{
		if ((point.Y > get_startPt().Y && point.Y > get_endPt().Y) || (point.Y < get_startPt().Y && point.Y < get_endPt().Y))
		{
			return false;
		}
		return true;
	}
	double left_side_equation = (point.X - get_startPt().X) / (get_endPt().X - get_startPt().X);

	//in case the Y coordinate of all three points is equal only the X coordinate should be checked
	if ((point.Y == get_startPt().Y) &&
		(point.Y == get_endPt().Y) &&
		(get_startPt().Y == get_endPt().Y))
	{
		if ((point.X > get_startPt().X && point.X > get_endPt().X) || (point.X < get_startPt().X && point.X < get_endPt().X))
		{
			return false;
		}
		return true;
	}
	double right_side_equation = (point.Y - get_startPt().Y) / (get_endPt().Y - get_startPt().Y);

	/*calculations used to round the doubles to a 'normal' state
	float value = (int)(var * 100 + .5);
	return (float)value / 100;*/

	float left_side_result = (int)(left_side_equation * 100 + 0.5);
	left_side_result /= 100;

	float right_side_result = (int)(right_side_equation * 100 + 0.5);
	right_side_result /= 100;

	return left_side_result == right_side_result;
}

std::ostream& Segment::ins(std::ostream& print) const
{
	print << Start_pt, End_pt;

	return print;
}

std::istream& Segment::ext(std::istream& in)
{
	cout << endl << "--- Create Segment Menu ---" << endl;

	Point pt_x(_Commands);
	Point pt_y(_Commands);

	in >> pt_x;
	_Commands = pt_x._Commands;
	pt_y._Commands = _Commands;

	in >> pt_y;
	_Commands = pt_y._Commands;

	Start_pt = pt_x;
	End_pt = pt_y;

	return in;
}

