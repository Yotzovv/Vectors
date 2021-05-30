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

	setOutputs(pt.getOutputs());

	this->_Point = pt;
}

void PointMenu::check_if_equal()
{
	Point newP(_Commands);

	cin >> newP;

	setOutputs(newP.getOutputs());

	bool are_point_equal = this->_Point == newP;

	auto result = (are_point_equal ? "Points are equal!" : "Points are not equal!");

	pushtToOutputs(result);

	cout << endl << result;
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

	auto output = "\n--- Point Menu ---\n"
		"1. Check if points are equal\n"
		"2. Go back\n"
		"\n>: ";

	cout << output;

	pushtToOutputs(output);

	int option;

	if (_Commands.size() < 1)
	{
		cin >> option;
	}
	else
	{
		_Commands = this->_Point._Commands;
		option = stoi(_Commands.front());
		_Commands.pop();
		cout << option;
	}

	pushtToOutputs(to_string(option));

	redirect(option);
}
