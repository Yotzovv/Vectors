#include "PointMenu.h"
#include <iostream>
#include "Point.h"

using namespace std;

void PointMenu::instantiate_point()
{
	double x, y, z;
	cin >> x;
	cin >> y;
	cin >> z;

	this->_Point = Point(x, y, z);
}

void PointMenu::check_if_equal()
{
	double x, y, z;
	cin >> x;
	cin >> y;
	cin >> z;

	bool are_point_equal = this->_Point == Point(x, y, z);

	cout << are_point_equal ? "Points are equal!" : "Points are not equal!";
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
	cout << "Chose an option:" << endl;
	cout << "1.Check if points are equal" << endl;

	cout << "option: ";

	int option;
	cin >> option;

	redirect_point_menu(option);
}
