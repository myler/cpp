#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "boost/bind.hpp"

class personal_info {
  std::string name_;
  std::string surname_;
  unsigned int age_;

public:
  	personal_info(
    const std::string& n,
    const std::string& s,
    unsigned int age):name_(n),surname_(s),age_(age) {}

  	std::string name() const {
    	return name_;
  	}

  	std::string surname() const {
    	return surname_;
  	}

  	unsigned int age() const {
    	return age_;
  	}

  	friend std::ostream &operator<<(std::ostream &os,const personal_info &pi) {
	  	os << pi.name() << ' ' <<
	    pi.surname() << ' ' << pi.age() << '\n';

	  	return os;
	}
};

int main(int argc, char const *argv[])
{
	std::vector<personal_info> vec;
	vec.push_back(personal_info("Little", "John", 30));
	vec.push_back(personal_info("Friar", "Tuck", 50));
	vec.push_back(personal_info("Robin", "Hood", 40));

	std::sort(vec.begin(), vec.end(),
		boost::bind(std::less<unsigned int>(),
		boost::bind(&personal_info::age, _1),
		boost::bind(&personal_info::age, _2)));

	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it;
	}

	return 0;
}