#include <ratio>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	typedef ratio<1, 999> FiveThirds;
	cout << FiveThirds::num << "/" << FiveThirds::den << endl;
	cout << std::nano::num << "/" << std::nano::den << endl;
	return 0;
}