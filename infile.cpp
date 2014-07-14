#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>

const int FILENAME_SIZE = 60;

int main(int argc, char const *argv[])
{
	using namespace std;

	char filename[FILENAME_SIZE];
	ifstream fin;
	cout << "Enter the name of data file: ";
	cin.getline(filename, FILENAME_SIZE);

	fin.open(filename);
	if (!fin.is_open())
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);
	}

	string str;
	std::vector<string> car_info;
	while(fin.good()) {
	    getline(fin, str);
	    car_info.push_back(str);
	}
	if (fin.eof())
		cout << "End of file reached.\n";
	else if (fin.fail())
		cout << "Input terminated by data mismatch.\n";
	else 
		cout << "Input terminated by unkown reason.\n";

	if (str.empty())
		cout << "No data processed.\n";
	else {
		cout << "The content is about car type.\n";
		for (std::vector<string>::iterator i = car_info.begin(); i < car_info.end(); ++i)
		{
			cout << *i << endl;
		}
	}
	fin.close();

	return 0;
}