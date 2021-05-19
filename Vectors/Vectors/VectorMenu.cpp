#include "VectorMenu.h"

using namespace std;

void VectorMenu::instantiate_vector()
{
    Vector v;
    cin >> v;
    this->_Vector = v;
}

void VectorMenu::redirect_vector_menu(int option)
{
    switch (option) {
    case 1:
        cout << _Vector.get_vector_length();
        break;
    case 2:
        cout << _Vector.is_vector_null();
        break;
    case 3:
        cout << _Vector.vector_direction();
    default:
        break;
    }
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
