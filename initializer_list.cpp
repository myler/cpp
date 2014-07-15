#include <iostream>
#include <initializer_list>

double sum(std::initializer_list<double> il);

int main(int argc, char const *argv[])
{
	double result = sum({1, 2, 3, 4, 5});
	std::cout << result << std::endl;

	return 0;
}

double sum(std::initializer_list<double> il)
{
	double sum = 0;
	for (auto iter = il.begin(); iter != il.end(); ++iter)
		sum += *iter;

	return sum;
}