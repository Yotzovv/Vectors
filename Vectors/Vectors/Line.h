#ifndef Line_H
#define Line_H

#pragma once
#include "Vector.h"
#include <vector>
#include "Point.h"

class Line : public Vector
{

public:
	Point get_point_X();
	Point get_point_Y();
	Vector getVector();
	void set_point_X(Point x);
	void set_point_Y(Point y);
	void setVector(Vector Vec);
	Line();
	Line(Point X, Point Y);
	Line(Vector vec, Point X);
	Line(Vector vec);
	Line(std::queue<std::string> cmds);
	Vector find_normal_vector(Line l);
	Vector find_normal_vector();
	Vector get_line_direction();
	bool operator||(Vector v1);
	friend bool operator==(Line&, Line&);//Checks if lines are equal
	bool operator&&(Vector v1);
	bool operator|(Line&);
	double find_angle_line(Vector v1);
	bool operator!=(Vector v1);
	bool operator+(Point pt);
	std::ostream& ins(std::ostream&); // was const 
	std::istream& ext(std::istream&);
private:
	Point X;
	Point Y;
	Vector vec;
};

#endif