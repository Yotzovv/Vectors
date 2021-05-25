#include "Vector.h"
#include "Point.h"
#include <iostream>
#include <cmath>
#include <exception>
#include <vector>
#include <math.h>

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
double Vector::get_vector_length(double x, double y, double z) {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

// Uses Points
// TODO: Merge with get_direction
double Vector::vector_direction() {


	if (is_vector_null()) {

		throw VectorLengthException();
	
	}
	return acos(atan((A.X - A.Y) / (B.X - B.Y))); // direction of a vector.
			
}

// Uses n1,n2,n3
// TODO: Merge with vector_direction
vector<double> Vector::get_direction()
{
	try {

		if (is_vector_null()) {

			throw VectorLengthException();
		}

		double v{}; //magnitude
		double n11;
		double n22;
		double n33;

		vector<double> directionthree;

		n11 = n1 / sqrt(pow(n1, 2) + pow(n2, 2) + pow(n3, 2));

		n22 = n2 / sqrt(pow(n1, 2) + pow(n2, 2) + pow(n3, 2));

		n33 = n3 / sqrt(pow(n1, 2) + pow(n2, 2) + pow(n3, 2));

		directionthree.push_back(n11);
		directionthree.push_back(n22);
		directionthree.push_back(n33);

		vector<double> result = { directionthree.at(0), directionthree.at(1), directionthree.at(2) };
		return result;
	}
	catch (const exception& e) {
		std::cout << e.what() << std::endl;
	}
}
