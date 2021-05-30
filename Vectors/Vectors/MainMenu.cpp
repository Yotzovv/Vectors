#include "MainMenu.h"
#include <iostream>
#include "PointMenu.h"
#include "VectorMenu.h"
#include "LineMenu.h"
#include "SegmentMenu.h"
#include "TriangleMenu.h"
#include "TetrahedronMenu.h"

using namespace std;

MainMenu::MainMenu(std::queue<std::string> cmds) : Menu(cmds)
{
}

void MainMenu::redirect(int chose)
{
	switch (chose)
	{
		case 1:
		{
			PointMenu point_menu(_Commands);

			point_menu.print_menu();
			this->setOutputs(point_menu.getOutputs());
			break;
		}
		case 2:
		{
			VectorMenu vector_menu(_Commands);

			vector_menu.print_menu();
			this->setOutputs(vector_menu.getOutputs());
			break;
		}
		case 3:
		{
			LineMenu(_Commands).print_menu();
			break;
		}
		case 4:
		{
			SegmentMenu(_Commands).print_menu();
			break;
		}
		case 5:
		{
			TriangleMenu(_Commands).print_menu();
			break;
		}
		case 6:
		{
			TetrahedronMenu(_Commands).print_menu();
			break;
		}
	}
}

void MainMenu::print_menu()
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

	redirect(chose);
}
