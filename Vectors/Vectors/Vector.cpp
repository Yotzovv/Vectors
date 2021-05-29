#include "Vector.h"
#include "Point.h"
#include <iostream>
#include <cmath>
#include <exception>
#include <vector>
#include <math.h>
#define PI 3.14159265


using namespace std;

Vector::Vector(std::queue<std::string> cmds)
{
	_Commands = cmds;
}

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

Vector::Vector() {
};


/// <summary>
/// Custom Exception class
/// TODO: Put it in a separate file
/// </summary>
class VectorLengthException : public exception
{
public:
	virtual const char* what() const throw() {
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
double Vector::get_vector_length()
{
	return sqrt(pow(n1, 2) + pow(n2, 2) + pow(n3, 2));
}


/// <summary>
/// Uses Point classess
/// TODO: Merge with get_direction 
/// // tanθ=y2 − y1x2 − x1
/// </summary//>
/// <returns></returns>

double Vector::vector_direction_by_pts()
{
	if (is_vector_null()) {
		throw VectorLengthException();
	}

	return atan((B.Y - A.Y) / (B.X - A.X)) * 180 / PI; // direction of a vector.		
}

// Uses n1,n2,n3
// TODO: Merge with vector_direction
vector<double> Vector::get_direction_by_nums()
{
	try {

		if (is_vector_null()) {

			throw VectorLengthException();
		}

		double v; //magnitude
		double a;
		double b;
		double c;

		vector<double> directionthree;

		a = n1 / sqrt(pow(n1, 2) + pow(n2, 2) + pow(n3, 2));

		b = n2 / sqrt(pow(n1, 2) + pow(n2, 2) + pow(n3, 2));

		c = n3 / sqrt(pow(n1, 2) + pow(n2, 2) + pow(n3, 2));

		directionthree.push_back(a);
		directionthree.push_back(b);
		directionthree.push_back(c);

		vector<double> result = { directionthree.at(0), directionthree.at(1), directionthree.at(2) };
		return result;
	}
	catch (const exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void Vector::print_direction()
{
	if (n1 == 0 && n2 == 0 && n3 == 0)
	{
		double result = vector_direction_by_pts();
		cout << result << endl;
	}

	vector<double> result = get_direction_by_nums();

	for (auto num : result)
	{
		cout << num;
	}
}


/// <summary>
/// Determines if 2 vectors are parrallel
/// </summary>
/// <param name="v"></param>
/// <returns></returns>
bool Vector::is_parallel(Vector v)
{
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
double Vector::operator*(const Vector& v)
{
	return v.n1 * n1 + v.n2 * n2 + v.n3 * n3;
}

/// <summary>
/// Checks if 2 vectors are perpendicullar
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="z"></param>
/// <returns></returns>
bool Vector::is_vector_perpendicullar(const Vector& v)
{
	try
	{
		if (is_vector_null()) {
			throw VectorLengthException();
		}
		return v.n1 * n1 + v.n2 * n2 + v.n3 * n3 == 0;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

//a + v = (x, y, z) + (v1, v2, v3) = (x + v1, y + v2, z + v3);
Vector Vector::operator+(const Vector& v)
{
	Vector result(0, 0, 0);
	result.n1 = n1 + v.n1;
	result.n2 = n2 + v.n2;
	result.n3 = n3 + v.n3;

	return result;
}

// substracting 2 vectors 
// a−v= (x, y, z)−(v1, v2, v3) = (x−v1, y−v2, z−v3)
Vector Vector::operator-(const Vector& v) {
	Vector result;
	result.n1 = n1 - v.n1;
	result.n2 = n2 - v.n2;
	result.n3 = n3 - v.n3;

	return result;
}

// x1, y1, z1
// x2, y2, z2
// x3, y3, z3
//
// x1(y2*z3 - z2*y3) - y1(x2*z3 - z2*x3) + z1(x2*y3 - y2*x3)
double Vector::operator()(const Vector& v2, const Vector v3)
{
	return n1 * (v2.n2 * v3.n3 - v2.n3 * v3.n2) - n2 * (v2.n1 * v3.n3 - v2.n3 * v3.n1) + n3 * (v2.n1 * v3.n2 - v2.n2 * v3.n1);
}

/// <summary>
/// Multiplies vector by a real number
/// </summary>
/// <param name="v"></param>
/// <returns>Vector</returns>
Vector operator*(double num, const Vector& v)
{
	Vector result;
	result.n1 = v.n1 * num;
	result.n2 = v.n2 * num;
	result.n3 = v.n3 * num;

	return result;
}

/// <summary>
/// Multiplies two vectors
/// </summary>
/// <param name="First Vector"></param>
/// <param name="Second Vector"></param>
/// <returns>Vector object</returns>
Vector operator^(const Vector& v1, const Vector& v2)
{
	Vector result;
	result.n1 = v1.n2 * v2.n3 - v1.n3 * v2.n2;
	result.n2 = v1.n1 * (-1) * v2.n3 + v1.n3 * v2.n1;
	result.n3 = v1.n1 * v2.n2 - v1.n2 * v2.n1;

	return result;
}

//overloads << operator
ostream& Vector::ins(ostream& print) const
{
	if (n1 == n2 == n3 == 0)
	{
		print << A, B;
	}
	else
	{
		print << "X: " << n1;
		print << "Y: " << n2;
		print << "Z: " << n3;
	}

	return print;
}

//Overlaods >> opeartor
istream& Vector::ext(istream& in)
{
	cout << endl << "--- Create Vector Menu ---" << endl;
	cout << endl << ">Choose method of creation:" << endl;
	cout << "1. Using 3 numbers" << endl;
	cout << "2. Using cordinates" << endl;
	cout << endl << ">: ";

	int option;

	if (_Commands.size() < 1)
	{
		cin >> option;
	}
	else
	{
		option = stoi(_Commands.front());
		_Commands.pop();
		cout << option;
	}

	switch (option)
	{
	case 1:
		cout << endl << "You chose 3 numbers initialization!" << endl;
		double x, y, z;

		cout << "x: ";
		if (_Commands.size() < 1)
		{
			cin >> x;
		}
		else
		{
			x = stoi(_Commands.front());
			_Commands.pop();
			cout << x << endl;
		}

		cout << "y: ";
		if (_Commands.size() < 1)
		{
			cin >> y;
		}
		else
		{
			y = stoi(_Commands.front());
			_Commands.pop();
			cout << y << endl;
		}

		cout << "z: ";
		if (_Commands.size() < 1)
		{
			cin >> z;
		}
		else
		{
			z = stoi(_Commands.front());
			_Commands.pop();
			cout << z << endl;
		}

		n1 = x;
		n2 = y;
		n3 = z;
		break;
	case 2:
		cout << endl << "You chose point initializaiton!" << endl;
		Point pt_x;
		Point pt_y;

		if (_Commands.size() > 0)
		{
			pt_x = Point(_Commands);
			pt_y = Point(_Commands);
		}

		in >> pt_x;
		_Commands = pt_x._Commands;
		in >> pt_y;
		_Commands = pt_y._Commands;

		A = pt_x;
		B = pt_y;
		break;
	}

	return in;
}
