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

	while (is_iterating)
	{
		IOMenu().print_menu();

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

			is_iterating = answer == 'y';
		}
	}

}