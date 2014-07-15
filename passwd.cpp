#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	char a[100];
	char ch;
	char *p = a;

	while((ch = cin.get()) != 13) {
	    cout << "*";
	    *p = ch;
	    p++;
	}

	cout << a << endl;

	return 0;
}