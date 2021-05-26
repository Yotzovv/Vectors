#include "PointMenu.h"
#include <iostream>
#include "Point.h"

using namespace std;

void PointMenu::instantiate_point()
{
	double x, y, z;

	cout << "Your point" << endl;
	cout << "x: ";
	cin >> x;

	cout << "y: ";
	cin >> y;

	cout << "z: ";
	cin >> z;

	this->_Point = Point(x, y, z);
}

void PointMenu::check_if_equal()
{
	Point newP;
	cin >> newP;

	bool are_point_equal = this->_Point == newP;

	cout << endl << (are_point_equal ? "Points are equal!" : "Points are not equal!");
}

void PointMenu::redirect_point_menu(int option)
{
	switch (option)
	{
	case 1:
		check_if_equal();
		break;
	default:
		break;
	}
}

void PointMenu::print_point_menu()
{
	instantiate_point();

	cout << endl << "Point Menu" << endl;
	cout << "1.Check if points are equal" << endl;

	cout << endl << ">: ";

	int option;
	cin >> option;

	redirect_point_menu(option);
}
