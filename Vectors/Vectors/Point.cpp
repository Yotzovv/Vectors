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
	return (point.getX() == getX() && point.getY() == getY() && point.getZ() == getZ());
}

string Point::get_data()
{
	string output = "> Your Point\n"
		"X: " + to_string(getX()) + '\n' +
		"Y: " + to_string(getY()) + '\n' +
		"Z: " + to_string(getZ()) + '\n';

	return output;
}

//Overlaods >> operator
std::istream& Point::ext(std::istream& in) 
{
	string output = "\n=== Create Point Menu ===\n"
		">Choose method of creation:\n"
		"\n1. Using cordinates (X,Y)"
		"\n2. Using 3 numbers (X,Y,Z)\n";

	cout << output;

	pushtToOutputs(output);

	cout << endl << ">: ";
	pushtToOutputs(">: ");

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
		pushtToOutputs("X: ");

		if (_Commands.size() < 1)
		{
			in >> q;
		}
		else
		{
			q = stoi(_Commands.front());
			_Commands.pop();
			cout << q << endl;

			pushtToOutputs((to_string(q) + "\n"));
		}

		cout << "Y: ";
		pushtToOutputs("Y: ");

		if (_Commands.size() < 1)
		{
			in >> f;
		}
		else
		{
			f = stoi(_Commands.front());
			_Commands.pop();
			cout << f << endl;

			pushtToOutputs(to_string(f) + "\n");
		}

		setX(q);
		setY(f);
		break;
	case 2:
		double a, b, c;
		cout << "X: ";
		pushtToOutputs("X: ");

		if (_Commands.size() < 1)
		{
			in >> a;
		}
		else
		{
			a = stoi(_Commands.front());
			_Commands.pop();
			cout << a << endl;
			pushtToOutputs(to_string(a) + "\n");
		}

		cout << "Y: ";
		pushtToOutputs("Y: ");

		if (_Commands.size() < 1)
		{
			in >> b;
		}
		else
		{
			b = stoi(_Commands.front());
			_Commands.pop();
			cout << b << endl;
			pushtToOutputs(to_string(b) + "\n");
		}

		cout << "Z: ";
		pushtToOutputs("Z: ");
		if (_Commands.size() < 1)
		{
			in >> c;
		}
		else
		{
			c = stoi(_Commands.front());
			_Commands.pop();
			cout << c << endl;
			pushtToOutputs(to_string(c) + "\n");
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
	auto output = "> Your Point\n"
		"X: " + to_string(getX()) + '\n' + 
		"Y: " + to_string(getY()) + '\n' +
		"Z: " + to_string(getZ()) +'\n';

	return print;
}
