#include <iostream>
#include "namesp.h"

void other(void);
void another(void);

int main(int argc, char const *argv[])
{
	using debts::Debt;
	using debts::show_debt;

	Debt golf = { { "Denny", "Goatsniff" }, 120.0 };
	show_debt(golf);
	other();
	another();

	return 0;
}

void other(void)
{
	using std::cout;
	using std::endl;
	using namespace debts;

	Person dg = { "Doodles", "Glister" };
	show_person(dg);
	cout << endl;

	Debt zippy[3];
	for (int i = 0; i < 3; ++i)
	{
		get_debt(zippy[i]);
	}
	for (int i = 0; i < 3; ++i)
	{
		show_debt(zippy[i]);
	}
	cout << "Total debt: $" << sum_debts(zippy, 3) << endl;

	return;
}

void another(void)
{
	using pers::Person;
	Person collector = { "Milo", "Rightshift" };
	pers::show_person(collector);
	std::cout << std::endl;
}