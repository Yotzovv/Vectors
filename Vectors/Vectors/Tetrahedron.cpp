#include "Tetrahedron.h"
#include <vector>
#include <string>
#include "Triangle.h"
#include "Segment.h"
#include <math.h>
#include "EqualPointException.h"

using namespace std;

bool Tetrahedron::is_point_valid()
{
	try
	{
		vector<string> indexes;
		vector<Point> pts = { A, B, C, D };
		vector<string> pts_names = { "A", "B", "C", "D" };

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
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

Tetrahedron::Tetrahedron()
{
}

Tetrahedron::Tetrahedron(std::queue<std::string> cmds)
{
	_Commands = cmds;
}


Tetrahedron::Tetrahedron(Point a, Point b, Point c, Point d)
{
	setA(a);
	setB(b);
	setC(c);
	setD(d);
	this->is_point_valid();
}

Point Tetrahedron::getA()
{
	return A;
}

Point Tetrahedron::getB()
{
	return B;
}

Point Tetrahedron::getC()
{
	return C;
}

Point Tetrahedron::getD()
{
	return D;
}

void Tetrahedron::setA(Point a)
{
	this->A = a;
}

void Tetrahedron::setB(Point b)
{
	this->B = b;
}

void Tetrahedron::setC(Point c)
{
	this->C = c;
}

void Tetrahedron::setD(Point d)
{
	this->D = d;
}

bool Tetrahedron::is_tetrahedron_regular()
{
	Segment s1(getA(), getB());
	double a = s1.find_segment_length();
	Segment s2(getA(), getD());
	double b = s2.find_segment_length();
	Segment s3(getB(), getC());
	double c = s3.find_segment_length();
	Segment s4(getC(), getD());
	double d = s4.find_segment_length();

	Triangle a1(getA(), getB(), getD());
	Triangle a2(getB(), getC(), getD());
	Triangle a3(getC(), getA(), getD());

	bool result = a1.is_triangle_equilateral() && a2.is_triangle_equilateral() && a3.is_triangle_equilateral();

	return result;
}

bool Tetrahedron::is_ortogonal()
{
	//AB2+ CD?2 = AC?2 + BD?2 = AD?2 + BC?2
	Segment s_ab(getA(), getB());
	Segment s_cd(getC(), getD());
	Segment s_bd(getB(), getD());
	Segment s_ac(getA(), getC());
	Segment s_bc(getB(), getC());
	Segment s_ad(getA(), getD());

	double ab = s_ab.find_segment_length();
	double cd = s_cd.find_segment_length();
	double bd = s_bd.find_segment_length();
	double ac = s_ac.find_segment_length();
	double bc = s_bc.find_segment_length();
	double ad = s_ad.find_segment_length();

	if ((pow(ab, 2) + pow(cd, 2) == pow(ac, 2) + pow(bd, 2)) &&
		(pow(ab, 2) + pow(cd, 2) == pow(ad, 2) + pow(bc, 2)) &&
		(pow(ac, 2) + pow(bd, 2) == pow(ad, 2) + pow(bc, 2)))
	{
		return true;
	}

	return false;
}

double Tetrahedron::find_surrounding_surface()
{
	Triangle acd(getA(), getC(), getD());
	Triangle abd(getA(), getB(), getD());
	Triangle bcd(getB(), getC(), getD());

	return acd.get_area() + abd.get_area() + bcd.get_area();
}

double Tetrahedron::get_volume()
{
	Vector ab(getA(), getB());
	Vector ac(getA(), getC());
	Vector ad(getA(), getD());

	return ((ab ^ ac) * ad) / 6;
}

//Divide Tetrahedron on 4 Triangles
//Check if Point is in any of the Triangles
bool Tetrahedron::operator<(Point pt)
{
	Triangle adc(getA(), getD(), getC());
	Triangle adb(getA(), getD(), getB());
	Triangle bdc(getB(), getD(), getC());
	Triangle abc(getA(), getB(), getC());

	return adc < pt || adb < pt || bdc < pt || abc < pt;
}

//Divide Tetrahedron on 4 Triangles
//Check if Point is outside of all triangles
bool Tetrahedron::operator>(Point pt)
{
	Triangle adc(getA(), getD(), getC());
	Triangle adb(getA(), getD(), getB());
	Triangle bdc(getB(), getD(), getC());
	Triangle abc(getA(), getB(), getC());

	return adc > pt || adb > pt || bdc > pt || abc > pt;
}

bool Tetrahedron::operator==(Point pt)
{
	Segment s1(getA(), getB());
	double a = s1.find_segment_length();
	Segment s2(getA(), getD()); //was curly brackets {}
	double b = s2.find_segment_length();
	Segment s3(getB(), getC());
	double c = s3.find_segment_length();
	Segment s4(getC(), getD());
	double d = s4.find_segment_length();

	bool result = s1 == pt && s2 == pt && s3 == pt && s4 == pt;

	return result;
}

std::ostream& Tetrahedron::ins(std::ostream& print) const
{
	print << endl << "--- Tetrahedron Specifics ---" << endl;
	print << A, B, C, D;

	return print;
}

std::istream& Tetrahedron::ext(std::istream& in)
{
	Point x(_Commands);
	cin >> x;
	_Commands = x._Commands;

	Point y(x._Commands);
	cin >> y;
	_Commands = y._Commands;

	Point z(y._Commands);
	cin >> z;
	_Commands = z._Commands;

	Point d(z._Commands);
	cin >> d;
	_Commands = d._Commands;

	getA() = x;
	getB() = y;
	getC() = z;
	getD() = d;

	return in;
}
