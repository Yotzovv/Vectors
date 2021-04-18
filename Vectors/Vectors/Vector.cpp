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
};

/// <summary>
/// Custom Exception class
/// TODO: Put it in a separate file
/// </summary>
class VectorLengthException : public exception {

public: virtual const char* what() const throw() {
	return "Vector length exception thrown";
}
};

/// <summary>
/// Checks if current vector is null
/// </summary>
/// <returns></returns>
bool Vector::is_vector_null()
{
	return n1 == n2 == n3;
}

/// <summary>
/// Overload function
/// Checks if passed vector is null
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="z"></param>
/// <returns></returns>
bool Vector::is_vector_null(int x, int y, int z)
{
	return n1 == n2 == n3;
}

/// <summary>
/// Uses n1,n2,n3
/// </summary>
/// <returns></returns>
double Vector::get_vector_length() {
	return sqrt(pow(n1, 2) + pow(n2, 2) + pow(n3, 2));
}

/// <summary>
/// Uses Point classess
/// TODO: Merge with get_direction
/// </summary>
/// <returns></returns>
double Vector::vector_direction() {


	if (is_vector_null()) {

		throw VectorLengthException();
	
	}
	return acos(atan((A.X - A.Y) / (B.X - B.Y))); // direction of a vector.
			
}

/// <summary>
/// Uses n1,n2,n3
/// TODO: Merge with vector_direction
/// </summary>
/// <returns></returns>
vector<double> Vector::get_direction() {

	try {

		if (is_vector_null()) {

			throw VectorLengthException();
		}

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
	catch (const exception &e) {
		std::cout << e.what() << std::endl;
	}
}

/// <summary>
/// Determines if 2 vectors are parrallel
/// </summary>
/// <param name="v"></param>
/// <returns></returns>
bool Vector::is_parallel(Vector v) {
	try {

		if (is_vector_null()) {
			throw VectorLengthException();
		}

		if (is_vector_null(v.n1, v.n2, v.n3)) {
			throw VectorLengthException();
		}

		return (v.n1 / n1 == v.n2 / n2 == v.n3 / n3);
	}
	catch (const exception& e) {
		std::cout << e.what() << std::endl;
	}
}

/// <summary>
/// Returns the scalar product of 2 vectors
/// </summary>
/// <param name="v"></param>
/// <returns></returns>
double Vector::operator*(const Vector& v) {
	return v.n1 * n1 + v.n2 * n2 + v.n3 * n3;
}

bool Vector::is_vector_perpendicullar(int x, int y, int z)
{
	try
	{
		if (is_vector_null()) {
			throw VectorLengthException();
		}
		return x * n1 + y * n2 + z * n3 == 0;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
