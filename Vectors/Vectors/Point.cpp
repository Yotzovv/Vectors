#include <iostream>
#include "Point.h"

using namespace std;

Point::Point() {};

Point::Point(double x, double y, double z)
{
	X = x;
	Y = y;
	Z = z;
};

Point::Point(double x, double y)
{
	X = x;
	Y = y;
};

bool Point::operator==(Point point)
{
	return (point.X == X && point.Y == Y && point.Z == Z);
};

//Overlaods >> operator
std::istream& Point::ext(std::istream& in) {
	cout << "\nCreate Point Menu\n";
	cout << "\nChoose method of creation:\n";
	cout << "\n1. Usin 2 numbers (X,Y)";
	cout << "\n2. Using 3 numbers (X,Y,Z)\n";

	int option;
	cin >> option;
	
	switch (option)
	{
	case 1:
		double q, f;

		cout << "X: ";
		cin >> q;

		cout << "Y: ";
		cin >> f;
		this->X = q;
		this->Y = f;
		break;
	case 2:
		double a, b, c;
		cout << "X: ";
		cin >> a;

		cout << "Y: ";
		cin >> b;

		cout << "Z: ";
		cin >> c;

		this->X = a;
		this->Y = b;
		this->Z = c;
		break;
	default:
		break;
	}

	return in;
}