#include <iostream>
#include <vector>
#include "boost/shared_ptr.hpp"

class A
{
public:
	virtual void sing() = 0;
protected:
	virtual ~A() {}
};

class B : public A
{
public:
	virtual void sing()
	{
		std::cout << "DO re mi fa so la";
	}
};

boost::shared_ptr<A> createA() {
	boost::shared_ptr<A> p(new B());
	return p;
}

int main(int argc, char const *argv[])
{
	typedef std::vector<boost::shared_ptr<A>> container_type;

	container_type container;
	for (int i = 0; i < 10; ++i)
	{
		container.push_back(createA());
	}
	std::cout << "The choir is gathered: \n";
	for (auto it = container.begin(); it != container.end(); ++it)
	{
		(*it)->sing();
	}

	return 0;
}