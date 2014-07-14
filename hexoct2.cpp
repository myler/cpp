#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int chest = 42;
	int waist = 42;
	int inseam = 42;

	cout << "Monsieur cuts a striking figure!" <<endl;
	cout << "chest = " << chest << " (decimal for 42)\n";
	cout << hex;
	cout << "waist = " << waist << " (hexadecimal for 42)\n";
	cout << oct;
	cout << "inseam = " << inseam << " (octal for 42)\n";
	return 0;
}