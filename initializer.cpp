#include <iostream>
#include <initializer_list>

void print(std::initializer_list<int>);

int main(int argc, char const *argv[])
{
	print({12, 3, 5, 7, 11, 13, 17.0});

	return 0;
}

void print(std::initializer_list<int> vals)
{
	for (auto p = vals.begin(); p != vals.end(); ++p)
	{
		std::cout << *p << std::endl;
	}
}