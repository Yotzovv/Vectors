#include "Vector.h"
#include "Point.h"
#include <iostream>
#include <cmath>
#include <exception>
#include <vector>
#include <math.h>
#include "vector"
#include "VectorLengthException.h"
#define PI 3.14159265


using namespace std;

double Vector::get_vector_n1()
{
	return this->n1;
}

double Vector::get_vector_n2()
{
	return this->n2;
}

double Vector::get_vector_n3()
{
	return this->n3;
}

Point Vector::get_vector_A()
{
	return this->A;
}

Point Vector::get_vector_B()
{
	return this->B;
}

void Vector::set_vector_n1(double N1)
{
	this->n1 = N1;
}

void Vector::set_vector_n2(double N2)
{
	this->n2 = N2;
}

void Vector::set_vector_n3(double N3)
{
	this->n3 = N3;
}

void Vector::set_vector_A(Point a)
{
	this->A = a;
}

void Vector::set_vector_B(Point b)
{
	this->B = b;
}

Vector::Vector(std::queue<std::string> cmds)
{
	_Commands = cmds;
}

Vector::Vector(double x, double y, double z)
{
	this->set_vector_n1(x);
	this->set_vector_n2(y);
	this->set_vector_n3(z);
};

Vector::Vector(Point x, Point y)
{
	this->set_vector_A(x);
	this->set_vector_B(y);
};

Vector::Vector() {
};

/// <summary>
/// Checks if current vector is null
/// </summary>
/// <returns></returns>
bool Vector::is_vector_null()
{
	return (get_vector_n1() == get_vector_n2())
		&& (get_vector_n1() == get_vector_n3())
		&& (get_vector_n2() == get_vector_n3());
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
	return (get_vector_n1() == get_vector_n2())
		&& (get_vector_n1() == get_vector_n3())
		&& (get_vector_n2() == get_vector_n3());
}

/// <summary>
/// Uses n1,n2,n3
/// </summary>
/// <returns></returns>
double Vector::get_vector_length()
{
	return sqrt(pow(get_vector_n1(), 2) + pow(get_vector_n2(), 2) + pow(get_vector_n3(), 2));
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

	return atan((get_vector_B().getY() - get_vector_A().getY())
		/ (get_vector_B().getX() - get_vector_A().getX())) * 180 / PI; // direction of a vector.		
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

		a = get_vector_n1() / sqrt(pow(get_vector_n1(), 2) + pow(get_vector_n2(), 2) + pow(get_vector_n3(), 2));

		b = get_vector_n2() / sqrt(pow(get_vector_n1(), 2) + pow(get_vector_n2(), 2) + pow(get_vector_n3(), 2));

		c = get_vector_n3() / sqrt(pow(get_vector_n1(), 2) + pow(get_vector_n2(), 2) + pow(get_vector_n3(), 2));

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
	if (get_vector_n1() == 0 && get_vector_n2() == 0 && get_vector_n3() == 0)
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

		if (is_vector_null(v.get_vector_n1(), v.get_vector_n2(), v.get_vector_n3())) {
			throw VectorLengthException();
		}

		return (v.get_vector_n1() / get_vector_n1() == v.get_vector_n2() / get_vector_n2())
			&&(v.get_vector_n1() / get_vector_n1() == v.get_vector_n3() / get_vector_n3())
			&&(v.get_vector_n2()/get_vector_n2() == v.get_vector_n3() / get_vector_n3());
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
	return v.n1 * get_vector_n1() + v.n2 * get_vector_n2() + v.n3 * get_vector_n3(); //??
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
		return v.n1 * get_vector_n1() + v.n2 * get_vector_n2() + v.n3 * get_vector_n3() == 0;
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
	result.n1 = get_vector_n1() + v.n1;
	result.n2 = get_vector_n2() + v.n2;
	result.n3 = get_vector_n3() + v.n3;

	return result;
}

// substracting 2 vectors 
// a−v= (x, y, z)−(v1, v2, v3) = (x−v1, y−v2, z−v3)
Vector Vector::operator-(const Vector& v) {
	Vector result;
	result.n1 = get_vector_n1() - v.n1;
	result.n2 = get_vector_n2() - v.n2;
	result.n3 = get_vector_n3() - v.n3;

	return result;
}

// x1, y1, z1
// x2, y2, z2
// x3, y3, z3
//
// x1(y2*z3 - z2*y3) - y1(x2*z3 - z2*x3) + z1(x2*y3 - y2*x3)
double Vector::operator()(const Vector& v2, const Vector v3)
{
	return get_vector_n1() * (v2.n2 * v3.n3 - v2.n3 * v3.n2) - get_vector_n2() * (v2.n1 * v3.n3 - v2.n3 * v3.n1) + get_vector_n3() * (v2.n1 * v3.n2 - v2.n2 * v3.n1);
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

string Vector::get_data()
{
	if ((n1 == n2) == (n3 == 0))
	{
		return get_vector_A().get_data() + get_vector_B().get_data();
	}
	else
	{
		return "X: " + to_string(n1) +
		"\nY: " + to_string(n2) +
		"\nZ: " + to_string(n3);
	}
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
	auto output = "\n--- Create Vector Menu ---\n"
	"\n>Choose method of creation:\n"
	"\n1. Using 3 numbers\n"
	"2. Using cordinates\n"
	"\n>: ";

	pushtToOutputs(output);

	cout << output;

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

	pushtToOutputs(to_string(option));

	switch (option)
	{
	case 1:
	{
		auto msg = "\nYou chose 3 numbers initialization!\n";
		pushtToOutputs(msg);

		double x, y, z;

		cout << endl << "x: ";

		pushtToOutputs("\nx: ");

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

		pushtToOutputs(to_string(x));

		cout << "y: ";
		pushtToOutputs("y: ");

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

		pushtToOutputs(to_string(y));

		cout << "z: ";
		pushtToOutputs("z: ");

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

		pushtToOutputs(to_string(z));

		n1 = x; //??
		n2 = y;
		n3 = z;
		break;
	}
	case 2:
		auto msg_point = "\nYou chose point initialization!\n";
		pushtToOutputs(msg_point);
		cout << msg_point;

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

		get_vector_A() = pt_x;
		get_vector_B() = pt_y;
		break;
	}

	return in;
}