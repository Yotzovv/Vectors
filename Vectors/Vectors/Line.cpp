#include "Vector.h"
#include "Point.h"
#include "Line.h"
#include <iostream>
#include <cmath>
#include <exception>
#include <vector>
#include <optional>
#include <math.h>
#define PI 3.14159265;

Point Line::get_point_X()
{
	return	this->X;
}

Point Line::get_point_Y()
{
	return this->Y;
}

Vector Line::getVector()
{
	return this->vec;
}

void Line::set_point_X(Point x)
{
	this->X = x;
}
void Line::set_point_Y(Point y)
{
	this->Y = y;
}
void Line::setVector(Vector Vec)
{
	this->vec = Vec;
}

Line::Line()
{
}

Line::Line(Point X, Point Y) :Vector(X, Y)
{

}

Line::Line(Vector vec, Point A) : Vector(vec)
{
	this->get_point_X() = A;
}

Line::Line(Vector vec) : Vector(vec)
{

}

Line::Line(std::queue<std::string> cmds)
{
	_Commands = cmds;
}

/// <summary>
/// Returns a vector, perpendicular to the line
/// </summary>
/// <param name="line l"></param>
/// <returns>Vector</returns>
Vector Line::find_normal_vector(Line l)
{
	double k = -(get_vector_n1() * l.get_vector_n1() + get_vector_n2() * l.get_vector_n2() + get_vector_n3() * l.get_vector_n3()) / (pow(get_vector_n1(), 2) + pow(get_vector_n2(), 2) + pow(get_vector_n3(), 2));

	double resX = (get_vector_n1() * k) + get_vector_A().getX();
	double resY = (get_vector_n2() * k) + get_vector_A().getY();
	double resZ = (get_vector_n3() * k) + get_vector_A().getZ();

	return Vector(resX, resY, resZ);
}

Vector Line::find_normal_vector()
{
	double k = -(get_vector_n1() * get_vector_A().getX() + get_vector_n2() * get_vector_A().getY() + get_vector_n3() * get_vector_A().getZ()) / (pow(get_vector_n1(), 2) + pow(get_vector_n2(), 2) + pow(get_vector_n3(), 2));

	double resX = (get_vector_n1() * k) + get_vector_A().getX();
	double resY = (get_vector_n2() * k) + get_vector_A().getY();
	double resZ = (get_vector_n3() * k) + get_vector_A().getZ();

	return Vector(resX, resY, resZ);
}


Vector Line::get_line_direction()
{
	vector<double> v1 = this->get_direction_by_nums();
	Vector result(v1[0], v1[1], v1[2]);

	return result;
}

//Checks if 2 lines are parallel
bool Line::operator||(Vector v1)
{
	//(y1-y2)/(x1-x2)
	double slope1 = (get_vector_A().getY() - get_vector_B().getY()) / (get_vector_A().getX() - get_vector_B().getX());
	double slope2 = (v1.get_vector_A().getY() - v1.get_vector_B().getY()) / (v1.get_vector_A().getX() - v1.get_vector_B().getX());

	return slope1 == slope2;
}


bool operator==(Line& l, Line& l2) //was const
{
	bool res;

	if (l.get_vector_n1() && l.get_vector_n2() && l.get_vector_n3() && l2.get_vector_n1() && l2.get_vector_n2() && l2.get_vector_n3() > -9999)
	{
		double x = (double)(l.get_vector_n1() / l2.get_vector_n1());
		double y = (double)(l.get_vector_n2() / l2.get_vector_n2());
		double z = (double)(l.get_vector_n3() / l2.get_vector_n3());

		res = (x == y) == (x == z) == (y == z);
	}

	else
	{
		double A = (double)(l.get_vector_A().getY() / l2.get_vector_A().getX());
		double B = (double)(l.get_vector_A().getY() / l2.get_vector_A().getY());
		double C = (double)(l.get_vector_B().getX() / l2.get_vector_B().getX());
		double D = (double)(l.get_vector_B().getY() / l2.get_vector_B().getY());

		res = (A == B) == (A == C) == (A == D) == (B == C) == (B == D) == (C == D);
	}
	return res;
}

int orientation(Point p, Point q, Point r)
{
	int val = (q.getY() - p.getY()) * (r.getX() - q.getX()) -
		(q.getX() - p.getX()) * (r.getY() - q.getY());

	if (val == 0) return 0;  // colinear

	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

bool isIntersecting(Point& p1, Point& p2, Point& q1, Point& q2) {
	return (((q1.getX() - p1.getX()) * (p2.getY() - p1.getY()) - (q1.getY() - p1.getY()) * (p2.getX() - p1.getX()))
		* ((q2.getX() - p1.getX()) * (p2.getY() - p1.getY()) - (q2.getY() - p1.getY()) * (p2.getX() - p1.getX())) < 0)
		&&
		(((p1.getX() - q1.getX()) * (q2.getY() - q1.getY()) - (p1.getY() - q1.getY()) * (q2.getX() - q1.getX()))
			* ((p2.getX() - q1.getX()) * (q2.getY() - q1.getY()) - (p2.getY() - q1.getY()) * (q2.getX() - q1.getX())) < 0);
}

bool Line::operator&&(Vector v1)
{
	//(y1-y2)/(x1-x2)
	double slope1 = (get_vector_A().getY() - get_vector_B().getY()) / (get_vector_A().getX() - get_vector_B().getX());
	double slope2 = (v1.get_vector_A().getY() - v1.get_vector_B().getY()) / (v1.get_vector_A().getX() - v1.get_vector_B().getX());

	//Equal swopes don't mean lines intersect for sure
	if (slope1 != slope2)
	{
		return false;
	}

	bool result = isIntersecting(A, B, v1.A, v1.B); // check

	return result;
}

bool Line::operator|(Line& l) //remove const before Line& - fixes not being able to use the l
{
	bool res;

	if ((get_vector_n1() && l.get_vector_n1() && get_vector_n2() && l.get_vector_n2() && get_vector_n3() && l.get_vector_n3()) == 0)
	{
		res = false;
	}
	else
	{
		res = ((get_vector_n1() * l.get_vector_n1()) + (get_vector_n2() * l.get_vector_n2()) + (get_vector_n3() * l.get_vector_n3())) == 0;
	}
	return res;
}

double Line::find_angle_line(Vector v1)
{
	double slope1 = (get_vector_A().getY() - get_vector_B().getY()) / (get_vector_A().getX() - get_vector_B().getX());
	double slope2 = (v1.get_vector_A().getY() - v1.get_vector_B().getY()) / (v1.get_vector_A().getX() - v1.get_vector_B().getX());

	double theta1 = atan(slope1) * (180.0 / 3.14);
	double theta2 = atan(slope2) * (180.0 / 3.14);

	double angle = abs(max(theta1, theta2) - min(theta1, theta2));
	return angle;
}

bool Line::operator!=(Vector v1)
{
	//(y1-y2)/(x1-x2)
	double slope1 = (get_vector_A().getY() - get_vector_B().getY()) / (get_vector_A().getX() - get_vector_B().getX());
	double slope2 = (v1.get_vector_A().getY() - v1.get_vector_B().getY()) / (v1.get_vector_A().getX() - v1.get_vector_B().getX());

	return slope1 == slope2;
}

//Checks if a point lies on a line
bool Line::operator+(Point pt)
{
	//formula used:
	//(pt.X - A.X) / (B.X-A.X) = l
	//(pt.Y - A.Y) / (B.Y-A.Y) = m
	//(pt.Z - A.Z) / (B.Z - A.Z) = n
	//l == m == n

	double l = (pt.getX() - get_vector_A().getX()) / (get_vector_B().getX() - get_vector_A().getX());
	double m = (pt.getY() - get_vector_A().getY()) / (get_vector_B().getY() - get_vector_A().getY());
	double n = (pt.getZ() - get_vector_A().getZ()) / (get_vector_B().getZ() - get_vector_A().getZ());

	if ((l == m) && (l == n) && (m == n))
	{
		return true;
	}
	return false;
}

std::ostream& Line::ins(std::ostream& print)  //removing const makes it work
{
	print << "Print Line" << endl;

	print << "Lines Vector" << endl;
	Vector::ins(print);

	print << "Lines Point" << endl;
	print << get_vector_A();

	return print;
}

std::istream& Line::ext(std::istream& in)
{
	cout << endl << "Create Line Menu" << endl;
	cout << endl << "Choose method of creation:" << endl;
	cout << "1. Using vector and point" << endl;
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
	{
		cout << endl << "You chose vector and point initialization!" << endl;
		Vector v1;

		if (_Commands.size() > 0)
		{
			v1 = Vector(_Commands);
		}

		cin >> v1;
		_Commands = v1._Commands;

		Point p1;

		if (_Commands.size() > 0)
		{
			p1 = Point(_Commands);
		}

		cin >> p1;
		_Commands = p1._Commands;

		Line(v1, p1);
		//TODO:
		break;
	}
	case 2:
	{
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

		get_vector_A() = pt_x;
		get_vector_B() = pt_y;
		break;
	}
	}

	return in;
}
