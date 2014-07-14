#include <iostream>
#include "complex.h"

int main(int argc, char const *argv[])
{
	using namespace std;
	using COMPLEX::Complex;

	Complex a(3.0, 4.0);
	Complex c;

	cout << "Enter a complex number (q to quit):" << endl;
	while(cin >> c) {
	    cout << "a is " << a << endl;
	    cout << "a + c is " << a + c << endl;
	    cout << "a - c is " << a - c << endl;
	    cout << "a * c is " << a * c << endl;
	    cout << "2 * c is " << 2 * c << endl;

	    cout << "Enter a complex number (q to quit):" << endl;
	}
	cout << "Done!" << endl;

	return 0;
}