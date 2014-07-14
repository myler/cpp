#include <iostream>
#include "string.h"

const int ARRARY_SIZE = 10;
const int MAX_LEN = 81;

int main(int argc, char const *argv[])
{
	using std::cout;
	using std::cin;
	using std::endl;

	String name;
	cout << "Hi, what's your name?\n>> ";
	cin >> name;

	cout << name << ", please enter up to " << ARRARY_SIZE
	<< " short sayings <empty line to quit>:\n";
	String sayings[ARRARY_SIZE];
	char temp[MAX_LEN];
	int i;
	for (i = 0; i < ARRARY_SIZE; ++i)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MAX_LEN);
		while(cin && cin.get() != '\n') {
		    continue;
		}
		if (!cin || temp[0] == '\n')
		{
			break;
		} else {
			sayings[i] = temp;
		}
	}
	int total = i;

	if (total > 0)
	{
		cout << "Here are your sayings:\n";
		for (int i = 0; i < total; ++i)
		{
			cout << sayings[i][0] << ": " << sayings[i] << endl;
		}

		int shortest = 0;
		int first = 0;
		for (int i = 0; i < total; ++i)
		{
			if (sayings[i].length() < sayings[shortest].length())
			{
				shortest = i;
			}
			if (sayings[i] < sayings[first])
			{
				first = i;
			}
		}

		cout << "Shortest saying:\n" << sayings[shortest] << endl;
		cout << "First alphabetically:\n" << sayings[first] << endl;
		cout << "This program used " << String::how_many() << " String objects. Bye!\n";
	} else {
		cout << "No input. Bye!\n";
	}

	return 0;
}