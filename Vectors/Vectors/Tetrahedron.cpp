#include "Tetrahedron.h"
#include <vector>
#include <string>
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
