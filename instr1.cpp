#include <iostream>

int main(int argc, char const *argv[])
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "Enter your name: " << endl;
	cin.getline(name, ArSize);
	cout << "Enter your favorite dessert: " << endl;
	cin.getline(dessert, ArSize);
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << endl;
	
	return 0;
}