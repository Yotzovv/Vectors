#include "Vector.h"
#include "Point.h"
#include <iostream>
#include <math.h>

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

bool Vector::is_vector_null()
{
	return n1 == n2 == n3;
}
double Vector::get_vector_length(double x, double y, double z) {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

	

	



