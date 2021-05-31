#include "Segment.h"
#include <math.h>
#include <cmath>

void Segment::set_startPt(Point pt)
{
	this->Start_pt = pt;
}

void Segment::set_endPt(Point pt)
{
	this->End_pt = pt;
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
	return (double)sqrt(pow(get_endPt().getX() - get_startPt().getX(), 2) + pow(get_endPt().getY() - get_startPt().getY(), 2) + pow(get_endPt().getZ() - get_startPt().getZ(), 2));
}

Point Segment::find_segment_middle()
{
	//possible bug? test it
	Point middle((get_startPt().getX() + get_endPt().getX()) / 2, (get_startPt().getY() + get_endPt().getY()) / 2);

	return middle;
}

//Check if point lies on segment
bool Segment::operator==(Point point)
{
	//formula used:
	//(x - x1) / (x2 - x1) = (y - y1) / (y2 - y1)

	//in case the X coordinate of all three points is equal only the Y coordinate should be checked
	if ((point.getX() == get_startPt().getX()) &&
		(point.getX() == get_endPt().getX()) &&
		(get_startPt().getX() == get_endPt().getX()))
	{
		if ((point.getY() > get_startPt().getY() && point.getY() > get_endPt().getY()) || (point.getY() < get_startPt().getY() && point.getY() < get_endPt().getY()))
		{
			return false;
		}
		return true;
	}
	double left_side_equation = (point.getX() - get_startPt().getX()) / (get_endPt().getX() - get_startPt().getX());

	//in case the Y coordinate of all three points is equal only the X coordinate should be checked
	if ((point.getY() == get_startPt().getY()) &&
		(point.getY() == get_endPt().getY()) &&
		(get_startPt().getY() == get_endPt().getY()))
	{
		if ((point.getX() > get_startPt().getX() && point.getX() > get_endPt().getX()) || (point.getX() < get_startPt().getX() && point.getX() < get_endPt().getX()))
		{
			return false;
		}
		return true;
	}
	double right_side_equation = (point.getY() - get_startPt().getY()) / (get_endPt().getY() - get_startPt().getY());

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
	//possible bug??
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