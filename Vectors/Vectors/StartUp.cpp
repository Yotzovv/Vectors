#include <iostream>
#include "Point.h"
#include "Triangle.h"
#include "MainMenu.h"
#include "Vector.h"
#include "Line.h"
#include "IOMenu.h"
#include "Line.h"
#include <vector>
#include "Vector.h"
#include "Triangle.h"
#include "Segment.h"

using namespace std;

int main()
{
	bool is_iterating = true;
	IOMenu io_menu;

	while (is_iterating)
	{
		io_menu.print_menu();

		bool is_invalid_input = true;

		while (is_invalid_input)
		{
			cout << endl << "Do you want to continue? (y/n)" << endl;
			cout << ">: ";

			char answer;
			cin >> answer;

			if (answer == 'y' || answer == 'n')
			{
				is_invalid_input = false;
			}

			if (answer == 'n') 
			{
				cout << "Do you want to write everything to a file? (y/n)" << endl;
				cout << ">: ";

				cin >> answer;

				if (answer == 'y')
				{
					io_menu.write_file();
				}
			}

			is_iterating = answer == 'y';
		}
	}

}