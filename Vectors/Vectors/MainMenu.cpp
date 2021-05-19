#include "MainMenu.h"
#include <iostream>

using namespace std;

int redirect(int chose) {
	switch (chose)
	{
	case 1:
		//PointMenu
		break;
	case 2:
		//VectorMenu
		break;
	case 3:
		//LineMenu
		break;
	case 4:
		//Segment
		break;
	case 5:
		//Triangle
		break;
	case 6:
		//Tetrahedron
		break;
	}
}

int print_main_menu()
{
	cout << "Choose a figure" << endl;
	cout << "1.Point" << endl;
	cout << "2.Vector" << endl;
	cout << "3.Line" << endl;
	cout << "4.Segment" << endl;
	cout << "5.Triangle" << endl;
	cout << "6.Tetrahedron" << endl;

	int chose;
	cin >> chose;

	redirect(chose);
}
