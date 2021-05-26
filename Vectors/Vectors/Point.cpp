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
	cout << "\n1. Usin 2 points (X,Y)";
	cout << "\n2. Using 3 numbers (X,Y,Z)\n";

	int option;
	cin >> option;
	
	switch (option)
	{
	case 1:
		double q, f;

		cout << "X: ";
		in >> q;

		cout << "Y: ";
		in >> f;
		this->X = q;
		this->Y = f;
		break;
	case 2:
		double a, b, c;
		cout << "X: ";
		in >> a;

		cout << "Y: ";
		in >> b;

		cout << "Z: ";
		in >> c;

		this->X = a;
		this->Y = b;
		this->Z = c;
		break;
	default:
		break;
	}

	return in;
}

//prints Point with << operator
std::ostream& Point::ins(std::ostream& print) const 
{
	print << "X: " << X;
	print << "Y: " << Y;
	print << "Z: " << Z;

	return print;
}
