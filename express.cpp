#include <iostream>

int main(int argc, char const *argv[])
{
	using namespace std;

	int x = 100;
	cout.setf(ios_base::boolalpha);
	cout << (x < 50) << endl;
	cout << (x > 50) << endl; 
	return 0;
}