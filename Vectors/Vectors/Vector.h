using namespace std;
#ifndef VECTOR_H
#define VECTOR_H
#pragma once
#include <iostream>
#include "Point.h"
#include <vector>


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
	double get_vector_length();
	bool is_vector_null();
	double vector_direction();
	vector<double> get_direction();

};

#endif 