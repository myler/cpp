#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
	using namespace std;

	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream fout;
	fout.open("carinfo.txt");

	cout << "Enter the make and model of automobile: ";
	cin.getline(automobile, 50);
	cout << "Enter the model year: ";
	cin >> year;
	cout << "Enter the original asking price: ";
	cin >> a_price;
	d_price = a_price * 0.913;

	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "Make and model: " << automobile << endl;
	cout << "Year: " << year << endl;
	cout << "Was asking $" << a_price << endl;
	cout << "Now asking $" << d_price << endl;

	fout << fixed;
	fout.precision(2);
	fout.setf(ios_base::showpoint);
	fout << "Make and model: " << automobile << endl;
	fout << "Year: " << year << endl;
	fout << "Was asking $" << a_price << endl;
	fout << "Now asking $" << d_price << endl;
	fout.close();

	return 0;
}