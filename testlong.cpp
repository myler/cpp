#include <iostream>

int main(int argc, char const *argv[])
{
	using namespace std;

	unsigned long res = 0;
	unsigned long array[] = {
		0x01020304,
		0x05060708
	};

	char *p = (char *) &array[0];
	p += 2;
	res = (unsigned long) *p;
	cout << res << endl;

	return 0;
}