#include "PointMenu.h"
#include "Point.h"
#include <iostream>

using namespace std;

PointMenu::PointMenu(std::queue<std::string> cmds)
{
	_Commands = cmds;
}

void PointMenu::instantiate_point()
{
	Point pt;

	if (_Commands.size() > 0)
	{
		pt = Point(_Commands);
	}

	cin >> pt;

	this->_Point = pt;
}

void PointMenu::check_if_equal()
{
	Point newP(_Commands);

	cin >> newP;

	bool are_point_equal = this->_Point == newP;

	cout << endl << (are_point_equal ? "Points are equal!" : "Points are not equal!");
}

void PointMenu::redirect(int option)
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

void PointMenu::print_menu()
{
	instantiate_point();

	cout << endl << "--- Point Menu ---" << endl;
	cout << "1. Check if points are equal" << endl;
	cout << "2. Go back" << endl;

	cout << endl << ">: ";

	int option;

	if (_Commands.size() < 1)
	{
		cin >> option;
	}
	else
	{
		setCmds(this->_Point._Commands);
		option = stoi(_Commands.front());
		_Commands.pop();
		cout << option;

	}

	redirect(option);
}