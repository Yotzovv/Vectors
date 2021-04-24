#ifndef POINT_H
#define POINT_H
#pragma once

#include <iostream>

class Point
{
public:
	double X;
	double Y;
	double Z;
	Point();
	Point(double x, double y, double z);
	bool operator==(Point point);
};


#endif