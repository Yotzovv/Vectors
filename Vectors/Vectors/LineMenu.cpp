#include "LineMenu.h"

LineMenu::LineMenu(std::queue<std::string> cmds)
{
	_Commands = cmds;
}

LineMenu::LineMenu()
{

}

void LineMenu::instantiate_line()
{
	Line line;

	if (_Commands.size() > 0)
	{
		line = Line(_Commands);
	}

	cin >> line;

	_Line = line;
}

void LineMenu::redirect(int option)
{
	switch (option)
	{
		case 1:
		{
			cout << "Line direction: " << endl;
			cout << _Line.get_line_direction();
			break;
		}
		case 2:
		{
			cout << "Normal vector: " << endl;
			cout << _Line.find_normal_vector();
			break;
		}
		case 3:
		{
			Line l1(_Commands);
			cin >> l1;
			cout << "Line angle: ";
			cout << _Line.find_angle_line(l1);
			_Commands = l1._Commands;
			break;
		}
		case 4:
		{
			Point p1;
			cin >> p1;
			cout << ((_Line + p1) ? "Point lies on the line." : "Point doesn\'t lie on the line.");
			break;
		}
		case 5:
		{
			Line parallel_line(_Commands);
			cin >> parallel_line;
			cout << ((_Line || parallel_line) ? "Lines are parallel." : "Lines are not parallel.");
			_Commands = parallel_line._Commands;
			break;
		}
		case 6:
		{
			Line equal_line(_Commands);
			cin >> equal_line;
			cout << ((_Line == equal_line) ? "Lines are equal." : "Lines are not equal.");
			_Commands = equal_line._Commands;
			break;
		}
		case 7:
		{
			Line intersected_line(_Commands);
			cin >> intersected_line;
			cout << ((_Line && intersected_line) ? "Lines intersect." : "Lines don\'t intersect.");
			_Commands = intersected_line._Commands;
			break;
		}
		case 8:
		{
			Line crossed_line(_Commands);
			cin >> crossed_line;
			cout << ((_Line != crossed_line) ? "Lines are crossed." : "Lines are not crossed.");
			_Commands = crossed_line._Commands;
			break;
		}
		case 9:
		{
			Line perpendicular_line(_Commands);
			cin >> perpendicular_line;
			cout << ((_Line | perpendicular_line) ? "Lines are perpendicular." : "Lines are not perpendicular.");
			_Commands = perpendicular_line._Commands;
			break;
		}
	}
}

void LineMenu::print_menu()
{
	instantiate_line();

	cout << endl << "--- Line Menu ---" << endl;

	cout << "1. Calculate direction" << endl;
	cout << "2. Calculate normal vector" << endl;
	cout << "3. Calculate the angle between 2 lines" << endl;
	cout << "4. Check if a point lies on the line" << endl;
	cout << "5. Check if two lines are parallel" << endl;
	cout << "6. Check if two lines are equals" << endl;
	cout << "7. Check if two lines intersect" << endl;
	cout << "8. Check if two lines are crossed" << endl;
	cout << "9. Check if two lines are perpendicular" << endl;
	cout << "10. Go back" << endl;

	cout << endl << ">: ";

	int option;

	if (_Commands.size() < 1)
	{
		cin >> option;
	}
	else
	{
		_Commands = this->_Line._Commands;
		option = stoi(_Commands.front());
		_Commands.pop();
		cout << option << endl;
	}

	redirect(option);
}
