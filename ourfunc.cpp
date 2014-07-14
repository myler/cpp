#include <iostream>

void myl(int);

int main() {
	using namespace std;

	myl(3);
	cout << "Pick an integer: ";
	int count;
	cin >> count;
	myl(count);
	cout << "Done!" << endl;
	return 0;
}

void myl(int n) {
	using namespace std;
	cout << "Myl says touch your toes " << n << " times." << endl;
}
