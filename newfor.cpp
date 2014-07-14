#include <iostream>

int main(int argc, char const *argv[])
{
	using namespace std;

	for (int x : {3, 5, 2, 8, 6})
		cout << x << " ";
	cout << endl;

	return 0;
}