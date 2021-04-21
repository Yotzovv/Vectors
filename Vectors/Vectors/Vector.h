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
	bool is_vector_null(int x, int y, int z);
	double vector_direction();
	vector<double> get_direction();
	bool is_parallel(Vector v);
	double operator*(const Vector& v); //Returns the scalar product of 2 vectors
	bool is_vector_perpendicullar(int x, int y, int z);
	Vector operator+(const Vector& v);
};

#endif 