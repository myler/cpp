#include <iostream>
#include <vector>
#include <algorithm>
#include "boost/function.hpp"

void print_new_value(int i)
{
	std::cout << "The value has been updated and is now " << i << '\n';
}

void interested_in_the_change(int i)
{
	std::cout << "Ah, the value has changed.\n";
}

class knows_the_previous_value
{
	int last_value_;
public:
	void operator()(int i)
	{
		static bool first_time = true;
		if (first_time)
		{
			last_value_ = i;
			std::cout << "This is the first change of value,"
			<< " so I don't knows the previous one.\n";
			first_time = false;
			return;
		}
		std::cout << "Previous value was " << last_value_ << '\n';
		last_value_ = i;
	}
};

class notifier
{
	typedef boost::function<void(int)> function_type;
	std::vector<function_type> vec_;
	int value_;
public:
	template <typename T> void add_observer(T t)
	{
		vec_.push_back(t);
	}

	void change_value(int i)
	{
		value_ = i;
		for (std::size_t i = 0; i < vec_.size(); ++i)
			vec_[i](value_);
	}
};

int main(int argc, char const *argv[])
{
	notifier n;
	n.add_observer(&print_new_value);
	n.add_observer(&interested_in_the_change);
	n.add_observer(knows_the_previous_value());

	n.change_value(42);
	std::cout << "\n";
	n.change_value(30);

	return 0;
}