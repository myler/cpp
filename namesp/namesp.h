#include <string>

#ifndef NAMESP_H
#define NAMESP_H

namespace pers
{
	struct Person
	{
		std::string fname;
		std::string lname;
	};
	void get_person(Person &);
	void show_person(const Person &);
}

namespace debts
{
	using namespace pers;
	struct Debt
	{
		Person name;
		double amount;
	};
	void get_debt(Debt &);
	void show_debt(const Debt &);
	double sum_debts(const Debt *ar, int n);
}

#endif // NAMESP_H