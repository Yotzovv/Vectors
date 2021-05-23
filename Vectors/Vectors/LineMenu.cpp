#include "LineMenu.h"

LineMenu::LineMenu()
{
	Line line;
	cin >> line;

	_Line = line;
}

void LineMenu::redirect_line_menu(int option)
{
	switch (option)
	{
		case 1: 
		{
			cout << _Line.get_line_direction();
			break;
		}
		case 2: 
		{
			cout << _Line.find_normal_vector();
			break;
		}
		case 3:
		{
			Line l1;
			cin >> l1;
			cout << _Line.find_angle_line(l1);
			break;
		}
		case 4:
		{
			Point p1;
			cin >> p1;
			cout << _Line + p1;
			break;
		}
		case 5:
		{
			Line parallel_line;
			cin >> parallel_line;
			cout << (_Line || parallel_line);
			break;
		}
		case 6:
		{
			Line equal_line;
			cin >> equal_line;
			cout << (_Line == equal_line);
			break;
		}
		case 7:
		{
			Line intersected_line;
			cin >> intersected_line;
			cout << (_Line && intersected_line);
			break;
		}
		case 8:
		{
			Line crossed_line;
			cin >> crossed_line;
			cout << (_Line != crossed_line);
			break;
		}
		case 9:
		{
			Line perpendicular_line;
			cin >> perpendicular_line;
			cout << (_Line | perpendicular_line);
			break;
		}
	}
}

void LineMenu::print_line_menu()
{
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

	cout << endl << ">: ";

	int option;
	cin >> option;

	redirect_line_menu(option);
}
