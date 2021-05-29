#include "VectorMenu.h"
#include "Vector.h"
#include <iostream>

using namespace std;

VectorMenu::VectorMenu(std::queue<std::string> cmds)
{
	_Commands = cmds;
}

VectorMenu::VectorMenu()
{
}

void VectorMenu::instantiate_vector()
{
	Vector v;

	if (_Commands.size() > 0)
	{
		v = Vector(_Commands);
	}

	cin >> v;

	_Vector = v;
}


void VectorMenu::redirect(int option)
{
	switch (option) {
		case 1:
		{
			cout << "Vector Length is: " << _Vector.get_vector_length();
			break;
		}
		case 2:
		{
			cout << (_Vector.is_vector_null() ? "Vector is null." : "Vector is not null.");
			break;
		}
		case 3:
		{
			cout << "Vector direciton: " << endl;
			_Vector.print_direction();
			break;
		}
		case 4:
		{
			Vector parallelV;
			cin >> parallelV;
			cout << (_Vector.is_parallel(parallelV) ? "Vectors are parallel." : "Vectors are not parallel.");
			break;
		}
		case 5:
		{
			Vector perpendicullarV;
			cin >> perpendicullarV;
			cout << (_Vector.is_vector_perpendicullar(perpendicullarV) ? "Vectors are perpendicular." : "Vectors are not perpendicular.");
			break;
		}
		case 6:
		{
			// this works with n1,n2,n3 only
			Vector vec_to_add;
			cin >> vec_to_add;
			cout << "New vector: " << endl;
			cout << _Vector + vec_to_add;
			break;
		}
		case 7:
		{
			Vector vec_to_sub;
			cin >> vec_to_sub;
			cout << "New vector: " << endl;
			cout << _Vector - vec_to_sub;
			break;
		}
		case 8:
		{
			int n;
			cin >> n;
			cout << "New vector: " << endl;
			cout << n * _Vector;
			break;
		}
		case 9:
		{
			Vector vec_to_multiply;
			cin >> vec_to_multiply;
			cout << "Scalar product: " << endl;
			cout << _Vector * vec_to_multiply;
			break;
		}
		case 10:
		{
			Vector newV;
			cin >> newV;
			cout << "Vector product: " << endl;
			cout << (_Vector ^ newV);
			break;
		}
		case 11:
		{
			Vector v1;
			Vector v2;
			cin >> v1;
			cin >> v2;
			cout << "Mixed product: " << endl;
			cout << v1(v2, _Vector);
			break;
		}
	}
}

void VectorMenu::print_menu()
{
	instantiate_vector();

	cout << endl << "--- Vector Menu ---" << endl;

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
	cout << "12. Go back" << endl;

	cout << endl << ">: ";

	int option;

	if (_Commands.size() < 1)
	{
		cin >> option;
	}
	else
	{
		_Commands = this->_Vector._Commands;
		option = stoi(_Commands.front());
		_Commands.pop();
		cout << option << endl;
	}

	redirect(option);
}
