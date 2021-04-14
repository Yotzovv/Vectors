#ifndef VECTOR_H
#define VECTOR_H
#pragma once
#include <iostream>
#include "Point.h"

class Vector
{
public:
	double n1;
	double n2;
	double n3;
	Point A;
	Point B;
    Vector(double X, double Y, double Z);
	Vector(Point x, Point y);
	double get_vector_length(double X, double Y, double Z);
	bool is_vector_null();
};

#endif 