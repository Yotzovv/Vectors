#include "Tetrahedron.h"
#include <vector>
#include <string>
#include "Triangle.h"
#include "Segment.h"
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

bool Tetrahedron::is_tetrahedron_regular()
{
	Segment s1(A, B);
	double a = s1.find_segment_length();
	Segment s2{ A, D };
	double b = s2.find_segment_length();
	Segment s3{ B,C };
	double c = s3.find_segment_length();
	Segment s4{ C,D };
	double d = s4.find_segment_length();

	Triangle a1(A, B, D);
	Triangle a2(B, C, D);
	Triangle a3(C, A, D);

	bool result = a1.is_triangle_equilateral(A, B, D) && a2.is_triangle_equilateral(B, C, D) && a3.is_triangle_equilateral(C, A, D);

	return result;
}

double Tetrahedron::get_volume()
{
	Vector ab(A, B);
	Vector ac(A, C);
	Vector ad(A, D);

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
	Segment s1(A, B);
	double a = s1.find_segment_length();
	Segment s2{ A, D };
	double b = s2.find_segment_length();
	Segment s3{ B,C };
	double c = s3.find_segment_length();
	Segment s4{ C,D };
	double d = s4.find_segment_length();
	
	bool result = s1 == pt && s2 == pt && s3 == pt && s4 == pt;

	return result;
}
