#include "Triangle.h"
#include "Vector.h"
#include "Segment.h"
#pragma once

Triangle::Triangle(Point x, Point y, Point z)
{
	setX(x);
	setY(y);
	setZ(z);

	is_point_valid();
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

Point Triangle::get_centroid(Point x, Point y, Point z)
{
	Point centroid;

	centroid.X = (x.X + y.X + z.X) / 3;
	centroid.Y = (x.Y + y.Y + z.Y) / 3;

	return centroid;
}


double Triangle::area_of_triangle()
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

double Triangle::perimeter_of_triangle()
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