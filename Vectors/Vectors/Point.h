#ifndef POINT_H
#define POINT_H
#pragma once

#include <iostream>

class Point
{
public:
	int X;
	int Y;
	int Z;
	Point();
	Point(int x, int y, int z);
	bool operator==(Point point);
};


#endif