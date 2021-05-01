#include "Vector.h"
#include "Point.h"
#include "Line.h"
#include <iostream>
#include <cmath>
#include <exception>
#include <vector>
#include <math.h>

Line::Line(Point X, Point Y):Vector(X,Y)
{

}

Line::Line(Vector vec, Point A):Vector(vec)
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
	/// <summary>
	/// Value X of point A of the vector
	/// </summary>
	double vecX = l.n1;
	/// <summary>
	/// Value Y of point A of the vector
	/// </summary>
	double vecY = l.n2;
	/// <summary>
	/// Value Z of point A of the vector
	/// </summary>
	double vecZ = l.n3;

	/// <summary>
	/// Value X of point A
	/// </summary>
	double pointA_X = l.A.X;
	/// <summary>
	/// Value Y of point A
	/// </summary>
	double pointA_Y = l.A.Y;
	/// <summary>
	/// Value Z of point A
	/// </summary>
	double pointA_Z = l.A.Z;

	double k = -
		(vecX * pointA_X
			+ vecY * pointA_Y
			+ vecZ * pointA_Z)
		/
		(pow(vecX, 2)
			+ pow(vecY, 2)
			+ pow(vecZ, 2));

	double resX = (vecX * k) + pointA_X;
	double resY = (vecY * k) + pointA_Y;
	double resZ = (vecZ * k) + pointA_Z;

	return Vector(resX, resY, resZ);
}
