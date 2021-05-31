#pragma once

#ifndef Point_hpp
#define Point_hpp

#include "Point.h"

class Triangle : public Point {
public:
	Triangle();
	Triangle(Point x, Point y, Point z);
	Triangle(std::queue<std::string> cmds);
	Point get_triangle_X();
	Point get_triangle_Y();
	Point get_triangle_Z();
	void set_triangle_X(Point x);
	void set_triangle_Y(Point y);
	void set_triangle_Z(Point z);
	Point get_incenter(Point x, Point y, Point z); // medicentyr to be deleted?
	Point get_incenter(); // medicentyr
	double get_area();
	double get_area(Point x, Point y, Point z);
	double get_perimeter();
	bool is_point_valid();
	double get_mid_side(double a, double b, double c);
	bool is_triangle_isosceles(); // ravnobedren
	bool is_triangle_equilateral(); // ravnostranen
	bool is_triangle_right(Point x, Point y, Point z);
	bool is_triangle_acute();
	bool is_triangle_obtuse(Point x, Point y, Point z);
	void get_triangle_type(); // dali e ostrougulen, tupougulen ili pravougulen
	bool operator<(Point point);
	bool operator>(Point point);
	bool operator==(Point point);
	std::ostream& ins(std::ostream&) const;
	std::istream& ext(std::istream&);
private:
	Point X;
	Point Y;
	Point Z;
};

#endif
