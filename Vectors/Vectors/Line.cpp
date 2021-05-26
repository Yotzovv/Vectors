#include "Vector.h"
#include "Point.h"
#include "Line.h"
#include <iostream>
#include <cmath>
#include <exception>
#include <vector>
#include <math.h>
#include <optional>

Line::Line(Point X, Point Y) :Vector(X, Y)
{

}

Line::Line(Vector vec, Point A) : Vector(vec)
{
	this->A = A;
}

Line::Line(Vector vec) : Vector(vec)
{

}

/// <summary>
/// Returns a vector, perpendicular to the line
/// </summary>
/// <param name="line l"></param>
/// <returns>Vector</returns>
Vector Line::find_normal_vector(Line l)
{
	double k = -(n1 * A.X + n2 * A.Y + n3 * A.Z) / (pow(n1, 2) + pow(n2, 2) + pow(n3, 2));

	double resX = (this->n1 * k) + this->A.X;
	double resY = (this->n2 * k) + this->A.Y;
	double resZ = (this->n3 * k) + this->A.Z;

	return Vector(resX, resY, resZ);
}

Vector Line::get_line_direction()
{
	vector<double> v1 = this->get_direction();
	Vector result(v1[0],v1[1],v1[2]);

	return result;
}

bool Line::operator||(Vector v1)
{
	//(y1-y2)/(x1-x2)
	double slope1 = (A.Y - B.Y) / (A.X - B.X);
	double slope2 = (v1.A.Y - v1.B.Y) / (v1.A.X - v1.B.X);

	return slope1 == slope2;
}


bool operator==(const Line& l, const Line& l2)
{
	bool res;
		
	if (l.n1 && l.n2 && l.n3 && l2.n1 && l2.n2 && l2.n3 > -9999) 
	{
		double x = (double)(l.n1 / l2.n1);
		double y = (double)(l.n2 / l2.n2);
		double z = (double)(l.n3 / l2.n3);

		res = (x == y) == (x == z) == (y == z);
	}

	else 
	{
	double A = (double)(l.A.X / l2.A.X);
	double B = (double)(l.A.Y / l2.A.Y);
	double C = (double)(l.B.X / l2.B.X);
	double D = (double)(l.B.Y / l2.B.Y);

	bool res = (A == B) == (A == C) == (A == D) == (B == C) == (B == D) == (C == D);
	}
	return res;
}
