#include "Triangle.h"
#include "Vector.h"
#include <cmath>
#include "Segment.h"
#include <math.h>
#pragma once

Triangle::Triangle()
{
}

Triangle::Triangle(Point x, Point y, Point z)
{
	setX(x);
	setY(y);
	setZ(z);

	is_point_valid();
}

Triangle::Triangle(std::queue<std::string> cmds)
{
	_Commands = cmds;
}

Point Triangle::getX()
{
	return this->X;
}

Point Triangle::getY()
{
	return this->Y;
}

Point Triangle::getZ()
{
	return this->Z;
}

class EqualPointException : public std::exception {
private:
	std::string message_;
public:
	EqualPointException(const std::string& message) : message_(message) {
		message_ = message;
	}
	const char* what() const noexcept override {
		return message_.c_str();
	}
};

bool Triangle::is_point_valid()
{
	try
	{
		vector<string> indexes;
		vector<Point> pts = { X, Y, Z };
		vector<string> pts_names = { "X", "Y", "Z" };

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == j)
				{
					continue;
				}

				if (pts[i] == pts[j])
				{
					indexes.push_back(pts_names[i]);
					indexes.push_back(pts_names[j]);
					throw EqualPointException("Point " + pts_names[i] + " equals point " + pts_names[j]);
				}
			}
		}

		return true;
	}
	catch (const EqualPointException& e)
	{
		std::cout << e.what();
	}
}

double Triangle::get_mid_side(double a, double b, double c)
{
	double mid;

	if ((a < b && b < c) || (c < b && b < a))
	{
		mid = b;
	}
	else if ((b < a && a < c) || (c < a && a < b))
	{
		mid = a;
	}
	else
	{
		mid = c;
	}

	return mid;
}

bool Triangle::is_triangle_iscoleses(Point x, Point y, Point z)
{
	Vector vec(x, y);
	Vector vec1(z, y);
	Vector vec2(x, z);

	double vec_lngth = vec.get_vector_length();
	double vec1_lngth = vec1.get_vector_length();
	double vec2_lngth = vec2.get_vector_length();

	if ((vec_lngth == vec1_lngth || vec_lngth == vec2_lngth) || (vec1_lngth == vec_lngth || vec1_lngth == vec2_lngth) || (vec2_lngth == vec_lngth || vec2_lngth == vec1_lngth))
	{
		return true;
	}
	else return false;
}

void Triangle::setX(Point x)
{
	X = x;
}

void Triangle::setY(Point y)
{
	Y = y;
}

void Triangle::setZ(Point z)
{
	Z = z;
}

Point Triangle::get_incenter(Point x, Point y, Point z)
{
	Point centroid;

	centroid.X = (x.X + y.X + z.X) / 3;
	centroid.Y = (x.Y + y.Y + z.Y) / 3;

	return centroid;
}


Point Triangle::get_incenter()
{
	Point centroid;

	centroid.X = (X.X + Y.X + Z.X) / 3;
	centroid.Y = (X.Y + Y.Y + Z.Y) / 3;

	return centroid;
}

double Triangle::get_area()
{
	Segment x(X, Y);
	Segment y(Y, Z);
	Segment z(Z, X);

	double a = x.find_segment_length();
	double b = y.find_segment_length();
	double c = z.find_segment_length();

	//S = √p(p - a)(p - b)(p - c)
	double p = (a + b + c) / 2;
	double area = (double)sqrt(p*(p - a) * (p - b) * (p - c));
	
	return area;
}

double Triangle::get_area(Point x, Point y, Point z)
{
	Segment s1(x, y);
	Segment s2(y, z);
	Segment s3(z, x);

	double a = s1.find_segment_length();
	double b = s2.find_segment_length();
	double c = s3.find_segment_length();
			   
	//S = √p(p - a)(p - b)(p - c)
	double p = (a + b + c) / 2;
	double area = (double)sqrt(p * (p - a) * (p - b) * (p - c));

	return area;
}

double Triangle::get_perimeter()
{
	Segment x(X, Y);
	Segment y(Y, Z);
	Segment z(Z, X);

	double a = x.find_segment_length();
	double b = y.find_segment_length();
	double c = z.find_segment_length();

	double perimeter = (a + b + c);

	return perimeter;
}


bool Triangle::is_triangle_equilateral(Point x, Point y, Point z) {

	Vector vec(x, y);
	Vector vec1(z, y);
	Vector vec2(x, z);

	double vec_lngth = vec.get_vector_length();
	double vec1_lngth = vec1.get_vector_length();
	double vec2_lngth = vec2.get_vector_length();

	if (vec_lngth == vec1_lngth == vec2_lngth) {
		return true;
	}
	else return false;
}

bool Triangle::is_triangle_right(Point x, Point y, Point z) {

	Segment vec(x, y);
	Segment vec1(y, z);
	Segment vec2(z, x);
	double mid;
	double sum; // of 2 shortest sides b'2 + c'2

	double a = vec.find_segment_length();
	double b = vec1.find_segment_length();
	double c = vec2.find_segment_length();

	mid = this->get_mid_side(a,b,c);

	sum = (pow(mid, 2) + pow(min(min(a, b), c), 2));
	if ((static_cast<int>(pow(max(max(a, b), c),2))) == static_cast<int>(sum)) {
		return true;
	}
	
	return false;
}

bool Triangle::is_triangle_acute(Point x, Point y, Point z) {

	Segment vec(x, y);
	Segment vec1(z, y);
	Segment vec2(x, z);
	double mid;
	double sum; // of 2 shortest sides b'2 + c'2

	double a = vec.find_segment_length();
	double b = vec1.find_segment_length();
	double c = vec2.find_segment_length();

	mid = this->get_mid_side(a, b, c);

	sum = (pow(mid, 2) + pow(min(min(a, b), c), 2));
	
	if (pow(max(max(a, b), c), 2) < sum) {
		return true;
	}

	return false;
}

bool Triangle::is_triangle_obtuse(Point x, Point y, Point z)
{
	Segment vec(x, y);
	Segment vec1(z, y);
	Segment vec2(x, z);
	double mid;
	double sum; // of 2 shortest sides b'2 + c'2

	double a = vec.find_segment_length();
	double b = vec1.find_segment_length();
	double c = vec2.find_segment_length();

	mid = this->get_mid_side(a, b, c);

	sum = (pow(mid, 2) + pow(min(min(a, b), c),2));
	if (static_cast<int>(pow(max(max(a, b), c), 2)) > sum) {
		return true;
	}

	return false;
}


void Triangle::get_triangle_type(Point x, Point y, Point z)
{	
	if (is_triangle_right(x, y, z)) 
	{
		cout << "the triangle is right." << endl;
	}
	
	if (this->is_triangle_acute(x,y,z)) 
	{
		cout << "the triagnle is acute." << endl;
	}
	
	if (this->is_triangle_obtuse(x,y,z)) 
	{
		cout << "the triangle is obtuse." << endl;
	}
}


void Triangle::get_triangle_type()
{
	if (is_triangle_right(X, Y, Z))
	{
		cout << "the triangle is right." << endl;
	}

	if (this->is_triangle_acute(X, Y, Z))
	{
		cout << "the triagnle is acute." << endl;
	}

	if (this->is_triangle_obtuse(X, Y, Z))
	{
		cout << "the triangle is obtuse." << endl;
	}
}

//Checks if Point is inside triangle
bool Triangle::operator<(Point pt)
{
	float total_area = get_area(this->X, this->Y, this->Z);
	float area1 = get_area(pt, this->Y, this->Z);
	float area2 = get_area(pt, this->X, this->Z);
	float area3 = get_area(pt, this->X, this->Y);

	if ((area1 + area2 + area3) <= total_area)
	{
		return true;
	}

	return false;
}

//Checks if Point is outside triangle
bool Triangle::operator>(Point pt)
{
	float total_area = get_area(this->X, this->Y, this->Z);
	float area1 = get_area(pt, this->Y, this->Z);
	float area2 = get_area(pt, this->X, this->Z);
	float area3 = get_area(pt, this->X, this->Y);

	if ((area1 + area2 + area3) <= total_area)
	{
		return false;
	}

	return true;
}

bool Triangle::operator==(Point point)
{
	Segment seg(X, Y);
	Segment seg1(Z, Y);
	Segment seg2(X, Z);

	double a = seg.find_segment_length();
	double b = seg1.find_segment_length();
	double c = seg2.find_segment_length();

	return (seg == point) || (seg1 == point) || (seg2 == point);
}

std::ostream& Triangle::ins(std::ostream& print) const
{
	print << "-- Triangle Specifics --" << endl;
	print << "X: " << X;
	print << "Y: " << Y;
	print << "Z: " << Z;

	return print;
}

std::istream& Triangle::ext(std::istream& in)
{

	cout << endl << "--- Triangle Menu ---" << endl;
	cout << ">Enter triangle cordinates (X,Y,Z)" << endl;

	Point x(_Commands);
	cin >> x;
	_Commands = x._Commands;

	Point y(_Commands);
	cin >> y;
	_Commands = y._Commands;

	Point z(_Commands);
	cin >> z;
	_Commands = z._Commands;

	return in;
}
