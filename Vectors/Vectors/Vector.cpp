#include "Vector.h"
#include "Point.h"
#include <iostream>

using namespace std;


Vector::Vector(double x, double y, double z)
{
	n1 = x;
	n2 = y;
	n3 = z;
};

Vector::Vector(Point x, Point y)
{
	A = x;
	B = y;
}

	

	



