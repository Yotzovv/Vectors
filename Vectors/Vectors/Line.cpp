#include "Vector.h"
#include "Point.h"
#include "Line.h"
#include <iostream>
#include <cmath>
#include <exception>
#include <vector>
#include <math.h>

Line::Line()
{
}

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
	double x = (double)(l.n1 / l2.n1);
	double y = (double)(l.n2 / l2.n2);
	double z = (double)(l.n3 / l2.n3);
	bool res = (x == y) == (x == z) == (y == z);
	return res;
}

int orientation(Point p, Point q, Point r)
{
	int val = (q.Y - p.Y) * (r.X - q.X) -
		(q.X - p.X) * (r.Y - q.Y);

	if (val == 0) return 0;  // colinear

	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

bool isIntersecting(Point& p1, Point& p2, Point& q1, Point& q2) {
	return (((q1.X - p1.X) * (p2.Y - p1.Y) - (q1.Y - p1.Y) * (p2.X - p1.X))
		* ((q2.X - p1.X) * (p2.Y - p1.Y) - (q2.Y - p1.Y) * (p2.X - p1.X)) < 0)
		&&
		(((p1.X - q1.X) * (q2.Y - q1.Y) - (p1.Y - q1.Y) * (q2.X - q1.X))
			* ((p2.X - q1.X) * (q2.Y - q1.Y) - (p2.Y - q1.Y) * (q2.X - q1.X)) < 0);
}

bool Line::operator&&(Vector v1)
{
	//(y1-y2)/(x1-x2)
	double slope1 = (A.Y - B.Y) / (A.X - B.X);
	double slope2 = (v1.A.Y - v1.B.Y) / (v1.A.X - v1.B.X);

	//Equal swopes don't mean lines intersect for sure
	if (slope1 != slope2)
	{
		return false;
	}

	bool result = isIntersecting(A, B, v1.A, v1.B);

	return result;
}

bool Line::operator|(const Line& l)
{
	bool res = ((n1 * l.n1) + (n2 * l.n2) + (n3 * l.n3)) == 0;
	return res;
}
double Line::find_angle_line(Vector v1)
{
	double cos_of_angle =((A.X * v1.A.X) + (B.X * v1.B.Y) /
		                 (sqrt(pow(A.X, 2) + (sqrt(pow(B.X, 2) *
		                 (sqrt(pow(v1.A.Y, 2) + (sqrt(pow(v1.B.Y, 2))))))))));

	return (acos(cos_of_angle) * 180.0 / 3.14);
}

bool Line::operator!=(Vector v1)
{
	//(y1-y2)/(x1-x2)
	double slope1 = (A.Y - B.Y) / (A.X - B.X);
	double slope2 = (v1.A.Y - v1.B.Y) / (v1.A.X - v1.B.X);

	return slope1 == slope2;
}

bool Line::operator+(Point pt) 
{
	bool is_point_on_line = ((pt.X >= this->A.X && this->B.X >= pt.X) || (pt.X >= this->B.X && this->A.X >= pt.X))
		&& (pt.Y >= this->A.Y && this->B.Y >= pt.Y) || (pt.Y >= this->B.Y && this->A.Y >= pt.Y);
	
	return is_point_on_line;
}
