#include "VectorMenu.h"
#include "Vector.h"
#include <iostream>

using namespace std;

VectorMenu::VectorMenu()
{
	Vector v;
	cin >> v;

	_Vector = v;
}

void VectorMenu::redirect_vector_menu(int option)
{
	switch (option) {
		case 1:
		{
			cout << _Vector.get_vector_length();
			break;
		}
		case 2:
		{
			cout << _Vector.is_vector_null();
			break;
		}
		case 3:
		{
			_Vector.print_direction();
			break;
		}
		case 4:
		{
			Vector parallelV;
			cin >> parallelV;
			cout << _Vector.is_parallel(parallelV);
			break;
		}
		case 5:
		{
			Vector perpendicullarV;
			cin >> perpendicullarV;
			cout << _Vector.is_vector_perpendicullar(perpendicullarV);
			break;
		}
		case 6:
		{
			// this works with n1,n2,n3 only
			Vector vec_to_add;
			cin >> vec_to_add;
			cout << _Vector + vec_to_add;
			break;
		}
		case 7:
		{
			Vector vec_to_sub;
			cin >> vec_to_sub;
			cout << _Vector - vec_to_sub;
			break;
		}
		case 8:
		{
			int n;
			cin >> n;
			cout << n * _Vector;
			break;
		}
		case 9:
		{
			Vector vec_to_multiply;
			cin >> vec_to_multiply;
			cout << _Vector * vec_to_multiply;
			break;
		}
		case 10:
		{
			Vector newV;
			cin >> newV;
			cout << (_Vector ^ newV);
			break;
		}
		case 11:
		{
			Vector v1;
			Vector v2;
			cin >> v1;
			cin >> v2;
			cout << v1(v2, _Vector);
			break;
		}
	}
}

void VectorMenu::print_vector_menu()
{
	cout << endl << "Vector Menu" << endl;

	cout << "1. Calculate length" << endl;
	cout << "2. Check for 0 vector" << endl;
	cout << "3. Calculate direction" << endl;
	cout << "4. Check if vectors are parallel" << endl;
	cout << "5. Check if vectors are perpendicular" << endl;
	cout << "6. Sum 2 vectors" << endl;
	cout << "7. Substract 2 vectors" << endl;
	cout << "8. Multiply vector by number" << endl;
	cout << "9. Scalar product of 2 vectors" << endl;
	cout << "10. Vector product of 2 vectors" << endl;
	cout << "11. Mixed Product of 3 vectors" << endl;

	cout << endl << ">: ";

	int option;
	cin >> option;

	redirect_vector_menu(option);
}
