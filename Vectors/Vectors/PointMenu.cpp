#include "PointMenu.h"
#include <iostream>
#include "Point.h"

using namespace std;

void PointMenu::instantiate_point()
{
	Point pt;
	cin >> pt;

	this->_Point = pt;
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

	cout << endl << "--- Point Menu ---" << endl;
	cout << "1. Check if points are equal" << endl;
	cout << "2. Go back" << endl;

	cout << endl << ">: ";

	int option;
	cin >> option;

	redirect_point_menu(option);
}
