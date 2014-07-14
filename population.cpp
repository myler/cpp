#include <iostream>

int main(int argc, char const *argv[])
{
	using namespace std;

	unsigned long world_population, usa_population;
	double rate;

	cout << "Enter the world's population: ";
	cin >> world_population;
	cout << "Enter the population of the US: ";
	cin >> usa_population;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	rate = double (usa_population) / world_population * 100;
	cout << "The population of the US is " << rate;
	cout << "% of the world population." << endl;;
	
	return 0;
}