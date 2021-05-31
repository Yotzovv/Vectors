#include "SegmentMenu.h"

SegmentMenu::SegmentMenu(std::queue<std::string> cmds)
{
	_Commands = cmds;
}

SegmentMenu::SegmentMenu()
{
}

void SegmentMenu::instantiate_segment()
{
	Segment segment;
	if (_Commands.size() > 0)
	{
		segment = Segment(_Commands);
	}

	cin >> segment;

	_Commands = segment._Commands;
	_Segment = segment;
}

void SegmentMenu::redirect(int option)
{
	switch (option)
	{
	case 1:
	{
		cout << "Segment length: " << _Segment.find_segment_length();
		break;
	}
	case 2:
	{
		cout << "Finding middle point..." << endl;
		cout << "Middle point: " << _Segment.find_segment_middle();
		break;
	}
	case 3:
	{
		Point pt(_Commands);
		cin >> pt;
		cout << ((_Segment == pt) ? "Point lies on segment." : "Point doesn\'t lie on segment.");
		break;
	}
	default:
	{
		break;
	}
	}
}

void SegmentMenu::print_menu()
{
	instantiate_segment();

	cout << endl << "--- Segment Menu ---" << endl;
	cout << "1. Calculate length" << endl;
	cout << "2. Calculate middle point" << endl;
	cout << "3. Check if a point lies on the segment" << endl;
	cout << "4. Go back" << endl;
	cout << endl << ">: ";

	int option;

	if (_Commands.size() < 1)
	{
		cin >> option;
	}
	else
	{
		option = stoi(_Commands.front());
		_Commands.pop();
		cout << option << endl;
	}

	redirect(option);
}
