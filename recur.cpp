#include <iostream>

void count_down(int n);

int main(int argc, char const *argv[])
{
	count_down(4);

	return 0;
}

void count_down(int n)
{
	using namespace std;

	cout << "Counting down ... " << n << "(n at " << &n << ")" << endl;
	if (n > 0)
	{
		count_down(n - 1);
	}
	cout << n << ": Kaboom!" << "(n at " << &n << ")" << endl;
}