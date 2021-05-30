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

IOMenu::IOMenu() : Menu()
{
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
		}
		myfile.close();
	}
	else
	{
		cout << "Unable to open file";
	}

	MainMenu main_menu(_Commands);

	main_menu.print_menu();

	this->setOutputs(main_menu.getOutputs());
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
		MainMenu main_menu(_Commands);
		main_menu.print_menu();
		this->setOutputs(main_menu.getOutputs());
		break;
	}
	case 3:
	{
		cout << endl << "> Choose the source of the input." << endl;
		cout << "> Will you read input from file or the console?" << endl;
		cout << "> For file input you will need to store your files in \"Input\" folder" << endl;
	}
	}
}

void IOMenu::print_menu()
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

void IOMenu::write_file()
{
	ofstream out_file("output.txt");

	for (auto output : getOutputs())
	{
		out_file << output << endl;
	}

	out_file.close();
}
