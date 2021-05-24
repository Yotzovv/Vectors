#include "IOMenu.h"
#include "MainMenu.h"
#include <iostream>
#include "PointMenu.h"
#include "VectorMenu.h"
#include "LineMenu.h"
#include "SegmentMenu.h"
#include "TriangleMenu.h"
#include "TetrahedronMenu.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

using namespace std;

namespace fs = std::filesystem;

void IOMenu::input_from_file(string line)
{
	cout << "You chose " << line << endl;
	//fputc(stoi(line), stdout);
	//MainMenu().redirect(stoi(line));
}

vector<string> IOMenu::read_directory()
{
	std::string path = "../Inputs";
	int counter = 0;
	vector<string> files;
	cout << endl << "-- Chose a file ---" << endl;

	for (const auto& entry : fs::directory_iterator(path))
	{
		files.push_back(entry.path().filename().string());
		std::cout << ++counter << ": " << entry.path().filename().string() << std::endl;
	}

	return files;
}

void IOMenu::read_file()
{
	vector<string> files = read_directory();

	cout << endl << ">: ";
	int option;
	cin >> option;

	string line;
	ifstream myfile("../Inputs/" + files[option - 1]);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			_Commands.push(line);
			//cout << line << '\n';
		}
		myfile.close();
	}
	else
	{
		cout << "Unable to open file";
	}

	this->print_main_menu();
}

void IOMenu::redirect(int chose)
{
	switch (chose)
	{
	case 1:
		read_file();
		break;
	case 2:
	{
		MainMenu().print_main_menu();
		break;
	}
	case 3:
	{
		cout << endl << "> Choose the source of the input." << endl;
		cout << "> Will you read input from file or the console?" << endl;
	}
	}
}

void IOMenu::print_io_menu()
{
	cout << endl << "--- Input Type Menu ---" << endl;
	cout << "1. Use a file" << endl;
	cout << "2. Use the console" << endl;
	cout << "3. Help!" << endl;


	cout << endl << ">: ";
	int chose;
	cin >> chose;

	redirect(chose);

}