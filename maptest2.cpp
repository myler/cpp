#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	
	map<string, int> Employees;
	Employees["Mike C."] = 12099;
	Employees["Charlie M."] = 98666;

	Employees.insert(pair<string, int>("David Li.", 29555));
	Employees.insert(map<string, int>::value_type("John O'rk.", 15677));
	Employees.insert(make_pair("Peter Q.", 53445));

	cout << "Map size: " << Employees.size() << endl;

	for (auto iter = Employees.begin(); iter != Employees.end(); ++iter)
	{
		cout << (*iter).first << ": " << (*iter).second << endl;
	}

	return 0;
}