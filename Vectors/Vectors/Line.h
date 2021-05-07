#ifndef Line_H
#define Line_H

#pragma once
#include "Vector.h"
#include <vector>
#include "Point.h"

class Line : public Vector 
{

public: 	
	Line(Point X, Point Y);
	Line(Vector vec, Point X);
	Line(Vector vec);
	Vector find_normal_vector(Line l);
	Vector get_line_direction();
	bool operator||(Vector v1);
	friend bool operator==(const Line&, const Line&);//Checks if lines are equal
};

#endif