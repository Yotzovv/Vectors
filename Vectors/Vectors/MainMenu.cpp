#include "MainMenu.h"
#include <iostream>
#include "PointMenu.h"
#include "VectorMenu.h"
#include "LineMenu.h"
#include "SegmentMenu.h"
#include "TriangleMenu.h"
#include "TetrahedronMenu.h"

using namespace std;

void MainMenu::redirectMain(int chose)
{
	switch (chose)
	{
	case 1:
	{
		PointMenu(_Commands).print_point_menu();
		break;
	}
	case 2:
		VectorMenu(_Commands).print_vector_menu();
		break;
	case 3:
		LineMenu(_Commands).print_line_menu();
		break;
	case 4:
		SegmentMenu().print_segment_menu();
		break;
	case 5:
		TriangleMenu().print_triangle_menu();
		break;
	case 6:
		TetrahedronMenu().print_tetrahedron_menu();
		break;
	}
}

void MainMenu::print_main_menu()
{
	cout << endl << "--- Main Menu ---" << endl;
	cout << "1.Point" << endl;
	cout << "2.Vector" << endl;
	cout << "3.Line" << endl;
	cout << "4.Segment" << endl;
	cout << "5.Triangle" << endl;
	cout << "6.Tetrahedron" << endl << endl;

	cout << ">: ";
	int chose;

	if (_Commands.size() < 1)
	{
		cin >> chose;
	}
	else
	{
		chose = stoi(_Commands.front());
		_Commands.pop();
		cout << chose;
	}

	redirectMain(chose);
}
