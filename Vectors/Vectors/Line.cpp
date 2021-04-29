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
