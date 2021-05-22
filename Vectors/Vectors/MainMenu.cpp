#include "MainMenu.h"
#include <iostream>
#include "PointMenu.h"
#include "VectorMenu.h"
#include "LineMenu.h"
#include "SegmentMenu.h"
using namespace std;

void MainMenu::redirect(int chose)
{
	switch (chose)
	{
	case 1:
		PointMenu().print_point_menu();
		break;
	case 2:
		VectorMenu().print_vector_menu();
		break;
	case 3:
		LineMenu().print_line_menu();
		break;
	case 4:
		SegmentMenu().print_segment_menu();
		break;
	case 5:
		//Triangle
		break;
	case 6:
		//Tetrahedron
		break;
	}
}

void MainMenu::print_main_menu()
{
	cout << "Main Menu" << endl;
	cout << "1.Point" << endl;
	cout << "2.Vector" << endl;
	cout << "3.Line" << endl;
	cout << "4.Segment" << endl;
	cout << "5.Triangle" << endl;
	cout << "6.Tetrahedron" << endl << endl;

	cout << ">: ";
	int chose;
	cin >> chose;

	redirect(chose);
}
