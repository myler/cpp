#include <iostream>
#include "boost/signals2.hpp"

void my_first_slot()
{
	std::cout << "This is my first slot." << std::endl;
}

class my_second_slot
{
public:
	void operator()() const
	{
		std::cout << "This is my second slot." << std::endl;
	}
};

int main(int argc, char const *argv[])
{
	
	boost::signals2::signal<void()> sig;
	sig.connect(&my_first_slot);
	sig.connect(my_second_slot());

	std::cout << "Emitting a signal...\n";
	sig();

	return 0;
}