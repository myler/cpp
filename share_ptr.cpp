#include <iostream>
#include <cassert>
#include "boost/shared_ptr.hpp"

class A
{
	boost::shared_ptr<int> no_;
public:
	A(boost::shared_ptr<int> no) : no_(no) {}
	void value(int i)
	{
		*no_ = i;
	}
};

class B
{
	boost::shared_ptr<int> no_;
public:
	B(boost::shared_ptr<int> no) : no_(no) {}
	int value() const
	{
		return *no_;
	}
};

int main(int argc, char const *argv[])
{
	boost::shared_ptr<int> temp(new int(14));
	A a(temp);
	B b(temp);
	a.value(28);
	assert(b.value() == 28);

	std::cout << "temp:" << *temp << std::endl;

	return 0;
}