#ifndef POINT_H
#define POINT_H
#pragma once

#include "Element.h"

class Point : public Element
{
public:
	double getX();
	double getY();
	double getZ();
	void setX(double x);
	void setY(double y);
	void setZ(double z);
	Point();
	Point(std::queue<std::string> cmds);
	Point(double x, double y, double z);
	Point(double x, double y);
	bool operator==(Point point);
	std::string get_data();
	std::ostream& ins(std::ostream&);
	std::istream& ext(std::istream&);
	double X;
	double Y;
	double Z;
private:
	//TODO ^^^
};

#endif