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

	setOutputs(v.getOutputs());

	_Vector = v;
}


void VectorMenu::redirect(int option)
{
	string result;

	switch (option) {
		case 1:
		{
			result = "Vector Length is: " + to_string(_Vector.get_vector_length());
			cout << result;
			break;
		}
		case 2:
		{
			result = (_Vector.is_vector_null() ? "Vector is null." : "Vector is not null.");
			cout << result;
			break;
		}
		case 3:
		{
			result = "Vector direciton: \n";
			cout << result;
			_Vector.print_direction();
			break;
		}
		case 4:
		{
			Vector parallelV;
			cin >> parallelV;
			result = (_Vector.is_parallel(parallelV) ? "Vectors are parallel." : "Vectors are not parallel.");
			cout << result;
			break;
		}
		case 5:
		{
			Vector perpendicullarV;
			cin >> perpendicullarV;
			result = (_Vector.is_vector_perpendicullar(perpendicullarV) ? "Vectors are perpendicular." : "Vectors are not perpendicular.");
			cout << result;
			break;
		}
		case 6:
		{
			// this works with n1,n2,n3 only
			Vector vec_to_add;
			cin >> vec_to_add;
			result = "New vector: \n" + (_Vector + vec_to_add).get_data();
			cout << result;
			break;
		}
		case 7:
		{
			Vector vec_to_sub;
			cin >> vec_to_sub;
			result = "New vector: \n" + (_Vector - vec_to_sub).get_data();
			cout << result;
			break;
		}
		case 8:
		{
			int n;
			cin >> n;
			result = "New vector: \n" + (n * _Vector).get_data();
			cout << result;
			break;
		}
		case 9:
		{
			Vector vec_to_multiply;
			cin >> vec_to_multiply;
			result = "Scalar product: \n" + to_string(_Vector * vec_to_multiply);
			cout << result;
			break;
		}
		case 10:
		{
			Vector newV;
			cin >> newV;
			result = "Vector product: \n" + (_Vector ^ newV).get_data();
			cout << result;
			break;
		}
		case 11:
		{
			Vector v1;
			Vector v2;
			cin >> v1;
			cin >> v2;
			result = "Mixed product: \n" + to_string((v1(v2, _Vector)));
			cout << result;
			break;
		}
	}

	pushtToOutputs(result);
}

void VectorMenu::print_menu()
{
	instantiate_vector();

	auto output = "\n--- Vector Menu ---\n"
		"1. Calculate length\n"
		"2. Check for 0 vector\n"
		"3. Calculate direction\n"
		"4. Check if vectors are parallel\n"
		"5. Check if vectors are perpendicular\n"
		"6. Sum 2 vectors\n"
		"7. Substract 2 vectors\n"
		"8. Multiply vector by number\n"
		"9. Scalar product of 2 vectors\n"
		"10. Vector product of 2 vectors\n"
		"11. Mixed Product of 3 vectors\n"
		"12. Go back\n"
		">: ";

	pushtToOutputs(output);

	cout << output;

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

	pushtToOutputs(to_string(option) + '\n');

	redirect(option);
}
