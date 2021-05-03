#include "Vector.h"
#include "Point.h"
#include "Line.h"
#include <iostream>
#include <cmath>
#include <exception>
#include <vector>
#include <math.h>

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
Vector Line::FindNormalVector(Line l)
{
	double k =
		-(this->n1 * this->A.X
			+ this->n2 * this->A.Y
			+ this->n3 * this->A.Z)
		/
		(pow(this->n1, 2)
			+ pow(this->n2, 2)
			+ pow(this->n3, 2));

	double resX = (this->n1 * k) + this->A.X;
	double resY = (this->n2 * k) + this->A.Y;
	double resZ = (this->n3 * k) + this->A.Z;

	return Vector(resX, resY, resZ);
}
