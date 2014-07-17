#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "boost/bind.hpp"
#include "boost/shared_ptr.hpp"

class status
{
	std::string name_;
	bool ok_;
public:
	status(const std::string &name) : name_(name), ok_(true) {}
	void break_it() {ok_ = false;}
	bool is_broken() const {return ok_;}
	void report() const
	{
		std::cout << name_ << " is " <<
		(ok_ ? "working nominaliiy" : "terribly broken")
		<< '\n';
	}
};

int main(int argc, char const *argv[])
{
	std::vector<boost::shared_ptr<status>> s_statuses;
	s_statuses.push_back(
	  boost::shared_ptr<status>(new status("status 1")));
	s_statuses.push_back(
	  boost::shared_ptr<status>(new status("status 2")));
	s_statuses.push_back(
	  boost::shared_ptr<status>(new status("status 3")));
	s_statuses.push_back(
	  boost::shared_ptr<status>(new status("status 4")));
	s_statuses[1]->break_it();
	s_statuses[3]->break_it();

	for (auto it = s_statuses.begin(); it != s_statuses.end(); ++it)
	{
		(*it)->report();
	}

	std::for_each(s_statuses.begin(), s_statuses.end(),
		boost::bind(&status::report, _1));

	return 0;
}