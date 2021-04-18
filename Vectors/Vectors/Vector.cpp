#include "Vector.h"
#include "Point.h"
#include <iostream>
#include <cmath>
#include <exception>
#include <vector>


using namespace std;

Vector::Vector(double x, double y, double z)
{
	n1 = x;
	n2 = y;
	n3 = z;

	
};

Vector::Vector(Point x, Point y)
{
	A = x;
	B = y;
}

class VectorLengthException : public exception {

public: virtual const char* what() const throw() {

	return "Vector length exception thrown";
}


};

bool Vector::is_vector_null()
{
	return n1 == n2 == n3;
}

double Vector::vector_direction() {

	if (is_vector_null()) {

		throw VectorLengthException();
	
	}
	return acos(atan((A.X - A.Y) / (B.X - B.Y))); // direction of a vector.
			
}

// Uses n1,n2,n3

vector<double> Vector::get_direction() {

	double v{}; //magnitude

	v = sqrt(pow((n1 + n2 + n3), 2)); // magnitude

	vector<double> directionthree;

	n1 = n1 / v;
	n1 = acos(n1);

	n2 = n2 / v;
	n2 = acos(n2);

	n3 = n3 / v;
	n3 = acos(n3);

	directionthree.push_back(n1);
	directionthree.push_back(n2);
	directionthree.push_back(n3);

	vector<double> result = { directionthree.at(0), directionthree.at(1), directionthree.at(2) };
	return result;

}
