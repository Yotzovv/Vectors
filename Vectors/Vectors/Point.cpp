#include <iostream>
#include "Point.h"

using namespace std;

double Point::getX()
{
	return this->X;
}

double Point::getY()
{
	return this->Y;
}

double Point::getZ()
{
	return this->Z;
}

void Point::setX(double x)
{
	this->X = x;
}

void Point::setY(double y)
{
	this->Y = y;
}

void Point::setZ(double z)
{
	this->Z = z;
}

Point::Point()
{
}

Point::Point(queue<string> cmds)
{
	_Commands = cmds;
}


Point::Point(double x, double y, double z)
{
	setX(x);
	setY(y);
	setZ(z);
};

Point::Point(double x, double y)
{
	setX(x);
	setY(y);
};

bool Point::operator==(Point point)
{
	return (point.X == getX() && point.Y == getY() && point.Z == getZ());
};

//Overlaods >> operator
std::istream& Point::ext(std::istream& in) {
	cout << "\n=== Create Point Menu ===\n";
	cout << ">Choose method of creation:\n";
	cout << "\n1. Using cordinates (X,Y)";
	cout << "\n2. Using 3 numbers (X,Y,Z)\n";

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

	cout << endl;

	switch (option)
	{
	case 1:
		double q, f;

		cout << "X: ";

		if (_Commands.size() < 1)
		{
			in >> q;
		}
		else
		{
			q = stoi(_Commands.front());
			_Commands.pop();
			cout << q << endl;
		}

		cout << "Y: ";

		if (_Commands.size() < 1)
		{
			in >> f;
		}
		else
		{
			f = stoi(_Commands.front());
			_Commands.pop();
			cout << f << endl;
		}

		setX(q);
		setY(f);
		break;
	case 2:
		double a, b, c;
		cout << "X: ";

		if (_Commands.size() < 1)
		{
			in >> a;
		}
		else
		{
			a = stoi(_Commands.front());
			_Commands.pop();
			cout << a << endl;
		}

		cout << "Y: ";

		if (_Commands.size() < 1)
		{
			in >> b;
		}
		else
		{
			b = stoi(_Commands.front());
			_Commands.pop();
			cout << b << endl;
		}

		cout << "Z: ";
		if (_Commands.size() < 1)
		{
			in >> c;
		}
		else
		{
			c = stoi(_Commands.front());
			_Commands.pop();
			cout << c << endl;
		}

		setX(a);
		setY(b);
		setZ(c);
		break;
	default:
		break;
	}

	return in;
}

//prints Point with << operator
std::ostream& Point::ins(std::ostream& print)
{
	print << "> Your Point" << endl;
	print << "X: " << getX() << endl;
	print << "Y: " << getY() << endl;
	print << "Z: " << getZ() << endl;

	return print;
}
