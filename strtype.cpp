#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	using namespace std;
	string str;
	cout << "Enter a string: ";
	getline(cin, str);
	cout << "You entered: " << str << endl;
	return 0;
}