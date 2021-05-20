#include "VectorMenu.h"
#include "Vector.h"
#include <iostream>

using namespace std;

VectorMenu::VectorMenu()
{
	Vector v;
	cin >> v;

	this->_Vector = v;
}

void VectorMenu::redirect_vector_menu(int option)
{
	//switch (option) {
	//case 1:
	//	cout << _Vector.get_vector_length();
	//	break;
	//case 2:
	//	cout << _Vector.is_vector_null();
	//	break;
	//case 3:
	//	_Vector.print_direction();
	//	break;
	//case 4:
	//	Vector newV;
	//	cin >> newV;
	//	cout << _Vector.is_parallel(newV);
	//	break;
	//case 5:
	//	Vector newV;
	//	cin >> newV;
	//	cout << _Vector.is_vector_perpendicullar(newV);
	//	break;
	//case 6:
	//	// this works with n1,n2,n3 only
	//	Vector newV;
	//	cin >> newV;
	//	Vector result = _Vector + newV;
	//	cout << result;
	//	break;
	//case 7:
	//	Vector newV;
	//	cin >> newV;
	//	Vector result = _Vector - newV;
	//	cout << result;
	//	break;
	//case 8:
	//	int n;
	//	cin >> n;
	//	Vector result = n * _Vector;
	//	cout << result;
	//	break;
	//case 9:
	//	Vector newV;
	//	cin >> newV;
	//	double result = _Vector * newV;
	//	cout << result;
	//	break;
	//case 10:
	//	Vector newV;
	//	cin >> newV;
	//	Vector result = _Vector ^ newV;
	//	cout << result;
	//	break;
	//case 11:
	//	Vector v1;
	//	Vector v2;
	//	cin >> v1;
	//	cin >> v2;
	//	double result = v1(v2, _Vector);
	//	cout << result;
	//	break;
	//default:
	//	break;
	//}
}

void VectorMenu::print_vector_menu()
{
	cout << "Vector Menu" << endl;

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

	cout << ">: ";

	int option;
	cin >> option;

	redirect_vector_menu(option);
}
