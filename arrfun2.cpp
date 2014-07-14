#include <iostream>

const int MAX = 5;

int fill_array(double *arr, int limit);
void show_array(const double *arr, int n);
void revalue(double r, double *arr, int n);

int main(int argc, char const *argv[])
{
	using namespace std;

	double properties[MAX];
	int size = fill_array(properties, MAX);
	show_array(properties, size);

	if (size > 0) {
		cout << "Enter revaluation factor: ";
		double factor;
		while(!(cin >> factor)) {
		    cin.clear();
		    while(cin.get() != '\n') {
		        continue;
		    }
		    cout << "Bad input; Please enter a number: ";
		}
		revalue(factor, properties, size);
		show_array(properties, size);
	}
	cout << "Done.\n";
	//cin.get();
	//cin.get();

	return 0;
}

int fill_array(double *arr, int limit) {
	using namespace std;

	double temp;
	int i;

	for (i = 0; i < limit; ++i)
	{
		cout << "Enter value #" << (i + 1) << ": ";
		cin >> temp;
		if (!cin) {
			cin.clear();
			while(cin.get() != '\n') {
			    continue;
			}
			cout << "Bad input; input process terminated.\n";
			//cin.sync();
			break;
		}
		*(arr + i) = temp;
	}
	return i;
}

void show_array(const double *arr, int n) {
	using namespace std;

	for (int i = 0; i < n; ++i)
	{
		cout << "Property #" << (i + 1) << ": $";
		cout << *(arr + i) <<endl;
	}
}

void revalue(double r, double *arr, int n) {
	for (int i = 0; i < n; ++i)
	{
		*(arr + i) *= r;
	}
}