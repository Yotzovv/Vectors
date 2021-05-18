#include "Tetrahedron.h"
#include <vector>
#include <string>
#include "Triangle.h"
#include "Segment.h"
#include <math.h>

using namespace std;

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

bool Tetrahedron::is_point_valid()
{
	try
	{
		vector<string> indexes;
		vector<Point> pts = { A, B, C, D };
		vector<string> pts_names = { "A", "B", "C", "D" };

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
	A = a;
}

void Tetrahedron::setB(Point b)
{
	B = b;
}

void Tetrahedron::setC(Point c)
{
	C = c;
}

void Tetrahedron::setD(Point d)
{
	D = d;
}

bool Tetrahedron::is_ortogonal()
{
	//AB2+ CD’2 = AC’2 + BD’2 = AD’2 + BC’2
	Segment s_ab(A, B);
	Segment s_cd(C, D);
	Segment s_bd(B, D);
	Segment s_ac(A, C);
	Segment s_bc(B, C);
	Segment s_ad(A, D);
    
	double ab = s_ab.find_segment_length();
	double cd = s_cd.find_segment_length();
	double bd = s_bd.find_segment_length();
	double ac = s_ac.find_segment_length();
	double bc = s_bc.find_segment_length();
	double ad = s_ad.find_segment_length();

	return pow(ab, 2) + pow(cd, 2) == pow(ac, 2) + pow(bd, 2) == pow(ad, 2) + pow(bc, 2); 
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


