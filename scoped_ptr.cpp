#include <iostream>
#include <string>
#include "boost/scoped_ptr.hpp"

int main(int argc, char const *argv[])
{
	boost::scoped_ptr<std::string>
	p(new std::string("Use scoped_ptr often."));

	if (p)
	{
		std::cout << *p << std::endl;
	}
	size_t i = (*p).size();
	std::cout << i << std::endl;
	*p = "Acts just like a pointer";
	if (p)
	{
		std::cout << *p << std::endl;
	}

	return 0;
}