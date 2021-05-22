#include "TetrahedronMenu.h"

using namespace std;

TetrahedronMenu::TetrahedronMenu()
{
	Tetrahedron th;
	cin >> th;

	_Tetrahedron = th;
}

void TetrahedronMenu::redirect_tetrahedron_menu(int option)
{
	switch (option)
	{
		case 1:
		{
			cout << _Tetrahedron.is_tetrahedron_regular();
			break;
		}
		case 2:
		{
			cout << _Tetrahedron.is_ortogonal();
			break;
		}
		case 3:
		{
			cout << _Tetrahedron.find_surrounding_surface();
			break;
		}
		case 4:
		{
			cout << _Tetrahedron.get_volume();
			break;
		}
		case 5:
		{
			Point th_inside;
			cin >> th_inside;

			cout << (_Tetrahedron < th_inside);
			break;
		}
		case 6:
		{
			Point th_outside;
			cin >> th_outside;

			cout << (_Tetrahedron > th_outside);
			break;
		}
		case 7:
		{
			Point th_side;
			cin >> th_side;

			cout << (_Tetrahedron == th_side);
			break;
		}
	}
}

void TetrahedronMenu::print_tetrahedron_menu()
{
	cout << endl << "--- Tetrahedron Menu ---" << endl;
	cout << "1. Check if is right" << endl;
	cout << "2. Check if is ortogonal" << endl;
	cout << "3. Calculate surrounding surface" << endl;
	cout << "4. Calculate volume" << endl;
	cout << "5. Check if point is inside" << endl;
	cout << "6. Check if point is outside" << endl;
	cout << "7. Check if point lies on the side" << endl;
	cout << "8. Go back" << endl;

	cout << endl << ">: ";

	int option;
	cin >> option;

	redirect_tetrahedron_menu(option);
}
