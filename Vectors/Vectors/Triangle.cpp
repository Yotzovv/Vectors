#include "Triangle.h"
#include "Vector.h"
#include <cmath>
#include "Segment.h"
#include <math.h>
#include "EqualPointException.h"

Triangle::Triangle()
{
}

Triangle::Triangle(Point x, Point y, Point z)
{
	set_triangle_X(x);
	set_triangle_Y(y);
	set_triangle_Z(z);

	is_point_valid();
}

Triangle::Triangle(std::queue<std::string> cmds)
{
	_Commands = cmds;
}

Point Triangle::get_triangle_X()
{
	return this->X;
}

Point Triangle::get_triangle_Y()
{
	return this->Y;
}

Point Triangle::get_triangle_Z()
{
	return this->Z;
}

void Triangle::set_triangle_X(Point x)
{
	X = x;
}

void Triangle::set_triangle_Y(Point y)
{
	Y = y;
}

void Triangle::set_triangle_Z(Point z)
{
	Z = z;
}

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

bool Triangle::is_triangle_isosceles()
{
	Segment AB(get_triangle_X(), get_triangle_Y());
	Segment AC(get_triangle_X(), get_triangle_Z());
	Segment BC(get_triangle_Y(), get_triangle_Z());

	double length_AB = AB.find_segment_length();
	double length_AC = AC.find_segment_length();
	double length_BC = BC.find_segment_length();

	if ((length_AB == length_AC) || (length_AB == length_BC) || (length_AC == length_BC))
	{
		return true;
	}
	return false;
}


Point Triangle::get_incenter(Point x, Point y, Point z) //to be deleted?
{
	Point centroid;
	centroid.setX((x.getX() + y.getX() + z.getX()) / 3);
	centroid.setY((x.getY() + y.getY() + z.getY()) / 3);

	return centroid;
}


Point Triangle::get_incenter()
{
	Point centroid;

	centroid.setX((get_triangle_X().getX() + get_triangle_Y().getX() + get_triangle_Z().getX()) / 3);
	centroid.setY((get_triangle_X().getY() + get_triangle_Y().getY() + get_triangle_Z().getY()) / 3);

	return centroid;
}

double Triangle::get_area()
{
	Segment x(get_triangle_X(), get_triangle_Y());
	Segment y(get_triangle_Y(), get_triangle_Z());
	Segment z(get_triangle_Z(), get_triangle_X());

	double a = x.find_segment_length();
	double b = y.find_segment_length();
	double c = z.find_segment_length();

	//S = √p(p - a)(p - b)(p - c)
	double p = (a + b + c) / 2;
	double area = (double)sqrt(p * (p - a) * (p - b) * (p - c));

	return area;
}

double Triangle::get_area(Point x, Point y, Point z) //to be deleted?
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
	Segment x(get_triangle_X(), get_triangle_Y());
	Segment y(get_triangle_Y(), get_triangle_Z());
	Segment z(get_triangle_Z(), get_triangle_X());

	double a = x.find_segment_length();
	double b = y.find_segment_length();
	double c = z.find_segment_length();

	double perimeter = (a + b + c);

	return perimeter;
}


bool Triangle::is_triangle_equilateral() {
	Segment AB(get_triangle_X(), get_triangle_Y());
	Segment AC(get_triangle_X(), get_triangle_Z());
	Segment BC(get_triangle_Y(), get_triangle_Z());

	double length_AB = AB.find_segment_length();
	double length_AC = AC.find_segment_length();
	double length_BC = BC.find_segment_length();

	if ((length_AB == length_AC) && (length_AC == length_BC) && (length_AB == length_BC))
	{
		return true;
	}
	return false;
}

bool Triangle::is_triangle_right(Point x, Point y, Point z) //?
{

	Segment vec(x, y);
	Segment vec1(y, z);
	Segment vec2(z, x);
	double mid;
	double sum; // of 2 shortest sides b'2 + c'2

	double a = vec.find_segment_length();
	double b = vec1.find_segment_length();
	double c = vec2.find_segment_length();

	mid = this->get_mid_side(a, b, c);

	sum = (pow(mid, 2) + pow(min(min(a, b), c), 2));
	if ((static_cast<int>(pow(max(max(a, b), c), 2))) == static_cast<int>(sum)) {
		return true;
	}

	return false;
}

bool Triangle::is_triangle_acute() {

	Segment AB(get_triangle_X(), get_triangle_Y());
	Segment AC(get_triangle_X(), get_triangle_Z());
	Segment BC(get_triangle_Y(), get_triangle_Z());

	double AB_length = AB.find_segment_length();
	double AC_length = AC.find_segment_length();
	double BC_length = BC.find_segment_length();

	double AB_squared = pow(AB_length, 2);
	double AC_squared = pow(AC_length, 2);
	double BC_squared = pow(BC_length, 2);

	//find the hypotenuse
	//c^2 < a^2 + b^2
	double longest_side = AB_length;
	double compare;

	if (AB_length < AC_length)
	{
		longest_side = AC_length;

		if (AC_length < BC_length)
		{
			longest_side = BC_length;

			compare = AB_squared + AC_squared;
			if (BC_squared < compare)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		compare = AB_squared + BC_squared;
		if (AC_squared < compare)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	else if (AB_length < BC_length)
	{
		longest_side = BC_length;

		compare = AB_squared + AC_squared;
		if (BC_squared < compare)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		compare = AC_squared + BC_squared;
		if (AB_squared < compare)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	return false;
}

bool Triangle::is_triangle_obtuse(Point x, Point y, Point z)
{
	Segment AB(get_triangle_X(), get_triangle_Y());
	Segment AC(get_triangle_X(), get_triangle_Z());
	Segment BC(get_triangle_Y(), get_triangle_Z());

	double AB_length = AB.find_segment_length();
	double AC_length = AC.find_segment_length();
	double BC_length = BC.find_segment_length();

	double AB_squared = pow(AB_length, 2);
	double AC_squared = pow(AC_length, 2);
	double BC_squared = pow(BC_length, 2);

	//find the hypotenuse
	//c^2 > a^2 + b^2
	double longest_side = AB_length;
	double compare;

	if (AB_length < AC_length)
	{
		longest_side = AC_length;

		if (AC_length < BC_length)
		{
			longest_side = BC_length;

			compare = AB_squared + AC_squared;
			if (BC_squared > compare)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		compare = AB_squared + BC_squared;
		if (AC_squared > compare)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	else if (AB_length < BC_length)
	{
		longest_side = BC_length;

		compare = AB_squared + AC_squared;
		if (BC_squared > compare)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		compare = AC_squared + BC_squared;
		if (AB_squared > compare)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	return false;
}

//use this one...
void Triangle::get_triangle_type()
{
	if (is_triangle_right(get_triangle_X(), get_triangle_Y(), get_triangle_Z()))
	{
		cout << "The triangle is right." << endl;
	}

	if (this->is_triangle_acute())
	{
		cout << "The triagnle is acute." << endl;
	}

	if (this->is_triangle_obtuse(get_triangle_X(), get_triangle_Y(), get_triangle_Z()))
	{
		cout << "The triangle is obtuse." << endl;
	}

	if (this->is_triangle_equilateral())
	{
		cout << "The triangle is equilateral." << endl;
	}

	if (this->is_triangle_isosceles())
	{
		cout << "The triangle is isosceles." << endl;
	}
}

//Checks if Point is inside triangle
bool Triangle::operator<(Point pt)
{
	float total_area = get_area(get_triangle_X(), get_triangle_Y(), get_triangle_Z());
	float area1 = get_area(pt, get_triangle_Y(), get_triangle_Z());
	float area2 = get_area(pt, get_triangle_X(), get_triangle_Z());
	float area3 = get_area(pt, get_triangle_X(), get_triangle_Y());

	if ((area1 + area2 + area3) <= total_area)
	{
		return true;
	}

	return false;
}

//Checks if Point is outside triangle
bool Triangle::operator>(Point pt)
{
	float total_area = get_area(get_triangle_X(), get_triangle_Y(), get_triangle_Z());
	float area1 = get_area(pt, get_triangle_Y(), get_triangle_Z());
	float area2 = get_area(pt, get_triangle_X(), get_triangle_Z());
	float area3 = get_area(pt, get_triangle_X(), get_triangle_Y());

	if ((area1 + area2 + area3) <= total_area)
	{
		return false;
	}

	return true;
}

bool Triangle::operator==(Point point)
{
	Segment seg(get_triangle_X(), get_triangle_Y());
	Segment seg1(get_triangle_Z(), get_triangle_Y());
	Segment seg2(get_triangle_X(), get_triangle_Z());

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
