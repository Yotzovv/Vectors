#include "TriangleMenu.h"

using namespace std;

TriangleMenu::TriangleMenu()
{
}

TriangleMenu::TriangleMenu(std::queue<std::string> cmds)
{
	_Commands = cmds;
}

void TriangleMenu::instantiate_triangle()
{
	Triangle t;

	if (_Commands.size() > 0)
	{
		t = Triangle(_Commands);
	}

	cin >> t;

	_Commands = t._Commands;
	_Triangle = t;
}

void TriangleMenu::redirect_triangle_menu(int option)
{
	switch (option)
	{
		case 1:
		{
			_Triangle.get_triangle_type();
			break;
		}
		case 2:
		{
			cout << "Triangle area: " << _Triangle.get_area();
			break;
		}
		case 3:
		{
			cout << "Triangle perimeter: " << _Triangle.get_perimeter();
			break;
		}
		case 4:
		{
			cout << "Triangle incenter: ";
			cout << _Triangle.get_incenter();
			break;
		}
		case 5:
		{
			Point inside_pt(_Commands);
			cin >> inside_pt;
			cout << ((_Triangle < inside_pt) ? "Point is inside triangle." : "Point is not inside triangle.");
			break;
		}
		case 6:
		{
			Point outside_pt(_Commands);
			cin >> outside_pt;
			cout << ((_Triangle > outside_pt) ? "Point is outside triangle." : "Point is not outside triangle.");
			break;
		}
		case 7:
		{
			Point side_pt(_Commands);
			cin >> side_pt;
			cout << ((_Triangle == side_pt) ? "Point is on triangle side." : "Point is not triangle side.");
			break;
		}
		case 8:
		{
			break;
		}
	}
}

void TriangleMenu::print_triangle_menu()
{
	instantiate_triangle();

	cout << endl << "--- Triangle Menu ---" << endl;
	cout << "1. Find Triangle Type" << endl;
	cout << "2. Calculate area" << endl;
	cout << "3. Calculate perimater" << endl;
	cout << "4. Find medicenter" << endl;
	cout << "5. Check if point is inside triangle" << endl;
	cout << "6. Check if point is outside triangle" << endl;
	cout << "7. Check if point lies on side of triangle" << endl;
	cout << "8. Go back" << endl;
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
		cout << option << endl;
	}

	redirect_triangle_menu(option);
}
