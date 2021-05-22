#include "SegmentMenu.h"

SegmentMenu::SegmentMenu()
{
	Segment segment;
	cin >> segment;

	_Segment = segment;
}

void SegmentMenu::redirect_segment_menu(int option)
{
	switch (option)
	{
		case 1: 
		{
			cout << _Segment.find_segment_length();
			break;
		}
		case 2:
		{
			cout << "Finding middle point..." << endl;
			cout << _Segment.find_segment_middle();
			break;
		}
		case 3:
		{
			Point pt;
			cin >> pt;
			cout << (_Segment == pt);
		}
	}
}

void SegmentMenu::print_segment_menu()
{
	cout << endl << "--- Segment Menu ---" << endl;
	cout << "1. Calculate length" << endl;
	cout << "2. Calculate middle point" << endl;
	cout << "3. Check if a point lies on the segment" << endl;
	cout << "4. Go back" << endl;
	cout << endl << ">: ";

	int option;
	cin >> option;
	redirect_segment_menu(option);
}
