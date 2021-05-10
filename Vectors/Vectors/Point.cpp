#include <iostream>
#include "Point.h"

using namespace std;

Point::Point() {};

Point::Point(double x, double y, double z)
{
	X = x;
	Y = y;
	Z = z;
};

bool Point::operator==(Point point)
{
	return (point.X == X && point.Y == Y && point.Z == Z);
};

