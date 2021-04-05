#include <iostream>

using namespace std;

class Point {

	int X;

	int Y;

	int Z;

public:
	Point(int x, int y, int z) {
		X = x;
		Y = y;
		Z = z;
	}

public:
	bool IsEqual(int x, int y, int z) {
		return (x == X) && (y == Y) && (z == Z);
	}
};