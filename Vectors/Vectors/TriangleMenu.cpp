#include "TriangleMenu.h"

using namespace std;

TriangleMenu::TriangleMenu()
{
	Triangle t;
	cin >> t;

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
			cout << _Triangle.get_area();
			break;
		}
		case 3:
		{
			cout << _Triangle.get_perimeter();
			break;
		}
		case 4:
		{
			cout << _Triangle.get_incenter();
			break;
		}
		case 5:
		{
			Point inside_pt;
			cin >> inside_pt;
			cout << (_Triangle < inside_pt);
			break;
		}
		case 6:
		{
			Point outside_pt;
			cin >> outside_pt;
			cout << (_Triangle > outside_pt);
			break;
		}
		case 7:
		{
			Point side_pt;
			cin >> side_pt;
			cout << (_Triangle == side_pt);
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
	cin >> option;

	redirect_triangle_menu(option);
}
