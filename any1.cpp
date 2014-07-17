#include <iostream>
#include  "boost/any.hpp"

int main(int argc, char const *argv[])
{
	boost::any a;
	a = std::string("This is a string");
	std::cout << boost::any_cast<std::string>(a) << std::endl;

	std::string b = boost::any_cast<std::string>(a);
	std::cout << b << std::endl;
	auto s = a;
	std::cout << boost::any_cast<std::string>(s) << std::endl;

	a = 42;
	std::cout << boost::any_cast<int>(a) << std::endl;
	auto c = a;
	std::cout << boost::any_cast<int>(c) << std::endl;

	return 0;
}