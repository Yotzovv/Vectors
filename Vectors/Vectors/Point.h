#ifndef POINT_H
#define POINT_H
#pragma once

#include <iostream>
#include "Element.h"
#include <queue>
#include <string>

class Point : public Element
{
public:
	Point(std::queue<std::string> cmds);
	double X;
	double Y;
	double Z;
	Point();
	Point(double x, double y, double z);
	Point(double x, double y);
	bool operator==(Point point);
	std::ostream& ins(std::ostream&) const;
	std::istream& ext(std::istream&);
	std::queue<std::string> _Commands;
};

#endif