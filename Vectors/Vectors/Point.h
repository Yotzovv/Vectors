#ifndef POINT_H
#define POINT_H
#pragma once

#include <iostream>
#include "Element.h"

class Point : public Element
{
public:
	double X;
	double Y;
	double Z;
	Point();
	Point(double x, double y, double z);
	Point(double x, double y);
	bool operator==(Point point);
	std::ostream& ins(std::ostream&) const;
	std::istream& ext(std::istream&);
};


#endif